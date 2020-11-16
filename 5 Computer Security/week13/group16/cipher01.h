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
   virtual std::string getPseudoAuth()  { return "Adam Miller"; }
   virtual std::string getCipherName()  { return "Affine Cipher"; }
   virtual std::string getEncryptAuth() { return "Kevin Billings"; }
   virtual std::string getDecryptAuth() { return "Parker Weech"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("Implementation of Affine Cipher. (2019, May 29). Retrieved from https://www.geeksforgeeks.org/implementation-affine-cipher/.");
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;
      // The encrypt pseudocode
      str = "encrypt(message, password)\n";
      str += "SET A = Password length\n";
      str += "// A must be coprime with 26\n";
      str += "IF A mod 2 equals 0\n";
      str += "   SET A = A + 1\n";
      str += "IF A mod 13 equal 0\n";
      str += "   SET A = A + 2\n";
      str += "IF A > 25\n";
      str += "   SET A = 25\n";
      str += "FOR each character in password\n";
      str += "   SET B = B + (int) (character - 'A')\n";
      str += "SET cipher = empty\n";
      str += "for each character in message\n";
      str += "   IF character Not equal ' '\n";
      str += "      SET cipher = cipher + (((A * (character - 'A') + B) Mod 26) + 'A')\n";
      str += "   ELSE cipher += character\n";
      str += "Return cipher\n\n";

      // The decrypt pseudocode
      str += "decrypt(cipher, password)\n";
      str += "SET A = Password length\n";
      str += "// A must be coprime with 26\n";
      str += "IF A mod 2 equals 0\n";
      str += "   SET A = A + 1\n";
      str += "IF A mod 13 equal 0\n";
      str += "   SET A = A + 2\n";
      str += "IF A > 25\n";
      str += "   SET A = 25\n";
      str += "FOR each character in password\n";
      str += "   SET B = B + (int) (character - 'A')\n";
      str += "FOR i < 26\n";
      str += "   SET flag = (A * i) mod 26\n";
      str += "   IF flag  is equal 1\n";
      str += "      SET A_INV = i\n";
      str += "FOR each character in cipher\n";
      str += "   IF character not equal ' '\n";
      str += "      message = message + (char) (((A_INV * ((character + 'A' - B)) mod 26 + 'A')\n";
      str += "   ELSE message += character\n";
      str += "RETURN message\n\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: This will encrypt the plainText with the Affine
    *       Cipher.
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText, 
                               const std::string & password)
   {
      // Variable to store cipherText
      std::string cipherText = plainText;
      
      // TODO - Add your code here
      // Make a key (a and b) from the password
      int a = 0;
      int b = 0;

      for (int i = 0; i < password.length(); i++)
      {
         a = i;
         b = b + (int) (password[i] - 'A');
      }

      // A must be coprime with 26
      if (a % 2 == 0)
         a = a + 1;
      if (a % 13 == 0)
         a = a + 2;
      if (a > 25)
         a = 25;

      // Create cipherText
      cipherText = "";
      
      for (int i = 0; i < plainText.length(); i++)
      {
         if (plainText[i] != ' ')
         {
            cipherText = cipherText + (char) (((a * (plainText[i] - 'A') + b) % 26) + 'A');
         }

         else
            cipherText += plainText[i];
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

      int a = 0;
      int b = 0;
      
      for (int i = 0; i < password.length(); i++)
      {
         a = i;
         b = b + (int) (password[i] - 'A');
      }
      
      // A must be coprime with 26                                                                                                                 
      if (a % 2 == 0)
         a = a + 1;
      if (a % 13 == 0)
         a = a + 2;
      if (a > 25)
         a = 25;
      
      // Create cipherText                                                                                                                       
      plainText = "";
      
      for (int i = 0; i < password.length(); i++)
      {
         b = b + (int) (password[i] - 'A');
      }
      
      for (int i = 0; i < cipherText.length(); i++)
      {
         if (cipherText[i] != ' ')
            plainText = plainText + (char) (((a * (cipherText[i] + 'A') - b) % 26) + 'A');
         
         else
            plainText += cipherText[i];
         
      }
      
      return plainText;
      
   }
};
   
#endif // CIPHER01_H
