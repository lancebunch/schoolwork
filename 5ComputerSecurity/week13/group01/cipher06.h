/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER06_H
#define CIPHER06_H
using namespace std;
#include <string>
#include <bits/stdc++.h>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher06
{
public:
   virtual std::string getPseudoAuth()  { return "Boone Mcintosh"; }
   virtual std::string getCipherName()  { return "XOR Cipher"; }
   virtual std::string getEncryptAuth() { return "Boone Mcintosh"; }
   virtual std::string getDecryptAuth() { return "Boone Mcintosh"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual string getCipherCitation()
   {
    string s = "XOR Cipher. Wikipedia, Wikimedia";
    s += "Foundation, 30 Nov. 2019, https://en.wikipedia.org/wiki/XOR_cipher\n";
    s += "XOR Cipher. GeeksforGeeks, 15 Aug. 2019,";
    s += "https://www.geeksforgeeks.org/xor-cipher/.\n";
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
      str =  "encryptDecrypt(char inpString[])\n";
      str += "{\n   set char xorKey <- a random letter\n";
      str += "   set int len <- the length of inpString[]\n";
      str += "   for each letter in inpString[]\n";
     str += "      raise the value of the letter to the power of the xorKey\n";
      str+= "      print the value of each letter after the XOR function.\n"; 

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * The XOR cipher encryption works by implementing the binary XOR function
    * on each of the letters in the plainText against the key 
    * and returning a new binary value for each letter.
    **********************************************************/
   virtual std::string encrypt(char plainText[],
                               char password)
   {
      // TODO - Add your code here
      int len = strlen(plainText);
      for (int i = 0; i < len; i++)
      {
         plainText[i] = plainText[i] ^ password;
         printf("%c", plainText[i]);
      }
      std::string cipherText = plainText;
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * The XOR cipher decryption works the exact same way as the encryption.
    * The XOR function is performed on each of the letters in the
    * cipherText against the key provided and a new letter is created
    * in binary to return the plainText.
    **********************************************************/
   virtual std::string decrypt(char cipherText[],
                               char password)
   {
      // TODO - Add your code here
      int len = strlen(cipherText);
      for (int i = 0; i < len; i++)
      {
         cipherText[i] = cipherText[i] ^ password;
         printf("%c", cipherText[i]);
      }
      std::string plainText = cipherText;

      return plainText;
   }
};

#endif // CIPHER06_H
