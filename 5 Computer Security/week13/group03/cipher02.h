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
   virtual std::string getPseudoAuth()  { return "Steven Anderson"; }
   virtual std::string getCipherName()  { return "Vigenere Cipher"; }
   virtual std::string getEncryptAuth() { return "Jonathan Baumert"; }
   virtual std::string getDecryptAuth() { return "Alejandro Di Bartolomeo"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += " Vigenère Cipher, ";
      s += "Rodriguez-Clark, Dan (2017), ";
      s += "Crypto Corner";
      s += "https://crypto.interactive-maths.com/vigenegravere-cipher.html";


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
      str =  "encrypt(message, key)\n";
      str += "  FOR i is less then message\n";
      str += "          integer<-(message[i] + key[i])%26\n";
      str += "          integer += 'A'\n";
      str += "          add integer to end of encrypted\n";
      str += "  return encrypted\n";

      // The decrypt pseudocode

      str += "decrypt(message, key)\n";
      str += "  For i is less then message\n";
      str += "          integer<-(message[i] - key[i])%26\n";
      str += "          integer += 'A'\n";
      str += "          add integer to end of decrypted\n";
      str += "  return decrypted\n";

      //Helper
      str += "key(message, key)\n";
      str += "  integer<-message size\n";
      str += "  FOR i less than message\n";
      str += "          IF integer equals i\n";
      str += "                  i equals 0\n";
      str += "          IF key size equals message size\n";
      str += "                  break\n";
      str += "          add value of key[i] to end of key\n";
      str += "  return key\n";

      return str;
   }
   

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText;

      // TODO - Add your code here
      std::string keyword = password;
      std::string key;
      std::string encrypted;
      int integer;

      std::string temp = plainText;
      temp.erase(remove_if(temp.begin(), temp.end(), ::isspace), temp.end());
      
      //adjust the key to a proper length
      for (int i = 0; i < temp.length(); i++)
	{
           if (temp.size() == i)
	    i = 0;
	  if(keyword.length() == temp.length())
	    break;
	  keyword += password[i];
	}

      for (int i=0; i<temp.length(); i++)
         cipherText += toupper(temp[i]);
      for (int i=0; i<keyword.length(); i++)
         key += toupper(keyword[i]);
          
      for (int i = 0; i < cipherText.length(); i++)
	{
	  integer = (cipherText[i] + key[i])%26;
	  integer += 'A';
	  encrypted += integer;
	}
      return encrypted;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText;
      std::string keyword = password;
      std::string key;
      std::string decrypted;
      int integer;

      std::string temp = cipherText;
      temp.erase(remove_if(temp.begin(), temp.end(), ::isspace), temp.end());

      //adjust the key to a proper length
      for (int i = 0; i < temp.length(); i++)
      {
         if (temp.size() == i)
            i = 0;
         if(keyword.length() == temp.length())
            break;
         keyword += password[i];
      }

      for (int i=0; i<temp.length(); i++)
         plainText += toupper(temp[i]);
      for (int i=0; i<keyword.length(); i++)
         key += toupper(keyword[i]);
      
      
      for(int i = 0; i < plainText.length(); i++)
      {
        integer = ((plainText[i] - key[i]+26) % 26);
        integer += 'A';
        decrypted += integer;
        
      }
      return decrypted;
   }
};

#endif // CIPHER02_H
