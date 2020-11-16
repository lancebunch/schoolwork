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
   virtual std::string getPseudoAuth()  { return "Jonathan Smith"; }
   virtual std::string getCipherName()  { return "VIC Cipher"; }
   virtual std::string getEncryptAuth() { return "Sam Gay"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string str;

      str  = "[1] KK, ";
      str += "\"VIC Cipher,\" crypto-it.net.";
      str += "[Online]. Available: ";
      str += "http://www.crypto-it.net/eng/simple/vic.html?tab=1.\n\n";

      str += "[2] \"VIC Cipher,\" en.wikipedia.org.";
      str += "[Online]. Available: ";
      str += "https://en.wikipedia.org/wiki/VIC_cipher.\n\n";

      return str;
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
      str += "    cipherText = new string\n";
      str += "    key = pass2Key(password)\n";
      str += "    // The first two '_' are null placeholders\n";
      str += "    vicArray = _ 0 1 2 3 4 5 6 7 8 9\n";
      str += "               _ u a e t s i v l h o\n";
      str += "     key index 0 . / ! # @ % & * ^ \\\n";
      str += "     key index 1 r n q p f c z b x y\n";
      str += "     key index 2 < > ? | { } [ ] - _\n";
      str += "     key index 3 m w g d k j   = + ~\n";
      str += "     key index 4 ( ) ` ' ; : , \"\n";
      str += "    for index = 0 to (length of plainText)\n";
      str += "       x, y = vicArray pos of plainText at index\n";
      str += "       num1 = vicArray at indices x and 0\n";
      str += "       num2 = vicArray at indices 0 and y\n";
      str += "       code = num2 concat num1\n";
      str += "       cipherText += code to ascii character\n";
      str += "    return cipherText\n\n";

      // The decrypt pseudocode
      str +=  "decrypt(cipherText, password)\n";
      str += "    plainText = new string\n";
      str += "    key = pass2Key(password)\n";
      str += "    vicArray = same as encryption array\n";
      str += "    for index = 0 to (length of cipherText)\n";
      str += "       code = cipherText to ascii code\n";
      str += "       y, x = code split into first and second digits\n";
      str += "       if x is null\n";
      str += "          x = 1\n";
      str += "       else\n";
      str += "          x = vicArray index of x in column 0\n";
      str += "       plainText = vicArray at indices x and (y + 1)\n";
      str += "    return plainText\n\n";

      // Helper function
      str += "pass2Key(password)\n";
      str += "    key = new int array of zeros\n";
      str += "    for index = 0 to (length of password)\n";
      str += "       key (index % 5) = key (index % 5) +\n"; 
      str += "           (password index to ascii code) % 10\n";
      str += "    return key\n";

      return str;
   }
   
   /**********************************************************
    * PASS2KEY
    * Description: Create key index based on password.
    **********************************************************/
  virtual int* pass2Key(const std::string & password)
  {
      int sizePassword = password.length();
      int sizeKey = 5;
      //key = new int array of zeros;
      static int* key = new int[sizeKey];
      for(int i=0; i<sizeKey; i++){ key[i] = 0; }
      
      //for index = 0 to (length of password)
      for(int i=0; i<sizePassword; i++){
        //key(index % 5) = key(index % 5) + (password index to ascii code) % 10;
        key[i%5] = key[i%5] + (int(password[i])) % 10;
      }
      
      //return key
      return key;
  }

   /**********************************************************
    * ENCRYPT
    * Description: Encrypt the plaintext based on x,y coordinates
    * in a lookup table.
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      //cipherText = new string;
      std::string cipherText = ""; 
      int sizePlainText = plainText.length();    
      int num1 = 0, num2 = 0, code;
      //key = pass2Key(password);
      int* key = pass2Key(password);
      
      //The first two '_' are null placeholders;
      //vicArray =  _ 0 1 2 3 4 5 6 7 8 9
      //            _ u a e t s i v l h o
      //  key index 0 . / ! # @ % & * ^ \
      //  key index 1 r n q p f c z b x y
      //  key index 2 < > ? | { } [ ] - _
      //  key index 3 m w g d k j   = + ~
      //  key index 4 ( ) ` ' ; : , "  
      char vicArray[7][11] = {
        {         ' ', '0', '1', '2',  '3', '4', '5', '6', '7', '8',  '9'}, 
        {         ' ', 'u', 'a', 'e',  't', 's', 'i', 'v', 'l', 'h',  'o'}, 
        {char(key[0]), '.', '/', '!',  '#', '@', '%', '&', '*', '^', '\\'},
        {char(key[1]), 'r', 'n', 'q',  'p', 'f', 'c', 'z', 'b', 'x',  'y'},
        {char(key[2]), '<', '>', '?',  '|', '{', '}', '[', ']', '-',  '_'},
        {char(key[3]), 'm', 'w', 'g',  'd', 'k', 'j', ' ', '=', '+',  '~'},
        {char(key[4]), '(', ')', '`', '\'', ';', ':', ',', '"'}        
      };
      
      //for index = 0 to (length of plainText);
      for(int i=0; i<sizePlainText; i++){
        for(int y=1; y<11; y++){ //column
          for(int x=1; x<7; x++){ //row
            //x, y = vicArray pos of plainText at index;
            if(vicArray[x][y] == plainText[i]){
              //num1 = vicArray at indices x and 0;
                  if(vicArray[x][0] != ' '){
                num1 += vicArray[x][0];
              }              
              //num2 = vicArray at indices 0 and y;
              num2 += vicArray[0][y];
              //code = num2 concat num1;
              code = num2 + num1;
              //cipherText += code to ascii character;
              cipherText += char(code);
            }            
          }
        }
      }
      
      //return cipherText;   
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

#endif // CIPHER06_H
