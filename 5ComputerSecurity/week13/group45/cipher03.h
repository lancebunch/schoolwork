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
   virtual std::string getPseudoAuth()  { return "Enos Ampaw"; }
   virtual std::string getCipherName()  { return "Transposition Cipher"; }
   virtual std::string getEncryptAuth() { return "Eric Mathusek"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("https://crypto.interactive-maths.com/simple-transposition-ciphers.html");
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
        str += "encrypt(plainText, password)\n";
        str += "calculate column of the matrix*/(key.length())";
        str += "calculate Maximum row of the matrix*/row = plainText.length()/col";
        str += "if(plainText.length() % col) ; row +=1(add a row)";
        str += "Adding the padding character '_' */ matrix[i][j] = '_'";
        str += "if(isalpha(plainText[k]) || plainText[k]==' ') -> add only space and alphabet in matrix";
        str += "if matrix is alpha -> cipherText += matrix[i][j]";
        str += "RETURN cipherText\n\n";


      // The decrypt pseudocode
        str += "decrypt(cipherText, password)\n";
        str += "col ->key.length";
        str += "row ->cipherText.length()/col";
        str += "cipherTextMat[i][j] -> cipherText[k++]; ";
        str += "deccipherText[i][k]->cipherTextMat[i][j]; ";
        str += "if(deccipherText[i][j] != '_') ; plainText+=decipherText[i][j]";
        str += "RETURN plainText\n\n";

      //Main Function                                                                                                                                                                                   
      str += " def main():\n";
      str += "    message = 'MY NAME IS ENOS'\n";
      str += "    password = 'SECRET'\n";
      str += "    print(\"Encrypted Text =\", cipherText)\n";                                                                                                                         
      str += "    print(\"plainText =\", plainText)\n";
      str += "      return str;\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * Implementation of the Transposition Cipher
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText = plainText;
//      std::string encrypt(std::string plainText, int key)
//      {
//         // Key = rows & length(plainText) = columns
//         char matrix[key][(plainText.length())];
//
//         // Fill matrix to distinguish filled spaces from blank ones
//         for (int i=0; i < key; i++)
//            for (int j = 0; j < plainText.length(); j++)
//                  matrix[i][j] = '\n';
//
//         // Find the direction
//         bool move_down = false;
//         int row = 0, col = 0;
//
//         for (int i=0; i < plainText.length(); i++)
//         {
//            // Checks direction of movement
//            if (row == 0 || row == key-1)
//                  move_down = !move_down;
//
//            // Fill corresponding alphabet
//            matrix[row][col++] = plainText[i];
//
//            // Find next row
//            move_down?row++ : row--;
//         }
//
//         // Construct cipher using matrix
//         string cipherText;
//         for (int i=0; i < key; i++)
//            for (int j=0; j < plainText.length(); j++)
//                  if (matrix[i][j]!='\n')
//                     cipherText.push_back(matrix[i][j]);
      
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
};

#endif // CIPHER03_H
