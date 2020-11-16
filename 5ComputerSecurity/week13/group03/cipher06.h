/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER06_H
#define CIPHER06_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher06 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Tyson Stark"; }
   virtual std::string getCipherName()  { return "Hill Cipher"; }
   virtual std::string getEncryptAuth() { return "Evan Harrison"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "GeeksForGeeks, ";
      s += "\"Implementation of Hill Cipher\", \n retrieved: ";
      s += "https://www.geeksforgeeks.org/hill-cipher/";

      s += "Tutorials Point, ";
      s += "\"Implement the Hill Cypher\", \n retrieved: ";
      s += "https://www.tutorialspoint.com/cplusplus-program-to-implement-the-hill-cypher";
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
      str += "Begin with getHillCipher(plainText, password)\n";
      str += "encrypt(cipherMatrix[][1], keyMatrix[][3], plainTextVector[][1])\n";
      str += "   cipherMatrix <- getMatrix(password, keyMatrix[][])\n";
      str += "   for x length of 3\n";
      str += "      for y length of 1\n";
      str += "         cipherMatrix[x][y] is 0\n";
      str += "            for z length of 3\n";
      str += "               cipherMatrix[x][y] +=\n"; 
      str += "               keyMatrix[y][z] * plainTextVector[z][y];\n";
      str += "            cipherMatrix[x][y] %= 26\n";
      // The decrypt pseudocode
      str += "decrypt(cipherMatrix[][1], keyMatrix[][3], plainTextVector[][1])\n";
      str += "   Inverse the Matrix <- InverseMatrix()\n";
      str += "      For x = 0 to 2\n";
      str += "         For y = 0 to 0\n";
      str += "            for z 0 to 2\n";
      str += "               cipherMatrix %= 26 + 65\n";
      // Get the Key Matrix
      str += "getMatrix(passwork, keyMatrix)\n";
      str += "   a = 0\n";
      str += "   for i 0 to 3\n";
      str += "      for j 0 to 3\n";
      str += "        keyMatrix = password % 65\n";
      str += "        a++\n";
      // Get Hill Cypher
      str += "hillCypher(plainText, password)\n";
      str += "   keyMatrix and plainTextVector\n";
      str += "   for 0 to 3\n";
      str += "      plainTextVector = plainText % 65\n";
      str += "   encrypt function\n";
      str += "   for 0 to 3\n";
      str += "      cipherText += cipherMatrix + 65\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * Encrypts message using Hill cypher
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
       std::string cipherText = "";
       int keyMatrix[100][100];
       int cipherMatrix[100][1];
       int n = plainText.length();
       int messageVector[100][1];
       getKeyMatrix(password, keyMatrix, n);
     
       // Get Message Vector
       for (int i = 0; i < n; i++)
       {
          messageVector[i][0] = (plainText[i]) % 65;
       }

       //Encrypt plainText
       for (int i = 0; i < n; i++)
       {
          for (int j = 0; j < 1; j++)
          {
       	     cipherMatrix[i][j] = 0;
               for (int a = 0; a < n; a++)
     	       {
                  cipherMatrix[i][j] += keyMatrix[i][a] * messageVector[a][j];
               }

               cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
          } 
       }
     
     
     	// Get cipher text
      for (int i = 0; i < n; i++)
      {
         cipherText += cipherMatrix[i][0] + 65;
      }
      
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
      // TODO - Add your code here
      return plainText;
   }
   
   private:
      void getKeyMatrix(std::string key, int keyMatrix[][100], int size)
      {
      	int k = 0;
      	for (int i = 0; i < size; i++)
      	{
      		for (int j = 0; j < size; j++)
      		{
      			if (k <= key.length())
      			{
      				keyMatrix[i][j] = (key[k]) % 65;
      				k++;
      			}
      		
      		}
      	}
      }
};

#endif // CIPHER06_H
