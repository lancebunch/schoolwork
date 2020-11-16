/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H
#include "cipher.h"
#include <string>

using namespace std;
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Anthony Lasley"; }
   virtual std::string getCipherName()  { return "AutoKey Cipher"; }
   virtual std::string getEncryptAuth() { return "Benj Jaffray"; }
   virtual std::string getDecryptAuth() { return "Shawn Lilly"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      //grabbed the formatting from example.h
      std::string s;
      s += "http://sappho.nku.edu/~christensen/ (2005, Chris Christen), ";
      s += "\"Extending Keys\", \n retrieved: 12/10/2019";
      s += "https://www.nku.edu/~christensen/1402extending%20keys.pdf \n";
      s += "new source \n";
      s += "practicalcryptography.com, \"Autokey Cipher\"";
      s += "\n retrieved: 12/10/2019";
      s += "http://practicalcryptography.com/ciphers/classical-era/autokey/";
      return s;
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      /*
         function getKey(password, plainText)
         {
            passCount = password.size()
            plainCount = plaintext.size()
			index = 0
            if passCount == plainCount
               return password
            if passCount < plainCount
               while (password.size() < plaintext.size())
                  
                  password += plaintext[index]
				  index++
               return password
            if  > plaintext.size()
               password.erase((passCount - 1), (plainCount - 1))
               return password
         }

         function encrypt(password, plainText)
         {
            password = getKey(password, plainText)
            encrypted
            int x
            for i in plainText.size()
               x = (plainText[i] + password[i]) % 95
               x += 32
               encrypted += x
            return encrypted
         }

         function decrypt(password, encrypted)
         {
            decrypted
            int x 
            for i in encrypted.size()
                  x = (encrypted[i] - password[i] + 95) % 95
                  x += 63
			      if(x > 126)
			         x = x % 95;
               if(key.size() < cipherText.size())
                  key += x;
               decrypted += x
            return decrypted
         }
      */


      str = "This function is how you convert the password into the key according to how auto key requires.\n\n"
      " function getKey(password, plainText)\n{\n passCount = password.size()\n"
		  " plainCount = plaintext.size()\n\n if passCount == plainCount\n\t return password\n"
		  " if passCount < plainCount\n\t while (password.size() < plaintext.size())\n\t\t passCount++\n"
		  "\t\t password += plaintext[passCount]\n\t\t return password\n if  > plaintext.size()\n\t "
		  "password.erase((passCount - 1), (plainCount - 1))\n\t return password\n}\n\n";

      str +=  "This function is how you encrypt your message according to auto keys encryption.\n\n"
      "function encrypt(password, plainText)\n{\n password = getKey(password, plainText)\n encrypted\n"
      " int x\n for i in plainText.size()\n\t x = (plainText[i] + password[i]) % 95\n"
      "\t x += 32\n\t encrypted += x\n return encrypted\n }\n\n";

      str += "This function is how you decrypt your message.\nyou also decrypt your key while decrypting the message.\n\n"
      "function decrypt(password, encrypted)\n {\n decrypted\n int x\n for i in encrypted.size()\n\t x = (encrypted[i] - password[i] + 95) % 95\n"
		  "\t x += 63\n\t if(x > 126)\n\t\t x = x % 95\n\tif(key.size() < cipherText.size())\n\t\t key += x;\n\t decrypted += x\n return decrypted\n }\n";

      return str;
   }

   /**********************************************************
    * GET_KEY
    * Sets up the password to be used by the encryption 
    * and decryption functions
    **********************************************************/
   string getKey(const std::string & plainText, const std::string & password)
   {
      // Copy the information
      string pswd = password;

      // If password is greater, truncate password to be same length
      if (password.size() > plainText.size())
         return pswd = password.substr((password.size() - 1), (plainText.size() - 1));
      // If password is smaller, concatinate the plainText
      else if (password.size() < plainText.size())
         for(int i = 0; (pswd.size() < plainText.size()); i++)
            pswd += plainText[i];

      // Returns the password copy that we have edited
      return pswd;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText, 
                               const std::string & password)
   {
      // Sets up the variables
      string cipherText;
      int x = 0;

      // Gets fixed key
      string pswd = getKey(plainText, password);

      // Runs though the string (char array) and encrypts the letters

      for (int i = 0; i < plainText.size(); i++)
      {
         x = (plainText[i] + pswd[i]) % 95;
         x += 32;
         cipherText += x;
      }

      // Returns the Cipher Text
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText, 
                               const std::string & password)
   {
      // variables for holding plain text and 
      string plainText;
      string key = password;
      int x = 0;
      
      // Go though the string and decrypt the letter
      for (int i = 0; i < cipherText.size(); i++)
      {
         x = (cipherText[i] - key[i] + 95) % 95;
         x += 63;
         if(x > 126)
            x = x % 95;
         if(key.size() < cipherText.size())
            key += x;
         plainText += x;
      }

      // Returns the plainText Text
      return plainText;
   }
};

#endif // CIPHER01_H