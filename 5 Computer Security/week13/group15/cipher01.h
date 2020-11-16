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
   virtual std::string getPseudoAuth()  { return "Riley Bigelow"; }
   virtual std::string getCipherName()  { return "Auto Key Cipher"; }
   virtual std::string getEncryptAuth() { return "Ryan Dockstader "; }
   virtual std::string getDecryptAuth() { return "Koby Campbell"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string citation = "Crypto Corner,\" Autokey Cipherr\",[online]Available: https://crypto.interactive-maths.com/autokey-cipher.html";  
      return std::string("citation");
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      str =  "encrypt(plainText, password)\n";
      str += "   /*Before Encryption can begin, create the key by combining the password and text*/\n";
      str += "   string key =  password + textValue\n";
      str += "   for\n";
      str += "   {\n";
      str += "      cipherText[i] = (plaintext[i] + Key[i]) mod(possible characters) + (minimum Character value)\n";
      str += "   }\n";
      str += "   RETURN cipherText\n\n";

      // The decrypt pseudocode
      str +=  "decrypt(plainText, password)\n";
      str += "   /*Before Encryption can begin, create the key by combining the password and text*/\n";
      str += "   string key =  password + textValue\n";
      str += "   for\n";
      str += "   {\n";
      str += "      plaintext[i] = (cipherText[i] - key[i] + (possible character)) mod (possible characters) + 62\n";
      str += "   }\n";
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
      std::string cipherText = plainText;
      std:: string text = "Will be used to encrpty and decrypt the secret messages between you and I.";
      // making key by combining passowrd and plain text
      std::string key = password + text;
      int index = 0;
	

      // encrytion of data Ei = (Pi + Ki) mod 94 + min character value
      for (int i = 0; i < plainText.length(); i++)
      {
         cipherText[i] = (cipherText[i] + key[i]) % 94 + 32 ;
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
      std:: string text = "Will be used to encrpty and decrypt the secret messages between you and I.";
      // making key by combining passowrd and plain text
      std::string key = password + text;
      
      plainText = cipherText;
      // decrytion of data Ei = (Pi - Ki +94) mod 94 + 64
      for (int i = 0; i < plainText.length(); i++)
      {
         plainText[i] = (plainText[i] - key[i] + 94) % 94;
         // if value is 64 space character        
         if (plainText[i] == 64)
            plainText[i] = ' ';
         else
         {
            // next two lines are for number char vlaues 
            // only way I could get it to work
            int y = plainText[i];
            int charValue = y + 62;
            // if value is greater than the max character value 
            // mod 94 to get correct char value 
            if (charValue > 126)
               charValue = charValue % 94;
            plainText[i] = (char)charValue; 
         }
      }
      return plainText;
   }
};

#endif // CIPHER01_H
