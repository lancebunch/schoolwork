/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER04_H
#define CIPHER04_H

#include <map>


/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher04 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Thomas Rosales"; }
   virtual std::string getCipherName()  { return "ROT13 Cipher"; }
   virtual std::string getEncryptAuth() { return "Peter Flickinger"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string source = "https://www.geeksforgeeks.org/rot13-cipher/\n";
      return std::string(source);
   }

   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // Pseudocode for creating the dictionaries used in the encrypt and decypt functions
      str += "map <char,int> dict1\n";
      str += "map <char,int> dict2\n";
      str += "for (int i = 1; i < 27; i++)\n";
      str += "   dict1[char(64 + i)] = i\n";
      str += "dict2[0] = 'Z'\n";
      str += "for (int i = 1; i < 26; i++)\n";
      str += "   dict2[i] = char(64 + i)\n";

      // The encryptCase pseudocode
      str =  "encrypt(plainText, password)\n";
      str += "string cipher = ""\n";
      str += "int shift = 13\n";
      str += "for int i = 0; i < plainText.size(); i++)\n";
      str += "   if (plainText[i] == ' ')\n";
      str += "      int num = (dict1[plainText[i] + shift) % 26\n";
      str += "      cipher += dict2[num]\n";
      str += "   else\n";
      str += "      cipher += " "";
      str += "RETURN cipher\n\n";

      // The decryptCase pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "string decipher = ""\n";
      str += "int shift = 13\n";
      str += "for int i = 0; i < plainText.size(); i++)\n";
      str += "   if (plainText[i] == ' ')\n";
      str += "      int num = (dict1[plainText[i] - shift + 26) % 26\n";
      str += "      decipher += dict2[num]\n";
      str += "   else\n";
      str += "      cipher += " "";
      str += "   RETURN decipher\n\n";

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

      std::map <char,int> dict1;
      std::map <int,char> dict2;
      for (int i = 1; i < 27; i++)
         dict1[char(64 + i)] = i;
      dict2[0] = 'Z';
      for (int i = 1; i < 26; i++)
         dict2[i] = char(64 + i);

      // The encryptCase pseudocode
      int shift = 13;
      for (int i = 0; i < plainText.size(); i++){
         if (plainText[i] != ' '){
            int num = (dict1[toupper(plainText[i])] + shift) % 26; 
            cipherText += dict2[num];
         }
         else {
            cipherText += " ";
         }
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
      std::string plainText = cipherText;
      // TODO - Add your code here
      return plainText;
   }
};

#endif // CIPHER04_H
