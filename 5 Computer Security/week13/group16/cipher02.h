/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

#include <map>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Parker Weech"; }
   virtual std::string getCipherName()  { return "Columnar Transposition"; }
   virtual std::string getEncryptAuth() { return "Adam Miller"; }
   virtual std::string getDecryptAuth() { return "Kevin Billings"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("Author_1: Malay B Pramanik \n Link_1: https://pdfs.semanticscholar.org/38d5/9f9bb68a4fc8f389cf71532db3cdd8b3001c.pdf \n Link_2: http://www.crypto-it.net/eng/simple/columnar-transposition.html?tab=0");
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
      str =  "\nENCRYPTION PSEUDOCODE:\n\nuser_input(keyword)\nmatrix_width = length(keyword)\nkey_num = make_sequence(keyword)\nuser_input(message)\nremove_spaces(message)\nmatrix_height = length(message)/matrix_width\nR = length(message) % matrix_width\nif(R != 0): matrix_height += 1\np_matrix = array[matrix_height][matrix_width]\ninput message into p_matrix\nalso input R number of extra char into p_matrix\nc_message = key_num(p_matrix)\n";

      // The decrypt pseudocode
      str += "\nDECRYPTION PSEUDOCODE:\n\nmatrix_width = length(keyword)\nkey_num = make_sequence(keyword)\nmatrix_height = length(c_message / matrix_width)\nR = length(c_message % matrix_width\nif(R != 0): matrix_height += 1\nc_matrix = array[matrix_height][matrix_width]\ninput c_message into c_matrix\np_message = key_num(c_matrix)\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText = plainText;
      // TODO - Add your code here

      // generate the key for the cipher
      std::map<int, int> key;
      for (int i = 0; i < password.length(); i++)
      {
         key[password[i]] = i;
      }

      int row, col, j;
      std::string cipherBuild = "";

      // create the size of the rows and columns
      col = password.length();
      row = plainText.length() / col;

      // ensure that there are enough rows to hold the cipher
      if (plainText.length() % col)
         row += 1;

      char matrix[row][col];

      // load the matrix with the appropriate values
      int k = 0;
      for (int i = 0; i < row; ++i)
      {
         int j = 0;
         while (j < col)
         {
            if (plainText[k] == '\0')
            {
               if (j < col)
                  matrix[i][j] = '_';
               j++;
               break;
            }
            
            if (isalpha(plainText[k]) || plainText[k] == ' ')
            {
               matrix[i][j] = plainText[k];
               j++;
            }

            k++;
         }
      }

      // use the key to create the cipher text from the matrix
      for (std::map<int, int>::iterator it = key.begin(); it != key.end(); it++)
      {
         j = it->second;

         for (int i = 0; i < row; i++)
         {
            if (isalpha(matrix[i][j]) || matrix[i][j] == ' ' || matrix[i][j] == '_')
            {
               cipherBuild += matrix[i][j];
            }
         }
      }

      // copy over completed cipher text
      cipherText = cipherBuild;

      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText = cipherText;
      // TODO - Add your code here

      // Make the key for the cipher
      std::map<int, int> key;
      for (int i = 0; i < password.length(); i++)
      {
         key[password[i]] = i;
      }
      
      // Create the matrix
      int column = password.length();
      int row = cipherText.length() / column;
      int r = cipherText.length() % column;

      if (r!=0)
      {
         row += 1;
      }
      
      char cipherMatrix[row][column];
      for (int j=0,k=0; j<column; j++)
      {
        for (int i=0; i<row; i++)
        {
           cipherMatrix[i][j] = cipherText[k++];
        }
      }
      
      // Fix the order
      int index = 0;
      for(std::map<int,int>::iterator  ii=key.begin(); ii!=key.end(); ++ii)
         ii->second = index++;

      char decrypt[row][column];
      std::map<int,int>::iterator ii=key.begin(); 
      int k = 0; 
      for (int l=0,j; password[l]!='\0'; k++) 
        { 
           j = key[key[l++]]; 
           for (int i=0; i<row; i++) 
           { 
            decrypt[i][k]=cipherMatrix[i][j]; 
           } 
        } 
  
    /* getting Message using matrix */
    plainText = ""; 
    for (int i=0; i<row; i++) 
    { 
        for(int j=0; j<column; j++) 
        { 
            if(decrypt[i][j] != '_') 
                plainText += decrypt[i][j]; 
        } 
    } 

      return plainText;
   }
};

#endif // CIPHER02_H
