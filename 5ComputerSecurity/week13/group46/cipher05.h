/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER05_H
#define CIPHER05_H
#include <map>
using namespace std;
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher05 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Marius Corca"; }
   virtual std::string getCipherName()  { return "Column Trnsposition"; }
   virtual std::string getEncryptAuth() { return "Josh Hellewell"; }
   virtual std::string getDecryptAuth() { return "Gage Mikos"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("Mary B. Pramanik, Implementation of Cryptography Technique using Columnar Transposition, Jan 2014, Onine [Available] https://pdfs.semanticscholar.org/38d5/9f9bb68a4fc8f389cf71532db3cdd8b3001c.pdf");
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
      str =  "encode (plainText, password)\n";
      str += " map<int, int> keyMap\n";
      	// put permutation order into map
      str += "	FOR i in password.length()\n";
      str += "		keyMap[password[i]] <- i\n";
      str += "	row <- 0\n";
      str += "	col <- 0\n";
      str += " j <- 0\n";

      	// calculate matrix size
      str += "	col <- password.length()\n";
      str += "	row <- plainText.length() / col\n";

      str += "	IF plainText % col != 0\n";
      str += "		row <- row + 1\n";

      str += "	char matrix[row][col]\n";

      str += "	k <- 0\n";
      str += "	FOR every i in row\n";
      str += "		FOR  every j in col\n";
      str += "			IF plainText[k] == '\0'\n";
      str += "				matrix[i][j] <- '_' \n";
      str += "			matrix[i][j] <- plainText[k]\n";
      str += "			j <- j + 1\n";
      str += "			k <- k + 1\n";

      str += "	FOR every map iterator it in keyMap\n";
      str += "		j <- it->second\n";
      str += "		FOR every i in row\n";
      str += "			cipherText <- matrix[i][j]\n";

      str += "	return cipherText\n";

      // The decrypt pseudocode
      str += "decrypt (cipherText, password)\n";

      	// find out row and column from matrix
      str += "	col <- password.length()\n";
      str += "	row <- cipherTet.length() / col\n";

      str += "	char cipherMatrix[row][col]\n";

      str += "	index <- 0\n";
      	// update order of key
      str += "	FOR every map iterator it in map\n";
      str += "		index <- index + 1\n";
      str += "		it->second <- index\n";

      	// copy the matrix column wise into new matrix
      str += "	char decipherMatrix[row][col]\n";
      str += "	iterator it for keyMap <- keyMap.begin()\n";
      str += "	k <- 0\n";
      str += "	FOR l <- 0, j; password[l] != '\0'; k++\n";
      str += "		j <- keyMap[password[l++]]; \n";
      str += "		FOR every i in row\n";
      str += "			decipherMatrix[i][k] <- cipherMatrix[i][j]\n";

      	// putting message into plainText
      str += "	FOR every i in row\n";
      str += "		FOR every j in col\n";
      str += "			IF decipherMatrix[i][j] != '_'\n";
      str += "				plainText <- plainText + decipherMatrix[i][j]\n";

      str += "	return plainText\n";
      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText = "";
      // TODO - Add your code here
      
      map<int, int> keyMap;
      for (int i = 0; i < password.length(); i++)
         keyMap[password[i]] = i;
      int j = 0;
      
      int col = password.length();
      int row = plainText.length()/col;
      if (plainText.length() % col)
         row++;
       char matrix[row][col];
       int k = 0;
       for (int i = 0; i < row; i++)
          for (j = 0; j < col;)
          {
             if (plainText[k] == '\0')
             {
                matrix[i][j] = '_';
                j++;
             }
             if (isalpha(plainText[k]) || plainText[k]==' ')
              {
                 matrix[i][j] = plainText[k];
                 j++;
              }
             k++;
          }
       for (map<int,int>::iterator it = keyMap.begin(); it != keyMap.end(); it++)
       {
          j = it->second;
          for (int i = 0; i < row; i++)
             if (isalpha(matrix[i][j]) || matrix[i][j]==' ' ||
                 matrix[i][j]=='_')
                cipherText += matrix[i][j];
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
      std::string plainText = ""; // = cipherText;
      
      map<int, int> keyMap;
      
      int col = password.length();
      int row = cipherText.length();
      
      char cipherMatrix[row][col];
      int index = 0;
      
      for (map<int,int>::iterator it = keyMap.begin(); it != keyMap.end(); it++)
      {
          index++;
          it->second = index;
      }
      
      char decipherMatrix[row][col];
      map<int,int>::iterator it = keyMap.begin();
      int k = 0;
      
      // can not initialize two variable in a loop but can achieve the same result by limiting scope with {}
      {
          int j;
          for (int l = 0; password[l] != '\0'; k++)
          {
              j = keyMap[password[l++]];
              for (int i = 0; i < row; i++)
              {
                  decipherMatrix[i][k] = cipherMatrix[i][j];
              }
          }
      }
      
      for (int i = 0; i < row; i++)
      {
         for (int j = 0; j < col; j++)
         {
             if (decipherMatrix[i][j] != '_')
                 plainText += decipherMatrix[i][j];
         }
      }
      
      return plainText;
   }
};

#endif // CIPHER05_H
