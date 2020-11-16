/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER07_H
#define CIPHER07_H

#include <cctype>
#include <sstream>
#include <string>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher07 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Mitch Patterson"; }
   virtual std::string getCipherName()  { return "Beaufort Cipher"; }
   virtual std::string getEncryptAuth() { return "James Downer"; }
   virtual std::string getDecryptAuth() { return "Jonathan Smith"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string str;
      
      str += "http://practicalcryptography.com/ciphers/beaufort-cipher/";
      
      return str;
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;
      
      // The encrypt pseudocode
      str =  "encrypt(plainText, password)\n";
      str += "FOR plainText length\n";
      str += "    IF password[current letter mod length of password] is a character\n";
      str += "       plainText[current letter] make upper case\n";
      str += "       password[current letter mod length of password] is a character\n";
      str += "          make upper case\n";
      str += "       cipherText[current letter] = (password[current letter mod length of password] + 26 - cipherText[current letter]) % 26 + 'A'\n\n";
      str += "return cipherText\n";
      
      // The decrypt pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "FOR cipherText length\n";
      str += "    IF password[current letter mod length of password] is a character\n";
      str += "       cipherText[current letter] make upper case\n";
      str += "       password[current letter mod length of password] is a character\n";
      str += "          make upper case\n";
      str += "       plainText[current letter] = (password[current letter mod length of password] + 26 - plainText[current letter]) % 26 + 'A'\n\n";
      str += "return plainText\n";
      
      return str;
   }

   /**********************************************************
    * ENCRYPT
    * Accepts plain text and a password as parameters.
    * Iterates through the plain text, converting the corresponding
    * plain text and password characters into offset values relative
    * to the least and greatest ASCII characters (' ' and '~', 
    * respectively). The plain text value is subtracted from the
    * key value, modded by the length of the alphabet, and coverted
    * into an ASCII character by adding the new value to the least
    * ASCII character. The character is then added to the cipher text.
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::ostringstream cipherText;
      
      for (unsigned int i = 0; i < plainText.length(); i++)
      {
         int p = (int)(plainText[i] - LEASTASCIICHAR);
         int k = (int)(password[i % password.length()] - LEASTASCIICHAR);
         
         int c = (k - p) % SIZEALPHABET;
         if (c < 0)
            c += SIZEALPHABET;
         
         cipherText << (char)(c + LEASTASCIICHAR);
      }
      
      return cipherText.str();
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::ostringstream plainText;
      
      for (unsigned int i = 0; i < cipherText.length(); ++i)
      {
         int c = (int)(cipherText[i] - LEASTASCIICHAR);
         int k = (int)(password[i % password.length()] - LEASTASCIICHAR);
         int p = (k - c) % SIZEALPHABET;
         if (p < 0)
            p += SIZEALPHABET;
         
         plainText << (char)(p + LEASTASCIICHAR);
      }

      return plainText.str();
   }

private:
   const char LEASTASCIICHAR = ' ';
   const char GREATESTASCIICHAR = '~';
   const int SIZEALPHABET = GREATESTASCIICHAR - LEASTASCIICHAR + 1;
};

#endif // CIPHER07_H
