/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H

#include <iostream>
#include <string>
using namespace std;

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Cody Martinson"; }
   virtual std::string getCipherName()  { return "Rail Fence Cipher"; }
   virtual std::string getEncryptAuth() { return "Sam Haynes"; }
   virtual std::string getDecryptAuth() { return "Landon Campbell"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("“Crypto,” Practical Cryptography. [Online]. Available: http://practicalcryptography.com/ciphers/rail-fence-cipher/. [Accessed: 14-Dec-2019].");
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
      str =  "Excryption\n";
      str += "Hash the password to create a key for the rail system\n";
      str += "using a char array iterate through the text and differetiate spaces\n";
      str += "change directions of the text\n";
      str += "create the cipher text from the new text\n";

      // The decrypt pseudocode
      str += "insert the decryption pseudocode\n";
      str += "Hash the password to create a key for the rail system\n";
      str += "using a char array iterate through the text and differetiate spaces\n";
      str += "mark the new spaces in the char array with an astric to create rows and columns of text\n";
      str += "create the plain text by fidning places that aren't an astric\n";
      str += "create the text by reading the 2D array in a zig zag pattern.";

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

      int key = 5;
      hash<string> passHash;
      key = passHash(password) % key;

      char rail[key][cipherText.length()];
      for(int i = 0; i < key; i++)
      {
         for(int j = 0; j < cipherText.length(); j++)
            rail[i][j] = '\n';
      }

      bool isDown = false;
      int row = 0;
      int column = 0;

      for(int i = 0; i < cipherText.length(); i++)
      {
         if(row == 0 || row == key-1)
         {
            isDown = !isDown;
         }
         rail[row][column++] = cipherText[i];

         isDown?row++ : row--;
      }

      string result;
      for(int i = 0; i < key; i++)
      {
         for(int j = 0; j < cipherText.length(); j++)
         {
            if(rail[i][j] != '\n')
               result.push_back(rail[i][j]);
         }
      }
      cipherText = result;
      
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
      int key = 5;
      hash<string> passHash;
      key = passHash(password) % key;

      char rail[key][plainText.length()];

      for(int i = 0; i < key; i++)
      {
         for(int j = 0; j < plainText.length(); j++)
            rail[i][j] = '\n';
      }
      bool isDown;
      int row = 0;
      int column = 0;

      for(int i = 0; i < plainText.length(); i++)
      {
         if(row == 0)
            isDown = true;
         if(row == key - 1)
            isDown = false;
         
         rail[row][column ++] = '*';

         isDown? row++ : row--;
      }

      int index = 0;
      for(int i = 0; i < key; i++)
      {
         for(int j = 0; j < plainText.length(); j++)
         {
            if(rail[i][j] == '*' && index < plainText.length())
               rail[i][j] = plainText[index++];
         }
      }

      string result;
      row = 0;
      column = 0;
      for(int i = 0; i < plainText.length(); i++)
      {
         if(row == 0)
            isDown = true;
         if(row == key-1)
            isDown = false;
         
         if(rail[row][column] != '*')
            result.push_back(rail[row][column++]);
         
         isDown? row++ : row--;
      }

      plainText = result;
      return plainText;
   }
};

#endif // CIPHER01_H
