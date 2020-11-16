/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER05_H
#define CIPHER05_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher05 : public Cipher
{
public:
   Cipher05() {
      leastAsciiChar = ' ';
      greatestAsciiChar = '~';
      sizeAlphabet = greatestAsciiChar - leastAsciiChar + 1;
   }
   virtual std::string getPseudoAuth()  { return "James Downer"; }
   virtual std::string getCipherName()  { return "Vigenère Cipher"; }
   virtual std::string getEncryptAuth() { return "Jonathan Smith"; }
   virtual std::string getDecryptAuth() { return "Stephen Nielson"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string str;
      
      str  = "A. Khanduri, ";
      str += "\"Vigenère Cipher,\" GeeksForGeeks.com. ";
      str += "[Online]. Available: ";
      str += "https://www.geeksforgeeks.org/vigenere-cipher/.\n\n";
      
      return str;
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;
      
      // Constants
      str  = "leastAsciiChar = ' '\n";
      str += "greatestAsciiChar = '~'\n";
      str += "sizeAlphabet = greatestAsciiChar - leastAsciiChar + 1\n";

      // The encrypt pseudocode
      str += "encrypt(plainText, password)\n";
      str += "    cipherText = new string\n";
      str += "    len(password)\n";
      str += "    for index = 0 to (length of plainText - 1)\n";
      str += "       value1 = charToAlphaOffset(plainText[index])\n";
      str += "       value2 = charToAlphaOffset(password[index % len])\n";
      str += "       value3 = modulo((value1 + value2), sizeAlphabet)\n";
      str += "       cipherText += alphaOffsetToChar(value3)\n";
      str += "    return cipherText\n\n";

      // The decrypt pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "    plainText = new string\n";
      str += "    len(password)\n";
      str += "    for index = 0 to (length of cipherText - 1)\n";
      str += "       value1 = charToAlphaOffset(cipherText[index])\n";
      str += "       value2 = charToAlphaOffset(password[index % len])\n";
      str += "       value3 = modulo((value1 - value2), sizeAlphabet)\n";
      str += "       plainText += alphaOffsetToChar(value3)\n";
      str += "    return plainText\n\n";
      
      // Helper function
      str += "modulo(lhs, rhs)\n";
      str += "    result = lhs % rhs\n";
      str += "    if result < 0\n";
      str += "       result = rhs + result\n";
      str += "    return result\n\n";
      
      // Helper function
      // leastAsciiChar is the lowest bound for acceptable characters,
      // which should be a space (' ').
      str += "charToAlphaOffset(ch)\n";
      str += "    offset = (ch as number) - (leastAsciiChar as number)\n";
      str += "    return offset\n\n";
      
      // Helper function
      str += "alphaOffsetToChar(offset)\n";
      str += "    ch = (offset + (leastAsciiChar as number)) as char\n";
      str += "    return ch\n\n";
            
      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText = "";
      int value1 = 0;
      int value2 = 0;
      int value3 = 0;
      for (int i = 0; i < plainText.length(); ++i)
      {
         value1 = charToAlphaOffset(plainText[i]);
         value2 = charToAlphaOffset(password[i % password.length()]);
         value3 = modulo((value1 + value2), sizeAlphabet);
         cipherText += alphaOffsetToChar(value3);
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
      // plainText = new string\n"; 
      std::string plainText;
      // for index = 0 to (length of cipherText)\n";
      for (int index = 0; index < cipherText.length(); index++)
      {
         //    value1 = charToAlphaOffset(cipherText[index])\n";
         int value1 = charToAlphaOffset(cipherText[index]);
         //    value2 = charToAlphaOffset(password[index])\n";
         int value2 = charToAlphaOffset(password[index % password.length()]);
         //    value3 = modulo((value1 - value2), sizeAlphabet)\n";
         int value3 = modulo((value1 - value2), sizeAlphabet);
         //    plainText += alphaOffsetToChar(value3)\n";
         plainText += alphaOffsetToChar(value3);
      }
      // return plainText\n\n";
      return plainText;
   }
   /**********************************************************
    * charToAlphaOffset
    * Converts the char to its int value - the int value of the
    * lowest acceptable ascii value, a space.
    **********************************************************/
    virtual int charToAlphaOffset(char ch)
    {
    // offset = (ch as number) - (leastAsciiChar as number)\n";
        int offset = (int)ch - (int)leastAsciiChar;
    // return offset\n\n";
        return offset;
    }
      
   /**********************************************************
    * alphaOffsetToChar
    * Converts the offset back to char by +ing the offset with 
    * the int value of the lowest acceptable ascii value, a space.
    **********************************************************/
    virtual char alphaOffsetToChar(int offset)
    {
    //    ch = (offset + (leastAsciiChar as number)) as char\n";
    	char ch = (char)(offset + (int)leastAsciiChar);
    //    return ch\n\n";
    	return ch;
    }

   /**********************************************************
    * Modulo
    * Modulos the lhs with the rhs, if the value is less than
    * zero, add the size of the alphabet to get a positive number.
    **********************************************************/
    virtual int modulo(int lhs, int rhs)
    {
    //     result = lhs % rhs\n";
        int result = lhs % rhs;
    //     if result < 0\n";
        if (result < 0)
        {
    //        result = rhs + result\n";
           result = rhs + result;
        }
    //    return result\n\n";
        return result;
    }

   // minimum "printable" character
   char leastAsciiChar;
   // maximum "printable" character
   char greatestAsciiChar;

   int sizeAlphabet;
};

#endif // CIPHER05_H
