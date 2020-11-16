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
   virtual std::string getPseudoAuth()  { return "Todd Anderson"; }
   virtual std::string getCipherName()  { return "Affine Cipher"; }
   virtual std::string getEncryptAuth() { return "Stephen Sharp"; }
   virtual std::string getDecryptAuth() { return "Jon Stutz"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("Modification Affine Ciphers Algorithm for Cryptography Password by Sriramoju Babu - April 2017");
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;
      
      // The encrypt pseudocode
      str =  "ENCRYPTION PSEUDOCODE\n";
      str += "\n";

      // convert str into numbers from 0-25 accordingly
      str += "getline() from user\n";
      str += "for (each in string)\n";
      str += "   myStr = string[i] - 97;\n";
      str += "   array[i] = encrypt(string[i]);\n";
      str += "\n";
      
      // encrypt each character and insert into final output
      str += "encrypt(string[i], password)\n";
      str += "   cipherText = (integer relatively prime to size of alphabet * string[i] + password.length()) % size of alphabet \n";
      str += "   return cipherText + 97;\n";
      str += "\n";
      
      str += "for (each in array)\n";
      str += "   myStr += array[i]\n";
      str += "cout << myStr;\n";
      str += "\n";

      // The decrypt pseudocode
      str += "DECRYPTION PSEUDOCODE\n";
      str += "for (each in string)\n";
      str += "Subtract 97 from each ascii value\n";
      str += "array[i] = decrypt(string[i]));\n";
      str += "\n";
      
      // decrypt each character and insert into final output
      str += "decrypt(string[i], password)\n";
      str += "   result = (integer relatively prime to size of alphabet)^-1 (string[i] - password.length()) % size of alphabet\n";
      str += "   return result;\n";
      str += "\n";
      
      str += "myStr = empty;\n";
      str += "for (each in array)\n";
      str += "   myStr += array[i]\n";
      str += "cout << myStr;\n";

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
      int array[plainText.length()];

      
      for(int i = 0; i < plainText.length(); i++)
      {
         int temp1 = (int)plainText[i] - 97;
         //int a = 85;
         int a = 5;
         //int b = 7;
         int b = password.length();
         //int m = 84;
         int m = 26;
         //int temp2 = (a * ((int)plainText[i] + b)) % m;
         int temp2 = ((a * temp1) + b ) % m;
         array[i] = temp2 + 97;
         cipherText += (char)temp2 + 97;
         std::cout << temp1 << " " <<temp2 << " : " << cipherText << std::endl;
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
      /*****It works now *****/
      //but it only works with alphabet characters
      std::string plainText = "";
      
      for (int i = 0; i < cipherText.length(); i++)
      {
      // p = a^-1 * (c-b) * mod m 
      // p = 21 * (c - 7) %26 %26
         int temp = 0;
         int modNotWorking = 0;
         int b = password.length();
         
         temp = (int)tolower(cipherText[i]) - 97;
         if (temp - b < 0 )
         {
            modNotWorking = temp - b + 26; 
         }
         else
         {
            modNotWorking = temp - b;
         }
         if (temp < b) temp += 26;//make sure that the value won't go negative
         temp = (21 * (temp - b)) % 26; // sometimes I get negative values even when using modlus operator
         plainText += (char)temp + 97;
         std::cout << temp << " " << modNotWorking << " " << plainText << "->";
      }
      return plainText;
   }
};

#endif // CIPHER02_H
