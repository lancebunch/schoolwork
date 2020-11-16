/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER03_H
#define CIPHER03_H

#include <iostream>   // standard input and output
#include <string>     // for convenience
#include <cassert>    // because I am paraniod
#include <stdlib.h>   // for atoi 
#include "cipher.h"
using namespace std;

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Pseudocode Benjamin Jaffray"; }
   virtual std::string getCipherName()  { return "Beaufort Cipher"; }
   virtual std::string getEncryptAuth() { return "Encrypt Shawn Lilly"; }
   virtual std::string getDecryptAuth() { return "Decrypt Anthony Lasley"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("Brian J. Winkel (1978) CASANOVA AND THE BEAUFORT CIPHER, Cryptologia, 2:2, 161-163, DOI: 10.1080/0161-117891852947");
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std:: string str = "// This function generates the key, if it isn't the same length we repeat the key untill they are the same length \n"
                           "generateKey(input, key):\n"
                              "\tfixedKey = key\n\n"
                              "\tif len(input) > len(tfixedKey):\n"
                                 "\t\tfor(i = 0; len(fixedKey) != len(input); i++):\n"
                                       "\t\t\tfixedKey += tfixedKey[i % len(tfixedKey)]\n"
                              "\telse if len(input) < len(tfixedKey):\n"
                                 "\t\treturn fixedKey.substr(0, plainText.length())\n\n"
                              "\treturn fixedKey\n\n"
                              
                           "// This function returns the encrypted text generated, with the logic behind the tabula recta and Beaufort algorithm \n"
                           "cipherText(input, key): \n"
                              "\tcipher_text = \"\"\n"
                              "\tfixedKey = generateKey(input, key)\n\n"
                              "\tfor len of input: \n"
                                 "\t\tx = int(fixedKey[i]) - int(input[i])\n\n"
                                 "\t\tif x < 0:\n"
                                       "\t\t\tx += 127 //int('DEL')\n"
                                 "\t\telse:\n"
                                       "\t\t\tx += int(' ') //The Space char\n\n"
                                 "\t\tcipher_text += char(x)\n\n"
                              "\treturn cipher_text\n\n"

                           "// This function decrypts the encrypted text and returns the original text, with the logic behind the tabula recta and Beaufort algorithm \n"
                           "originalText(cipher_text, key): \n"
                              "\toriginal_text = \"\"\n"
                              "\tfixedKey = generateKey(input, key)\n\n"
                              "\tfor len of cipher_text: \n"
                                 "\t\tx = int(fixedKey[i]) - int(cipher_text[i]) \n\n"
                                 "\t\tif x < 0:\n"
                                       "\t\t\tx += 127 //int('DEL')\n"
                                 "\t\telse:\n"
                                       "\t\t\tx += int(' ') //The Space char\n\n"
                                 "\t\toriginal_text += char(x)\n\n"
                              "\treturn original_text\n";

      return str;
   }

   /**********************************************************
    * GENERATE_KEY
    * Sets up the password to be used by the encryption 
    * and decryption functions
    **********************************************************/
   string generateKey(const std::string & plainText, 
                      const std::string & password)
   {
      string fixedKey = password;

      // if plainText and password are the same length we are good
      if (plainText.length() > fixedKey.length())
      {
         for (int i = 0; fixedKey.length() != plainText.length(); i++)
         {
            fixedKey += fixedKey[i % fixedKey.length()];
         }
      }
      else if (plainText.length() < fixedKey.length())
      {
         return fixedKey.substr(0, plainText.length());
      }


      return fixedKey;
      
   }
   /**********************************************************
    * ENCRYPT
    * This function returns the encrypted text generated, with 
    * the logic behind the tabula recta and Beaufort algorithm
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      // set up variables
      string cipherText = "";
      // make password work with plainText
      string fixedKey = generateKey(plainText, password);

      for (int i = 0; i < plainText.length(); i++)
      {
         int x = int(fixedKey[i]) - int(plainText[i]);

         if (x < 0)
         {
            //int('DEL')
            x += 127;
         }
         else
         {
            //The Space char
            x += int(' '); 
         }

         cipherText += x;
      }
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * This function decrypts the encrypted text and returns the 
    * original text, with the logic behind the tabula recta and 
    * Beaufort algorithm 
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      string plainText = "";
      string fixedKey = generateKey(cipherText, password);
      int x;
      for (int i = 0; i < cipherText.size(); i++)
      {
         //subtract the ascii value of password from encoded text
         x = fixedKey[i] - cipherText[i]; 

         // if negative offset by adding 127
         if(x < 0)                        
            x += 127;
         // else add the offset of the space character
         else                             
            x += 32;
         
         // add to decrypted text character by character
         plainText += x;                  
         
      }
      // return decrypted text
      return plainText;                   
   }
};

#endif // CIPHER03_H
