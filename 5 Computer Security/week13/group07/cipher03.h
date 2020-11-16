/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER03_H
#define CIPHER03_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03 : public Cipher
{
public:
   virtual std::string getPseudoAuth() { return "Hans Peterson"; }
   virtual std::string getCipherName() { return "Polybius Square"; }
   virtual std::string getEncryptAuth() { return "Cameron Johnson"; }
   virtual std::string getDecryptAuth() { return "Matthew Wilson"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("http://practicalcryptography.com/ciphers/polybius-square-cipher/");
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
      str += "char keysquare[25] = efdmgxlahwqbucnoizpsyrvtk;\n";
      str += "void encrypt(str keyword, str plaintext) {\n";
      str += "  string newPass;\n";
      str += "  for (char c : plaintext) {\n";
      str += "    for (int i = 0; i < 25; i++) {\n";
      str += "      if (c == keysquare[i]) {\n";
      str += "        newPass.append(keyword[i / 5]);\n";
      str += "        newPass.append(keyword[i % 5]);\n";
      str += "      }\n";
      str += "    }\n";
      str += "  }\n";
      str += "}\n";

      str += "void decrypt(str keyword, str encryptedText) {\n";
      str += "  str originalText;\n";
      str += "  for (int i = 0; i < encryptedText.size(); i += 2) {\n";
      str += "    int pos = 0;\n";
      str += "    for (int j = 0; j < 5; j++) { //5 is the max for the keyword\n";
      str += "      if (encryptedText[i] == keyWord[j]) {\n";
      str += "        pos *= 5;\n";
      str += "      }\n";
      str += "      if (encryptedText[i + 1] == keyWord[j]) {\n";
      str += "        pos += 5;\n";
      str += "      }\n";
      str += "    }\n";
      str += "    originalText.append(keysquare[pos]);\n";
      str += "  }\n";
      str += "}\n";
      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string &plainText,
                               const std::string &password)
   {
      std::string cipherText;

      char keysquare[26] = "efdmgxlahwqbucnoizpsyrvtk";

      for (const char c : plainText)
      {
         for (int i = 0; i < 25; i++)
         {
            if (c == keysquare[i])
            {
               cipherText += password[i / 5];
               cipherText += password[i % 5];
            }
         }
      }
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string &cipherText,
                               const std::string &password)
   {
      std::string plainText;
      // TODO - Add your code here
     
        char keysquare[26] = "efdmgxlahwqbucnoizpsyrvtk";
        std::string originalText;
        for (int i = 0; i < cipherText.size(); i += 2) {
            int pos = 0;
            
            for (int j = 0; j < 5; j++) { 
                if (cipherText[i] == password[j]) {
                    pos *= 5;
                }
                if (cipherText[i + 1] == password[j]) {
                    pos += 5;
                }
            }
            std::string s(1, keysquare[pos]);
            originalText.append(s);
        }
        return originalText;
    }
};

#endif // CIPHER03_H
