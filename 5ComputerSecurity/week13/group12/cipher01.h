/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H

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
      std::cout << "THIS IS THE SIZE OF THE ALPHABET: " << sizeAlphabet << std::endl;
      password_a = 5;
   }
   
   virtual std::string getPseudoAuth()  { return "Evan Harrison"; }
   virtual std::string getCipherName()  { return "Affine Cipher"; }
   virtual std::string getEncryptAuth() { return "Tyson Stark"; }
   virtual std::string getDecryptAuth() { return "Reed Harston"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s = "Zafar, Yasin, ";
      s += "GeeksforGeeks.com (2019), ";
      s += "\'Implementation of Affine Cipher\', \n   retrieved: ";
      s += "https://www.geeksforgeeks.org/implementation-affine-cipher/\n";
      return s;
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // The encrypt pseudocode
      str =  "encrypt(plainText, password)\n";
      str += "   password_a <- 5\n "; // this takes 2 key values, we will just make one a fixed integer (a) which has to be coprime with char set size
      str += "   offsetFromPassword <- setOffsetFromPassword(password)\n "; // offset from password (b)  
      str += "   for i in length of plainText\n";
      str += "      cipherText += tochar(((password_a * (plainText[i] - valueMinimum)) + offsetFromPassword) % sizeOfAlphabet))\n"; // formula for encription is (ax + b)%alphabet
      str += "return cipherText";

      // The decrypt pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   flag = 0\n";
      str += "   for i in sizeOfAlphabet\n";
      str += "      flag = (5 * i) % 26\n";
      str += "      if flag == 1\n";
      str += "         inverse = i\n";
      str += "   for i in cipherText\n";
      str += "      offsetFromPassword <- setOffsetFromPassword(password)\n";
      str += "      plainText <- tochar(inverse * (cipherText[i] + valueMinimum - offsetFromPassword )) % sizeOfAlphabet\n";
      str += "   return plainText\n\n";
      

      // OffsetFromPassword
      str += "offsetFromPassword(password)\n";
      str += "   for i in password\n";
      str += "     offset <- (password[i] - valueMinimum)\n"; // minimum char value is ' ' (space)
      str += "   return offset % size\n";

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
      // TODO - Add your code here
      
      int password_b = cipherKeyFromPassword(password);
      std::cout << "THIS IS PASSWORD B: " << password_b << std::endl;

      for (std::string::const_iterator i = plainText.begin(); i != plainText.end(); i++)
      {
      std::cout << "THIS IS THE CURRENT CHARACTER: " << *i << std::endl;
      std::cout << "THIS IS ITS VALUE:             " << (int)*i << std::endl;
      std::cout << "THIS IS ITS INDEX:             " << indexFromCharacter(*i) << std::endl;
         cipherText += characterFromIndex(((password_a * indexFromCharacter(*i)) + password_b) % sizeAlphabet);
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
      
      int password_b = cipherKeyFromPassword(password);
      std::cout << "THIS IS PASSWORD B: " << password_b << std::endl;

      // Find modular inverse of password_a

      int flag = 0;
      int inverse_a = 0;

      for (int i = 0; i < sizeAlphabet; ++i)
      {
         flag = (password_a * i) % sizeAlphabet;
         if (flag == 1)
            inverse_a = i;
      }

      // Decrypt message

      for (std::string::const_iterator i = cipherText.begin(); i != cipherText.end(); i++)
      {
      std::cout << "THIS IS THE CURRENT CHARACTER: " << *i << std::endl;
      std::cout << "THIS IS ITS INDEX:             " << indexFromCharacter(*i) << std::endl;
         plainText += characterFromIndex((inverse_a * (indexFromCharacter(*i) - password_b)) % sizeAlphabet);
      }

      return plainText;
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

   /***************************************************
    * CIPHER KEY FROM PASSWORD
    * Get the key used in the formula corresponding to a given password
    **************************************************/
   int cipherKeyFromPassword(const std::string & password)
   {
      int offset = 0;
      for (std::string::const_iterator it = password.begin();
           it != password.end();
           ++it)
         offset += indexFromCharacter(*it);

      return offset % sizeAlphabet;
   }
   
   private:
   char valueMinimum;
   char valueMaximum;
   int sizeAlphabet;
   int password_a;
      
};

#endif // CIPHER01_H
