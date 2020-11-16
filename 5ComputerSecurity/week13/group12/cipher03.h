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
   virtual std::string getPseudoAuth()  { return "Reed Harston"; }
   virtual std::string getCipherName()  { return "Rail Fence"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string citation;
      citation = "Rodriguez-Clark, Daniel, Crypto Corner, ";
      citation += "\"Rail Fence Cipher\", \n retrieved: ";
      citation += "https://crypto.interactive-maths.com/rail-fence-cipher.html\n";

      return citation;
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
      str =  "Get PlainText\n";
      str += "Get key (the number of rails)\n";
      str += "Remove spaces from PlainText\n";
      str += "Make PlainText uppercase\n";
      str += "\n";
      str += "NumberOfRows = key\n";
      str += "NumberOfColumns = len(PlainText)\n";
      str += "Direction = down\n";
      str += "CurrentRow = 0\n";
      str += "CipherText = empty string\n";
      str += "\n";
      str += "CipherArray = an array with NumberOfRows rows of NumberOfColumns length each\n";
      str += "Pre-fill cipher array with a known character that won’t be in PlainText (space or newline would work)\n";
      str += "\n";
      str += "// Fill the cipher array\n";
      str += "For i = 0; i < NumberOfColumns; i++\n";
      str += "	 CipherArray[CurrentRow][i] = PlainText[i]\n";
      str += "\n";
      str += "	 If CurrentRow is first row\n";
      str += "    set direction to down\n";
      str += "	 Else if CurrentRow is last row\n";
      str += "    set direction to up\n";
      str += "\n";
      str += "  If direction is down\n";
      str += "    Increment CurrentRow by one\n";
      str += "  Else\n";
      str += "    Decrement CurrentRow by one\n";
      str += "\n";
      str += "// Read the array out to final cipher text\n";
      str += "For character in CipherArray // Go through each value row by row\n";
      str += "	 if character is not the pre-filled character\n";
      str += "		append character to CipherText\n";


      // The decrypt pseudocode
      str += "Decrypt:\n";
      str += "Get CipherText\n";
      str += "Get key (number of rails)\n";
      str += "\n";
      str += "NumberOfRows = key\n";
      str += "NumberOfColumns = len(CipherText)\n";
      str += "Direction = down\n";
      str += "CurrentRow = 0\n";
      str += "PlainText = empty string\n";
      str += "\n";
      str += "CipherArray = an array with NumberOfRows rows of NumberOfColumns length each\n";
      str += "Pre-fill cipher array with a known character that won’t be in CipherText (space or newline would work)\n";
      str += "\n";
      str += "Index = 0\n";
      str += "\n";
      str += "// Fill the cipher array\n";
      str += "For i = 0; i < NumberOfColumns; i++\n";
      str += "	 CipherArray[CurrentRow][i] = CipherText[Index]\n";
      str += "	 Increment Index by 1\n";
      str += "\n";
      str += "  If CurrentRow is first row\n";
      str += "    set direction to down\n";
      str += "  Else if CurrentRow is last row\n";
      str += "    set direction to up\n";
      str += "\n";
      str += "	 If direction is down\n";
      str += "    Increment CurrentRow by one\n";
      str += "  Else\n";
      str += "    Decrement CurrentRow by one\n";
      str += "\n";
      str += "// Read the array out to final plain text\n";
      str += "For character in CipherArray // Go through each value row by row\n";
      str += "	 if character is not the pre-filled character\n";
      str += "		append character to PlainText\n";


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
      // TODO - Add your code here
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
