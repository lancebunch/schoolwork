/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H
#include <algorithm>
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Chris Carrick"; }
   virtual std::string getCipherName()  { return "Affine Cipher"; }
   virtual std::string getEncryptAuth() { return "Zach Zendejas"; }
   virtual std::string getDecryptAuth() { return "Joseph Burgess"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("citation");
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

      // The decrypt pseudocode
      str += "insert the decryption pseudocode\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & c_plainText, 
                               const std::string & c_password)
   {
     std::string plainText = c_plainText;
     std::string password = c_password;
     std::transform(plainText.begin(), plainText.end(), plainText.begin(), ::toupper);
     std::transform(password.begin(), password.end(), password.begin(), ::toupper);
     const int a = 17;
     const int b = (password.size() % 24) + 1;
     ///Cipher Text initially empty 
     std::string cipherText = "";
     for (int i = 0; i < plainText.size(); i++)
       {
	 // Avoid space to be encrypted  
	 if (plainText[i] != ' ')
	   cipherText += (char)((((a * (plainText[i] - 'A')) + b) % 26) + 'A');
	 else
	   //else simply append space character 
	   cipherText += plainText[i];
       }
     return cipherText;
   }
   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText, 
                               const std::string & c_password)
   {
     std::string password = c_password;
     std::transform(password.begin(), password.end(), password.begin(), ::toupper);
     
     const int a = 17;
     const int b = (password.size() % 24) + 1;
     
     std::string plainText = "";
     int a_inv = 0;
     int flag = 0;
  
     for (int i = 0; i < 26; i++)
       {
	 flag = (a * i) % 26;
	 
	 if (flag == 1)
	   {
	     a_inv = i;
	   }
       }
     for (int i = 0; i < cipherText.size(); i++)
       {
	 if (cipherText[i] != ' ')
	   plainText += (char)((a_inv * (cipherText[i] + 'A' - b) % 26) + 'A');
	 else
	   //else simply append space characte 
	   plainText += cipherText[i];
       }
     return plainText;
   }
};

#endif // CIPHER01_H
