/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER06_H
#define CIPHER06_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher06 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Caleb Hensley"; }
   virtual std::string getCipherName()  { return "Porta Cipher"; }
   virtual std::string getEncryptAuth() { return "Colton Moore"; }
   virtual std::string getDecryptAuth() { return "Ben Dzado"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string url = "American Cryptogram Association,\n";
      url += "https://www.cryptogram.org/downloads/aca.";
      url += "info/ciphers/Porta.pdf,\naccessed December 11\n\n";

      url += "Practical Cryptography,\nhttp://practicalcryptography";
      url += ".com/ciphers/classical-era/porta/,\nAccessed December 11\n";
      return url;
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
      str  = "The Tableau with only 'char' looks like this:\n";
      str += "Keys| a b c d e f g h i j k l m n o p q r s t u v w x y z\n";
      str += "---------------------------------------------------------\n";
      str += "A,B | n o p q r s t u v w x y z a b c d e f g h i j k l m\n";
      str += "C,D | o p q r s t u v w x y z n m a b c d e f g h i j k l\n";
      str += "E,F | p q r s t u v w x y z n o l m a b c d e f g h i j k\n";
      str += "G,H | q r s t u v w x y z n o p k l m a b c d e f g h i j\n";
      str += "I,J | r s t u v w x y z n o p q j k l m a b c d e f g h i\n";
      str += "K,L | s t u v w x y z n o p q r i j k l m a b c d e f g h\n";
      str += "M,N | t u v w x y z n o p q r s h i j k l m a b c d e f g\n";
      str += "O,P | u v w x y z n o p q r s t g h i j k l m a b c d e f\n";
      str += "Q,R | v w x y z n o p q r s t u f g h i j k l m a b c d e\n";
      str += "S,T | w x y z n o p q r s t u v e f g h i j k l m a b c d\n";
      str += "U,V | x y z n o p q r s t u v w d e f g h i j k l m a b c\n";
      str += "W,X | y z n o p q r s t u v w x c d e f g h i j k l m a b\n";
      str += "Y,Z | z n o p q r s t u v w x y b c d e f g h i j k l m a\n\n";

      str += " // NOTE: HOWEVER, the encryption must account for characters and\n";
      str += " // punctuation. These 94 values are represented by (char)32 to\n";
      str += " (char)126.\n\n";

      str += "Pseudocode:\n";
      str += " // Construct the tableau\n";
      str += " var alphabet = (the characters ' ' -> '~')";
      str += " var tableau[][]";
      str += " loop 1 through 47 as i\n";
      str += "    loop 1 through 94 as j\n";
      str += "       tableau[i][j] = (next variable in alphabet mod 95)\n\n";

      str += " // Key consists of password duplicated until it reaches\n";
      str += " // password size\n";
      str += " while key size < password size\n";
      str += "    concatenate password to key\n\n";

      str += " var encrypted\n";
      str += " iterate through plainText size\n";
      str += "    encrypted[index] = tableau[keyChar - 32][plainTextChar - 32]\n";

      str += " // Note: Instead of using the Tableau, you could use the key/2";
      str += " as an index.\n\n";

      str += " output encrypted\n\n";

      // The decrypt pseudocode
      str += " // NOTE: Encryption and decryption use the same function\n\n";

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
      
      std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
      std::string key = "";
      char tableau[13][26] = {
        {'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'},
        {'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'n', 'm', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'},
        {'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'n', 'o', 'l', 'm', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'},
        {'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'n', 'o', 'p', 'k', 'l', 'm', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'},
        {'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'n', 'o', 'p', 'q', 'j', 'k', 'l', 'm', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'},
        {'s', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'n', 'o', 'p', 'q', 'r', 'i', 'j', 'k', 'l', 'm', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'},
        {'t', 'u', 'v', 'w', 'x', 'y', 'z', 'n', 'o', 'p', 'q', 'r', 's', 'h', 'i', 'j', 'k', 'l', 'm', 'a', 'b', 'c', 'd', 'e', 'f', 'g'},
        {'u', 'v', 'w', 'x', 'y', 'z', 'n', 'o', 'p', 'q', 'r', 's', 't', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'a', 'b', 'c', 'd', 'e', 'f'},
        {'v', 'w', 'x', 'y', 'z', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'a', 'b', 'c', 'd', 'e'},
        {'w', 'x', 'y', 'z', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'a', 'b', 'c', 'd'},
        {'x', 'y', 'z', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'a', 'b', 'c'},
        {'y', 'z', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'a', 'b'},
        {'z', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'a'}};
      
      for(int i = 0; key.length() < cipherText.length(); i++)
          key += password[i%password.length()];
      
      for(int i = 0; i < cipherText.length(); i++)
      {
          int row = ((tolower(key[i])-97)/2); // Get row in tableau
          int col;
          for(col = 0; tolower(tableau[row][col]) != tolower(cipherText[i]); col++); // Get index of letter in current row
          cipherText[i] = alphabet[col];
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
      std::string plainText = cipherText;
      std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
      std::string key = "";
      char tableau[13][26] = {
        {'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'},
        {'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'n', 'm', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'},
        {'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'n', 'o', 'l', 'm', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'},
        {'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'n', 'o', 'p', 'k', 'l', 'm', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'},
        {'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'n', 'o', 'p', 'q', 'j', 'k', 'l', 'm', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'},
        {'s', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'n', 'o', 'p', 'q', 'r', 'i', 'j', 'k', 'l', 'm', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'},
        {'t', 'u', 'v', 'w', 'x', 'y', 'z', 'n', 'o', 'p', 'q', 'r', 's', 'h', 'i', 'j', 'k', 'l', 'm', 'a', 'b', 'c', 'd', 'e', 'f', 'g'},
        {'u', 'v', 'w', 'x', 'y', 'z', 'n', 'o', 'p', 'q', 'r', 's', 't', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'a', 'b', 'c', 'd', 'e', 'f'},
        {'v', 'w', 'x', 'y', 'z', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'a', 'b', 'c', 'd', 'e'},
        {'w', 'x', 'y', 'z', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'a', 'b', 'c', 'd'},
        {'x', 'y', 'z', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'a', 'b', 'c'},
        {'y', 'z', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'a', 'b'},
        {'z', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'a'} };

      for (int i = 0; key.length() < plainText.length(); i++)
         key += password[i%password.length()];

      for (int i = 0; i < plainText.length(); i++)
      {
         int row = ((tolower(key[i]) - 97) / 2); // Get row in tableau
         int col;
         for (col = 0; tolower(tableau[row][col]) != tolower(plainText[i]); col++); // Get index of letter in current row
         plainText[i] = alphabet[col];
      }
      return plainText;
   }
};

#endif // CIPHER06_H
