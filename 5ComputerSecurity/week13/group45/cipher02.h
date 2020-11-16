/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

#include <cstring>
#include <iostream>
#include <algorithm> 

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Daniel Stepp"; }
   virtual std::string getCipherName()  { return "Columnar Cipher"; }
   virtual std::string getEncryptAuth() { return "Greg De Ligne"; }
   virtual std::string getDecryptAuth() { return "Claire Hocker"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("https://crypto.interactive-maths.com/columnar-transposition-cipher.html");
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // The encrypt pseudocode
      str =  "Get the message the user wants to encrypt\n";
      str += "Get the password the user wants to use\n";
      str += "Remove spaces from the message\n";
      str += "Break the message up into pieces the length of the password\n";
      str += "\tFill in empty spaces with the letter 'X'\n";
      str += "Determine the alphabetical order of the password\n";
      str += "\tIf repeats, the letter that comes first in the password is ordered first\n";
      str += "Save characters by index\n";
      str += "\tEvery piece should print out a letter\n";
      str += "\tThe order of the letter is the index of the first alphabetized letter of the password\n";

      // The decrypt pseudocode
      str += "Get the encrypted message\n";
      str += "Get the password\n";
      str += "Divide the length of the encrypted message by the length of the password\n";
      str += "Create a data structure that will hold that many strings of the password's length\n";
      str += "Determine the alphabetical order of the password\n";
      str += "Take the first character of the encrypted message and save it to the data structure's string at the index of the first alphabetical letter of the password.\n";
      str += "Pop off the first character of the encrypted message\n";
      str += "Repeat until you fill in the first element of the data structure\n";
      str += "Repeat until you go through every index\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * Creates the key mapped to our password and
    * stores the plainText into the table to be read as
    * a cipher.
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText;      
      std::string key;
      
      /* Capitalize and delete spaces in the password */
      for (int i = 0; i < password.length(); i++)
         if (isalpha(password[i]))
            key += toupper(password[i]);
      
      /* Get all sizes for our table */
      int sizePassword = key.length();
      int sizePlainText = plainText.length();
      int sizeTable = (sizePlainText / sizePassword) + 1;
      
      /* Copy string to a c_string. This was necessary for our compiler. */
      char message[sizePlainText + 1];
      strcpy(message, plainText.c_str());
   
      /* Dynamically allocate table and index */
      int * keyIndex = new int [sizePassword];
      char * table = new char [sizeTable * sizePassword];
      
      /* Ensure key index is set to 0 */
      for (int i = 0; i < sizePassword; i++)
         keyIndex[i] = 0;
      
      /* Ensure the table is empty */
      for (int i = 0; i < (sizeTable * sizePassword); i++)
         table[i] = '\0';
      
      /* Copy the plaintext in the table */
      for (int i = 0; i < sizePlainText; i++)
         table[i] = message[i];
      
      /* Create the key index */
      int count = 1;
      
      for (char i = 'A'; i <= 'Z'; i++) // loop through the alphabet
      {
         for (int j = 0; j < sizePassword; j++) // for all letter in password
         {
            if (key[j] == i)     // if it matches we assign it an order number
            {
               keyIndex[j] = count;
               count++;
            }
         }
      }

      /* Read the cipherText from the table */
      for (int i = 1; i <= sizePassword; i++) // all numbers of the key
      {
         for (int j = 0; j < sizePassword; j++) // find index to the key
         {
            if (i == keyIndex[j])                 // if they match
            {
               for (int k = 0; k < sizeTable; k++)
               {
                  cipherText += table[k * sizePassword + j]; // copy the column
               }
            }
         }
      }
      
      /* Free our memory */
      delete [] table;
      delete [] keyIndex;
      
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
	  std::string cipher = cipherText;
	  std::string key = password;

	  int keySize = key.length();
	  int numRows = cipherText.length() / keySize;
	  
	  int * alphOrder = new int[keySize];
	
	  std::string alphabetized = key;
	  std::sort(alphabetized.begin(), alphabetized.end());

	  std::string * decrypted = new std::string[numRows];


	  //Take the first character of the encrypted message and save it 
	  //to the data structure's string at the index of the first alphabetical letter of the password.
	  //Pop off the first character of the encrypted message
	  //Repeat until you fill in the first element of the data structure
	  //Repeat until you go through every index

	  //inefficient, but couldn't figure out another way
	  std::string savedKey = key;
	  int k = 0;
	  for (int i = 0; i < keySize; i++)
	  {
		  for (int j = 0; j < savedKey.length(); j++)
		  {
			  if (alphabetized[i] == savedKey[j])
			  {
				  decrypted[j] += cipher[0];
				  cipher.erase(0, 1);
			  }
		  }
	  }

	  delete[] alphOrder;
	  delete[] decrypted;
	  
	  return plainText;
   }
};

#endif // CIPHER02_H
