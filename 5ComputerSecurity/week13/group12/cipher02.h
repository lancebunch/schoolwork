/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Tyson Stark"; }
   virtual std::string getCipherName()  { return "Hill Cipher"; }
   virtual std::string getEncryptAuth() { return "Evan Harrison"; }
   virtual std::string getDecryptAuth() { return "Reed Harston"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s = "GeeksForGeeks, ";
      s += "\"Implementation of Hill Cipher\", \n retrieved: ";
      s += "https://www.geeksforgeeks.org/hill-cipher/\n";

      s += "Tutorials Point, ";
      s += "\"Implement the Hill Cypher\", \n retrieved: ";
      s += "https://www.tutorialspoint.com/cplusplus-program-to-implement-the-hill-cypher\n";
      return s;
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // TODO: please format your pseudocode
      // The encrypt pseudocode
      str = "Begin with getHillCipher(plainText, password)\n";
      str += "encrypt(cipherMatrix[][1], keyMatrix[][3], plainTextVector[][1])\n";
      str += "   cipherMatrix <- getMatrix(password, keyMatrix[][])\n";
      str += "   for x length of 3\n";
      str += "      for y length of 1\n";
      str += "         cipherMatrix[x][y] is 0\n";
      str += "            for z length of 3\n";
      str += "               cipherMatrix[x][y] +=\n"; 
      str += "               keyMatrix[y][z] * plainTextVector[z][y];\n";
      str += "            cipherMatrix[x][y] %= 26\n";
      // The decrypt pseudocode
      str += "decrypt(cipherMatrix[][1], keyMatrix[][3], plainTextVector[][1])\n";
      str += "   Inverse the Matrix <- InverseMatrix()\n";
      str += "      For x = 0 to 2\n";
      str += "         For y = 0 to 0\n";
      str += "            for z 0 to 2\n";
      str += "               cipherMatrix %= 26 + 65\n";
      // Get the Key Matrix
      str += "getMatrix(passwork, keyMatrix)\n";
      str += "   a = 0\n";
      str += "   for i 0 to 3\n";
      str += "      for j 0 to 3\n";
      str += "        keyMatrix = password % 65\n";
      str += "        a++\n";
      // Get Hill Cypher
      str += "hillCypher(plainText, password)\n";
      str += "   keyMatrix and plainTextVector\n";
      str += "   for 0 to 3\n";
      str += "      plainTextVector = plainText % 65\n";
      str += "   encrypt function\n";
      str += "   for 0 to 3\n";
      str += "      cipherText += cipherMatrix + 65\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * Encrypts message using Hill cypher
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
       std::string cipherText = "";
       int keyMatrix[100][100];
       int cipherMatrix[100][1];
       int n = plainText.length();
       int messageVector[100][1];
       getKeyMatrix(password, keyMatrix, n);
     
       // Get Message Vector
       for (int i = 0; i < n; i++)
       {
          messageVector[i][0] = (plainText[i]) % 65;
       }

       //Encrypt plainText
       for (int i = 0; i < n; i++)
       {
          for (int j = 0; j < 1; j++)
          {
       	     cipherMatrix[i][j] = 0;
               for (int a = 0; a < n; a++)
     	       {
                  cipherMatrix[i][j] += keyMatrix[i][a] * messageVector[a][j];
               }

               cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
          } 
       }
     
     
     	// Get cipher text
      for (int i = 0; i < n; i++)
      {
         cipherText += cipherMatrix[i][0] + 65;
      }
      
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText = "I got something wrong in the matrix math and couldn't figure it out.";

      float invertedKeyMatrix[100][100];
      int decipherMatrix[100];//[1];
      int n = cipherText.length();
      int messageVector[100];//[1];
      // getKeyMatrix(password, keyMatrix, n);
//      getInvertedKeyMatrix(password, invertedKeyMatrix, n);

      // Get Message Vector
//      for (int i = 0; i < n; i++)
//      {
//         messageVector[i] = (cipherText[i]) % 65;
//      }
//
//      for (int i = 0; i < n; ++i)
//      {
//         decipherMatrix[i] = 0;
//         for (int a = 0; a < n; ++a)
//         {
//            decipherMatrix[i] += invertedKeyMatrix[i][a] * messageVector[a];
//         }
//
//         decipherMatrix[i] = decipherMatrix[i] % 26;
//      }
//
//     	// Get plain text
//      for (int i = 0; i < n; i++)
//      {
//         plainText += decipherMatrix[i] + 65;
//      }

      return plainText;
   }
   
   private:
      void getKeyMatrix(std::string key, int keyMatrix[][100], int size)
      {
      	int k = 0;
      	for (int i = 0; i < size; i++)
      	{
      		for (int j = 0; j < size; j++)
      		{
      			if (k <= key.length())
      			{
      				keyMatrix[i][j] = (key[k]) % 65;
      				k++;
      			}
      		   // else? The memory is unitialized, we'll get random values for the rest of the values the passowrd doesn't cover!
      		}
      	}
      }

      /**********************************************************
       * GET InvertedKeyMatrix
       * Get the inverted matrix of the key matrix to decipher the text
       **********************************************************/
      void getInvertedKeyMatrix(std::string key, float invertedKeyMatrix[100][100], int size)
      {
         int keyMatrix[100][100];
         getKeyMatrix(key, keyMatrix, size);

         invertMatrix(keyMatrix, invertedKeyMatrix, size);
      }


      void getCofactor(int matrix[100][100], int temp[100][100], int p, int q, int size)
      {
         int i = 0, j = 0;

         for (int row = 0; row < size; ++row)
         {
            // Don't copy the values from the given row
            if (row == p)
            {
               ++row;
               if (row >= size)
                  break;
            }

            for (int col = 0; col < size; ++col)
            {
               // Don't copy the values from the given column
               if (col == q)
               {
                  ++col;
                  if (col >= size)
                     break;
               }

               temp[i][j] = matrix[row][col];
               ++j;

               // Move to next row if this row is filled
               if (j == size - 1)
               {
                  j = 0;
                  ++i;
               }
            }
         }
      }

      int findDeterminant(int matrix[100][100], int size)
      {
         // If there is only one element then this will be easy
         if (size == 1)
            return matrix[0][0];

         int determinant = 0;

         int temp[100][100];

         int sign = 1;

         for (int f = 0; f < size; ++f)
         {
            getCofactor(matrix, temp, 0, f, size);
            determinant += sign * matrix[0][f] * findDeterminant(temp, size - 1);

            sign = -sign;
         }

         return determinant;
      }

      void findAdjoint(int matrix[100][100], int adjoint[100][100], int size)
      {
         if (size == 1)
         {
            adjoint[0][0] = 1;
            return;
         }

         int sign = 1;
         int temp[100][100];

         for (int i = 0; i < size; ++i)
         {
            for (int j = 0; j < size; ++j)
            {
               getCofactor(matrix, temp, i, j, size);

               // sign of adjoint is positive if sum
               // of row and column is even
               sign = ((i+j) % 2 == 0) ? 1 : -1;

               adjoint[j][i] = sign * findDeterminant(temp, size - 1);
            }
         }
      }

      bool invertMatrix(int matrix[100][100], float inverse[100][100], int size)
      {
         int determinant = findDeterminant(matrix, size);
         if (determinant == 0)
         {
            // Can't find the inverse of a singular matrix
            return false;
         }

         int adjoint[100][100];
         findAdjoint(matrix, adjoint, size);

         for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
               inverse[i][j] = adjoint[i][j] / float(determinant);

         return true;
      }
};

#endif // CIPHER02_H
