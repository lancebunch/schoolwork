/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER03_H
#define CIPHER03_H

#include <vector>
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03 : public Cipher
{
public:
   virtual std::string getPseudoAuth() { return "Justin Hurst"; }
   virtual std::string getCipherName() { return "Rail Fence Cipher"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "Dave Purdon"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("https://www.101computing.net/the-rail-fence-cipher/");
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
      str += "plaintext = inputtext\n";
      str += "plaintext = UPPERCASE(plaintext)\n";
      str += "plaintext = REPLACE(plaintext, " ", "")\n";
      str += "ciphertext = ""\n";
      str += "for i from 0 to plaintext.length - 1\n";
      str += "  ciphertext = ciphertext + plaintext[i]\n";
      str += "  for i from 1 to plaintext.length - 1\n";
      str += "    ciphertext = ciphertext + plaintext[i]\n";
      str += "output ciphertext\n\n";

      // The decrypt pseudocode
      str += "ciphertext = inputtext\n";
      str += "ciphertext = UPPERCASE(ciphertext)\n";
      str += "ciphertext = REPLACE(ciphertext, " ", "")\n";
      str += "if ciphertext.lenght mod 2 != 0 then\n";
      str += "  ciphertext = ciphertext + " "\n";
      str += "midpoint = ciphertext.length / 2\n";
      str += "plaintext = ""\n";
      str += "for i from 0 to midpoint - 1\n";
      str += "  plaintext = plaintext + ciphertext[i] + ciphertext[i+midpoint]\n";
      str += "output plaintext\n";

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
      cipherText = "";
      int rows = password.length();
      int cols = plainText.length();

      std::vector<std::vector<char>> rail(rows, std::vector<char>(cols));
      for (int i = 0; i < rows; i++)
      {
         for (int j = 0; j < cols; j++)
         {
            rail[i][j] = '\n';
         }
      }
      bool dir_down = false;
      int row = 0, col = 0;

      for (int i = 0; i < cols; i++)
      {
         if (row == 0 || row == rows - 1)
         {
            dir_down = !dir_down;
         }
         rail[row][col++] = plainText[i];
         dir_down ? row++ : row--;
      }

      for (int i = 0; i < rows; i++)
      {
         for (int j = 0; j < cols; j++)
         {
            if (rail[i][j] != '\n')
            {
               cipherText.push_back(rail[i][j]);
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
      plainText = "";
      int rows = password.length();
      int cols = cipherText.length();

      std::vector<std::vector<char>> fence(rows, std::vector<char>(cols));
      for (int i = 0; i < rows; i++)
      {
         for (int j = 0; j < cols; j++)
         {
            fence[i][j] = '\n';
         }
      }
      bool dir_down;
      int row = 0, col = 0;
      for (int i = 0; i < cols; i++)
      {
         if (row == 0)
         {
            dir_down = true;
         }
         if (row == rows - 1)
         {
            dir_down = false;
         }
         fence[row][col++] = '*';
         dir_down ? row++ : row--;
      }

      int index = 0;
      for (int i = 0; i < rows; i++)
      {
         for (int j = 0; j < cols; j++)
         {
            if (fence[i][j] == '*' && index < cols)
            {
               fence[i][j] = cipherText[index++];
            }
         }
      }
      row = 0, col = 0;
      for (int i = 0; i < cols; i++)
      {
         if (row == 0)
         {
            dir_down = true;
         }
         if (row == rows - 1)
         {
            dir_down = false;
         }
         if (fence[row][col] != '*')
         {
            plainText.push_back(fence[row][col++]);
         }
         dir_down ? row++ : row--;
      }
      return plainText;
   }
};

#endif // CIPHER03_H
