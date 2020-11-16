/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER05_H
#define CIPHER05_H

#include <iostream>
#include <string>
#include <map>


using namespace std;

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher05 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Jonathan Roberts"; }
   virtual std::string getCipherName()  { return "Keyword Cipher"; }
   virtual std::string getEncryptAuth() { return "Elias Ramirez"; }
   virtual std::string getDecryptAuth() { return "Rebecca D. Johnson"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("https://www.geeksforgeeks.org/keyword-cipher/");
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
      str =  "encoder(keyword, plaintext)\n";
      str += "\tSET keyArray \n";
      str += "\tSET cipherText \n";
      str += "\tFOR count = 0 to length of keyword\n";
      str += "\t\tFOR count = 0 to length of keyArray\n";
      str += "\t\tIF keywordChar is in keyArray \n";
      str += "\t\t\tSET isInKeyArrayFlag = true \n";
      str += "\tIF NOT isInKeyArrayFlag  \n";
      str += "\t\t SET keyArray = keywordChar  \n";
      str += "\n";
      str += "\tFOR Alphabet A to Z\n";
      str += "\t\tFOR count = 0 to length of keyArray\n";
      str += "\t\t\tIF Alphabet is in keyArray \n";
      str += "\t\t\tSET isInKeyArrayFlag = true \n";
      str += "\tIF NOT isInKeyArrayFlag  \n";
      str += "\t\t SET keyArray = Alphabet  \n";
      str += "\n";
      str += "\tFOR count = 0 to length of plaintext\n";
      str += "\t\tSET plainTextCharInt = plaintextChar - 64\n";
      str += "\t\tSET cipherText = keyArray[plainTextCharInt]\n";
      str += "\tRETURN cipherText\n\n";


      // The decrypt pseudocode
      str += "decoder(keyword, cipherText)\n";
      str += "\tSET keyArray \n";
      str += "\tSET plaintext \n";
      str += "\tFOR count = 0 to length of keyword\n";
      str += "\t\tFOR count = 0 to length of keyArray\n";
      str += "\t\tIF keywordChar is in keyArray \n";
      str += "\t\t\tSET isInKeyArrayFlag = true \n";
      str += "\tIF NOT isInKeyArrayFlag  \n";
      str += "\t\t SET keyArray = keywordChar  \n";
      str += "\n";
      str += "\tFOR Alphabet A to Z\n";
      str += "\t\tFOR count = 0 to length of keyArray\n";
      str += "\t\t\tIF Alphabet is in keyArray \n";
      str += "\t\t\tSET isInKeyArrayFlag = true \n";
      str += "\tIF NOT isInKeyArrayFlag  \n";
      str += "\t\t SET keyArray = Alphabet  \n";
      str += "\n";
      str += "\tFOR count = 0 to length of cipherText\n";
      str += "\t\tSET cipherTextCharInt = cipherTextChar - 64\n";
      str += "\t\tSET plaintext = keyArray[cipherTextCharInt]\n";
      str += "\tRETURN plaintext";

      return str;
   }

  
   // Original Set of letters 
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Function generates the encoded text 
string encoder(string key)
{
   string encoded = "";
   bool arr[26] = { 0 };

   // This loop inserts the keyword 
   // at the start of the encoded string 
   for (int i = 0; i < key.size(); i++)
   {
      if (key[i] >= 'A' && key[i] <= 'Z')
      {
         // To check whether the character is inserted 
         // earlier in the encoded string or not 
         if (arr[key[i] - 65] == 0)
         {
            encoded += key[i];
            arr[key[i] - 65] = 1;
         }
      }
      else if (key[i] >= 'a' && key[i] <= 'z')
      {
         if (arr[key[i] - 97] == 0)
         {
            encoded += key[i] - 32;
            arr[key[i] - 97] = 1;
         }
      }
   }

   // This loop inserts the remaining 
   // characters in the encoded string. 
   for (int i = 0; i < 26; i++)
   {
      if (arr[i] == 0)
      {
         arr[i] = 1;
         encoded += char(i + 65);
      }
   }
   return encoded;
}

// Function that generates encodes(cipher) the message 
string cipheredIt(string msg, string encoded) 
{ 
    string cipher=""; 
  
    // This loop ciphered the message. 
    // Spaces, special characters and numbers remain same. 
    for (int i=0; i<msg.size(); i++) 
    { 
        if (msg[i] >='a' && msg[i] <='z') 
        { 
            int pos = msg[i] - 97; 
            cipher += encoded[pos]; 
        } 
        else if (msg[i] >='A' && msg[i] <='Z') 
        { 
            int pos = msg[i] - 65; 
            cipher += encoded[pos]; 
        } 
        else
        { 
            cipher += msg[i]; 
        } 
    } 
    return cipher; 
} 

// This function will decode the message 
string decipheredIt(string msg, string encoded)
{
   // Hold the position of every character (A-Z) 
   // from encoded string 
   map <char, int> enc;
   for (int i = 0; i < encoded.size(); i++)
   {
      enc[encoded[i]] = i;
   }

   string decipher = "";

   // This loop deciphered the message. 
   // Spaces, special characters and numbers remain same. 
   for (int i = 0; i < msg.size(); i++)
   {
      if (msg[i] >= 'a' && msg[i] <= 'z')
      {
         int pos = enc[msg[i] - 32];
         decipher += alphabet[pos];
      }
      else if (msg[i] >= 'A' && msg[i] <= 'Z')
      {
         int pos = enc[msg[i]];
         decipher += alphabet[pos];
      }
      else
      {
         decipher += msg[i];
      }
   }
   return decipher;
}

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText = plainText;
      
           // Function call to generate encoded text 
       string encoded = encoder(password);
       

      return cipheredIt(plainText,encoded);
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
  {
   std::string plainText = cipherText;
   
     // Function call to generate encoded text 
   string encoded = encoder(password);

   return decipheredIt(cipherText, encoded);
  }
    
};

#endif // CIPHER05_H
