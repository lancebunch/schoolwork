/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H

#include <cctype>
#include <set>
#include <sstream>
#include <string>
#include<bits/stdc++.h>

using namespace std;

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Stephen Nielson"; }
   virtual std::string getCipherName()  { return "Keyword Cipher"; }
   virtual std::string getEncryptAuth() { return "Lina Nielsen"; }
   virtual std::string getDecryptAuth() { return "Jimmy Downer"; }

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
    * Takes in a plaintext and password values as parameters.
    * Populates the Lookup Table in order to create a cipher text.
    * Goes through each character in Plain Text and assigns
    * appropriate value from the Lookup Table.
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      // lookupTable = generateLookUpTableFromPassword(password)
      string lookupTable = generateLookupTableFromPassword(password);

      // set cipherText = \"\"
      string cipherText = "";

      // for each p in plainText
      for (const char * p = plainText.c_str(); *p; p++)
      {
         // if not isalpha(p)
         if (!isalpha(*p))

            // cipherText += p
            cipherText += *p;
         else
         {
            // index = toupper(p) - 'A'
            int index = toupper(*p) - 'A';

            // if islower(p)
            if (islower(*p))

               // cipherText += tolower(character in lookupTable
               //   at position index)
               cipherText += tolower(lookupTable[index]);
            
            else

               // cipherText += character in lookupTable at position
               //   index
               cipherText += lookupTable[index];
         }
      }

      // RETURN cipherText
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * Accepts cipher text and password as parameters.
    * Generates a lookup table from the password.
    * Iterates through the cipher text; if a given cipher character
    * is non-alphabetic, it's stored in the plain text and skipped;
    * otherwise, the index of the character is found in the lookup table.
    * The index is then added to 'A' or 'a' (depending on the case of the
    * cipher letter) and converted into a character and stored in the
    * plain text.
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      // plainText = ""
      std::ostringstream plainText;      
      // lookupTable = generateLookupTableFromPassword(password)
      std::string lookupTable = generateLookupTableFromPassword(password);
      // for p in cipherText
      for (unsigned int i = 0; i < cipherText.length(); i++)
      {
         char c = cipherText[i];
         
         // if not isalpha(p)
         if (!isalpha(c))
         {
            // plainText += p
            plainText << c;
         }
         // else
         else
         {
            // index = find index of uppercase(p) in lookupTable
            size_t index = lookupTable.find(toupper(c));
            // if islower(p)
            if (islower(c))
            {
               // plainText += 'a' + index
               plainText << (char)('a' + (int)index);
            }
            // else
            else
            {
               // plainText += 'A' + index
               plainText << (char)('A' + (int)index);
            }
         }
      }
      // return plainText
      return plainText.str();
   }

private:
   /**************************************************
    * REMOVE DUPLICATE LETTERS
    * Goes through each character in a given password
    * and removes duplicate letters
    *************************************************/
   virtual string removeDuplicateLetters(string password)
   {
      // duplicates = new set of characters
      set <char> duplicates;
      
      // deDupedPassword = \"\"
      string deDupedPassword = "";
      transform(password.begin(), password.end(), password.begin(), ::toupper);

      // for uppercase(p) in password
      for (std::string::const_iterator it = password.begin();
           it != password.end();
           ++it)
      {
         // if isalpha(p) and duplicates.count(p) is less than 1
         if (isalpha(*it) && duplicates.count(*it) < 1)
         {
            // insert p into duplicates
            duplicates.insert(*it);

            // deDupedPassword += p
            deDupedPassword += (*it);
         }
      }

      // return deDupedPassword
      return deDupedPassword;
   }

   /**************************************************
    * GENERATE LOOKUP TABLE FROM PASSWORD
    * Populates a Lookup Table based on a given password
    * after duplicate letters have been removed
    *************************************************/
   virtual string generateLookupTableFromPassword(string password)
   {
      // deDupedPassword = removeDuplicateLetters(password)
      string deDupedPassword = removeDuplicateLetters(password);
      string lookupTable = "";

      // lookupTable = deDupedPassword
      lookupTable += deDupedPassword;

      // for i from 0 to 25
      for (int i = 0; i < 26; i++)
      {
         // if find of 'A' + i in deDupedPassword is null position
         if (deDupedPassword.find('A' + i) == std::string::npos)

            // lookupTable += 'A' + i
            lookupTable += ('A' + i);
      }

      // return lookupTable
      return lookupTable;
   }
};

#endif // CIPHER01_H
