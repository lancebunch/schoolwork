/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

#include <math.h>

using namespace std;
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Landon Campbell"; }
   virtual std::string getCipherName()  { return "Hill Cipher"; }
   virtual std::string getEncryptAuth() { return "Cody Martison"; }
   virtual std::string getDecryptAuth() { return "Sam Haynes"; }

   
   
   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("Hill, Lester S. 1929. https://web.archive.org/web/20110719235517/http://w08.middlebury.edu/INTD1065A/Lectures/Hill%20Cipher%20Folder/Hill1.pdf");
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
      str =  "Encryption:  Convert plaintext and the password into seperate matrices. Multipy the matrices and mod 26 each value.\n";
      str += "The plaintext length must be a multiple of the length of the password.\n";

      // The decrypt pseudocode
      str += "Decryption: Convert the password back into a matrix. Then take the inverse of the matrix.";
      str += "Convert the cipher text into a matrix and multiple it with the inverse matrix of the password.";
      str += "Finally take the mod 26 of each value and convert back to letters.\n";

      return str;
   }

    
  
   /**********************************************************
    * ENCRYPT
    * Encrypts the text using matrices.
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      
      int length = plainText.length();
      int width = (password.length() / length);
      int passwordMatrix[width][length];
      
      
      int letterCount = 0;

      for (int i = 0; i < width; i++)
      {
         for (int j = 0; j < length; j++)
         {
            passwordMatrix[i][j] = (password[letterCount]) % 65;
            letterCount++;
            
         }
      }
      

       

      int plaintextMatrix[width][1];
      int cipherMatrix[width][1];

      
      for (int i = 0; i < width; i++)
      {
         plaintextMatrix[i][0] = (plainText[i]) % 65;
         
      }

      std::string cipherText;
      for (int i = 0; i < width; i++)
      {
         for (int j = 0; j < 1; j++)
         {
            cipherMatrix[i][j] = 0;

            for (int k = 0; k < width; k++)
            {
               cipherMatrix[i][j] += passwordMatrix[i][k] * plaintextMatrix[k][j];
            }

            cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
         }
      }

      
      

      // convert matrix to text
      for (int i = 0; i < width; i++)
      {
         cipherText += (char)(cipherMatrix[i][0] + 65);
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
      
      
      int length = cipherText.length();
      int width = (password.length() / length);
      
      float inverseMatrix[width][length];

      float plaintextMatrix[width][1];
      float cipherMatrix[width][1];
      float passwordMatrix[width][length];

      int letterCount = 0;
      

      for (int i = 0; i < width; i++)
      {
         for (int j = 0; j < length; j++)
         {
            passwordMatrix[i][j] = (password[letterCount]) % 65;
            
            letterCount++;
         }
      }
      

      float tempMatrix[length][width];
      float temp1;
      float temp2;

      
      for (int i = 0; i < length; i++)
      {
         for (int j = 0; j < width; j++)
         {
            if (i == j)
            {
               tempMatrix[i][j] = 1;
            }
            else
            {
               tempMatrix[i][j] = 0;
            }
         }
      }

      

      for (int k = 0; k < width; k++)
      {
         for (int i = 0; i < width; i++)
         {
            temp1 = passwordMatrix[i][k];
            temp2 = passwordMatrix[k][k];

            for (int j = 0; j < length; j++)
            {
               if (i != k)
               {
                  passwordMatrix[i][j] = passwordMatrix[i][j] * temp2 - temp1 * passwordMatrix[k][j];
                  tempMatrix[i][j] = tempMatrix[i][j] * temp2 - temp1 * tempMatrix[k][j];

               }
            }
         }
      }

      
      for (int i = 0; i < width; i++)
      {
         for (int j = 0; j < length; j++)
         {
            inverseMatrix[i][j] = tempMatrix[i][j] / passwordMatrix[i][i];
            
         }
      }
      

      for (int i = 0; i < width; i++)
      {
         for (int j = 0; j < 1; j++)
         {
            for (int k = 0; k < length; k++)
            {
               plaintextMatrix[i][j] = plaintextMatrix[i][j] + inverseMatrix[i][k] *  cipherMatrix[k][j];
            }
         }
      }

      
      std::string plainText;

      for (int i = 0; i < width; i++)
      {
         for (int j = 0; j < 1; j++)
         {
            plainText += (char)(fmod(plaintextMatrix[i][0], 26) + 65);
         }
      }

      
      return plainText;
   }


   
};

#endif // CIPHER02_H
