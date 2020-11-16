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
   virtual std::string getPseudoAuth()  { return "Jon Stutz"; }
   virtual std::string getCipherName()  { return "Beaufort Cipher"; }
   virtual std::string getEncryptAuth() { return "Todd Anderson"; }
   virtual std::string getDecryptAuth() { return "Chase Haymond"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string citation;
      citation += "practicalcryptography.com (2019), ";
      citation += "\"Beaufort Cipher\', \n   retrieved: ";
      citation += "http://practicalcryptography.com/ciphers/beaufort-cipher/";
      return citation;
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // TODO: please format your pseudocode
      
      str = " Use a 26 x 26 matrix, each row is shift one from the previous\n";
      str += "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n";
      str += "B C D E F G H I J K L M N O P Q R S T U V W X Y Z A\n";
      str += "C D E F G H I J K L M N O P Q R S T U V W X Y Z A B\n\n";
      str += "encrypt(plainText, password)\n";
      str += "   plainText = plainText.uppper()\n";
      str += "   password = password.uppper()\n";
      str += "   while length(plaintext) > password; password = password + password;\n";
      str += "   FOR p and q is all values of plainText and password\n";
      str += "      // loop through the array to find the index of the match letter of p\n";
      str += "      for i =0; i<26; i++\n";
      str += "        if matrix[p - 'A'][i] == q\n";
      str += "           offset = i\n\n";
      str += "      letter = matrix[0][offset]\n";
      str += "      cipherText += letter\n";
      str += "   RETURN cipherText\n\n";

      // The decryptCase pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   password = password.uppper()\n";
      str += "   cipherText = cipherText.uppper()\n";
      str += "   while length(plaintext) > length(password); password = password + password;\n";
      str += "   FOR p and q is all values of cipherText and password\n";
      str += "      // loop through the array to find the index of the match letter of p\n";
      str += "      for i =0; i<26; i++\n";
      str += "        if matrix[p - 'A'][i] == q\n";
      str += "           offset = i\n\n";
      str += "      letter = matrix[0][offset]\n";
      str += "      plainText += letter\n";
      str += "   RETURN plainText\n\n";
      
      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      // building the 26 x 26 matrix
      char alpha[26][26];
      for (int i = 0; i < 26; i++)
      {
         for (int j = 0; j < 26; j++)
         {
            alpha[i][j] = char(((i + j) % 26) + 'A');
         }
      }
      std::string cipherText;
      std::string pw = password;
      std::string pt = plainText;
      int t;
      int p;

      // Make password match or longer than plainText
      do {pw += pw;}
      while (pw.length() < pt.length());

      // Convert plainText to ASCII
      for (int i = 0; i < pt.length(); i++)
      {
         // 33 represents the smallest ASCII character value
         // which sets the scale to "!" = 0, and so on
         t = int(pt[i] - 33);
         p = int(pw[i] - 33);
         cipherText += char((p - t) % 94) + 33;
      }
      
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: This takes cipher text and decrypts it useing the
    *        the password as a key.
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText;

      for (int textIndex = 0; textIndex < cipherText.length(); textIndex++)
      {

         //This will get correct letter from password
         int passwordIndex = (textIndex % password.length());

         char cipherLetter = cipherText[textIndex];
         char passwordLetter = password[passwordIndex];

         //Use the same math to decrypt that we used to encrypt
         int offset = normalizeOffset(cipherLetter - 33, passwordLetter - 33);

         plainText += char(offset + 33);
      }

      return plainText;
   }

private:

   int normalizeOffset(char LetterOfPlainText, char LetterOfPassword) 
   {
      // mod by 94 because there are 94 valid chars the user could enter
      int offset = (LetterOfPassword - LetterOfPlainText) % 94;
      return offset;
   }
};

#endif // CIPHER01_H
