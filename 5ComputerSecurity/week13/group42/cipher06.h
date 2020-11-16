/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
*
*    Author: Isaac Malmstrom & (Type your name here if you contributed)
********************************************************************/
#ifndef CIPHER06_H
#define CIPHER06_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher06 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Isaac Malmstrom"; }
   virtual std::string getCipherName()  { return "ADFGX Cipher"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string citation;
      citation = "practicalcryptography.com (2019), ";
      citation += "\"ADFGX Cipher\",";
      citation += "\nRetrieved: http://practicalcryptography.com/ciphers/adfgx-cipher/";
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
      // The encrypt pseudocode
      str =  "insert the encryption pseudocode\n";

      str += "ENCRYPTION\n";
      str += "encrypt(plainText, password)\n";
      str += "\nSET cipherText to EMPTY";
      str += "\nSET map<char, string>sortByPassword";
      str += "\nSET keysquare to abdefghijklmnopqrstuvwxyz";
      str += "\nFOR each char in plainText; SET index to 0";
      str += "   \nIF plainText[index] is equal to keysquare[index]";
      str += "      \nIF index/5 equals 0 THEN cipherText += A";
      str += "      \nELSE IF index/5 equals 1 THEN cipherText += D";
      str += "      \nELSE IF index/5 equals 2 THEN cipherText += F";
      str += "      \nELSE IF index/5 equals 3 THEN cipherText += G";
      str += "      \nELSE IF index/5 equals 4 THEN cipherText += X";
      str += "      \nIF index%5 equals 0 then cipherText += A";
      str += "      \nElSE IF index%5 equals 1 THEN cipherText += D";
      str += "      \nElSE IF index%5 equals 2 THEN cipherText += F";
      str += "      \nElSE IF index%5 equals 3 THEN cipherText += G";
      str += "      \nElSE IF index%5 equals 4 THEN cipherText += X";
      str += "   \nINSERT (password[index], cipherText) to sortByPassword";
      str += "\nCLEAR cipherText";
      str += "\nSTD::SORT(sortByPassword.begin(), sortByPassword.end())";
      str += "\nFOR each string in sortByPassword; SET index to 0";
      str += "   \ncipherText += sortByPassword[index]";
      str += "\nRETURN cipherText"; 


      // The decrypt pseudocode
      str += "insert the decryption pseudocode\n";

      str += "DECRYPTION/n";
      str += "decrypt(encryptedText, password)\n";
      str += "\nSET cipherText to EMPTY";
      str += "\nSET sortedKey to password";
      str += "\nSTD::SORT(sortedKey.begin(), sortedKey.end())";
      str += "\nSET map<char, string>sortByPassword";
      str += "\nSET keysquare to abdefghijklmnopqrstuvwxyz";
      str += "\nFOR each char in encryptedText; SET index to 0; increase index by 2 each loop";
      str += "   \ncipherText += encryptedText[index] && encryptedText[index+1]";
      str += "   \nINSERT (sortedKey[index], cipherText) to sortByPassword";
      str += "\nCLEAR cipherText";
      str += "\nSTD::SORT(sortByPassword.begin(), sortByPassword.end())";
      str += "\nFOR each string in sortByPassword; SET index to 0";
      str += "   \ncipherText += sortByPassword[index]";
      str += "\nRETURN cipherText";

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

#endif // CIPHER06_H
