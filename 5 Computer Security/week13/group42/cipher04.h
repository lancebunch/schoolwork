/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER04_H
#define CIPHER04_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher04 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Chase Haymond"; }
   virtual std::string getCipherName()  { return "Playfair Cipher"; }
   virtual std::string getEncryptAuth() { return "Jon Stutz"; }
   virtual std::string getDecryptAuth() { return "Stephen Sharp"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "PracticalCryptography.com, ";
      s += "\"Playfair Cipher\', \n   retrieved: ";
      s += "http://practicalcryptography.com/ciphers/playfair-cipher/";
      return s;
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // The key needs to be 25 letters, no letters used twice, leaving out
      // the letter j. (i and j will be used interchangebly).
      //
      // for example the key could be,
      // "zaqwsxcderfvbgtyhnmuiklop".
      //
      // It then needs to be entered into a 5x5 array.
      // So the final key would be,
      //  z a q w s
      //  x c d e r
      //  f v b g t
      //  y h n m u
      //  i k l o p

      // The encrypt pseudocode
      str =  "encrypt(plainText, key[5][5])\n";

      	// 1.  if plaintext is uneven add an x to the end
      str =  "   IF plaintext length is odd\n";
      str =  "      plaintext += 'x'\n";

      	// 2.  if any pair is the same letter, replace second one with x
      str =  "   IF plaintext[i] == plaintext[i + 1]\n";
      str =  "      plaintext[i + 1] = 'x'\n";

      	// 3.  iterate through all of plaintext. Increment 2 at
      	//     a time because you look at 2 letters at a time
      str += "   FOR p = 0; p is all values of plainText; p += 2\n";

      	// 4.  Locate the letters in the key square
      	//        Find locataion of first letter in pair
      str += "      FOR r = 0 -> all 5 rows\n";
      str += "         FOR c = 0 -> all 5 colums\n";
      str += "            IF key[r][c] == plainText[p]\n";
      str += "               letterOneColumn = c\n";
      str += "               letterOneRow = r\n";

      	//        Find locataion of second letter in pair
      str += "      FOR r = 0 -> all 5 rows\n";
      str += "         FOR c = 0 -> all 5 colums\n";
      str += "            IF key[r][c] == plainText[p]\n";
      str += "               letterTwoColumn = c\n";
      str += "               letterTwoRow = r\n";

      	// If the letters are in different rows and columns, replace 
      	// the pair with the letters on the same row respectively but 
      	// at the other pair of corners of the rectangle defined by 
      	// the original pair
      str += "     IF letterOneColumn != letterTwoColumn AND letterOneRow != letterTwoRow\n";
      str += "        cipherText += key[letterOneRow][letterTwoColumn]\n";
      str += "        cipherText += key[letterTwoRow][letterOneColumn]\n";

      	// If the letters are in the same row
      str += "     IF letterOneRow == letterTwoRow\n";
      str += "        cipherText += key[letterOneRow][(letterTwoColumn + 1) % 5]\n";
      str += "        cipherText += key[letterTwoRow][(letterOneColumn + 1) % 5]\n";

      	// If the letters are in the same column
      str += "     IF letterOneColumn == letterTwoColumn\n";
      str += "        cipherText += key[letterOneRow - 1) % 5][letterTwoColumn]\n";
      str += "        cipherText += key[letterTwoRow - 1) % 5][letterOneColumn]\n";

      str += "   RETURN cipherText\n\n";


      // The decrypt pseudocode 
      str +=  "decrypt(encryptedText, key[5][5])\n";

      	// 1.  iterate through all of plaintext. Increment 2 at
      	//     a time because you look at 2 letters at a time
      str += "   FOR p = 0; p is all values of encryptedText; p += 2\n";

      	// 2.  Locate the letters in the key square
      	//        Find locataion of first letter in pair
      str += "      FOR r = 0 -> all 5 rows\n";
      str += "         FOR c = 0 -> all 5 colums\n";
      str += "            IF key[r][c] == encryptedText[p]\n";
      str += "               letterOneColumn = c\n";
      str += "               letterOneRow = r\n";

      	//        Find locataion of second letter in pair
      str += "      FOR r = 0 -> all 5 rows\n";
      str += "         FOR c = 0 -> all 5 colums\n";
      str += "            IF key[r][c] == encryptedText[p]\n";
      str += "               letterTwoColumn = c\n";
      str += "               letterTwoRow = r\n";

      	// If the letters are in different rows and columns, replace 
      	// the pair with the letters on the same row respectively but 
      	// at the other pair of corners of the rectangle defined by 
      	// the original pair
      str += "     IF letterOneColumn != letterTwoColumn AND letterOneRow != letterTwoRow\n";
      str += "        cipherText += key[letterOneRow][letterTwoColumn]\n";
      str += "        cipherText += key[letterTwoRow][letterOneColumn]\n";

      	// If the letters are in the same row
      str += "     IF letterOneRow == letterTwoRow\n";
      str += "        cipherText += key[letterOneRow][(letterTwoColumn - 1) % 5]\n";
      str += "        cipherText += key[letterTwoRow][(letterOneColumn - 1) % 5]\n";

      // If the letters are in the same column
      str += "     IF letterOneColumn == letterTwoColumn\n";
      str += "        cipherText += key[letterOneRow + 1) % 5][letterTwoColumn]\n";
      str += "        cipherText += key[letterTwoRow + 1) % 5][letterOneColumn]\n";

      str += "   RETURN cipherText\n\n";


      return str;
   }

   /**********************************************************
    * ENCRYPT
    * Uses the plaufair cipher algorithm and returns the 
    * encrypted text
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      // I am making the assumption that the password enter meets the requirements
      std::string plainTextCopy = plainText;

      //Convert password to a 5 x 5 matrix
      char keySquare[5][5];
      int x = 0;

      normalizePassword(keySquare, password);
      
      for (int i = 0; i < plainTextCopy.length(); i++)
      {
         if (!isalpha(plainTextCopy[i]))
         {
            plainTextCopy.erase(i,1);
         }
      }
      // check length of plainText
      if (plainTextCopy.length() % 2 == 1)
      {
         plainTextCopy += 'x';
      }
      
      std::string cipherText = plainTextCopy;
      // start encrypting
      for (int i = 0; i < plainTextCopy.length(); i+=2)
      {
         int letterOneRow = 0;
         int letterOneCol = 0;
         int letterTwoRow = 0;
         int letterTwoCol = 0;

         // if there are any double letters, repalce the second one with x
         if (plainTextCopy[i] == plainTextCopy[i + 1])
         {
            plainTextCopy[i + 1] = 'x';
         }
         for (int row = 0; row < 5; row++)
         {
            for (int col = 0; col < 5; col++)
            {
               if ( keySquare[row][col] == plainTextCopy[i] )
               {
                  letterOneRow = row;
                  letterOneCol = col;   
               }
               if (keySquare[row][col] == plainTextCopy[i + 1] )
               {
                  letterTwoRow = row;
                  letterTwoCol = col;
               }
            }
         }
         // Not in the same col or row
         if ( letterOneRow != letterTwoRow && letterOneCol != letterTwoCol )
         {
            cipherText[i] = keySquare[letterOneRow][letterTwoCol];
            
            cipherText[i + 1] = keySquare[letterTwoRow][letterOneCol];
         }
         // Same row
         else if ( letterOneRow == letterTwoRow )
         {
            cipherText[i] = keySquare[letterOneRow][(letterOneCol + 1) % 5];
            
            cipherText[i + 1] = keySquare[letterTwoRow][(letterTwoCol + 1) % 5];
         }
         // same col
         else if ( letterOneCol == letterTwoCol )
         {
            cipherText[i] = keySquare[(letterOneRow + 1) % 5][letterOneCol];
            
            cipherText[i + 1] = keySquare[(letterTwoRow + 1) % 5][letterTwoCol];
         }
         else
         {
            // something went wrong
            cipherText[i] = ':';
            
            cipherText[i + 1] = '(';
         }
      }
      return cipherText.substr(0,plainText.length());
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText = "";
      int letterOneColumn = 0;
      int letterOneRow = 0;
      int letterTwoColumn = 0;
      int letterTwoRow = 0;
      
      //create the key
      char key[5][5];
      normalizePassword(key, password);
      const char * p = &cipherText.front();
      
      //start decrypting
      for (int i = 0; i < cipherText.length(); i++)
      {
         //loop through rows
         for (int r = 0; r < 5; r++)
         {
            //loop through columns
            for(int c = 0; c < 5; c++)
            {
               //check if these coordinates are correct
               if(key[r][c] == *p)
               {
                  //set first letter's coordinates
                  letterOneColumn = c;
                  letterOneRow = r;
               }
            }
         }
         //iterate forward one
         p++;
         i++;
         //loop through rows
         for (int r = 0; r < 5; r++)
         {
            //loop through columns
            for (int c = 0; c < 5; c++)
            {
               //check if these coordinates are correct
               if(key[r][c] == *p)
               {
                  //set second letter's coordinates
                  letterTwoColumn = c;
                  letterTwoRow = r;
               }
            }
         }
          
         //if the coordinates for both letters differs
         if (letterOneColumn != letterTwoColumn && letterOneRow != letterTwoRow)
         {
         std::cout << "hit\n";
            plainText += key[letterOneRow][letterTwoColumn];//add this character
            plainText += key[letterTwoRow][letterOneColumn];//add this character
         }
         //if the y coordinate is the same
         else if (letterOneRow == letterTwoRow)
         {
         std::cout << "row\n";
            //use a character in a different position
            plainText += key[letterTwoRow][(letterOneColumn - 1) % 5];
            plainText += key[letterOneRow][(letterTwoColumn - 1) % 5];
         }
         //if the x coordinate is the same
         else if (letterOneColumn == letterTwoColumn)
         {
         std::cout << "column\n";
            //use characters in another position
            plainText += key[(letterOneRow - 1) % 5][letterTwoColumn];
            plainText += key[(letterTwoRow - 1) % 5][letterOneColumn];
         }
         
         p++;
      }
      
      return plainText.substr(0,cipherText.length());
   }
private:

   void normalizePassword(char keySquare[][5], std::string password) {
      std:: string defaultKey = "zaqwsxcderfvbgtyhnmuiklop";
      //Convert password to a 5 x 5 matrix
      //char keySquare[5][5];
      int x = 0;
      for (int i = 0; i < 5; i++)
      {
         for (int j = 0; j < 5; j++)
         {
            if ( x < password.length())
            {
               if (isalpha(password[x]) && defaultKey.find(tolower(password[x])) != std::string::npos)
               {
                  defaultKey.erase(defaultKey.find(tolower(password[x])),1);
                  keySquare[i][j] = tolower(password[x]);
                  x++;
               }
               else
               {
                  keySquare[i][j] = defaultKey[x % defaultKey.length()];
                  x++;
               }
            }
            else
            {
               keySquare[i][j] = defaultKey[x % defaultKey.length()];
               x++;
            }
         }
      } 
   }

};

#endif // CIPHER04_H
