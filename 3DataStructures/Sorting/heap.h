/***********************************************************************
* Program:
*    Week 11, Sorting
*    Brother Ercanbrack, CS 235
*
* Author:
*   Lance Bunch  
* Summary: 
*
************************************************************************/
#include <vector>

using namespace std;

/*************************************************************************
* function :: PERCOLATEDOWN
* Logic determines how to make a hypothetical Binary Heap Tree
**************************************************************************/
template <class T>
void percolateDown(vector<T> &data, int index, int wall)
{
   // iL is equal to the "left node" of the hypothetical tree
   int iL = index * 2;

   // iR is eqaul to the "right node" of the hupothetical tree
   int iR = iL + 1;

   // if iR is less than or equal to the vector wall
   // and the data of iR is greater than the data of iL
   // and the data of iR is greater than the data of the halfway point
   if (iR <= wall &&
       data[iR] > data[iL] &&
       data[iR] > data[index])
   {
      // swap the halfway point data with iR data
      swap(data[index], data[iR]);
      // call percolateDown recursively giving it iR as halfway point
      percolateDown(data, iR, wall);
   }
   // if iL is less than or equal to the vector wall
   // and iL data is greater than the halfway point data
   else if (iL <= wall && data[iL] > data[index])
   {
      // swap the halfway point with iL data
      swap(data[index], data[iL]);
      // call percolateDown recursively giving it iL as halfway point
      percolateDown(data, iL, wall);
   }
}

/*************************************************************************
* function :: HEAPIFY
* calls the percolateDown function to turn a vector into a heap
**************************************************************************/
template <class T>
void heapify(vector<T> &data, int wall)
{
   // setting i(ndex) = to halfway through the vector
   for (int i = wall / 2; i > 0; i--)
   {
      percolateDown(data, i, wall);
   }
}

/*************************************************************************
* This function sorts a vector using a heap sort.
* Input:  data -  Vector to be sorted.
* Output: data -  Vector sorted
**************************************************************************/
template <class T>
void heapSort(vector<T> &data)
{
   // creating a wall at the end of the vector
   int wall = data.size() - 1;

   // putting our vector in a hypothetical tree
   heapify(data, wall);

   // begin the sort loop
   while (wall > 1)
   {
      swap(data[1], data[wall]);
      wall--;
      percolateDown(data, 1, wall);
   }
   cerr << "Leaving heapSort...\n";
}
