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
   virtual std::string getPseudoAuth()  { return "Andrew Jester"; }
   virtual std::string getCipherName()  { return "Bifid Cipher"; }
   virtual std::string getEncryptAuth() { return "Ian Stubbs"; }
   virtual std::string getDecryptAuth() { return "Michael Wilkins"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("Practical Cryptography, \"Bifid Cipher\"[Online]Available: http://practicalcryptography.com/ciphers/classical-era/bifid/");
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

      str = "encrypt(plainText, Password)";
      str += "   //set key\n";
      str += "   keySquare[5][5]\n";
      str += "   setKeySquare(password, keySquare)\n";
      str += "   //make local variables\n";
      str += "   rowGroup = \"\"\n";
      str += "   colGroup     = \"\"\n";
      str += "   cipherString = \"\"\n";
      str += "   cipherNumArray:string\n";
      str += "   //create cipher numbers\n";
      str += "   for(i = 0; i < plainText.size; i++)\n";
      str += "      letter = plaintext[i]\n";
      str += "         //find letter row, col numbs\n";
      str += "        for(row = 0; row < 5; row++)\n";
      str += "            for(col = 0; col < 5; col++)\n";
      str += "                if(keySquare[row][col] == letter)\n";
      str += "                    if(rowGroup.size < 5) //separate into groups of 5\n";
      str += "                        rowGroup += row\n";
      str += "                        colGroup += col\n";
      str += "                    else //create groups of 10 with row + col\n";
      str += "                        cipherNumArray.push(rowGroup += colGroup)\n";
      str += "                        rowGroup = \"\"\n";
      str += "                        colGroup = \"\"\n";
      str += "                        rowGroup += row\n";
      str += "                        colGroup += col\n";
      str += "        //convert back to letters\n"; 
      str += "        for(i = 0 i < cipherNumArray.size; i+=2)\n";
      str += "            fiveLetterGroup =  cipherNumArray\n";
      str += "            for(i = 0; i < fiveLetterGroup.size; i++)\n";
      str += "                cipherString += keySquare[i][i+1]\n";
      str += "                if (i == 9)\n";
      str += "                    cipherString += \" \"\n";
      str += "        return cipherString\n\n\n";
      
         
         

      // The decrypt pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   //set key\n";
      str += "   keySquare[5][5]\n";
      str += "   setKeySquare(password, keySquare)\n";

      str += "   rowArray\n";
      str += "   colArray\n";
      str += "   plaintext = \"\"\n";
      str += "   //turn cipher text to cipher numbers\n";
      str += "   while(!cipherText != end)\n";
      str += "    fiveLetters = getNextFiveValues(cipherText)\n";
      str += "    numGroup = \"\"\n";
      str += "    for(i = 0; i < 5; i++){\n";
      str += "        index = findLetterIndex(fiveLetters[i])\n";
      str += "        numbGroup += index.row\n";
      str += "        numbGroup += index.col\n";
      str += "    }\n";

      str += "    //first five numbs\n";
      str += "    rowArray.push(numGroup[0]->numbGroup[4])\n";
      str += "    //last five numbs\n";
      str += "    colArray.push(numGroup[5]->numbGroup[9])\n";

      str += "    //get plain text\n";
      str += "    for(i = 0 i < rowArray.size)\n";
      str += "        letter = findletter(rowArray[i], colArray[i])\n";
      str += "        plainText += letter\n";

      str += "   return plainText\n\n\n";


      str += "setKeySquare(key, &array)\n";
      str += "   row = 0\n";
      str += "   col = 0\n";
    
      str += "   for(i = 0; i < 25; i++)\n"; 
      str += "      array[row][col] = key[i]\n";
      str += "      if(row < 5)\n";
      str += "          row++\n";
      str += "      else\n";
      str += "           row = 0\n";
      str += "           col++\n";
      
      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText, 
                               const std::string & password)
   {
      string cipherTextTemp = "";
      string cipherText = "";
      char keySquare[5][5];
      
      int len = plainText.length();
      int r = 0;
      int c = 0;
      
      for (int i = 0; i < len; i++)
      {
        if (plainText[i] != 'j'; 
        {
          keySquare[r][c++] = plainText[i]
          if(c % 5 == 0)
          {
            r++;
            c = 0;
          }
        }
      }
      
      for (int i = 0; i < 5; i++)
      {
        for (int j = 0; j < 5; j++)
        {
          cipherTextTemp += getString(keySquare[i][j]);
        }
      }
      
      for (i = 0; i < cipherTextTemp.length(); i += 2)
      {
        cipherText += getString(cipherTextTemp[i]);
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

      string cipherText;

      int row = 5;
      int col = 5

      char keySquare[row][col];
      

      int rowArray;
      int colArray;
      
      string fiveLetters;

      string getNextFiveValues;

      string plainText = " ";

      while (cipherText.length() != cipherText.end())
      {
         fiveLetters = getNextFiveValues(cipherText[i]);
         int numGroup = " "

         for (int i = 0; i < 5; i++)
         {
           int numbGroup
           string index = findLetterIndex(fiveLetters[i]);
           numbGroup += index.row;
           numbGroup += index.row;
         }
      }

      rowArray.push(numGroup[0]->numbGroup[4])
      colArray.push(numGroup[5]->numbGroup[9])

      for(int i = 0; i < rowArray.size; i++)
      {
        char letter = findLetter(rowArray[i], colArray[i]);
        plainText += letter;
      }
      

      return plainText;
   }
};

#endif // CIPHER01_H
