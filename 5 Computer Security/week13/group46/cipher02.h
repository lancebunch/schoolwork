/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

#include <iostream>   // standard input and output
#include <string>     // for convenience
#include <cassert>    // because I am paraniod
#include <stdlib.h>   // for atoi 
#include "cipher.h"

using namespace std;
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual string getPseudoAuth()  { return "Pseudocode Shawn Lilly"; }
   virtual string getCipherName()  { return "Running Key Cipher"; } 
   virtual string getEncryptAuth() { return "Encrypt Benj Jaffray"; } 
   virtual string getDecryptAuth() { return "Decrypt Anthony Lasley"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual string getCipherCitation()
   {
      string s;
      s += "Sravana Reddy, Kevin Knight, Decoding Running Key Ciphers, 2016, https://www.aclweb.org/anthology/P12-2016.pdf \n";
      s += "Randy Nichols LANAKI, CLASSICAL CRYPTOGRAPHY COURSE,  1996, https://www.cryptogram.org/downloads/LANAKI%20Crypto%20Lessons/LESSON15.pdf page 11";
      s += "https://www.cryptogram.org/downloads/aca.info/ciphers/RunningKey.pdf \n";

      return s;
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual string getPseudocode()
   {
      string str;

      // rotatePassword
      str = "This function shuffles the password around so it doesn't repeat\n";
      str += "rotatePassword(password)\n";
      str += "{\n";
      str += "    passwordChar = \"\"\n";
      str += "    passwordCopy = \"\"\n";
      str += "\n";
      str += "    passwordChar = password\n";
      str += "    passwordCopy = password\n";
      str += "\n";
      str += "    for (int i = 0; i <= passwordCopy.length - 1; i++)\n";
      str += "       passwordCopy[i] = passwordCopy[i + 1]\n";
      str += "       if (i == passwordCopy.length - 1)\n";
      str += "          passwordCopy[passwordCopy.length - 1] = passwordChar[0]\n";
      str += "\n";
      str += "    return passwordCopy\n";
      str += "}\n\n";

      // The get key
      str += "This function gets the key\n";
      str += "getKey(plainText, password)\n";
      str += "{\n";
      str += "   passwordCount = password.length\n";
      str += "   plainTextCount = plainText.length\n";
      str += "\n";
      str += "   if (passwordCount == plainTextCount)\n";
      str += "      return password\n";
      str += "\n";
      str += "   key = password\n";
      str += "   message = plainText\n";
      str += "\n";
      str += "   if (passwordCount < plainTextCount)\n";
      str += "      while (passwordCount < plainTextCount)\n";
      str += "      key += rotatePassword(key)\n";
      str += "      passwordCount += passwordCount\n";
      str += "\n";
      str += "   if (passwordCount > plainTextCount)\n";
      str += "      key.erase((plainTextCount), (passwordCount - 1))\n";
      str += "\n";
      str += "   return key\n";
      str += "}\n\n";

      // The encrypt pseudocode
      str += "This function encrypts\n";
      str += "encrypt(plainText, password)\n";
      str += "{\n";
      str += "    cipherText;\n";
      str += "    key = getKey(password, plainText);\n";
      str += "    convert = 0;\n";
      str += "    for (size_t i = 0; i < plainText.length; i++)\n";
      str += "\n";
      str += "       convert = (plainText[i] + password[i]) % 95 + 32\n";
      str += "       cipherText += convert\n";
      str += "    return cipherText\n";
      str += "}\n\n";

      // The decrypt pseudocode
      str += "This function decrypts\n";
      str += "decrypt(cipherText, password)\n";
      str += "{\n";
      str += "   plainText = \"\"\n";
      str += "   psw = getKey(cipherText, password)\n";
      str += "\n";
      str += "   for (int i = 0; i < cipherText.length; i++)\n";
      str += "      convert = (cipherText[i] - password[i] + 95) %95 + 63\n";
      str += "      if(convert > 126)\n";
      str += "        convert %= 95\n";
      str += "      plainText += convert\n";
      str += "\n";
      str += "   return plainText;\n";
      str += "}\n\n";

      return str;
   }

   /***************************************************
   * ROTATEPASSWORD
   * This function shuffles the pasword so it doesn't
   * just repeat
   ***************************************************/
   string rotatePassword(const string & password)
   {
      // set up the variables
      string passwordChar = "";
      string passwordCopy= "";
      // passwordChar is for holding the first char of password
      passwordChar = password;
      passwordCopy = password;
      // loop through password and move the characters one 
      // forward and wrap the first one to the back
      for (int i = 0; i <= passwordCopy.length() - 1; i++)
      {
         passwordCopy[i] = passwordCopy[i + 1];
         if (i == passwordCopy.length() - 1)
         {
            passwordCopy[passwordCopy.length() - 1] = passwordChar[0];
         }
      }

      //return the rotated password
      return passwordCopy;
   }
   /***************************************************
   * GETKEY
   * this function makes the key
   ***************************************************/
   string getKey(const string & plainText, const string & password)
   {
      // Sets the size variables
      int passwordCount = password.size();
      int plainTextCount = plainText.size();

      // If they are the length return password
      if (passwordCount == plainTextCount)
      {
         return password;
      }

      string key = password;
      string message = plainText;
      // If password is bigger then rotate the password
      // this is what makes Running Key Cipher unique
      if (passwordCount < plainTextCount)
      {

         while (passwordCount < plainTextCount)
         {
            key += rotatePassword(key);
            passwordCount += passwordCount;
         }
      }

      // if assword is smaller then trim it down
      if (passwordCount > plainTextCount)
      {
         key.erase((plainTextCount), (passwordCount - 1));
      }

      // this is just a check if things go wrong
      if (passwordCount != plainTextCount)
      {
         assert("pasword and text not same\n");
      }
      return key;

   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual string encrypt(const string & plainText,
                          const string & password)
   {
      string cipherText;
      // get the key from the password
      string key = getKey(plainText, password);
      int convert = 0;
      // loop through each char in the string and encrypt it
      for (size_t i = 0; i < plainText.length(); i++)
      {
         // encrypt each char
         convert = (plainText[i] + key[i]) % 95 + 32;
         // add char to encrypted text
         cipherText += convert;
      }
      // return encrypted text. 
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual string decrypt(const string & cipherText,
                          const string & password)
   {
      // Variable stuff
      string plainText = "";
      string psw = getKey(cipherText, password);

      // Run though the cipherText and do the decrypt math
      for (int i = 0; i < cipherText.size(); i++) 
      {
         int convert = (cipherText[i] - psw[i] + 95) %95 + 63;

         // Math check if we are going out of bounds
         if(convert > 126)
            convert %= 95;

         plainText += convert;
      }

      return plainText;
   }
};

#endif // CIPHER02_H
