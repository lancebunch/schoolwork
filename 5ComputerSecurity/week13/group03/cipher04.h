/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER04_H
#define CIPHER04_H
#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <string>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher04 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Alejandro Di Bartolomeo"; }
   virtual std::string getCipherName()  { return "Affine Cipher"; }
   virtual std::string getEncryptAuth() { return "Steven Anderson"; }
   virtual std::string getDecryptAuth() { return "Tyler Elkington"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "GeeksforGeeks,  ";
      s += "\"Affine Cipher\', \n  retrieved: ";
      s += "https://www.geeksforgeeks.org/implementation-affine-cipher/\n";

      s += "Rumkin.com ";
      s += "\"Affine Cipher generator tool, retrieved: ";
      s += "http://rumkin.com/tools/cipher/affine.php\n";

      return s;
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
      str += "encrypt(plainText, password)\n";
      str += "   num <- 0\n";  
      str += "   fixedKey <- 55\n";
      str += "   code <- (int)password[0]\n";    
      str += "   FOR i < cipherText.length\n"; 
      str += "      IF isupper(cipherText[i]\n";      
      str += "         num <- (fixedKey * ((int)cipherText[i] - 65))+code\n";   
      str += "         IF num > 25\n";  
      str += "            DO\n";
      str += "               num -= 26\n";  
      str += "            WHILE num > 25\n";  
      str += "         cipherCode += (char)(num + 65)\n";  
      str += "      IF islower(cipherText[i]\n";
      str += "         num <- (fixedKey * ((int)cipherText[i] - 97))+code\n";   
      str += "         IF num > 25\n";  
      str += "            DO\n";
      str += "               num -= 26\n";  
      str += "            WHILE num > 25\n";  
      str += "         cipherCode += (char)(num + 97)\n"; 
      str += "      ELSE\n";
      str += "         cipherCode += cipherText[i]\n"; 
      str += "   RETURN cipherCode\n\n"; 

      // The decrypt pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   num <- 0\n";  
      str += "   fixedKey <- 9\n";
      str += "   code <- (int)password[0]\n";    
      str += "   FOR i < plainText.length\n"; 
      str += "      IF isupper(plainText[i]\n";      
      str += "         num <- (fixedKey * ((int)plainText[i] - 65))-code\n";   
      str += "         IF num > 25\n";  
      str += "            DO\n";
      str += "               num -= 26\n";  
      str += "            WHILE num > 25\n";  
      str += "         decipheredCode += (char)(num + 65)\n";  
      str += "      IF islower(plainText[i]\n";
      str += "         num <- (fixedKey * ((int)plainText[i] - 97))-code\n";   
      str += "         IF num > 25\n";  
      str += "            DO\n";
      str += "               num -= 26\n";  
      str += "            WHILE num > 25\n"; 
      str += "         ELSE IF num < 0\n"; 
      str += "            DO\n";
      str += "               num += 26\n";  
      str += "            WHILE num < 0\n"; 
      str += "         decipheredCode += (char)(num + 97)\n"; 
      str += "      ELSE\n";
      str += "         decipheredCode += plainText[i]\n"; 
      str += "   RETURN decipheredCode\n\n"; 

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
      std::string cipherCode;           //Encrypted code
      int num = 0;                      //Placeholder variable to calculate encryption for each letter
      int fixedKey = 55;                //Must be a co-prime number with the length of the alphabet(26)
                                        //We'll leave this number fixed for the code to not get complicated
      int code = (int)password[0];
      
      for (int i = 0; i < cipherText.length(); i++)
      {
        if(isupper(cipherText[i]))
        {       
            num = ((fixedKey * ((int)cipherText[i] - 65)) + code);
            
            if(num > 25)
            {
              do
              {
                num -= 26;     
              }
              while (num > 25);
            }
            cipherCode += ((char)(num + 65));
        }
        else if(islower(cipherText[i]))
        {
            num = ((fixedKey * ((int)cipherText[i] - 97)) + code);
      
            if(num > 25)
            {
              do
              {
                num -= 26;     
              }
              while (num > 25);
            }
            cipherCode += ((char)(num + 97));
        }
        else
        {
          cipherCode += cipherText[i];
        }
      }
      return cipherCode;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText = cipherText;
      std::string decipheredCode;    //Decrypted code
      int fixedKey = 9;         //This is the modular multiplicative inverse of fixedKey "55" that
                                //we used to encrypt the plaintext in the encrypt function. Mod 26 was used
      int num = 0;              //Placeholder variable to calculate encryption for each letter
      
      int code = (int)password[0];
      
      for (int i = 0; i < plainText.length(); i++)
      {
          if(isupper(plainText[i]))
          {       
              num = fixedKey * (((int)plainText[i] - 65) - code);
              
              if(num > 25)
              {
                do
                {
                  num -= 26;     
                }
                while (num > 25);
              }
              else if(num < 0)
              {
                do
                {
                  num += 26;
                }
                while (num < 0);
              }
              decipheredCode += ((char)(num + 65));
          }
          else if(islower(plainText[i]))
          {
              num = fixedKey * (((int)plainText[i] - 97) - code);
      
              if(num > 25)
              {
                do
                {
                  num -= 26;     
                }
                while (num > 25);
              }
              else if(num < 0)
              {
                do
                {
                  num += 26;
                }
                while (num < 0);
              }
              decipheredCode += ((char)(num + 97));
          }
          else
          {
            decipheredCode += plainText[i];
          }
      }
      return decipheredCode;
   }
};

#endif // CIPHER04_H
