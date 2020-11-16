/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER03_H
#define CIPHER03_H

#include <string>
#include <iostream>
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Sam Haynes"; }
   virtual std::string getCipherName()  { return "Nihilist Cipher"; }
   virtual std::string getEncryptAuth() { return "Landon Campbell"; }
   virtual std::string getDecryptAuth() { return "Cody Martinson"; }
   

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("Crypto-it.net. (2019). Nihilist cipher - polyalphabetic substitution cipher | Crypto-IT. [online] Available at: http://www.crypto-it.net/eng/simple/nihilist.html?tab=0 [Accessed 13 Dec. 2019].");
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str = "";

      // TODO: please format your pseudocode
      // The encrypt pseudocode
      str += "****ENCRYPTION****\n\n";
      str += "for each letter,index in plainText:\n";
      str += "\tencryption_str += string(getSquareNumber(letter) + getSquareNumber(password[index % password.length]))\n";
      str += "return encryption_str\n\n";

      // The decrypt pseudocode
      str += "****DECRYPTION****\n\n";
      str += "count = 0\n";
      str += "for each two_digits in cipherText:\n";
      str += "\tdecrypted_str = getSquareLetter(two_digits - getSquareNumber(password[count % password.length]))\n";
      str += "count++\n";
      str += "NOTE: j's are replaced with i's in this cipher,and any non alphabet characters are removed\n";

      return str;
   }

   /**********************************************************
    * SANITIZE
    * Sanitizes a string for use with the cipher
    * ********************************************************/
   virtual std::string sanitize(std::string dirty) 
   {
      std::string sanitized = "";
      for (int i = 0; i < dirty.length(); i++)
      {
         char letter = std::tolower(dirty[i]);
	 if (letter >= 97 && letter <= 122) 
            sanitized += letter;
      }
      return sanitized;
   }
   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText = "";
      std::string plain = sanitize(plainText);
      std::string pwd = sanitize(password);
      for (int i = 0; i < plain.length(); i++) 
      {
         int pwd_num = getSquareNumber(pwd[i % pwd.length()]);
         cipherText += std::to_string(getSquareNumber(plain[i]) + pwd_num);
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
      std::string plainText = "";
      std::string cipher = cipherText;
      std::string pwd = sanitize(password);
      int count = 0; 
      for (int i = 0; i < cipher.length(); i += 2) 
      {
	 int pwd_sq_num = getSquareNumber(pwd[count % pwd.length()]);
         std::string two_digits = ""; 
	 two_digits += cipher[i];
	 two_digits += cipher[i+1];
         int two_digits_int = atoi(two_digits.c_str()); 
         plainText += getSquareLetter(two_digits_int - pwd_sq_num);
         count++;
      }
      return plainText;
   }

private:
   /**********************************************************************
    * GET SQUARE NUMBER 
    * Returns an integer based on that characters position in the square
    * ********************************************************************/
   virtual int getSquareNumber(char letter) 
   {
      //j is replaced with i in implementation 
      if (letter == 'j') {
         letter = 'i';
      }
      char p_square[5][5] = 
      {
         {'t','h','e','q','u'},
         {'i','c','k','b','r'},
         {'o','w','n','f','x'},
         {'m','p','d','v','s'},
         {'l','a','z','y','g'}
      };
      int i_idx;
      int j_idx;
      for (int i = 0; i < 5; i++) 
      {
         for (int j = 0; j < 5; j++) 
         {
            if (p_square[i][j] == letter) 
            {
               i_idx = i+1;
               j_idx = j+1;
            }
         }
      }
      return atoi((std::to_string(i_idx) + std::to_string(j_idx)).c_str());
   }

   /**********************************************************************
    * GET SQUARE LETTER 
    * Returns a letter based on a two digit integer
    * ********************************************************************/
   virtual char getSquareLetter(int number) 
   {
      char p_square[5][5] = 
      {
         {'t','h','e','q','u'},
         {'i','c','k','b','r'},
         {'o','w','n','f','x'},
         {'m','p','d','v','s'},
         {'l','a','z','y','g'}
      };

      int i_idx = 0;
      if (number >= 10) {
         i_idx = number / 10;
      }
      int j_idx = number % 10;
      i_idx -=1;
      j_idx -=1;
      return p_square[i_idx][j_idx];
   }
};

#endif // CIPHER03_H
