/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER03_H
#define CIPHER03_H

#include <regex>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03 : public Cipher
{
public:
   Cipher03() {
      valueMinimum = ' ';
      valueMaximum = '~';
   }
   virtual std::string getPseudoAuth()  { return "Lina Nielsen"; }
   virtual std::string getCipherName()  { return "Rail Fence Cipher"; }
   virtual std::string getEncryptAuth() { return "Stephen Nielson"; }
   virtual std::string getDecryptAuth() { return "Sam Gay"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "GeeksforGeeks.com (2019), ";
      s += "\"Rail Fence Cipher - Encryption and Decryption\", ";
      s += "\n  retrieved: ";
      s += "https://www.geeksforgeeks.org/rail-fence-cipher-encryption-decryption/";
      s += "\nSiahaan A. P. U. (2016), ";
      s += "\"Rail Fence Cryptography in Securing Information\", \n  retrieved: ";
      s += "https://www.researchgate.net/publication/305722266_Rail_Fence_Cryptography_in_Securing_Information";
      return s;
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // The encrypt pseudocode
      str =  "encrypt(plainText, password)\n";
      str += "   plainText <- regex_replace(plainText, regex(all empty spaces), \"\")\n";
      str += "   rails <- offsetFromPassword(password)\n";
      str += "   railMatrix[rails][size of plainText]\n";
      str += "   FOR i <- each value in rails\n";
      str += "      FOR j <- each value in plainText\n";
      str += "         railMatrix[i][j] <- \".\"\n";
      str += "   row <- 0\n";
      str += "   check <- FALSE\n";
      str += "   FOR i <- each value in plainText\n";
      str += "      IF !check\n";
      str += "         railMatrix[row][i] <- plainText[i]\n";
      str += "         row is incremented\n";
      str += "         IF row equals password\n";
      str += "            check <- TRUE\n";
      str += "            row is decremented\n";
      str += "         ELSE IF check\n";
      str += "            row is decremented\n";
      str += "            railMatrix[row][i] <- plainText[i]\n";
      str += "            IF row equals 0\n";
      str += "               check <- FALSE\n";
      str += "               row <- 1\n";
      str += "   cipherText <- \"\"\n";
      str += "   FOR i <- each value in rails\n";
      str += "      FOR j <- each value in plainText\n";
      str += "         cipherText += railMatrix[i][j]\n";
      str += "   cipherText <- regex_replace(cipherText, regex(all periods), \"\")\n";
      str += "   RETURN cipherText\n\n";

      // The decrypt pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   cipherText <- regex_replace(cipherText, regex(all empty spaces), \"\")\n";
      str += "   rails <- offsetFromPassword(password)\n";
      str += "   railMatrix[rails][size of cipherText]\n";
      str += "   FOR i <- each value in password\n";
      str += "      FOR j <- each value in cipherext\n";
      str += "         railMatrix[i][j] <- \".\"\n";
      str += "   row <- 0\n";
      str += "   check <- FALSE\n";
      str += "   FOR i <- each value in cipherText\n";
      str += "      IF !check\n";
      str += "         railMatrix[row][i] <- cipherText[i]\n";
      str += "         row is incremented\n";
      str += "         IF row equals password\n";
      str += "            check <- TRUE\n";
      str += "            row is decremented\n";
      str += "         ELSE IF check\n";
      str += "            row is decremented\n";
      str += "            railMatrix[row][i] <- cipherText[i]\n";
      str += "            IF row equals 0\n";
      str += "               check <- FALSE\n";
      str += "               row <- 1\n";
      str += "   order <- 0\n";
      str += "   FOR i <- each value in password\n";
      str += "      FOR j <- each value in cipherText\n";
      str += "         temp <- \"\"\n";
      str += "         temp += railMatrix[i][j]\n";
      str += "         IF (regex_match(temp, regex(all periods)))\n";
      str += "            CONTINUE\n";
      str += "         ELSE\n";
      str += "            railMatrix[i][j] <- cipherText[order]\n";
      str += "            order is incremented\n";
      str += "   plainText <- \"\"\n";
      str += "   check <- FALSE\n";
      str += "   row <- 0\n";
      str += "   FOR i <- each value in cipherText\n";
      str += "      IF !check\n";
      str += "          plainText += railMatrix[row][i]\n";
      str += "          row is incremented\n";
      str += "          IF row equals password\n";
      str += "             check <- TRUE\n";
      str += "             row is decremented\n";
      str += "      ELSE IF check\n";
      str += "         row is decremented\n";
      str += "         plainText += railMatrix[row][i]\n";
      str += "         IF row equals 0\n";
      str += "            check <- FALSE\n";
      str += "            row <- 1\n";
      str += "   plainText <- regex_replace(plainText, regex(all periods), \"\")\n";
      str += "   RETURN plainText\n\n";

      // helper routine
      str += "offsetFromPassword(password)\n";
      str += "   FOR p is all values of password\n";
      str += "     offset <- indexFromCharacter(p)\n";
      str += "   RETURN offset % size\n\n";
      return str;
   }

   /**********************************************************
    * ENCRYPT
    * Takes in a plaintext value and a password encryption key
    * and encryptes the plainText value using the Rail Fence
    * Cipher algorithm.  The password is used to compute the
    * number of rails and from there the plainText is encrypted.
    * The cipherText is then returned.
    * @params plainText a string of characters to encrypt
    * @params password an encyption key used to determine # of rails.
    * @return string the encrypted cipher text computed from the plainText
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      // plainText <- regex_replace(plainText, regex(all empty spaces), "")
      std::regex e("\\s");
      std::string pText = regex_replace(plainText, e, "");
      int rails = password.length();
   

      // railMatrix[password][size of plainText]
      char railMatrix[rails][pText.length()];
      // FOR i <- each value in password
      for (int i = 0; i < rails; i++)
      {
         // FOR j <- each value in plainText
         for (int j = 0; j < pText.length(); j++)
         {
            // railMatrix[i][j] <- "."
            railMatrix[i][j] = '.';
         }
      }

      // row <- 0
      // check <- FALSE
      int row = 0;
      bool check = false;
      // FOR i <- each value in plainText
      for (int i = 0; i < pText.length(); i++)
      {
         // IF !check
         if (!check)
         {
            // railMatrix[row][i] <- plainText[i]
            railMatrix[row][i] = pText[i];
            // row is incremented
            row++;
            // IF row equals password
            if (row == rails)
            {
               // check <- TRUE
               check = true;
               // row is decremented
               row--;
            }
         }
         // ELSE IF check
         else if (check)
         {
      
            // row is decremented
            row--;
            // railMatrix[row][i] <- plainText[i]
            railMatrix[row][i] = pText[i];
            // IF row equals 0
            if (row == 0)
            {
               // check <- FALSE
               // row <- 1
               check = false;
      
               row = 1;
            }
         }
      }
      // cipherText <- ""
      std::string cipherText = "";
      // FOR i <- each value in password
      for (int i = 0; i < rails; i++)
      {
         // FOR j <- each value in plainText
         for (int j = 0; j < pText.length(); j++)
         {
            // cipherText += railMatrix[i][j]
            cipherText += railMatrix[i][j];
         }
      }
      // cipherText <- regex_replace(cipherText, regex(all periods), "")
      std::regex period("\\.");
      cipherText = regex_replace(cipherText, period, "");
      // RETURN cipherText

      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * description: function accepts the cipher text and password
    * and populates a matrix with the cipher text based on the 
    * password parameter. The algorithm then alternates, logically,
    * between characters in the matrix to be copied to the plain
    * text string.
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText = "";
      
      //cipherText <- regex_replace(cipherText, regex(all empty spaces), "")
      std::regex emptySpace("\\s");
      std::string pText = regex_replace(plainText, emptySpace, "");
      //rails <- offsetFromPassword(password);
      int sizeCipherText = cipherText.length();
      int sizePassword = password.length();
      int rails = sizePassword;
      //railMatrix[rails][size of cipherText]
      char railMatrix[rails][sizeCipherText];
            
      //FOR i <- each value in password
      for(int i=0; i<sizePassword; i++){
        //FOR j <- each value in cipherText\n";
        for(int j=0; j<sizeCipherText; j++){
          //railMatrix[i][j] = ".";
          railMatrix[i][j] = '.';
        }
      }
      
      //row <- 0;
      //check <- FALSE;
      int row = 0;
      bool check = false;
      
      //FOR i <- each value in cipherText
      for(int i=0; i<sizeCipherText; i++){
        //IF !check\n";
        if(!check){
          //railMatrix[row][i] <- cipherText[i];
          railMatrix[row][i] = cipherText[i];
          //row is incremented;
          row++;
          //IF row equals password
          if(row == rails){
            //check <- TRUE;
            check = true;
            //row is decremented;
            row--;
          }
          //ELSE IF check\n";
          else if(check){
            //row is decremented;
            row--;
            //railMatrix[row][i] <- cipherText[i];
            railMatrix[row][i] = cipherText[i];
            //IF row equals 0
            if(row == 0){
              //check <- FALSE;
              check = false;
              //row <- 1;]
              row = 1;
            }
          }
        }
      }
      //order <- 0\n";
      int order = 0;
      
      //FOR i <- each value in password
      for(int i=0; i<sizePassword; i++){
        //FOR j <- each value in cipherText
        for(int j=0; j<sizeCipherText; j++){
          //temp <- "";
          std::string temp("");
          //temp += railMatrix[i][j];
          temp += railMatrix[i][j];
          //IF (regex_match(temp, regex(all periods)))
          std::regex period("\\.");
          if(regex_match(temp, period)){
            //CONTINUE;
            continue;
          }
          //ELSE
          else{
            //railMatrix[i][j] <- cipherText[order];
            railMatrix[i][j] = cipherText[order];
            //order is incremented;
            order++;
          }
        }
      }
      
      //plainText <- "";
      plainText = "";
      //check <- FALSE;
      check = false;
      //row <- 0;
      row = 0;
      //FOR i <- each value in cipherText\n";
      for(int i=0; i<sizeCipherText; i++){
        //IF !check
        if(!check){
        //plainText += railMatrix[row][i];
        plainText += railMatrix[row][i];
        //row is incremented;
        row++;
          //IF row equals password
          if(row == rails){
            //check <- TRUE;
            check = true;
            //row is decremented;
            row--;
          }
        }
        //ELSE IF check
        else if(check){
          //row is decremented;
          row--;
          //plainText += railMatrix[row][i];
          plainText += railMatrix[row][i];
          //IF row equals 0
          if(row == 0){
            //check <- FALSE;
            check = false;
            //row <- 1;
            row = 1;
          }
        }
      }
      //plainText <- regex_replace(plainText, regex(all periods), "");
      std::regex period("\\.");
      plainText = regex_replace(plainText, period, "");
      
      //RETURN plainText;      
      return plainText;
   }

   /**********************************************************
    * offsetFromPassword
    * Given a password string compute a numeric value to use 
    * for the rails cipher offset.
    * @param password The password string to compute the offset from.
    * @return int A numeric value representing the password
    **********************************************************/
   virtual int offsetFromPassword(const std::string & password)
   {
      // FOR p is all values of password\n";
      //    offset <- indexFromCharacter(p)\n";
      // RETURN offset % size\n\n";
      int offset = 0;
      for (std::string::const_iterator it = password.begin();
           it != password.end();
           ++it)
         offset += indexFromCharacter(*it);

      return offset % sizeAlphabet;
   }

   /**************************************************
    * INDEX FROM CHARACTER
    * Get an index value from a given letter.
    *************************************************/
   int indexFromCharacter(char letter)
   {
      // return the value
      if (letter > valueMaximum || letter < valueMinimum)
         return 0;
      else
         return (int)(letter - valueMinimum); 
   }

   // minimum "printable" character
   char valueMinimum;

   // maximum "printable" character
   char valueMaximum;

   int sizeAlphabet;
};

#endif // CIPHER03_H
