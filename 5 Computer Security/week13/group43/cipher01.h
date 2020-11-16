/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H

#include <iostream>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "pseudocode Dylan Doelling"; }
   virtual std::string getCipherName()  { return "Vigenere Cipher"; }
   virtual std::string getEncryptAuth() { return "Hyde"; }
   virtual std::string getDecryptAuth() { return "Caleb Hensley"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string strCitation;
      strCitation = "URL: http://inventwithpython.com/hacking/chapter19.html\n";
      strCitation += "Author: Al Sweigart\n";
      strCitation += "Title of Book: Cracking Codes with Python: An Introduction to Building and Breaking Ciphers\n";
      strCitation += "Title of Chapter: THE VIGENERE CIPHER\n";
      strCitation += "Date of Publication: 2018\n";

      return strCitation;   
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // get final password pseudocode (makes sure password is correct length)
      str =   "string getFinalPassword(plainText, password)\n";
      str +=  "//Password should be as long as the plainText, if it is not repeat the password until it is\n";
      str +=  "\tif (password.length() == plainText.length())\n";
      str +=  "\t\treturn finalPassword\n";  
      str +=  "\telse if (password.length() < plainText.length())\n";
      str +=  "\t\tfor(int i = 0; i < (plainText.lenth() - password.length()); i++)\n";
      str +=  "\t\t//make password a string and keep appending the next letter of the password until it equals the length of the plainText\n";
      str +=  "\t\t\tfinalPassword += (password[i % length of password])\n";
      str +=  "\t\treturn finalPassword\n";
      str +=  "\telse if (password.length() > plainText.length())\n";
      str +=  "\t\t//take substring of password until it equals the length of plainText\n";
      str +=  "\t\tfinalPassword = password.substr(0, plainText.length())\n";
      str +=  "\treturn finalPassword\n";

      // The encrypt pseudocode
      //adds the ascii values of the letters of the password and plainText then mod by 95 then add by 32
      str +=  "Encrypt\n";
      str +=  "//Formula: Ci = Ek(Mi) = (Plain text ascii value + password ascii value) mod 95\n";
      str +=  "//it is mod 95 because ascii value we use is upto 95\n";
      str +=  "encryptFunction(plainText, finalPassword)\n";
      str +=  "\tfor(int i = 0; i < plainText.length(); i++)\n";
      str +=  "\t\t//converting the letters to ascii values to do calculations, +32 for space character\n";
      str +=  "\t\tint cipherNumericValue = ((int(plainText[i]) + int(finalPassword[i])) % 95) + 32\n";
      str +=  "\t\t//need to convert back to the ascii values to the actual alphabet\n";
      str +=  "\t\tstring cipherText += (char)cipherNumericValue\n";
      str +=  "\treturn cipherText\n";

      // The decrypt pseudocode
      //subtracts the ascii values of the letters of the password and cipherText then add by 95 then mod by 95 then add 63
      str += "Decrypt\n";
      str += "//Formula: Mi = Dk(Ci) = (Cipher text ascii value - password ascii value + 95) mod 95\n";
      str +=  "decrypt(cipherText, finalPassword)\n";
      str +=  "\tfor (int i = 0; i < cipherText.length(); i++)\n";
      str +=  "\t\t//converting the letters to ascii values to do calculations\n";
      str +=  "\t\tint decryptNumericValue = ((int(cipherText[i]) - int(finalPassword[i]) + 95) % 95) + 63\n";
      str +=  "\t\tif(decryptNumeric > 126)\n\t\t\tdecryptNumeric = decryptNumeric % 95 \n";
      str +=  "\t\t//need to convert back to the ascii values to the actual alphabet\n";
      str +=  "\t\tstring plainText += (char)decruptNumeric\n";
      str +=  "\treturn plainText\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText, 
                               const std::string & password)
   {
      std::string finalPassword = getFinalPassword(plainText, password);
      std::string cipherText = encryptFunction(plainText, finalPassword);
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
      
      // Get the key to encrypt
      std::string key = getFinalPassword(plainText, password);

      // Get the plainText from the cipherText  
      plainText = decryptFunction(cipherText, key);

      return plainText;
   }
private:
   /**************************************************
   * GETFINALPASSWORD
   * Checks the length of the password, add when too short, cut when too long
   ************************************************/
   std::string getFinalPassword(std::string plainText, std::string password)
   {
      int diff = plainText.length() - password.length();
      std::string finalPassword = password;
      if (password.length() == plainText.length())
      {
         return password;
      }
      else if (password.length() < plainText.length())
      {
        for (int i = 0; i < diff; i++)
         {
            finalPassword += password[i % password.length()];
         }
         return finalPassword;
      }
      else // if (password.length() > plainText.length())
      { 
         finalPassword = password.substr(0, plainText.size());
         return finalPassword;
      }
   }

   /**************************************************
   * ENCRYPTFUNCTION
   * returns the encrypted text from given plaintext and password
   *************************************************/
   std::string encryptFunction(std::string plainText, std::string finalPassword)
   {
      std::string cipherText;
      for (int i = 0; i < plainText.length(); i++)
      {
         int cipherNumericValue =
            (((int(plainText[i]) - 32) +
            (int(finalPassword[i])) - 32) % 95) + 32;
          cipherText += (char)cipherNumericValue;
      }
      return cipherText;
   }

   /**************************************************
   * DECRYPT FUNCTION
   * returns the decrypted text from given cipherText and password
   *************************************************/
   std::string decryptFunction(std::string cipherText, std::string key)
   {
      std::string plainText;
    
      // Subtracts the key from the cipherText to get the plainText
      for (int i = 0; i < cipherText.length(); i++)
      {
         // Convert the cipher and key characters to ints and subtract them,
         // 'reverse modding' their difference to be within 0 -> 95
         int cipherNumericValue =
            (((int)(cipherText[i]) - 32) - ((int)(key[i]) - 32));
         if (cipherNumericValue < 0)
            cipherNumericValue = 95 + cipherNumericValue;

         // Return the character back to the char value it needs to be
         // (alphabetic characters, numbers, and special characters)
         cipherNumericValue += 32;
         plainText += (char)cipherNumericValue;
      }
   
      return plainText;
   }

};

#endif // CIPHER01_H
