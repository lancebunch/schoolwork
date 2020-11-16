/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H

#include <string>
using namespace std;

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Jonathan Carlson"; }
   virtual std::string getCipherName()  { return "Rail Fence Cipher"; }
   virtual std::string getEncryptAuth() { return "Rebecca D. Johnson"; }
   virtual std::string getDecryptAuth() { return "Rick Johnson"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
   	  std::string citation = "Kowalczyk, C. 2013, \"crypto-it\", [online]Available: http://www.crypto-it.net/eng/simple/rail-fence-cipher.html?tab=0"; 	
      return std::string(citation);
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
      str += "\n\
         SET messageInput\n\
         SET rowNumber\n\
         SET fenceTable\n\
         fenceTable = rowNumber\n\
         SET r\n\
         SET direction\n\
         fenceTable = messageInput\n\
         IF (r == (rowNumber - 1) AND direction == 1) OR\n\
         	(r == 0) AND (direction == -1)\n\
      	 THEN direction = -direction\n\
      	 r = r + direction\n\
      	 SET row = 0\n\
      	 WHILE row < rowNumber\n\
      	 	FOR pos < fenceTable[row]\n\
      	 		messageOutput += fenceTable[row\n\
      	 row++\n\
      	 RETURN messageOutput\n\
      ";

      // The decrypt pseudocode
      //str += "insert the decryption pseudocode\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText, 
                               const std::string & password)
  {
     int key = password.length();
     // create the matrix to cipher plain text 
     // key = rows , length(text) = columns 
     char rail[key][(plainText.length())]; 

     // filling the rail matrix to distinguish filled 
     // spaces from blank ones 
     for (int i=0; i < key; i++) 
        for (int j = 0; j < plainText.length(); j++)
           rail[i][j] = '\n'; 
    
     // to find the direction 
     bool dir_down = false; 
     int row = 0, col = 0; 
    
     for (int i=0; i < plainText.length(); i++) 
     { 
        // check the direction of flow 
        // reverse the direction if we've just 
        // filled the top or bottom rail 
        if (row == 0 || row == key-1) 
           dir_down = !dir_down; 
    
        // fill the corresponding alphabet 
        rail[row][col++] = plainText[i]; 
    
         // find the next row using direction flag 
         dir_down?row++ : row--; 
     } 
    
     //now we can construct the cipher using the rail matrix 
     std::string result; 
     for (int i=0; i < key; i++) 
         for (int j=0; j < plainText.length(); j++) 
            if (rail[i][j]!='\n') 
               result.push_back(rail[i][j]); 
    
     return result; 
  }

 /**********************************************************
  * DECRYPTRAILFENCE
  * This function receives cipher-text and key 
  * and returns the original text after decryption 
  **********************************************************/
  string decryptRailFence(string cipher, int key)
  {
     // create the matrix to cipher plain text 
     // key = rows , length(text) = columns 
     char rail[key][cipher.length()];
  
     // filling the rail matrix to distinguish filled 
     // spaces from blank ones 
     for (int i = 0; i < key; i++)
        for (int j = 0; j < cipher.length(); j++)
           rail[i][j] = '\n';
  
     // to find the direction 
     bool dir_down;
  
     int row = 0, col = 0;
  
     // mark the places with '*' 
     for (int i = 0; i < cipher.length(); i++)
     {
        // check the direction of flow 
        if (row == 0)
           dir_down = true;
        if (row == key - 1)
           dir_down = false;
  
        // place the marker 
        rail[row][col++] = '*';
  
        // find the next row using direction flag 
        dir_down ? row++ : row--;
     }
  
     // now we can construct the fill the rail matrix 
     int index = 0;
     for (int i = 0; i < key; i++)
        for (int j = 0; j < cipher.length(); j++)
           if (rail[i][j] == '*' && index < cipher.length())
              rail[i][j] = cipher[index++];
  
     // now read the matrix in zig-zag manner to construct 
     // the resultant text 
     string result;
  
     row = 0, col = 0;
     for (int i = 0; i < cipher.length(); i++)
     {
        // check the direction of flow 
        if (row == 0)
           dir_down = true;
        if (row == key - 1)
           dir_down = false;
  
        // place the marker 
        if (rail[row][col] != '*')
           result.push_back(rail[row][col++]);
  
        // find the next row using direction flag 
        dir_down ? row++ : row--;
     }
     return result;
  }

   /**********************************************************
    * DECRYPT
    * Gets the encoded text and key and returns decrypted 
    * plaintext
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText, 
                               const std::string & password)
  {
      int key = password.length();
      std::string plainText = cipherText;
      
      // pass encoded text and key and return decrypted plaintext
      return decryptRailFence(cipherText, key);
  }

};
#endif // CIPHER01_H
