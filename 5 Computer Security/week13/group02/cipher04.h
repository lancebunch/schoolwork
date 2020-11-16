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
   virtual std::string getPseudoAuth()  { return "Samuel Gay"; }
   virtual std::string getCipherName()  { return "Columnar Transposition Cipher"; }
   virtual std::string getEncryptAuth() { return "Lina Nielsen (Mitch Patterson didn't complete it"; }
   virtual std::string getDecryptAuth() { return "Lina Nielsen"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
       std::string s1 = "J. Lyons, 'Columnar Transposition Cipher', Practical Cryptography, 2009, \nAvailable at: practicalcryptography.com/ciphers/columnar-transposition-cipher/";
       
       s1 += "\n\n";
       
       s1 += "Y. Zafar, 'Columnar Transposition Cipher', GeeksforGeeks, 2018, \nAvailable at: https://www.geeksforgeeks.org/columnar-transposition-cipher/";
       
       return s1;
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;
      
      
      //Sam's notes//
      
      //encrypt
      //create 2 dimensional array
        //width = number of char in 'password'
        //height = (combined number of char in 'password' and 'text') / width
          //if modulous of the above division >= 1, height++;
      //Populate array
        //'password' goes in top row
        //'text' fills remaining rows; filled left-to-right, top-to-bottom
          //use irregular transposition: leave empty spaces empty at end of array 
      //read char into 'cipher text'
        //text read in by column 
        //column order to be read in is alphabetical: abc123
          //ex.: 'password' = 'dumb'; order of columns is b, d, m, u.
        
        
      //ex. encrypt:
      //'password' = 'dumb'
      //'text' = 'get me out of here'
     
      //array:
      //|d u m b|
      //|g e t  |
      //|m e   o|
      //|u t   o|
      //|f h e r|
      //|e      |
     
      //'cipher text' = "b oor dgmufemt  e ueeth "          
                
      
      // TODO: please format your pseudocode
      // The encrypt pseudocode
      str =  "encrypt(plainText, password)\n";
      str += "  count = 0;\n";
      str += "  cipherText = '';\n";
      str += "  numColumns = length of password;\n";
      str += "  numRows    = (length of password and plainText)/numColumns;\n";
      str += "  IF numRows % numColumns >= 1\n";
      str += "    numRows++;\n";
      str += "  columnTransposition[numRows][numColumns];\n";
      str += "\n";
      str += "  //populate array: password\n";
      str += "  FOR i in numColumn \n";
      str += "    columnTransposition[0][i] <- password[i];\n";
      str += "\n";
      str += "  //populate array: plainText\n";
      str += "  FOR j=1 in numRow \n";
      str += "    FOR i in numColumn\n";
      str += "      columnTransposition[j][i] <- plainText[count];\n";
      str += "      IF plainText[count] == /0\n";
      str += "        columnTransposition[j][i] <- '';\n";
      str += "      count++;\n";
      str += "\n";
      str += "  //determine order\n";
      str += "  sortString(password);\n";
      str += "\n";
      str += "  //populate cipherText\n";
      str += "  FOR i in numColumns\n";
      str += "    FOR j in numRows\n";
      str += "      cipherText += columnTransposition[j][password[i]];\n";
      str += "\n";
      str += "RETURN cipherText;\n";
     


      //decrypt
      //create 2 dimensional array
        //width = number of char in 'password'
        //height = (combined number of char in 'password' and 'text') / width
          //if modulous of the above division >= 1, height++;
      //Populate array
        //input text char by char
        //input into columns: top-to-bottom
        //order of rows to input to is indicated by 'password' ordered alphabetically: abc123
          
      //ex. encrypt:
      //'password' = 'dumb'
      //'cipherText' = "b oor dgmufemt  e ueeth "    

     
      //array:
      //|b d m u|
      //|_ g t e|
      //|o m _ e|
      //|r u _ t|
      //|_ f e h|
      //|_ e _ _|
     
      //'plainText' = 'get me out of here'

          
          
      // The decrypt pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "  count = 0;\n";
      str += "  plainText = '';\n";
      str += "  numColumns = length of password;\n";
      str += "  numRows    = (length of cipherText)/numColumns;\n";
      str += "  IF numRows % numColumns >= 1\n";
      str += "    numRows++;\n";
      str += "  columnTransposition[numRows][numColumns];\n";
      str += "\n";
      str += "  //populate array: cipherText\n";
      str += "  FOR i in numColumn \n";
      str += "    FOR j=0 in numRow \n";
      str += "      columnTransposition[j][i] <- cipherText[count];\n";
      str += "      count++;\n";
      str += "\n";
      str += "  //determine order\n";
      str += "  //order is the same as password;\n";
      str += "\n";
      str += "  //populate cipherText\n";
      str += "  FOR i in numColumns\n";
      str += "    FOR j in numRows\n";
      str += "      plainText += columnTransposition[j][password[i]];\n";
      str += "\n";
      str += "RETURN plainText;\n";

      return str;
   }

   virtual std::string sortString(std::string &str)
   {
      sort(str.begin(), str.end());
      
      return str;
   }
   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      // count = 0
   int count = 0;

   // plainText = ''
   string cipherText = "";

   // numColumns = length of password
   int numColumns = password.length();

   // numRows = (length of cipherText)/numColumns
   int numRows = (password.length() + plainText.length()) / numColumns;

