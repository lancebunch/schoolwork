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
   virtual std::string getPseudoAuth()  { return "Kevin Billings"; }
   virtual std::string getCipherName()  { return "Rail Fence Cipher"; }
   virtual std::string getEncryptAuth() { return "Parker Weech"; }
   virtual std::string getDecryptAuth() { return "Adam Miller"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;

      s += "Kumar, Ashutosh,. GeeksforGeeks, Circa 2016\n";
      s += "\"Rail Fence Cipher – Encryption and Decryption\", \n";
      s += "Available: \n";
      s += "https://www.geeksforgeeks.org/";
      s += "rail-fence-cipher-encryption-decryption/";

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
       // The encryptCase pseudocode
       str =  "encrypt(plainText, password)\n";

       str += "   // Matrix where rows = password, columns = plainText length\n";
       str += "   rail[row][column]\n";

       str += "   // Fill empty matrix\n";
       str += "   FOR each row\n";
       str += "      FOR each column\n";
       str += "         SET rail[row][column] = endline\n";

       str += "   SET directionDown = FALSE\n";
       str += "   SET row = 0\n";
       str += "   SET column = 0\n";

       str += "   FOR each plainText letter i\n";
       str += "      IF row is 0 OR row is password-1\n";
       str += "         // Flip direction\n";
       str += "         SET directionDown = !directionDown\n";
       str += "      Put letter in matrix\n";
       str += "      SET rail[row][column++] = plainText[i]\n";
       str += "      directionDown?row++ : row--;\n";

       str += "   // Create the cipher\n";
       str += "   SET cipherText = 0\n";
       str += "   FOR each row\n";
       str += "      FOR each column\n";
       str += "         IF rail[row][column]! = endline\n";
       str += "            SET cipherText += rail[row][column]\n";
       str += "   RETURN cipherText\n\n";

       // The decryptCase pseudocode
       str += "decrypt(cipherText, password)\n";

       str += "   // Matrix where rows = password, columns = cipherText length\n";
       str += "   rail[row][column]\n";

       str += "   // Fill empty matrix\n";
       str += "   FOR each row\n";
       str += "      FOR each column\n";
       str += "         SET rail[row][column] = endline\n";

       str += "   SET directionDown = FALSE\n";
       str += "   SET row = 0\n";
       str += "   SET column = 0\n";

       str += "   FOR each plainText letter i\n";
       str += "      IF row is 0\n";
       str += "         SET directionDown = TRUE\n";
       str += "      IF row is password-1\n";
       str += "         SET directionDown = FALSE\n";

       str += "      SET rail[row][column++] = *\n";

       str += "      // Find the next row\n";
       str += "      directionDown?row++ : row--;\n";

       str += "   // Fill the rail matrix\n";
       str += "   SET index = 0\n";       
       str += "   FOR each row\n";
       str += "      FOR each column\n";
       str += "         IF rail[row][column] = * AND index < cipherText length \n";
       str += "            rail[row][column] = cipherText[index++]\n";

       str += "   SET plainText = 0\n";
       str += "   SET row = 0\n";
       str += "   SET column = 0\n";       
       str += "   FOR each cipherText letter i\n";
       str += "      IF row is 0\n";
       str += "         SET directionDown = TRUE\n";
       str += "      IF row is password-1\n";
       str += "         SET directionDown = FALSE\n";

       str += "      IF rail[row][column]! = *\n";
       str += "          SET plainText += rail[row][column++]\n";

       str += "      // Find the next row\n";
       str += "      directionDown?row++ : row--;\n";

       str += "   RETURN plainText\n\n";
      
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
      std::istringstream iss (password);
      int pass;
      iss >> pass;
      // TODO - Add your code here
        
      char rail[pass][(plainText.length())]; 
      
      for (int i=0; i < pass; i++) 
         for (int j = 0; j < plainText.length(); j++) 
            rail[i][j] = '\n'; 
  
      bool dir_down = false; 
      int row = 0, col = 0; 
      
      for (int i=0; i < plainText.length(); i++) 
      { 
         if (row == 0 || row == pass-1) 
            dir_down = !dir_down; 
         
         rail[row][col++] = plainText[i]; 
         
         dir_down?row++ : row--; 
      } 
      
      for (int i=0; i < pass; i++) 
         for (int j=0; j < plainText.length(); j++) 
            if (rail[i][j]!='\n') 
               cipherText.push_back(rail[i][j]);  

      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      //std::string plainText = cipherText;
      std::string plainText = "";
      // TODO - Add your code here
      int key = password.length();
      bool directionDown = false;
      int row = 0;
      int col = 0;
      char rails[key][cipherText.length()];

      for (int i = 0; i < key; i++)
      {
         for (int j = 0; j < cipherText.length(); j++)
         {
            rails[i][j] = '\n';
         }
      }

      for (int i = 0; i < cipherText.length(); i++)
      {
         if (row == 0)
         {
            directionDown = true;
         }
         if (row == key - 1)
         {
            directionDown = false;
         }

         rails[row][col++] = '*';

         directionDown ? row++ : row--;
      }

      int index = 0;
      for (int i = 0; i < key; i++)
      {
         for (int j = 0; j < cipherText.length(); j++)
         {
            if (rails[i][j] == '*' && index < cipherText.length())
            {
               rails[i][j] = cipherText[index++];
            }
         }

         directionDown ? row++ : row--;
      }

      row = 0, col = 0;
      for (int i = 0; i < cipherText.length(); i++)
      {
         if (row == 0)
         {
            directionDown = true;
         }
         if (row == key - 1)
         {
            directionDown = false;
         }

         if (rails[row][col] != '*')
         {
            plainText.push_back(rails[row][col++]);
         }
      }

      return plainText;
   }
};

#endif // CIPHER03_H
