/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

#include <cctype>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual std::string getPseudoAuth() { return "Cameron Johnson"; }
   virtual std::string getCipherName() { return "Beaufort Cipher"; }
   virtual std::string getEncryptAuth() { return "Hans Peterson"; }
   virtual std::string getDecryptAuth() { return "Avery Reed"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "PracticalCryptography.com (2012), ";
      s += "\"Classical Era - Beaufort Cipher\", \n   retrieved: ";
      s += "\n  http://practicalcryptography.com/ciphers/classical-era/beaufort/";
      s += "beaufort-cipher";
      return s;
   }

   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;
      // The encryptCase pseudocode
      str = "encrypt(plainText, password)\n";
      str += "   offset <- offsetFromPassword(password)\n";
      str += "   i <- 0\n";
      str += "   FOR p is all values of plainText\n";
      str += "      index <- (offset[i] - indexFromCharacter(*p)) % size\n";
      str += "      cipherText += characterFromIndex(index)\n";
      str += "      i += 1\n";
      str += "   RETURN cipherText\n\n";

      // The decryptCase pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   offset <- offsetFromPassword(password)\n";
      str += "   i <- 0\n";
      str += "   FOR p is all values of cipherText\n";
      str += "      offsetI <- size - offset[i]\n";
      str += "      index <- (offsetI - indexFromCharacter(*p)) % size\n";
      str += "      plainText += characterFromIndex(index)\n";
      str += "      i += 1\n";
      str += "   RETURN plainText\n\n";

      // helper routine
      str += "offsetFromPassword(password)\n";
      str += "   i <- 0\n";
      str += "   FOR p is all values of password\n";
      str += "      offset[i] <- indexFromCharacter(p)\n";
      str += "      i += 1\n";
      str += "   RETURN offset\n\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string &plainText,
                               const std::string &password)
   {
     std::string cipherText = "";
     std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
     
     for (int i = 0; i < plainText.size(); i++) {
       char c0 = plainText[i];
       char c1 = password[i % password.size()];
       
       int start = 0;
       
       for (int j = 0; j < 26; j++) {
         if (alphabet[j] == toupper(c0)) {
           start = j;
           break;
         }
       }
       
       int offset = 0;
       
       for (int j = start; j < start + 26; j++) {
         int letter = j % 26;
         
         if (alphabet[letter] == toupper(c1)) {
           break;
         }
         
         offset++;
       }
       
       //std::cout << "Offset: " << offset << "\n";
       cipherText += alphabet[offset];
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
        std::string plainText = "";
        std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
     for (int i = 0; i < cipherText.size(); i++) {
       char offSet0 = cipherText[i];
       char offSet1 = password[i % password.size()];
       int start = 0;
       for (int j = 0; j < 26; j++) {
         if (alphabet[j] == toupper(offSet0)) {
           start = j;
           break;
         }
       }
       int offset = 0;
       for (int j = start; j < start + 26; j++) {
         int letter = j % 26;
         if (alphabet[letter] == toupper(offSet1)) {
           break;
         }
         offset++;
       }
       plainText += alphabet[offset];
     }

        return plainText;
   }
};

#endif // CIPHER02_H
