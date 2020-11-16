/********************************************************************
* Header:
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
   virtual std::string getPseudoAuth()  { return "Zach Zendejas"; }
   virtual std::string getCipherName()  { return "Beaufort Cipher"; }
   virtual std::string getEncryptAuth() { return "Justin Hurst"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("");
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
      str =  "cypherText(string plainText, string password\n";
      str += "  string cipher text\n";
      str += "  for i size of plainText\n";
      str += "     int x equals plainText[i] and password[i] mod 26\n";
      str += "     x += 'A'\n";
      str += "     cypherText push back x\n";
      str += "  return cipherText\n";

      // The decrypt pseudocode
      str += "originalText(string cipherText, string password)\n";
      str += "  string originalText\n";
      str += "  for i size of cipherText\n";
      str += "    int x equals cipherText[i] minus password[i] mod 26\n";
      str += "    x += 'A'\n";
      str += "    originalText push back x\n";
      str += "  return originalText\n";


      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
     std::string cipherText = "";
     std::string alphabet = "abcdefghijklmnopqrstuvwxyz";     
     for (int i = 0; i < plainText.size(); i++) {
       char c0 = plainText[i];
       char c1 = password[i % password.size()];       
       int begin = 0;       
       for (int c = 0; c < 26; c++) {
         if (alphabet[c] == tolower(c0)) {
           begin = c;
           break;
         }
       }       
       int offset = 0;       
       for (int c = begin; c < begin + 26; c++) {
         int letter = c % 26;         
         if (alphabet[letter] == tolower(c1)) {
           break;
         }         
         offset++;
       }       
      cipherText += alphabet[offset];
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
      // TODO - Add your code here
      return plainText;
   }
};

#endif // CIPHER05_H
