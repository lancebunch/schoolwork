/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER03_H
#define CIPHER03_H


#include <string>
using namespace std;
/********************************************************************
 * CLASS
 *******************************************************************/
const int a = 7; 
const int b = 10; 

class Cipher03 : public Cipher
{
public:
   virtual std::string getPseudoAuth() { return "Michael Wilkis"; }
   virtual std::string getCipherName() { return "Affine Author"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("Practical Cryptography, \"Affine Cipher\"[Online]Available: http://practicalcryptography.com/ciphers/classical-era/affine/");
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
      str += "   FOR (i = 0; i < cipherText.length; i++\n";
      str += "   cipherText = cipherText + (char) ((((a * (password[i] - 'A')) + b) % 26) + 'A')\n";
      str += "   RETURN cipherText\n\n"; 

      // The decrypt pseudocode
      str =  "decrypt(cipherText, password)\n";
      str += "   FOR (i = 0; i < cipherText.length; i++\n";
      str += "   plainText = plainText + char (((a * ((password[i]+ 'A' - b)) % 26)) + 'A')\n";
      str += "   plainText += (cipherText[i] - key[i]) % 26\n";
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
      std::string cipherText = plainText;
      //enter code here
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
      //enter code here
      return plainText;
   }
};

#endif // CIPHER03_H
