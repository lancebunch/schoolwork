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
   virtual std::string getPseudoAuth()  { return "Stephen Sharp"; }
   virtual std::string getCipherName()  { return "Polybius Cipher"; }
   virtual std::string getEncryptAuth() { return "Alex Bentley"; }
   // Because these were the only options remaining
   virtual std::string getDecryptAuth() { return "Alex Bentley"; }  

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "T. Kondo, \"An Extended Version of the Polybius Cipher\"\n";
      s += "International Journal of Computer Applications, vol 79 no 13\n";
      s += "[Online] Available: http://citeseerx.ist.psu.edu/viewdoc/";
      s += "download?doi=10.1.1.481.4109&rep=rep1&type=pdf";
      
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
      str =  "ENCRYPT:\n";
      str += "encrypt(plainText, password):\n";
      str += "\tSET key = abcdefghijklmnopqrstuvwxyz,.!?0123456789\n";
      str += "\tkey += password\n";
      str += "\tSET text = plainText\n";
      str += "\tSET cipherText\n\n";
      str += "\tplainText = toLower(plainText)";
      str += "\tFOR c1 is a char in text\n";
      str += "\t\tSET first = 0\n";
      str += "\t\tSET second = 0\n";
      str += "\t\tFOR c2 is a char in key and i counts from 1:\n";
      str += "\t\t\tIF c1 EQUALS c2\n";
      str += "\t\t\t\tfirst = i / 6\n";
      str += "\t\t\t\tsecond = i % 6\n";
      str += "\t\tADD first and second to cipherText AS character\n";
      str += "\tRETURN cipherText\n\n";

      // The decrypt pseudocode
      str += "DECRYPT:\n";
      str += "decrypt(cipherText, password):\n";
      str += "\tSET key = abcdefghijklmnopqrstuvwxyz,.!?0123456789\n";
      str += "\tkey += password\n";
      str += "\tSET plainText\n";
      str += "\tFOR c in cipherText:\n";
      str += "\t\tSET index = (integer) c * 6\n";
      str += "\t\tINCR c\n";
      str += "\t\tADD (integer) c to index\n";
      str += "\t\tindex = index % length of key\n";
      str += "\t\tADD key[index] to plainText\n";
      str += "\tRETURN plainText\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string key = "abcdefghijklmnopqrstuvwxyz,.!?0123456789";
      key += password;
      std::string text = plainText;
      std::string cipherText = "";
      for (int i = 0; i < text.length(); ++i)
      {
         char c1 = tolower(text[i]);
         int first = 0;
         int second = 0;
         for (int j = 1, k = 0; k < key.length(); ++j, ++k)
         {
            char c2 = key[k];
            if (c1 == c2)
            {
               first = j / 6;
               second = j % 6;
            }
         }
         cipherText += key[first];
         cipherText += key[second];
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
      std::string key = "abcdefghijklmnopqrstuvwxyz,.!?0123456789";
      key += password;
      std::string plainText = "";
      for (int i = 0; i < cipherText.length(); ++i)
      {
         char c = cipherText[i];
         int index = key.find_last_of(c) * 6;
         c = cipherText[++i];
         index += key.find_last_of(c);
         index %= key.length();
         plainText += key[(index - 1) % key.length()];
      }
      return plainText;
   }
};

#endif // CIPHER05_H
