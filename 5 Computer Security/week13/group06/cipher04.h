/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER04_H
#define CIPHER04_H

#include <map>
#include <vector>
#include <string>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher04 : public Cipher
{
public:
   virtual std::string getPseudoAuth() { return "Joseph Burgess"; }
   virtual std::string getCipherName() { return "Columnar Transposition"; }
   virtual std::string getEncryptAuth() { return "Dave Purdon"; }
   virtual std::string getDecryptAuth() { return "Zach Zendejas"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("\"Columnar Transposition Cipher.\" GeeksforGeeks, 30 Aug. 2019, https://www.geeksforgeeks.org/columnar-transposition-cipher/n");
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
      str = "encryptMessage(plainText, password)\n";
      str += "   map <int, int> keymap\n";
      str += "   setPermutationOrder(&keymap, password)\n";
      str += "   Cipher = null \n";
      str += "   Setup matrix:\n";
      str += "   Number of columns = password length\n";
      str += "   Number of rows = plainText length/col\n";
      str += "   If there is a reminder of plaintext / col\n";
      str += "      row += 1 for left over plain text \n";
      str += "   charMatrix[number of rows][number of columns]\n";
      str += "      for i each row in matrix and k for each plainTextChar\n";
      str += "         for j each column\n";
      str += "            if plaintext[k] == ‘\\0’ this is a padding character\n";
      str += "               matrix[i][j] = ‘_’\n";
      str += "               j++\n";
      str += "            if plaintext is alpha OR plaintext[k] is a space\n";
      str += "               matix[i][j] = plainText[k]\n";
      str += "               j++\n";
      str += "         k++ discard anything else and move onto next plainTextChar\n";
      str += "         make cipher:\n";
      str += "         for key for all elements in keymap inorder\n";
      str += "            j = key\n";
      str += "            for i as each row in matrix\n";
      str += "               if matrix[i][j] is alpha OR matrix[i][j] is space\n";
      str += "                  cipher += matrix[i][j]\n";
      str += "   return cipher \n\n";

      // The decrypt pseudocode
      str += "decryptMessage(cipherText, password)\n";
      str += "   map <int, int> keymap\n";
      str += "   setPermutationOrder(keymap, password)\n";
      str += "   col = key length\n";
      str += "   row = cipher length/number of columns\n";
      str += "   char cipherMatrix[row][col]\n";
      str += "   for j as each column and k as each element in cipher\n";
      str += "      for i as each row\n";
      str += "         cipherMatrix[i][j] = cipher[k++]\n";
      str += "   update the order of key for decryption\n";
      str += "   int index = 0\n";
      str += "   for i as each element in keymap";
      str += "   : read key map in alpha order and assign the order to the variable \n";
      str += "      i = index++\n";
      str += "   Arrange the matrix column wise according";
      str += "   to permutation order by adding into new matrix\n";
      str += "   char orderCipher[row][col]\n";
      str += "   legnth = 0\n";
      str += "   orderCipherColumn = 0\n";
      str += "   for key[legnth] != ‘\\0’\n";
      str += "      CipherColumn = keyMap[key[legnth++]]\n";
      str += "      rowIndex = 0\n";
      str += "      for rowIndex < row\n";
      str += "         orderCipher[rowIndex][orderCipherColumn] = cipherMatrix[rowIndex][cipherColumn]\n";
      str += "         rowIndex++\n";
      str += "         orderCipherColumn++\n";
      str += "   msg = null\n";
      str += "   for r for each row\n";
      str += "      for c for each col\n";
      str += "         if orderCipher[r][c] != '_'\n";
      str += "            plainText += oderCipher[i][j]\n";
      str += "   return plainText\n\n";

      //Helper routine
      str += "setPermutationOrder(keymap, key)\n";
      str += "   Add the permutation order into a map\n";
      str += "   For index < key length\n";
      str += "      keyMap[key[index]] = index \n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string &plainText,
                               const std::string &password)
   {
      std::string cipherText = plainText;
      // TODO - Add your code here
      std::map<int, int> keyMap;
      for (int i = 0; i < password.length(); i++)
      {
         keyMap[password[i]] = i;
      }

      int j;
      cipherText = "";
      int col = password.length();
      int row = plainText.length() / col;

      if (plainText.length() % col)
      {
         row += 1;
      }
      std::vector<std::vector<char>> matrix(row, std::vector<char>(col));

      for (int i = 0, k = 0; i < row; i++)
      {
         for (int j = 0; j < col;)
         {
            if (plainText[k] == '\0')
            {
               matrix[i][j] = '_';
               j++;
            }

            if (isalpha(plainText[k]) || plainText[k] == ' ')
            {
               matrix[i][j] = plainText[k];
               j++;
            }
            k++;
         }
      }

      for (std::map<int, int>::iterator ii = keyMap.begin(); ii != keyMap.end(); ++ii)
      {
         j = ii->second;
         for (int i = 0; i < row; i++)
         {
            if (isalpha(matrix[i][j]) || matrix[i][j] == ' ' || matrix[i][j] == '_')
            {
               cipherText += matrix[i][j];
            }
         }
      }

      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string &cipherText,
                               const std::string &password)
   {
      std::string plainText = cipherText;
      // TODO - Add your code here
      std::map <int, int> keyMap;
      int col = password.length();

      // calc row and column for cipher matrix
      int row = cipherText.length()/col;
      char cipherMat[row][col];

      // add character into matrix
      for(int j = 0, k = 0; j < col; j++)
         for (int i = 0; i < row; i++)
            cipherMat[i][j] = cipherText[k++];

      // update the order of the key decryption
      int index = 0;
      for ( std::map<int, int>::iterator ii=keyMap.begin(); ii!=keyMap.end(); ++ii)
         ii ->second = index++;

      // arrange the matrix column wise according to permutation
      char decCipher[row][col];
      std::map <int, int>::iterator ii = keyMap.begin();
      int k = 0;

      for (int l = 0, j; password[l] != '\0'; k++)
      {
         j = keyMap[password[l++]];
         for (int i = 0; i < row; i++)
         {
            decCipher[i][k] = cipherMat[i][j];
         }
      }

      // get the message using the matrix
      for (int i = 0; i < row; i++)
      {
         for (int j = 0; j < col; j++)
         {
            if(decCipher[i][j] != '_')
               plainText += decCipher[i][j];
         }
      }
      return plainText;
   }
};

#endif // CIPHER04_H
