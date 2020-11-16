/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER08_H
#define CIPHER08_H

#include <vector>
#include <string>
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03 : public Cipher
{
public:
   virtual std::string getPseudoAuth() { return "Ian Stubbs"; }
   virtual std::string getCipherName() { return "Columnar Transportation Cipher"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
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
      str += "  key = getPassphrase(plainText, password)\n";
      str += "  FOR i is less than Row\n";
      str += "   FOR j is less than Column";
      str += "    cipherText[i][j] is plainText[i]";
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
