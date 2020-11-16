/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER07_H
#define CIPHER07_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher07 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Eric Mathusek"; }
   virtual std::string getCipherName()  { return "Autokey Cipher"; }
   virtual std::string getEncryptAuth() { return "Enos Ampaw"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "Crypto Corner (2019), ";
      s += "Autokey Cipher";
      s += "https://crypto.interactive-maths.com/autokey-cipher.html";
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
      str = "encrypt(pText, key)\n";
      str += "   IF (keyLen < plainLen)\n";
      str += "      key = makeKey(key, pText)\n";
      str += "   cipherText = makeCiphText(key, pText)\n";
      str += "   RETURN cipherText\n\n";

      // The decrypt pseudocode
      str += "decrypt(cipherText, key)\n";
      str += "   pText = makepText(key, cipherText, alph)\n";
      str += "   RETURN pText\n\n";

      // If key < pText
      str += "makeKey(key, pText)\n";
      str += "   FOR (i = values in pText)";
	   str += "		WHILE (plainLen != keyLen, increment i + 1)\n";
      str += "      key += *i\n";
      str += "   RETURN key\n\n";

      // Build the cipherText
      str += "makeCiphText(key, pText)\n";
      str += "   cipherText = \"\"\n";
      str += "   FOR (i = current index of pText)\n";
      str += "      ascii += (pText[i] + key[i]) % 26\n";
      str += "      ascii += 'A'\n";
      str += "      cipherText += ascii\n";
      str += "   RETURN cipherText\n\n";

      // Build pText
      str += "buildpText(key, cipherText, alph)\n";
      str += "   pText = \"\"\n";
      str += "   FOR (i = current index of cipherText)\n";
      str += "      ascii += (cipherText[i] - key[i] + 26) % 26\n";
      str += "      ascii += 'A'\n";
      str += "      pText += ascii\n";
      str += "      IF (keyLen != cipherText length)\n";
      str += "         key += ascii\n";
      str += "   RETURN pText\n\n";
      
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
};

#endif // CIPHER07_H
