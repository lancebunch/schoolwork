/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

#include <vector>
#include <string>

using namespace std;
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual std::string getPseudoAuth() { return "Ian Stubbs"; }
   virtual std::string getCipherName() { return "Columnar Transportation Cipher"; }
   virtual std::string getEncryptAuth() { return "Michael Wilkins"; }
   virtual std::string getDecryptAuth() { return " "; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("http://practicalcryptography.com/ciphers/classical-era/columnar-transposition/");
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
      str =  "encrypt(plainText, password)\n";
      str += "  COL = password Length\n";
      str += "  ROW = plainText / COL\n";
      str += "  array[ROW][COL]\n";
      str += "  FOR i is less than Row\n";
      str += "   FOR j is less than Column\n";
      str += "    array[i][j] is plainText[i]\n";
      str += "  FOR j less than Alphabatised COL\n";
      str += "   FOR i less than ROW\n";
      str += "    cipherText = array[COL][ROW]\n";
      str += "  RETURN cipherText\n\n"; 

      // The decrypt pseudocode
      str =  "decrypt(cipherText, password)\n";
      str += "  COL = password length";
      str += "  ROW = cipherText length";
      str += "  FOR i is less than Row\n";
      str += "   FOR j is less than Column";
      str += "    plainText[i] is cipherText[i][j]";
      str += "  RETURN plainText\n\n"; 
      

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string &plainText,
                               const std::string &password)
   {
      string cipherText = plainText;

      int col = password.length();
      
      // We add length to plaintext so tha values are being divided.
      int c = plainText.length() / col;

      int row = c;

      char array[row][col];

      for (int i = 0; i < row; i++)
      {
         for (int j = 0; j < col; j++)
         {
            array[i][j] = plainText[i];
         }   
      }
      
      for (int j = 0; j < col; j++)
      {
         for (int i = 0; i < row; i++)
         {
            cipherText = array[col][row];
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
      
      return plainText;
   }
};

#endif // CIPHER03_H
