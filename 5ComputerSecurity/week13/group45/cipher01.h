/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H

#include <cstring>
#include <iostream>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Claire Hocker"; }
   virtual std::string getCipherName()  { return "One-time Pad Cipher"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "Greg De Ligne"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
	  std::string link = "https://s3.amazonaws.com/academia.edu.documents/50361613/H18060205458.pdf?response-content-disposition=inline%3B%20filename%3DSMS_Encryption_Using_One-Time_Pad_Cipher.pdf&X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAIWOWYYGZ2Y53UL3A%2F20191214%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20191214T170356Z&X-Amz-Expires=3600&X-Amz-SignedHeaders=host&X-Amz-Signature=c66458650672445189648b7197f7b76f254226374f3631e2d66c04249236cd12";
      return std::string("Iqbal, Muhammad & Pane, Muhammad & Siahaan, Andysah Putera Utama. (2016). \nSMS Encryption Using One-Time Pad Cipher. \nIOSR Journal of Computer Engineering (IOSR-JCE). 18. 2278-661. 10.9790/0661-18060205458.");
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
      str +=  "ENCRYPTION PSEUDOCODE\n\n";
	  str += "\tSET plainText = INPUT\n";
	  str += "\tSET password = INPUT\n";
	  str += "\tSET key = password\n";
	  str += "\tIF plainTextSize > keySize\n";
	  str += "\t\tTHEN \n";
	  str += "\t\t\tWHILE plainTextSize > keySize\n";
	  str += "\t\t\t\tADD key to key\n";
	  str += "\t\t\tENDWHILE\n\n";
	  str += "\tENDIF\n";
	  str += "\tSET cipherText = ''\n";
	  str += "\tFOR all the characters in plaintext\n";
	  str += "\t\tSET ciperTextChar = plainTextChar XOR keyChar\n";
	  str += "\tRETURN cipherText\n\n\n";



      // The decrypt pseudocode
	  str += "DECRYPTION PSEUDOCODE\n\n";
	  str += "\tSET cipherText = INPUT\n";
	  str += "\tSET password = INPUT\n";
	  str += "\tSET key = password\n";
	  str += "\tIF cipherTextSize > keySize\n";
	  str += "\t\tTHEN \n";
	  str += "\t\t\tWHILE cipherTextSize > keySize\n";
	  str += "\t\t\t\tADD key to key\n";
	  str += "\t\t\tENDWHILE\n\n";
	  str += "\tENDIF\n";
	  str += "\tSET plainText = ''\n";
	  str += "\tFOR all the characters in cipherText\n";
	  str += "\t\tSET plainTextChar = cipherTextChar XOR keyChar\n";
	  str += "\tRETURN plainText\n\n\n";
      return str;

   }

   /**********************************************************
    * ENCRYPT
    * Augments all letters of the plainText with the key to
    * generate the cipher.
    * Greg De Ligne: No one claimed the encryption function
    * so I had to create it for the decryption to work. My original
    * encryption implementation is in cipher02.h.
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText, 
                               const std::string & password)
   {
      std::string cipherText;
      // TODO - Add your code here
      int sizePlain = plainText.length();
      
      /* Copy string to a c_string. This was necessary for our compiler. */
      char plain[sizePlain + 1];
      strcpy(plain, plainText.c_str());
      
      char key[sizePlain + 1];
      
      /* Repeating the password over the size of plainText */
      for (int i = 0; i < sizePlain; i++)
         key[i] = password[i % password.length()];
      
      /* XOR the two letters to create a cipher */
      for (int i = 0; i < sizePlain; i++)
         cipherText += (char)((plain[i] ^ key[i]) + 33);

      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * Reduces all letters of the cipher with the key to
    * restitute the original message.
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText, 
                               const std::string & password)
   {
      std::string plainText;
      // TODO - Add your code here
      int sizeCipher = cipherText.length();
      
      /* Copy string to a c_string. This was necessary for our compiler. */
      char cipher[sizeCipher + 1];
      strcpy(cipher, cipherText.c_str());
      
      char key[sizeCipher + 1];
      
      /* Repeating the password over the size of plainText */
      for (int i = 0; i < sizeCipher; i++)
         key[i] = password[i % password.length()];
      
      /* XOR the two letters to return the letter */
      for (int i = 0; i < sizeCipher; i++)
         plainText += (char)((cipher[i] - 33) ^ key[i]);
      
      return plainText;
   }
};

#endif // CIPHER01_H
