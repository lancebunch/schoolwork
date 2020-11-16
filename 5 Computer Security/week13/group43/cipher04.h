/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER04_H
#define CIPHER04_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher04 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Ben Dzado"; }
   virtual std::string getCipherName()  { return "Salsa20"; }
   virtual std::string getEncryptAuth() { return "Daniel Hansen"; }
   virtual std::string getDecryptAuth() { return "Ethan Rawlins"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      
      return std::string("https://cr.yp.to/snuffle/salsafamily-2007225.pdg");
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
      str = "For encyptions\n";
      str += "xor text with key\n";
      str += "for(int i = 0 i < 20 i++)\n";
      str += "rotate text bytes\n";
      str += "xor text with key again\n";
      
      // The decrypt pseudocode
      str += "\nFor decyptions\n";
      str += "xor text with key\n";
      str += "for(int i = 0 i < 20 i++)\n";
      str += "reverse rotate text bytes\n";
      str += "xor text with key again\n";
      return str;
   }

   /**********************************************************
    * ENCRYPT
    * This function XORs the message against the cipher, rotates 
    * the slightly encrypted message 20 times to the right, performing
    * immediately after each rotation
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText = plainText;
      xorString(cipherText, password);
      for (int i = 0; i < 20; i++)
      {
         rotate(cipherText);
         xorString(cipherText, password);
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
      xorString(plainText, password);
      for (int i = 0; i < 20; i++)
      {
         reverseRotate(plainText);
         xorString(plainText, password);
      }
   
      return plainText;
   }
   
private:
   /**********************************************************
    * ROTATE
    * This function takes a string and rotates all of its elements
    * one to the right
    **********************************************************/
   void rotate(std::string & text)
   {
      int textLength = text.length();
      char nextChar = text[textLength - 1];
      
      for (int i = 0, nextIndex = 0; i < textLength; i++)
      {
         char temp = text[i];
         text[i] = nextChar;
         nextChar = temp;
      }
   }
   
   /**********************************************************
    * REVERSE ROTATE
    * This function takes a string and rotates all of its elements
    * one to the left
    **********************************************************/
   void reverseRotate(std::string & text)
   {
      reverse(text.begin(), text.begin()+1);
      reverse(text.begin()+1, text.end());
      reverse(text.begin(), text.end());
   }
   
   /**********************************************************
    * XOR STRING
    * This function takes a string and XORs each of its characters  
    * with the key. If the key has fewer characters than the message, 
    * continue looping through the key until every character in the 
    * message has been XORed.
    **********************************************************/
   void xorString(std::string & text, const std::string & key)
   {
      int keyLength = key.length();
      for (int i = 0; i < text.length(); i++)
      {
         text[i] = text[i] ^ key[i % keyLength];
      }
   }
   
};

#endif // CIPHER04_H