//   numRows += 1;
   if ((password.length() + plainText.length()) % numColumns >= 1)
      numRows++;
//   numRows += 1;
   cout << numRows << endl;
   // columnTransposition[numRows][numColumns]
   char columnTransposition[numRows][numColumns];

   for (int i = 0; i < numColumns; i++)
   {
      columnTransposition[0][i] = password[i];
          cout <<  columnTransposition[0][i];
   }
   cout << endl;

   for (int i = 1; i < numRows; i++)
   {
      for (int j = 0; j < numColumns; j++)
      {
          if (count < plainText.length())
          {
             columnTransposition[i][j] = plainText[count];
          }
         else
         {
            columnTransposition[i][j] = ' ';
         }
         cout<< columnTransposition[i][j];
         count++;
      }
      cout << endl;
   }
   string oldPassword = password;
   string temp = sortString(oldPassword);

   int order[numColumns];

   for (int i = 0; i < numColumns; i++)
   {
      order[i] = password.find(temp[i]);
      cout << order[i] << endl;
   }

   // FOR i in numColumns
   for (int i = 0; i < numColumns; i++)
   {
      // order of reading
         int k = order[i];
         cout << k << endl;

      // FOR j in numRows
      for (int j = 0; j < numRows; j++)
      {

         // plainText += columnTransposition[j][password[i]]
         cipherText += columnTransposition[j][k];
      }
   }
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * Takes in a ciphertext and a password values in order to
    * decrypt the ciphertext. Fills the table with provided
    * ciphertext, determines the order in which it should be
    * read from the table according to the given password to
    * get the plaintext result.
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      // count = 0
      int count = 0;

      // plainText = ''
      string plainText = "";

      // numColumns = length of password
      int numColumns = password.length();

      // numRows = (length of cipherText)/numColumns
      int numRows = cipherText.length() / numColumns;

      // IF numRows % numColumns >= 1\n";
      //   numRows++;\n";
      //   (not included)
      
      // columnTransposition[numRows][numColumns]
      char columnTransposition[numRows][numColumns];

      // FOR j=0 in numRow (changed to numColumns)
      for (int i = 0; i < numColumns; i++)
      {
         // FOR i in numColumn (changed to numRows)
         for (int j = 0; j < numRows; j++)
         {
            // columnTransposition[j][i] <- cipherText[count]
            columnTransposition[j][i] = cipherText[count];
            
            // count++
            count++;
         }
      }

      // Additional code to make the decrypt() work
      //   determine the order
      //   declare new order array
      //   declare new string for a password as it appears in the table
      int order[numColumns];
      string temp = "";

      // assign values to the temp string
      for (int i = 0; i < numColumns; i++)
      {
         temp += columnTransposition[0][i];
      }

      // populate order array
      for (int i = 0; i < numColumns; i++)
      {
         order[i] = temp.find(password[i]);
      }

      // FOR i in numColumns (changed to numRows)
      for (int i = 1; i < numRows; i++)
      {
         // FOR j in numRows (changed to numColumns)
         for (int j = 0; j < numColumns; j++)
         {

            // Additional code
            //   order of reading
            int k = order[j];

            // plainText += columnTransposition[j][password[i]]
            //   (changed [password[i]] to [k] in order to get a
            //   correct value from the table based on the order
            //   array
            plainText += columnTransposition[i][k];
         }
      }
      
      return plainText;
   }
};

#endif // CIPHER04_H
