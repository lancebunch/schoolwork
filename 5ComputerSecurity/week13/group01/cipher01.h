/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H

#include <set>
#include <cctype>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Stephen Nielson"; }
   virtual std::string getCipherName()  { return "Keyword Cipher"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "GeeksforGeeks.com (2019), ";
      s += "\"Keyword Cipher\', \n   retrieved: ";
      s += "https://www.geeksforgeeks.org/keyword-cipher/";
      s += "\nCipher was adapted to support LC characters for round-trip encrypt/decrypt";
      return s;
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
      str +=  "   lookupTable = generateLookUpTableFromPassword(password)\n";
      str +=  "   set cipherText = \"\"\n";
      str +=  "   for each p in plainText\n";
      str +=  "      if not isalpha(p)\n";
      str +=  "         cipherText += p\n";
      str +=  "      else\n";
      str +=  "         index = toupper(p) - 'A'\n";
      str +=  "         if islower(p)\n";
      str +=  "            cipherText += tolower(character in lookupTable at position index)\n";
      str +=  "         else\n";
      str +=  "            cipherText += character in lookupTable at position index\n";
      str +=  "    RETURN cipherText\n\n";

      // The decryptCase pseudocode
      str +=  "decrypt(cipherText, password)\n";
      str +=  "   plainText = \"\"\n";
      str +=  "   lookupTable = generateLookupTableFromPassword(password)\n";
      str +=  "   for p in cipherText\n";
      str +=  "      if not isalpha(p)\n";
      str +=  "         plainText += p\n";
      str +=  "      else\n";
      str +=  "         index = find index of uppercase(p) in lookupTable\n";
      str +=  "         if islower(p)\n";
      str +=  "            plainText += 'a' + index\n";
      str +=  "         else\n";
      str +=  "            plainText += 'A' + index\n";
      str +=  "return plainText\n\n";

      // helper routine
      str +=  "generateLookupTableFromPassword(password)\n";
      str +=  "   deDupedPassword = removeDuplicateLetters(password);\n";
      str +=  "   lookupTable = deDupedPassword\n";
      str +=  "   for i from 0 to 25\n";
      str +=  "      if find of 'A' + i in deDupedPassword is null position \n";
      str +=  "         lookupTable += 'A' + i \n";
      str +=  "return lookupTable\n\n";

      // helper routine
      str +=  "removeDuplicateLetters(password)\n";
      str +=  "   duplicates = new set of characters\n";
      str +=  "   deDupedPassword = \"\"\n";
      str +=  "   for uppercase(p) in password\n";
      str +=  "      if isalpha(p) and duplicates.count(p) is less than 1\n";
      str +=  "         insert p into duplicates\n";
      str +=  "         deDupedPassword += p\n";
      str +=  "   return deDupedPassword\n";
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

#endif // CIPHER01_H
