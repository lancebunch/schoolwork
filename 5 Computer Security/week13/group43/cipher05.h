/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
*
* Cipher: Foursquare
********************************************************************/
#ifndef CIPHER05_H
#define CIPHER05_H

#include <stack>
#include <set>
#include <queue>
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher05 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Colton Moore";   }
   virtual std::string getCipherName()  { return "Foursquare";     }
   virtual std::string getEncryptAuth() { return "Ben Dzado"; }
   virtual std::string getDecryptAuth() { return "Daniel Hansen";  }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("Practical Cryptography, http://practicalcryptography.com/ciphers/four-square-cipher/");
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
	  // http://practicalcryptography.com/ciphers/four-square-cipher/
      str  =  "Encryption\n";
	  str +=  "Create 2d char array [5][5] as alphMatrix\n";
	  str +=  "Create string AS alphabet\n";
	  str +=  "SET alphabet 'a, b, c, d, e, f, g, h, i, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z' (j is purposely excluded)\n";
	  str +=  "CONVERT alphabet to 5x5 char array AS alphMatrix, from left to right, then top to bottom\n";
	  str +=  "\n";
	  str +=  "CREATE two different strings AS k1 and k2\n";
	  str +=  "SET k1 any string of 25 characters or less, with each character being unique, and a letter from the alphabet string\n";
	  str +=  "APPEND to k1 the letters from the alphabet string that are not currently present in the k1 string\n";
	  str +=  "CONVERT k1 to 5x5 char array AS k1Matrix, from left to right, then top to bottom ([[1, 2, 3, 4, 5], [6, 7, 8, 9, 10]...etc])\n";
	  str +=  "REPEAT steps for k2\n";
      str +=  "\n";
	  str +=  "CREATE string as userMessage\n";
	  str +=  "CREATE string as encodedMessage\n";
	  str +=  "SET userMessage as any message to encode, with only letters from the alphabet string\n";
	  str +=  "IF userMessage has an odd length of characters, append 'X' at the end\n";
      str +=  "\n";
      str +=  "CREATE integer AS x\n";
      str +=  "CREATE integer AS y\n";
	  str +=  "FOR i EQUALS 0, i LESS THAN length of userMessage, INCREMENT i by 2\n";
	  str +=  "   SET x -> column number of userMessage[i]   inside of alphMatrix\n";
	  str +=  "   SET y -> row    number of userMessage[i+1] inside of alphMatrix\n";
      str +=  "   SET encodedMessage[i] -> k1Matrix[y][x]\n";
      str +=  "   \n";
      str +=  "   SET x -> column number of userMessage[i+1] inside of alphMatrix\n";
	  str +=  "   SET y -> row    number of userMessage[i]   inside of alphMatrix\n";
	  str +=  "   SET encodedMessage[i+1] -> k2Matrix[y][x]\n";
	  str +=  "\n";
      str +=  "RETURN encodedMessage\n";
	  str +=  "\n";

      // The decrypt pseudocode
      str +=  "Decryption\n";
	  str +=  "Create 2d char array [5][5] as alphMatrix\n";
	  str +=  "Create string AS alphabet\n";
	  str +=  "SET alphabet 'a, b, c, d, e, f, g, h, i, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z' (j is purposely excluded)\n";
	  str +=  "CONVERT alphabet to 5x5 char array AS alphMatrix, from left to right, then top to bottom\n";
	  str +=  "\n";
	  str +=  "CREATE two different strings AS k1 and k2\n";
	  str +=  "SET k1 any string of 25 characters or less, with each character being unique, and a letter from the alphabet string\n";
	  str +=  "APPEND to k1 the letters from the alphabet string that are not currently present in the k1 string\n";
	  str +=  "CONVERT k1 to 5x5 char array AS k1Matrix, from left to right, then top to bottom ([[1, 2, 3, 4, 5], [6, 7, 8, 9, 10]...etc])\n";
	  str +=  "REPEAT steps for k2\n";
      str +=  "\n";
	  str +=  "CREATE string as encodedMessage\n";
	  str +=  "CREATE string as decodedMessage\n";
	  str +=  "SET encodedMessage as any message to decode, with only letters from the alphabet string\n";
	  str +=  "IF encodedMessage has an odd length of characters, append 'X' at the end\n";
      str +=  "\n";
      str +=  "CREATE integer AS x\n";
      str +=  "CREATE integer AS y\n";
	  str +=  "FOR i EQUALS 0, i LESS THAN length of encodedMessage, INCREMENT i by 2\n";
	  str +=  "   SET x -> column number of encodedMessage[i]   inside of k1Matrix\n";
	  str +=  "   SET y -> row    number of encodedMessage[i+1] inside of k2Matrix\n";
      str +=  "   SET decodedMessage[i] -> alphMatrix[y][x]\n";
      str +=  "   \n";
      str +=  "   SET x -> column number of encodedMessage[i+1] inside of k1Matrix\n";
	  str +=  "   SET y -> row    number of encodedMessage[i]   inside of k2Matrix\n";
	  str +=  "   SET decodedMessage[i+1] -> alphMatrix[y][x]\n";
	  str +=  "\n";
      str +=  "RETURN decodedMessage\n";
	  str +=  "\n";

      return str;
   }

   /****************************************************************
    * ENCRYPT
    * Takes in two passwords with only unique characters
    * with each character being a letter of the alphabet, except j
    * and encrypts the plainText
    ****************************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText = plainText;
      std::string key2 = reverseString(password);
      std::string key1 = createKey(password);
      key2 = createKey(key2);
      createKeyMatrices(key1, key2);
      cipherText = encryptAlgorithm(cipherText);
      return cipherText;
   }

   /*******************************************************************
    * DECRYPT
    * Takes in two passwords with only unique characters
    * with each character being a letter of the alphabet, except j
    * and decrypts the cypherText
    *******************************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText = cipherText;
      // Create the 2 keys necessary for Foursquare
      std::string key2 = reverseString(password);
      std::string key1 = createKey(password);
      key2 = createKey(key2);
      
      // Create the key matrices for lookup in encryption
      createKeyMatrices(key1, key2);
      //displayMatrices();
      
      /* 
         I don't have to create a message, as it's already received
         from the user beforehand.
         I don't have to make text length even or conform 
         to alphabet since the message is already encoded, and thus
         ensure that it already conforms to those standards.
      */
      
      // Decode message using algorithm
      plainText = decryptAlgorithm(cipherText);
      
      return plainText;
   }
