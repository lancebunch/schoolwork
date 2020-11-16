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
   Cipher01()
   {
      valueMinimum = ' ';
      valueMaximum = '~';
      sizeAlphabet = valueMaximum - valueMinimum;
   }

   virtual std::string getPseudoAuth() { return "Anthony England"; }
   virtual std::string getCipherName() { return "Vigenere Cipher"; }
   virtual std::string getEncryptAuth() { return "Avery Reed"; }
   virtual std::string getDecryptAuth() { return "Cameron Johnson"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "LearnCryptography.com (2016), ";
      s += "\"Learn Cryptography - Vigenere Cipher\", \n   retrieved: ";
      s += "\n   https://learncryptography.com/classical-encryption/";
      s += "vigenere-cipher";
      return s;
   }

   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // The encryptCase pseudocode
      str = "encrypt(plainText, password)\n";
      str += "   offset <- offsetFromPassword(password)\n";
      str += "   i <- 0\n";
      str += "   FOR p is all values of plainText\n";
      str += "      index <- indexFromCharacter(*p)\n";
      str += "      index += offset[i % password.length]\n";
      str += "      index %= sizeAlphabet\n";
      str += "      cipherText += characterFromIndex(index)\n";
      str += "      i += 1\n";
      str += "   RETURN cipherText\n\n";

      // The decryptCase pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   offset <- offsetFromPassword(password)\n";
      str += "   i <- 0\n";
      str += "   FOR p is all values of cipherText\n";
      str += "      offsetI <- sizeAlphabet - offset[i % password.length]\n";
      str += "      index <- indexFromCharacter(*p) + offsetI\n";
      str += "      index %= sizeAlphabet\n";
      str += "      plainText += characterFromIndex(index)\n";
      str += "      i += 1\n";
      str += "   RETURN plainText\n\n";

      // helper routine
      str += "offsetFromPassword(password)\n";
      str += "   i <- 0\n";
      str += "   FOR p is all values of password\n";
      str += "      offset[i] <- indexFromCharacter(p)\n";
      str += "      i += 1\n";
      str += "   RETURN offset\n\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText, const std::string & password) {
   	std::string cipherText;
	int offSet = 0;
	for(int p = 0; p < plainText.length(); p++) {
		char index = plainText[p];
		if(index >= 'a' && index <= 'z') index += 'A' - 'a';
		else if(index < 'A' || index > 'Z') continue;
		cipherText += (index + password[offSet] - 2 * 'A') % 26 + 'A';
		offSet = (offSet + 1) % password.length();
	}
	return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string &cipherText,
                               const std::string &password)
   {
      std::string plainText;

      int *offset = offsetFromPassword(password);

      // set counter to go through array along with for loop
      int i = 0;
      // go through the string by each character
      for (const char *p = cipherText.c_str(); *p; p++)
      {
         int offsetI = (sizeAlphabet - offset[i]);

         // convert the character into an index we can work with
         int index = indexFromCharacter(*p);

         // perform the shift
         index += offsetI;

         // make sure it is within range
         index %= sizeAlphabet;

         // send the index into the ciphertext
         plainText += characterFromIndex(index);

         // move up the counter
         i++;
      }
      return plainText;
   }

private:
   /**********************************************************
    * OFFSET
    * Gets the offset from the password
    **********************************************************/
   int * offsetFromPassword(const std::string &password)
   {
      static int offset[256]; // create array to hold offset values
      int p = 0;
      for (int i = 0; i < password.size(); i++)
      {
         // get offset values from ascii values from each char in password
         offset[i] = indexFromCharacter(password[i]);
      }
      return offset;
   }

   /**************************************************
    * INDEX FROM CHARACTER
    * Get an index value from a given letter.
    *************************************************/
   int indexFromCharacter(char letter)
   {
      // return the value
      if (letter > valueMaximum || letter < valueMinimum)
         return 0;
      else
         return (int)(letter - valueMinimum);
   }

   /**************************************************
    * CHARACTER FROM INDEX
    * Get the characer value from a given index.
    *************************************************/
   char characterFromIndex(int index)
   {
      if (index >= 0 && index < sizeAlphabet)
         return (char)(index + valueMinimum);
      else
         return ' ';
   }

   // minimum "printable" character
   char valueMinimum;

   // maximum "printable" character
   char valueMaximum;

   int sizeAlphabet;
};

#endif // CIPHER01_H
