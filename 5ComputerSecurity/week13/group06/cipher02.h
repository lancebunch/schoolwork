/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H
#include <algorithm>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Dave Purdon"; }
   virtual std::string getCipherName()  { return "Vigenere Cipher"; }
   virtual std::string getEncryptAuth() { return "Joseph Burgess"; }
   virtual std::string getDecryptAuth() { return "Justin Hurst"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "Shene, C.K. (2014), \"The Algebraic Nature of the Vigenere Cipher\"";
      s += "\n retrieved: https://pages.mtu.edu/~shene/NSF-4/Tutorial/Vig-Algebraic.html";  
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
      str =  "encrypt(plainText, password)\n";
      str += "  key = getPassphrase(plainText, password)\n";
      str += "  FOR i is all values of plainText\n";
      str += "   cipherText += (plainText[i] + key[i]) % 26\n";
      str += "  RETURN cipherText\n\n"; 

      // The decrypt pseudocode
      str =  "decrypt(cipherText, password)\n";
      str += "  key = getPassphrase(cipherText, password)\n";
      str += "  FOR i is all values of cipherText\n";
      str += "   plainText += (cipherText[i] - key[i]) % 26\n";
      str += "  RETURN plainText\n\n"; 

      // helper function
      str += "getPassphrase(text, password)\n";
      str += "  IF password.Lenth >= test.length\n";
      str += "    RETURN password.substring(0, text.length)\n";
      str += "  ELSE\n";
      str += "    key = password\n";
      str += "    index = 0\n";
      str += "    WHILE key.length != text.length\n";
      str += "      key += password[index]\n";
      str += "      IF index == password.Length - 1\n";
      str += "        index = 0\n";
      str += "      ELSE\n";
      str += "        index = index +1\n";
      str += "      END IF\n";
      str += "    END WHILE\n";
      str += "  RETURN key\n";
      str += "  END IF\n";
      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & cPlainText,
                               const std::string & cPassword)
   {
     std::string plainText = cPlainText;
     std::string password = cPassword;
     std::transform(plainText.begin(), plainText.end(), plainText.begin(), ::toupper);
     std::transform(password.begin(), password.end(), password.begin(), ::toupper);
     std::string cipherText;
     std::string key = getPassphrase(plainText, password);
     for (int i = 0; i < plainText.size(); i++) 
       { 
	 int x = (plainText[i] + key[i]) %26;
	 x += 'A'; 
	 cipherText.push_back(x); 
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
      std::string plainText, plainTextOutput, key;
      std::string tempPass = password;
      int number;
      
      for (int i = 0; i < cipherText.length(); i++)
      {
         if (cipherText.size() == i)
            i = 0;
         if(tempPass.length() == cipherText.length())
            break;
         tempPass += password[i];
      }
      for (int i=0; i < cipherText.length(); i++)
         plainText += tolower(cipherText[i]);
      for (int i=0; i < tempPass.length(); i++)
         key += tolower(tempPass[i]);      
      
      for(int i = 0; i < plainText.length(); i++)      
      {
        number = ((plainText[i] - key[i]+26) % 26);
        number += 'A';
        plainTextOutput += number;        
      }
      return plainTextOutput;
   }
  
private:

  std::string getPassphrase(std::string text, std::string password)
  {
    std::string key;
    for(int keyIndex = 0, passwordIndex = 0; keyIndex < text.size(); ++keyIndex, ++passwordIndex)
      {
	if(passwordIndex == password.size())
	  passwordIndex = 0;
        key += password[passwordIndex];
      }
    return key;
  }
  
};
  
#endif // CIPHER02_H