private:
   char keyMatrix1[5][5];
   char keyMatrix2[5][5];
   std::string alphabet = {'a','b','c','d','e','f','g','h','i','k','l','m','n',
                           'o','p','q','r','s','t','u','v','w','x','y','z'};
   char alphaMatrix[5][5] = {{'a','b','c','d','e'}, {'f','g','h','i','k'},
                             {'l','m','n','o','p'}, {'q','r','s','t','u'},
                             {'v','w','x','y','z'}};
   
   /*******************************************************************
    * CREATE KEY
    * Remove any duplicate letter
    * Ignore anything that not a letter
    * Substitute 'j' with 'i'
    * 
    * std::set was used to ensure each character was unique in the string
    * std::queue was used to maintain insertion order (otherwise the password
    * strength would be greatly diminshed)
    * std::pair is the return value after set.insert() and its second object 
    * describes if the set.insert() was successful or if the element already 
    * existed in the set
    * Idea found at: https://stackoverflow.com/questions/46511614/preserving-
    *                insertion-order-on-a-stdset-or-stdunordered-set
    *******************************************************************/
   std::string createKey(const std::string & password)
   {
      std::set<char> keySet;
      std::pair<std::set<char>::iterator, bool> setInsertPair;
      std::queue<char> keyQueue;
      std::string key;
      
      for (char c : password)
      {
         // If it's not a letter, just skip it
         if (!isalpha(c))
            continue;
      
         // Convert all letters to lowercase
         if (!islower(c))
            c = tolower(c);
         
         // Substitude 'j' for 'i'
         if (c == 'j')
            c = 'i';
         
         setInsertPair = keySet.insert(c);
         
         // If the set was able to insert c, add c to keyQueue
         if (setInsertPair.second)
            keyQueue.push(c);
      }
      
      // Insert the rest of the alphabet that wasn't used into the the key
      for (char c : alphabet)
      {
         setInsertPair = keySet.insert(c);
         if(setInsertPair.second)
            keyQueue.push(c);
      }
      
      // Empty keyQueue into key
      while (!keyQueue.empty())
      {
         key += keyQueue.front();
         keyQueue.pop();
      }
     
      return key;
   }
    
   /*******************************************************************
    * REVERSE STRING
    * Foursquare requires 2 keys, since the user can only enter 1, we
    * generate a second password, being the exact reverse of the 
    * original. 
    * Without the second key, it's essentially a Playfair cipher.
    *******************************************************************/
   std::string reverseString(const std::string & key1)
   {
      std::stack<char> temp;
      std::string key2;
      
      // Fill the stack
      for (char c : key1)
         temp.push(c);

      // Empty the stack into the new key
      while(!temp.empty())
      {
         key2 += temp.top();
         temp.pop();
      }
      return key2;
   }
   
   /*******************************************************************
    * CREATE KEY MATRIX
    * Fill a 5 by 5 matrix with the password, then the rest of the unused
    * alphabet
    *******************************************************************/
    void createKeyMatrices(const std::string & key1, const std::string & key2)
    {
       for (int row = 0, keyIndex = 0; row < 5; row++)
       {
          for (int col = 0; col < 5; col++, keyIndex++)
          {
             keyMatrix1[row][col] = key1[keyIndex];
             keyMatrix2[row][col] = key2[keyIndex];
          }
       }
    }
    
   /*******************************************************************
    * DISPLAY MATRIX
    * cout the contents of both 2-D, 5X5 matrices for debugging purposes
    *******************************************************************/
   void displayMatrices()
   {
      std::cout << "Key Matrix 1\n";
      std::cout << "================================\n";
      for (int row = 0; row < 5; row++)
      {
         for (int col = 0; col < 5; col++)
            std::cout << keyMatrix1[row][col] << " ";
         std::cout << std::endl;
      }
     
      std::cout << "Key Matrix 2\n";
      std::cout << "================================\n";
      for (int row = 0; row < 5; row++)
      {
         for (int col = 0; col < 5; col++)
            std::cout << keyMatrix2[row][col] << " ";
         std::cout << std::endl;
      }
       
   }
    
   /*******************************************************************
    * FIND COLUMN
    * This is a helper function iterates through a 5X5 matrix until it
    * finds the desired letter. Then, return the current column
    *******************************************************************/
   int findColumn (const char letter, const char matrix[][5])
   {
      for (int row = 0; row < 5; row++)
         for (int col = 0; col < 5; col++)
            if(matrix[row][col] == letter)
               return col;
      return -1;
   }
    
   /*******************************************************************
    * FIND ROW
    * This is a helper function iterates through a 5X5 matrix until it
    * finds the desired letter. Then, return the current row
    *******************************************************************/
   int findRow (const char letter, const char matrix[][5])
   {
      for (int row = 0; row < 5; row++)
         for (int col = 0; col < 5; col++)
            if(matrix[row][col] == letter)
               return row;
      return -1;
   }
    
   /*******************************************************************
    * DECRYPT ALGORITHM
    * This algorithm is used to decrypt the message
    *******************************************************************/
   std::string decryptAlgorithm(const std::string & message)
   {
      std::string decodedMessage;
      int x = 0, y = 0;
      
      for (int i = 0; i < message.length(); i += 2)
      {
         x = findColumn(message[i], keyMatrix1);
         y = findRow(message[i + 1], keyMatrix2);
         decodedMessage += alphaMatrix[y][x];
         
         x = findColumn(message[i + 1], keyMatrix1);
         y = findRow(message[i], keyMatrix2);
         decodedMessage += alphaMatrix[y][x];
      }
      
      return decodedMessage;
   }

   std::string encryptAlgorithm(const std::string & message)
   {
      std::string encodedMessage;
      int x = 0, y = 0;

      for (int i = 0; i < message.length(); i += 2)
      {
         x = findColumn(message[i], alphaMatrix);
         y = findRow(message[i + 1], alphaMatrix);
         encodedMessage += keyMatrix1[y][x];

         x = findColumn(message[i + 1], alphaMatrix);
         y = findRow(message[i], alphaMatrix);
         encodedMessage += keyMatrix2[y][x];
      }

      return encodedMessage;
   }
};

#endif // CIPHER05_H
