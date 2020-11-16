/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "pseudocode author"; }
   virtual std::string getCipherName()  { return "cipher name"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

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
      
      str = " If you use the decimal value for each capital letter it will work out\n\n";
      str += "encrypt(plainText, password)\n";
      str += "   plainText = plainText.uppper()\n";
      str += "   password = password.uppper()\n";
      str += "   while length(plaintext) > password; password = password + password;\n";
      str += "   FOR p and q is all values of plainText and password\n";
      str += "      offset = normalizeOffset(p, q)\n";
      str += "      letter = offset + 'A'\n";
      str += "      cipherText += char(letter)\n";
      str += "   RETURN cipherText\n\n";

      // The decryptCase pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   password = password.uppper()\n";
      str += "   cipherText = cipherText.uppper()\n";
      str += "   while length(plaintext) > length(password); password = password + password;\n";
      str += "   FOR p and q is all values of cipherText and password\n";
      str += "      offset = normalizeOffset(p, q)\n";
      str += "      letter = offset + 'A'\n";
      str += "      plainText += char(letter)\n";
      str += "   RETURN plainText\n\n";

      // normalize routine
      str += "normalizeOffset(LetterOfPlainText, LetterOfPassword)\n";
      str += "   offset = (LetterOfPassword - LetterOfPlainText)%26)\n";
      str += "   if offset != 0 RETURN offset + 1\n";
      str += "   RETURN offset\n";
      
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

#endif // CIPHER02_H
