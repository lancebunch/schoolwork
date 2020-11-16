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
   Cipher04()
   {
      valueMinimum = ' ';
      valueMaximum = '~';
      sizeAlphabet = valueMaximum - valueMinimum;
      halfSizeAlphabet = sizeAlphabet / 2;
   }
   
   virtual std::string getPseudoAuth()  { return "Matthew Wilson"; }
   virtual std::string getCipherName()  { return "Porta Cipher"; }
   virtual std::string getEncryptAuth() { return "Anthony England"; }
   virtual std::string getDecryptAuth() { return "Hans Peterson"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
    std::string s;
    s += "Lyons, J. (2012). Porta Cipher. ";
    s += "Retrieved December 12, 2019, ";
    s += "from http://practicalcryptography.com/ciphers/porta-cipher/.";
      return s;
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
      str = "function encrypt(plaintext, key){\n";
      str += "	cyperText equals empty string\n";
      str += "	int offset equals new int[key length]\n";
      str += "	call function offsetFromPassword(offset, key)\n";
      str += "	int I equals 0\n";
      str += "	for each character in plaintext starting with it\n";
      str += "	int charIndex equals call function indexFromCharacter(it)\n";
      str += "	int index equals call function getPortaIndex(offset[I MOD key length], charIndex)\n";
      str += "	cipherText plus equals characterFromIndex(index)\n";
      str += "	I plus plus\n";
      str += "	end for loop\n";
      str += "	delete offset\n";
      str += "	return ciphertext\n";
      str += "	end function\n";
      str += "}\n";

      // The decrypt pseudocode
     str += "return call function encrypt(cipherText, password)\n";

      return str;// = ":)\n\n";
   }

    /**********************************************************
    * ENCRYPT
    * Uses a table of reciprocal cipher alphabets to encrypt text
    **********************************************************/
   virtual std::string encrypt(const std::string &plainText,
                               const std::string &password)
   {
      std::string cipherText = "";
      
      // set offset
      int * offset = new int[password.size()];
      offsetFromPassword(offset, password);
      
      // encrypt each character from offset
      int i = 0;
      for (auto it = plainText.begin(); it != plainText.end(); ++it)
      {
         // get index of character in reciprocal table
         int charIndex = indexFromCharacter(*it);
         int index = getPortaIndex(offset[i % password.size()], charIndex);
                  
         cipherText += characterFromIndex(index);
         
         i++;
      }
      
      // deallocate memory
      delete offset;
      
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string &cipherText,
                               const std::string &password)
   {
     return encrypt(cipherText, password);
   }
   
private:
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
   
   /**************************************************
    * GET PORTA INDEX
    * Get a Porta offset value from a given letter.
    *************************************************/
   int getPortaIndex(const int &offset, const int &charIndex)
   {
      int index = charIndex;
      
      // create reciprocal halfs of the alphabet
      if (charIndex < halfSizeAlphabet)
      {
         index += offset; 
         index %= halfSizeAlphabet;
         index += halfSizeAlphabet;
      }
      else
      {         
         index -= offset + halfSizeAlphabet; 
         index += halfSizeAlphabet;
         index %= halfSizeAlphabet;
      }
      
      return index;
   }

   /***************************************************
    * OFFSET FROM PASSWORD
    * Sets Porta offset corresponding to a given password
    **************************************************/
   void offsetFromPassword(int * offset, const std::string &password)
   {      
      for (int i = 0; i < password.size(); i++)
      {
         // get offset values from ascii values from each char in password
         offset[i] = indexFromCharacter(password[i]) / 2;
      }
   }

   // minimum "printable" character
   char valueMinimum;

   // maximum "printable" character
   char valueMaximum;

   int sizeAlphabet;
   int halfSizeAlphabet;
};
#endif // CIPHER04_H
