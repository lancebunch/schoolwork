/***********************************************************************
 * Program:
 *    Week 08, OpenMP Lab
 * Author:
 *    Lance Bunch
 * Summary:
 *    Showcases threads by doing matrix multiplication
 ************************************************************************/

#include <iostream>  // for COUT and CERR
#include <fstream>   // for IFSTREAM
#include <pthread.h> // for PTHREAD_T and the PTHREAD functions
#include <iomanip>   // for SETW
#include <cassert>   // because I am paranoid
#include <omp.h>     // for OpenMP
using namespace std;

/***********************************************************
 * MATRIX MULTIPLICATION
 * A data-structure to contain the notion of matrix multiplication
 **********************************************************/
struct MatrixMultiplication
{
   int *arrayDestination = NULL; // destination array
   int *arrayRHS = NULL;         // right-hand-side
   int *arrayLHS = NULL;         // left-hand-side

   int numRowRHS;
   int numColRHS;
   int numRowLHS;
   int numColLHS;
};

// This variable represents the shared memory between the parent thread
// and all the children. Recall from the reading how the main way for
// threads to communicate is through shared memory. This shared memory
// needs to be global.
MatrixMultiplication matrix;

// custom made variable for each thread to have destinations
struct Identify
{
   int row = 0;
   int col = 0;
};

// prototypes
// void doMultiply(Identify cell[]);
bool readMatrix(const char *fileName,
                int *&array,
                int &numRow,
                int &numCol);
bool multiply(MatrixMultiplication &m, int numThreads);
void display(MatrixMultiplication &m);

/*************************************************
 * MAIN
 * Turn the input parameters into calls to threads
 ************************************************/
int main(int argc, char **argv)
{
   int numRow;
   int numCol;

   // prompt for number of threads
   int numThreads;
   cout << "How many threads? ";
   cin >> numThreads;

   // make sure we have the proper number of parameters
   if (argc != 3)
   {
      cout << "Usage:\n\t" << argv[0] << "  left-hand-side  right-hand-side\n";
      return 1;
   }

   // read the LHS
   if (!readMatrix(argv[1], matrix.arrayLHS, numRow, numCol))
   {
      cout << "Unable to open matrix file " << argv[1] << endl;
      return 1;
   }
   matrix.numRowLHS = numRow;
   matrix.numColLHS = numCol;

   // read the RHS
   if (!readMatrix(argv[2], matrix.arrayRHS, numRow, numCol))
   {
      cout << "Unable to open matrix file " << argv[1] << endl;
      return 1;
   }
   matrix.numRowRHS = numRow;
   matrix.numColRHS = numCol;

   // multiply
   if (!multiply(matrix, numThreads))
      cout << "Unable to perform matrix multiplication\n";
   else
      display(matrix);

   // free
   delete[] matrix.arrayLHS;
   delete[] matrix.arrayRHS;
   delete[] matrix.arrayDestination;
   return 0;
}

/*******************************************************
 * READ MATRIX
 * Read a matrix from a file (fileName) and put the results
 * into an array (array). Return false if anything bad happens
 ******************************************************/
bool readMatrix(const char *fileName,
                int *&array,
                int &numRow,
                int &numCol)
{
   numRow = 0;
   numCol = 0;

   // open the file
   ifstream fin(fileName);
   if (fin.fail())
      return false;

   // read the file
   fin >> numCol >> numRow;
   if (numRow < 1 || numCol < 1)
   {
      fin.close();
      return false;
   }

   array = new int[numRow * numCol];
   for (int r = 0; r < numRow; r++)
      for (int c = 0; c < numCol; c++)
         fin >> array[r * numCol + c];

   if (fin.fail())
   {
      fin.close();
      return false;
   }

   // close the file
   fin.close();
   return true;
}

/**************************************************
 * doMultiply
 * Child function to multiply a single cell in dest matrix
 *************************************************/
void doMultiply(Identify cell[])
{
   // Setting destination index based off of identifier cell
   int dest = cell->row * matrix.numColRHS + cell->col;
   int sourceRow = cell->row * matrix.numColLHS;
   for (int i = 0; i < matrix.numColLHS; i++)
   {
      // Algorithm to perform mult.....Take the row index of LHS matrix......times the col index of RHS matrix
      matrix.arrayDestination[dest] += matrix.arrayLHS[sourceRow + i] * matrix.arrayRHS[i * matrix.numColRHS + cell->col];
   }
}

/**************************************************
 * MULTIPLY
 * Perform matrix multiplication
 *************************************************/
bool multiply(MatrixMultiplication &m, int numThreads)
{
   int numRowDes = m.numRowLHS;
   int numColDes = m.numColRHS;

   m.arrayDestination = new int[numRowDes * numColDes];
   for (int row = 0; row < numRowDes; row++)
      for (int col = 0; col < numColDes; col++)
         m.arrayDestination[row * numColDes + col] = 0;

   if (m.numRowRHS != m.numColLHS)
      return false;

   // Struct variable to identify which cell of the matrix to work on
   Identify data[numThreads];

// Nested For loop to make sure we fully multiply both matrices
#pragma omp parallel for num_threads(numThreads)
   for (int row = 0; row < numRowDes; row++)
   {
      for (int col = 0; col < numColDes; col++)
      {
         int pos = row * numColDes + col;
         // Setting the identifier cell
         data[pos].row = row;
         data[pos].col = col;

         // Time to multiply, add pos to reference specific index
         doMultiply(data + pos);
      }
   }

#ifdef _OPENMP
   cerr << "_OPENMP defined, threadct = " << numThreads << endl;
#else
   cerr << "_OPENMP not defined" << endl;
#endif

   return true;
}

/******************************************************
 * DISPLAY
 * Display the entire matrix operation
 *****************************************************/
void display(MatrixMultiplication &m)
{
   int maxRow = (m.numRowRHS > m.numRowLHS) ? m.numRowRHS : m.numRowLHS;
   int numRowDes = m.numRowLHS;
   int numColDes = m.numColRHS;

   for (int row = 0; row < maxRow; row++)
   {
      // Left-hand-side
      if (row < m.numRowLHS)
      {
         cout << "|";
         for (int col = 0; col < m.numColLHS; col++)
            cout << setw(3) << m.arrayLHS[row * m.numColLHS + col];
         cout << "  |";
      }
      else
         cout << setw(3 * m.numColLHS + 4) << " ";

      // multiply symbol or space
      cout << ((maxRow - 1) / 2 == row ? " X " : "   ");

      // Right-hand-side
      if (row < m.numRowRHS)
      {
         cout << "|";
         for (int col = 0; col < m.numColRHS; col++)
            cout << setw(3) << m.arrayRHS[row * m.numColRHS + col];
         cout << "  |";
      }
      else
         cout << setw(3 * m.numColRHS + 4) << " ";

      // equals
      cout << ((maxRow - 1) / 2 == row ? " = " : "   ");

      // result
      if (row < numRowDes)
      {
         cout << "|";
         for (int col = 0; col < numColDes; col++)
            cout << setw(4) << m.arrayDestination[row * numColDes + col];
         cout << "   |";
      }

      // endl at the end of the line
      cout << endl;
   }
}
