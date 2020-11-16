/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Tyler Elkington"; }
   virtual std::string getCipherName()  { return "Rail-Fence Cipher"; }
   virtual std::string getEncryptAuth() { return "Alejandro Di Bartolomeo"; }
   virtual std::string getDecryptAuth() { return "Jonathan Baumert"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "Practical Cryptography, ";
      s += "\"Rail-fence Cipher\', \n   retrieved: ";
      s += "http://practicalcryptography.com/ciphers/classical-era/rail-fence/\n\n";

      s += "GeeksforGeeks, ";
      s += "\"Rail Fence Cipher - Encryption and Decryption\', \n   retrieved: ";
      s += "https://www.geeksforgeeks.org/rail-fence-cipher-encryption-decryption/\n\n";
      
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
      // The encrypt pseudocode
      str =  "encrypt(plainText, password)\n";
      str += "   offest <- offsetFromPassword(password)\n";
      str += "   rail[offset][plainText.length]\n";
      str += "   FOR i is less than offset\n";
      str += "      FOR j is less than plainText\n";
      str += "        rail <- '\\n'\n";
      str += "   FOR i is less than plainText\n";
      str += "      IF row == 0 OR row == offest-1\n";
      str += "         downDirection <- NOT downDirection\n";
      str += "      rail[row][col++] <- plainText[i]\n";
      str += "      downDirection ? row++ : row--\n";
      str += "   FOR i is less than offset\n";
      str += "      FOR j is less than plainText\n";
      str += "         IF rail is NOT '\\n'\n";
      str += "            result.push_back(rail)\n";
      str += "   RETURN result\n\n";

      // The decrypt pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   offset <- offsetFromPassword(password)\n";
      str += "   rail[offset][cipherText.length]\n";
      str += "   FOR i is less than offset\n";
      str += "      FOR j is less than cipherText\n";
      str += "         rail <- '\\n'\n";
      str += "   FOR i is less than cipherText\n";
      str += "      IF row == 0\n";
      str += "         downDirection <- true\n";
      str += "      IF row == offset-1\n";
      str += "         downDirection <- false\n";
      str += "      rail[row][col++] <- '*'\n";
      str += "      downDirection ? row++ : row--\n";
      str += "   FOR i is less than offest\n";
      str += "      FOR j is less than cipherText\n";
      str += "         IF rail == '*' AND index is less than cipherText\n";
      str += "            rail <- cipherText[index++]\n";
      str += "   FOR i is less than cipherText\n";
      str += "      IF row == 0\n";
      str += "         downDirection <- true\n";
      str += "      IF row == offset-1\n";
      str += "         downDirection <- false\n";
      str += "      IF rail[row][col] is NOT '*'\n";
      str += "         result.push_back(rail[row][col++])\n";
      str += "      downDirection ? row++ : row--\n";
      str += "   RETURN result\n\n";

      // helper routine
      str += "offsetFromPassword(password)\n";
      str += "   FOR p is all values of password\n";
      str += "     offset <- indexFromCharacter(p)\n";
      str += "   RETURN offset % size\n\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText, 
                               const std::string & password)
   {
     std::string cipherText = plainText;
     int index = 0;
     std::string result;
     int key = stoi(password);
     int cipherlength = cipherText.length();    
     bool downDirection;
     int row = 0;
     int col = 0;
     char rail[key][cipherlength];
      
     for(int i = 0; i < key; i++)
     {
	     for(int j = 0; j < cipherlength; j++)
	     {
	       rail[i][j] = '\n';
	     }
     }
     for(int i = 0; i < cipherlength; i++)
     {
       if(row == 0 || row == key - 1)
       {
         downDirection = false;
       }
       rail[row][col++] = plainText[i];
       downDirection ? row++ : row--;
     }
     for(int i = 0; i < key; i++)
     {
       for(int j = 0; j < cipherlength; j++)
       {
          if (rail[row][col] != '*')
          {
            result.push_back(rail[row][col++]);
          }
       }
     }

      return result;
   }
  
   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText, 
                               const std::string & password)
   {
     int index = 0;
     std::string result;
     int key = stoi(password);
     int cipherlength = cipherText.length();    
     bool downDirection;
     int row = 0;
     int col = 0;
     char rail[key][cipherlength];
     
     //fill the rail with blank values
     for (int i = 0; i < key; i++)
     {
  	   for (int j=0; j < cipherlength; j++)
  	   {
  	     rail[i][j] = '\n';
  	   }
     }
      //add the filler '*' values to the rail
      for (int i= 0; i < cipherlength; i++)
      {
        if(row == 0)
        {
  	      downDirection = true;
        }
        if(row == key-1)
        {
  	      downDirection = false;
        }
        rail[row][col++] = '*';
        downDirection?row++ : row--;
      }
      //fill the ciphered values into the rail
      for(int i = 0; i < key; i++)
      {
        for (int j = 0; j < cipherlength; j++)
  	    {
      	  if(rail[i][j] == '*' && index<cipherlength)
    	    {
    	      rail[i][j] = cipherText[index++];
    	    }
  	    }
      }
    
      row = 0;
      col = 0;
      //read the rail
      for (int i = 0; i < cipherlength; i++)
      {
        if(row == 0)
        {
          downDirection = true;
        }
        if(row == key-1)
        {
          downDirection = false;
        }
        if (rail[row][col] != '*')
        {
          result.push_back(rail[row][col++]);
        }
        downDirection?row++ : row--;
      }
      return result;
     }
};


#endif // CIPHER01_H
