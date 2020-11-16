/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER04_H
#define CIPHER04_H
//using namespace std;
#include <iostream>
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher04 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Joshua Hellewell"; }
   virtual std::string getCipherName()  { return "Rail fence cipher"; }
   virtual std::string getEncryptAuth() { return "Gage Mikos"; }
   virtual std::string getDecryptAuth() { return "Jonathon Dawson"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("Geek for Geeks\n https://www.geeksforgeeks.org/rail-fence-cipher-encryption-decryption/");
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
      str =  "encrypt(plainText, password)\n";
         // set key to 3
      str += "   key <- password.length\n";

      // for loop to set each spot on the rails to a space
      str += "   FOR i is all values of key\n";
      str += "      FOR J is all values of plainText.length()\n";
      // default value must be something like\n or else it wouldn't be able
      // to hold the value you choose
      str += "          rails <- '\n'\n";
      str += "   \n";

      
      str += "   down <- false\n";
      str += "   row <- 0\n";
      str += "   col <- 0\n";
      
      // loop to add each character to the right spot in the rail
      str += "   FOR i is all values of plainText.length()\n";
      
      // if its the top or bottom row go the other direction
      str += "      IF row == 0 OR row == key - 1\n";
      str += "          down <- !down\n";

      // add the next value in
      str += "      rails[row][col++] = plainText[i]\n";
      // move to the next row
      str += "      IF down == true\n";
      str += "         row++\n";
      str += "      ELSE\n";
      str += "         row--\n";
      str += "   \n";


      // put the values in the right order. 
      str += "   FOR i is all values of key\n";
      str += "      FOR j is all values of plainText.length\n";
      str += "         IF rails != '\n'\n";
      str += "            result <- rails[i][j]\n";
      str += "   RETURN result\n";


      
      
      // The decrypt pseudocode
      str += "decrypt(cipherText, password\n";
      str += "   key <- password.length()\n";
      str += "   FOR i is all values of key\n";
      str += "      FOR J is all values of cipherText.length()\n";
      str += "          rails <- '\n'\n";
      str += "   \n";

      
      str += "   down <- false\n";
      str += "   row <- 0\n";
      str += "   col <- 0\n";

      // loop to add each character to the right spot in the rail
      str += "   FOR i is all values of cipherText.length()\n";

      // if its the top or bottom row go the other direction
      str += "      IF row == 0 OR row == key - 1\n";
      str += "          down <- !down\n";
      // place a marker for next section
      str += "      rail[row][col++] <- '\n'\n";

      // move to the next row                                
      str += "      IF down == true\n";
      str += "         row++\n";
      str += "      ELSE\n";
      str += "         row--\n";

      // fill the rails
      str += "   index <- 0\n";
      str += "   FOR i is all values of key\n";
      str += "      FOR j is all values of cipherText.length()\n";
      str += "         rail[i][j] <- cipherText[index++]\n";
      str += "   \n";

      // read the rails up and down to get original
      str += "   down <- false\n";
      str += "   row <- 0\n";
      str += "   col <- 0\n";
      str += "   FOR i is all values of cipherText.length()\n";
      // if its the top or bottom row go the other direction              
      str += "      IF row == 0 OR row == key - 1\n";
      str += "          down <- !down\n";

      // put the values in
      str += "      IF rail[row][col] != '\n'\n";
      str += "         result += rail[row][col++]\n";
      // move to the next row                                         
      str += "      IF down == true\n";
      str += "         row++\n";
      str += "      ELSE\n";
      str += "         row--\n";
      
      str += "   RETURN RESULT\n";
      str += "   \n";
      

      
      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      //std::string cipherText = plainText;
      int key = password.length();
      char rail[key][(plainText.length())];
      std::string result;
      
      for(int i = 0; i < key; i++)
      {
          for(int j = 0; j < plainText.length(); j++)
          {
              rail[i][j] = '\n';//'\n';
          }
      }
      
      bool down = false;
      int row = 0;
      int col = 0;
      
      for (int i=0; i < plainText.length(); i++) 
      {
          if (row == 0 || row == key-1)
            down = !down;
            
          rail[row][col++] = plainText[i];
          
          if (down == true)
            row++;
          else
            row--;
      }
      
      for (int i=0; i < key; i++) 
         for (int j=0; j < plainText.length(); j++) 
             if (rail[i][j] != '\n')//'\n') 
                  result += rail[i][j];       
      
      return result;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText = "";
      int key = password.length();
      char rail[key][cipherText.length()];
      
      for(int i=0; i < key; i++){
         for(int j = 0; j < cipherText.length(); j++){
            rail[i][j] = '\n';
         }
      }

      
      bool down = false;
      int row = 0;
      int col = 0;

      // loop to add each character to the right spot in the rail
      //str += "   FOR i is all values of cipherText.length()\n";
      for(int i=0; i < cipherText.length(); i++){
      // if its the top or bottom row go the other direction
         if(row == 0 || row == key - 1){
            down = !down;
         }
      // place a marker for next section
         rail[row][col++] = '*';

      // move to the next row
      down ? row++ : row--;
      }

      // fill the rails
      int index = 0;
      for(int i=0; i < key; i++){
         for(int j=0; j < cipherText.length(); j++){
            if(rail[i][j] != '\n'){
               rail[i][j] = cipherText[index++];
            }
         }
      }


      // read the rails up and down to get original
      down = false;
      row = 0;
      col = 0;

      for(int i=0; i < cipherText.length(); i++){
         if(row == 0 || row == key - 1){
            down = !down;
         }

      // put the values in
         if(rail[row][col] != '\n'){
            plainText += rail[row][col++];
         }
         down ? row++ : row--;
      }


      return plainText;
   }
};

#endif // CIPHER04_H
