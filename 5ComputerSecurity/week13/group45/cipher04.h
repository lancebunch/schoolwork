/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER04_H
#define CIPHER04_H

#include <vector>
#include<string.h>
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher04 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Greg De Ligne"; }
   virtual std::string getCipherName()
   {
      return "Myszkowski Transposition Cipher";
   }
   
   virtual std::string getEncryptAuth() { return "Claire Hocker"; }
   virtual std::string getDecryptAuth() { return "Eric Mathusek"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string str;
      
      str = "Rodriguez-Clark, D. (2019). Myszkowski Transposition Cipher.";
      str += " Crypto Corner.\n\t[Retrieved from: https://";
      str += "crypto.interactive-maths.com/";
      str += "myszkowski-transposition-cipher.html]";
      
      return str;
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // The encrypt pseudocode
      str =  "\t\tEncryption\n\n";
      str += "STRING cipherText\n";
      str += "INT sizePassword = GET password LENTGH\n";
      str += "INT sizePlainText = GET plainText LENTGH\n";
      str += "INT sizeTable = (sizePlainText / sizePassword) + 1\n";
      str += "(Dynamically Allocate) CHAR table [sizeTable] [sizePassword]\n";
      str += "(Dynamically Allocate) INT keyIndex [sizePassword]\n\n";
      str += "SET password and plaintext to ALL CAPITALS (Or all lower)\n\n";
      str += "************* Store message in table ***********\n";
      str += "INT count = 0\n";
      str += "FOR INT i = 0, i < sizeTable, i++\n";
      str += "   FOR INT j = 0, j < sizePassword, j++\n";
      str += "      table[i][j] = plainText[count]\n";
      str += "      count++\n\n";
      str += "*************** Create the keyIndex **************\n";
      str += "INT count = 1\n";
      str += "BOOL detected = false\n";
      str += "FOR CHAR i = A, i <= Z, i++\n";
      str += "   FOR INT j = 0, j < sizePassword, j++\n";
      str += "      IF password[j] == i\n";
      str += "         keyIndex[j] = count\n";
      str += "         detected = true\n";
      str += "   IF detected\n";
      str += "      detected = false\n";
      str += "      count++\n\n";
      str += "********** Read cipherText from table **********\n";
      str += "INT count = 1\n";
      str += "WHILE keyIndex != {0,0,0,0,…}\n";
      str += "   FOR INT i = 0, i < sizePassword, i++\n";
      str += "      IF keyIndex[i] = count\n";
      str += "         FOR INT j = 0, j < sizeTable, j++\n";
      str += "            cipherText += table[j][i]\n";
      str += "         keyIndex[i] = 0\n";
      str += "   count++\n\n";
      str += "RETURN cipherText\n\n";
      
      // The decrypt pseudocode
      str += "\t\tDecryption\n\n";
      str += "STRING plainText\n";
      str += "INT sizePassword = GET password LENTGH\n";
      str += "INT sizeCipherText = GET cipherText LENTGH\n";
      str += "INT sizeTable = (sizeCipherText / sizePassword) + 1\n";
      str += "(Dynamically Allocate) CHAR table [sizeTable] [sizePassword]\n";
      str += "(Dynamically Allocate) INT keyIndex [sizePassword]\n\n";
      str += "SET password and ciphertext to ALL CAPITALS (Or all lower)\n";
      str += "***** Create the keyIndex (same as encryption) *****\n";
      str += "INT count = 1\n";
      str += "BOOL detected = false\n";
      str += "FOR CHAR i = A, i <= Z, i++\n";
      str += "   FOR INT j = 0, j < sizePassword, j++\n";
      str += "      IF password[j] == i\n";
      str += "         keyIndex[j] = count\n";
      str += "         detected = true\n";
      str += "   IF detected\n";
      str += "      count++\n\n";
      str += "********* Store cipherText in table ********\n";
      str += "INT keyCount = 1\n";
      str += "INT cipherTextCount = 0\n";
      str += "WHILE keyIndex != {0,0,0,0,…}\n";
      str += "   FOR INT i = 0, i < sizePassword, i++\n";
      str += "      IF keyIndex[i] = count\n";
      str += "         FOR INT j = 0, j < sizeTable, j++\n";
      str += "            table[j][i] = cipherText[cipherTextCount]\n";
      str += "            cipherTextCount++\n";
      str += "         keyIndex[i] = 0\n";
      str += "   count++\n\n";
      str += "****** Read plainText from table *******\n";
      str += "FOR INT i = 0, i < sizeTable, i++\n";
      str += "   FOR INT j = 0, j < sizePassword, j++\n";
      str += "      plainText += table[i][j]\n\n";
      str += "RETURN plainText\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * Implementation of the Myszkowski Transposition Cipher
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
     //
     std::string cipherText = "";
	  std::string plain = "";
	  std::string pswd = "";
	 
	  int passwordSize = password.length();
	  int plainTextSize = plainText.length();
	  int tableSize = (plainTextSize / passwordSize) + 1;

	  //2D array via 1D array. We will use mods to access
	  //I give credit to the husband for suggesting I do this. I had no idea how 
	  //to dynamically allocate a 2D array. Good thing he's working on the graph assignment!
	  char * table = new char[tableSize * passwordSize];
	  int * keyIndex = new int[passwordSize];

	  //Make everything uppercase
	  int i = 0;
	  while (plainText[i])
	  {
		  plain += toupper(plainText[i]);
		  i++;
	  }

	  i = 0;
	  while (password[i])
	  {
		  pswd += toupper(password[i]);
		  i++;
	  }

	  //Fill keyIndex with 0's
	  for (int i = 0; i < passwordSize; i++)
		  keyIndex[i] = 0;

	  //Fill the table with null characters
	  for (int i = 0; i < (tableSize * passwordSize); i++)
		  table[i] = '\0';
	  
	  //Copy the message into the the table
	  for (int i = 0; i < plainTextSize; i++)
		  table[i] = plain[i];

	  //Fill the keyIndex
	  int count = 1;
	  std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	  bool detected = false;
	  for (int i = 0; i < 26; i++) {
		  for (int j = 0; j < passwordSize; j++)
		  {
			 if (pswd[j] == alphabet[i])
			  {
				  keyIndex[j] = count;
				  detected = true;
           }
			 if (detected)
			 {
				 detected = false;
				 count++;
			 }
		  }
	  }

	  //Read cipherText from table
	  count = 1;
	  while (count <= passwordSize)
	  {
		  for (int i = 0; i < passwordSize; i++)
		  {
			  if (keyIndex[i] == count)
			  {
				  for (int j = 0; j < tableSize; j++)
					  cipherText += table[j * passwordSize + i];
			  } 
		  }
		  count++;
	  }

	  //Delete arrays
	  delete [] keyIndex;
	  delete [] table;

      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * Decryption of the Myszkowski Transposition Cipher
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText = cipherText;
//      std::string cipherText = "";
	   std::string plain = "";
      std::string pswd = "";
      
      int passwordSize = password.length();
      int plainTextSize = plainText.length();
      int tableSize = (plainTextSize / passwordSize) + 1;

      //2D array via 1D array. We will use mods to access
      //I give credit to the husband for suggesting I do this. I had no idea how 
      //to dynamically allocate a 2D array. Good thing he's working on the graph assignment!
      char * table = new char[tableSize * passwordSize];
      int * keyIndex = new int[passwordSize];

//      //Make everything uppercase
//      int i = 0;
//      while (plainText[i])
//      {
//         plain += toupper(plainText[i]);
//         i++;
//      }
//
//      i = 0;
//      while (password[i])
//      {
//         pswd += toupper(password[i]);
//         i++;
//      }
//         return plainText;
//   }
//   //Fill the keyIndex
//	  int count = 1;
//	  std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//	  bool detected = false;
//	  for (int i = 0; i < 26; i++)
//   {
//		  for (int j = 0; j < passwordSize; j++)
//		  {
//			 if (pswd[j] == alphabet[i])
//			  {
//				  keyIndex[j] = count;
//				  detected = true;
//           }
//			 if (detected)
//			 {
//				 detected = false;
//				 count++;
//			 }
//		  }
//	   }
//
//     // Store cipherText in table
//     int keyCount = 1;
//     for (char i = 'A', i <= 'Z', i++)
//     {
//         for (int j = 0, j < passwordSize, i++)
//         {
//           if (keyIndex[i] = count))
//           {
//               for (int j = 0, j < tableSize, j++)
//               {
//                  table[j][i] = cipherText[cipherTextCount];
//                  cipherTextCount++;
//               }
//               keyIndex[i] = 0;
//           }
//         count++;
//     }
//
//     // Read plainText from Table
//     for (int i = 0, i < tableSize, i++)
//     {
//        for (int j = 0, j < passwordSize, i++)
//        {
//           plainText += table[i][j];
//        }
//
//     }
      return plainText;
   }
};

#endif // CIPHER04_H
