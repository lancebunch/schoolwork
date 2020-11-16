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
   virtual std::string getPseudoAuth()  { return "Jonathan Baumert"; }
   virtual std::string getCipherName()  { return "Autokey Cipher"; }
   virtual std::string getEncryptAuth() { return "Tyler Elkington"; }
   virtual std::string getDecryptAuth() { return "Steven Anderson"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "Practical Cryptography,  ";
      s += "\"Autokey Cipher\', \n  retrieved: ";
      s += "https://www.practicalcryptography.com/ciphers/classical-era/autokey/\n";

      s += "University of Rhode Island ";
      s += "\"Classical Cryptogeraphy, retrieved: ";
      s += "https://cs.uri.edu/cryptography/classicalvigenere.htm\n";

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
      str =  "encrypt(plainText, keyword)\n ";
      str += "   matrix[a-z][a-z];\n";
      str += "   if keywordsize < plaintextsize\n";
      str += "      for i < sizedifference\n";
      str += "         keyword += plaintext[i]\n";
      str += "   for i < plaintextsize\n";
      str += "      output += matrix[plaintext[i]][keyword[i]\n";
      str += "   return output\n";

      
      // The decrypt pseudocode
      str += "decrypt(encryptdText, keyword)\n ";
      str += "   matrix[a-z][a-z];\n";
      str += "   for i < encryptedTextsize\n";
      str += "      for j < 26\n";
      str += "         if matrix[keyword[i]][j] == encryptedText[i]\n";
      str += "            output += matrix[0][j]\n";
      str += "      keyword += output[i]\n";
      str += "  return output\n";
      
      return str;
   }


   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      // std::string cipherText = plainText;
      std::string cipherText;
      std::string newKey = password;
      // TODO - Add your code here
      char a[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
      char alphabet[26][26];

      //populate the table
      for(int i=0;i<26;i++)
      {
         for(int j=0;j<26;j++)
            alphabet[i][j]=a[(i+j)%26];
      }
      std::string temp = plainText;
      temp.erase(remove_if(temp.begin(), temp.end(), ::isspace), temp.end());      

      int sizeDifference = temp.size() - password.size();
      if (password.size() < temp.size())
      {
         int i = 0;
         while (i < sizeDifference)
         {
            newKey += temp[i];
            ++i;
         }
      }

      for (int i = 0; i < temp.size(); i++)
      {
         cipherText += alphabet[temp[i]-97][newKey[i]-97];
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
      // std::string plainText = cipherText;
      // TODO - Add your code here
      std::string plainText;
      std::string key = password;
      char a[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
      char table[26][26];
      int i,j;
      //populate the table
      for(i=0;i<26;i++)
      {
         for(j=0;j<26;j++)
            table[i][j]=a[(i+j)%26];
      }
      i = 0;
      j = 0;

      std::string temp = cipherText;
      temp.erase(remove_if(temp.begin(), temp.end(), ::isspace), temp.end());
      
      
      while(j!=temp.size())
      {
         if(temp[j] == table[key[j]-97][i])
         {
            plainText += table[0][i];
            key += table[0][i];
            j++;
            i=0;
         }
         else
            i++;
      }
      
      return plainText;
   }
};

#endif // CIPHER03_H
