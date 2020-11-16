/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER03_H
#define CIPHER03_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Alex Bentley"; }
   virtual std::string getCipherName()  { return "Vigenere Cipher"; }
   virtual std::string getEncryptAuth() { return "Chase Haymond"; }
   virtual std::string getDecryptAuth() { return "Todd Anderson"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("Rick Neff - CS237");
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
      str =  "encrypt(plainText, password)\n";
      str += "\tcipherText = \"\"\n";
      str += "\tfor i in length(plainText)\n";
      str += "\t\tkeyIndex = i % length(password)\n";
      str += "\t\tplainNum = alphaToNum(plainText[i])\n";
      str += "\t\tkeyNum = alphaToNum(password[keyIndex])\n";
      str += "\t\tcipherNum = (plainNum + keyNum) % alphabetLength\n";
      str += "\t\tcipherText += numToAlpha(cipherNum)\n";
      str += "\treturn cipherText\n";

      // The decrypt pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "\tplainText = \"\"\n";
      str += "\tfor i in length(cipherText)\n";
      str += "\t\tkeyIndex = i % length(password)\n";
      str += "\t\tcipherNum = alphaToNum(cipherText[i])\n";
      str += "\t\tkeyNum = alphaToNum(password[keyIndex])\n";
      str += "\t\tplainNum = (cipherNum - keyNum) % alphabetLength\n";
      str += "\t\tplainText += numToAlpha(plainNum)\n";
      str += "\treturn plainText\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: This uses the password as a key to encrypt a message
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText;// = plainText;

      int alphabetLength = 26;

      for (int i = 0; i < plainText.length(); ++i)
      {
         int keyIndex = i % password.length();

         int plainNum =tolower(plainText[i]) - (int)'a';
         int keyNum = tolower(password[keyIndex]) - (int)'a';

         int cipherNum = ((plainNum + keyNum) % alphabetLength) + (int)'a';

         cipherText += (char)cipherNum;
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
       // Variables
      int keyIndex  = 0;
      int cipherNum = 0;
      int keyNum    = 0;
      int plainNum  = 0;
      int alphabetSize = 26;
      
      std::string p = password;
      std::string h = cipherText;
      std::string plainText;
      
      // Make password match or longer than cipherText
      do {p += p;}
      while (p.length() < cipherText.length());
      
      std::cout << "Pass: " << p << std::endl;
      
      // I Know the Math, Just Do It
      for (int i = 0; i < h.length(); i++)
      {
         keyIndex = i % p.length();
         cipherNum = (int)(h[i]);
         keyNum = (int)(p[keyIndex]);
         
         std::cout << "cipherNum = " << cipherNum << "  keyNum = " << keyNum << std::endl;
         plainNum = (cipherNum - keyNum + alphabetSize) % alphabetSize;

         plainText += (char)(plainNum) + 97;
      }
      
      return plainText;
   }
};

#endif // CIPHER03_H
