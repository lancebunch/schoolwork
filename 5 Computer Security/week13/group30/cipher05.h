/********************************************************************
0;136;0c* Header:
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

   Cipher05()
   {
      valueMinimum = ' ';
      valueMaximum = '~';
      sizeAlphabet = valueMaximum - valueMinimum;
   }
   
   virtual std::string getPseudoAuth()  { return "Evan Harrison"; }
   virtual std::string getCipherName()  { return "Affine Cipher"; }
   virtual std::string getEncryptAuth() { return "Tyson Stark"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "Zafar, Yasin, ";
      s += "GeeksforGeeks.com (2019), ";
      s += "\'Implementation of Affine Cipher\', \n   retrieved: ";
      s += "https://www.geeksforgeeks.org/implementation-affine-cipher/";
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
       std::string cipherText = plainText;
      // TODO - Add your code here
      /*int password_a = 5;
      int password_b = offsetFromPassword(password);

      for (int i = plainText.begin(); i != plainText.end(); i++)
      {
         cipherText += tochar(((password_a * (plainText[i] - valueMinimum)) + password_b) % 26));
         }*/

         return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText = cipherText;
      // TODO - Add your code here
      return plainText;
   }

   /********************************************************
    * OFFSET FROM PASSWORD
    * Offset from given password
    *********************************************************/

   /*int offsetFromPassword(const std::string & password)
   {
      int offset = 0;
      for (std::string::const_it i = password.begin(); i != password.end(); ++i)
      {
         offset += password[i] - valueMinimum;
      }

      return offset % password.size();
      }*/
   
   private:
   char valueMinimum;
   char valueMaximum;
   int sizeAlphabet;
      
};

#endif // CIPHER05_H
