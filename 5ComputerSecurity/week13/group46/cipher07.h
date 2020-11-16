/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER07_H
#define CIPHER07_H

#include <string>

//using namespace std;

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher07 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Gage Mikos"; }
   virtual std::string getCipherName()  { return "Vigenere"; }
   virtual std::string getEncryptAuth() { return "Jonathon Dawson"; }
   virtual std::string getDecryptAuth() { return "Marius Corca"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("citation");
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
      str =  "Encryption\n";
      str += "The plaintext(P) and key(K) are added modulo 26.\n";
      str += "Ei = (Pi + Ki) mod 26\n";
      str += "\n";
      
      str += "encrypt(text, password)\n";
      str += "{\n";
      
      // password needs to repeat itself until it is the same size of text
      str += "FOR increment EQUALS size of password WHILE size of text is GREATER THAN increment, increment by 1\n";
      str += "    Password EQUALS password PLUS password at increment MODULUS size of password\n";
      str += "    (password += password[i%password.size()])\n";
      str += "\n";
      
      // alphabet will be in a string for use of string.find()
      str += "SET a string of the alphabet to {all Lowercase Letters then all Uppercase Letters then all Numbers then all Symbols} \n";
      str += "DECLARE string for encrypted text\n";
      str += "\n";
      
      // look up string.find() if not familiar with it, this loop creates the encrypted string    
      str += "FOR increment EQUALS 0 WHILE size of text is GREATER THAN increment, increment by 1\n";
      str += "	  SET int to (alphabet string find text at increment) PLUS (alphabet string find password at increment)\n";      
      // string.find() returns position of passed value beginning from 0, if we call this member function twice we will be short by 1 from the corresponding alphabet location
      str += "    int EQUALS int PLUS 1\n";
      str += "    int EQUALS int MODULUS size of alphabet string\n";
      str += "    Encrypted text EQUALS encrypted text PLUS alphabet string at int\n";
      str += "\n";
      
      str += "RETURN encrypted text\n";
      str += "\n";
      str += "\n";
      str += "\n";



      // The decrypt pseudocode
      str += "Decryption\n";
      str += "The plaintext(P) and key(K) are added modulo 26.\n";
      str += "Di = (Ei - Ki + 26) mod 26\n";
      str += "\n";
      
      str += "decrypt(encrypted text, password)\n";
      str += "{\n";
      // password needs to repeat itself until it is the same size of encrypted text
      str += "FOR increment EQUALS size of password WHILE size of encrypted text is GREATER THAN increment, increment by 1\n";
      str += "    Password EQUALS password plus password at increment modulus size of password\n";
      str += "    (password += password[i%password.size()])\n";
      str += "\n";
      
      // alphabet will be in a string for use of string.find(), elements must be in same order as encrypt
      str += "SET a string of the alphabet to {all Lowercase Letters then all Uppercase Letters then all Numbers then all Symbols} \n";
      str += "Declare string of plain text\n";
      str += "\n";
      
      // look up string.find() if not familiar with it, this loop creates the encrypted text  
      str += "FOR increment EQUALS 0 WHILE size of encrypted text is GREATER THAN increment, increment by 1\n";
      str += "	  SET int to (alphabet string find encrypted text at increment) MINUS (alphabet string find password at increment)\n";
      // string.find() returns position of passed value beginning from 0, if we call this member function twice we will be short by 1 from the corresponding alphabet location
      str += "    int EQUALS int PLUS 1\n";
      str += "    int EQUALS int PLUS size of alphabet string\n";
      str += "    int EQUALS int MODULUS size of alphabet string\n";
      str += "    plain text EQUALS plain text PLUS alphabet string at int\n";
      str += "\n";
      
      str += "Return plain text\n";

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
      
      // alphabet will be in a string for use of string.find()
      const std::string placements= "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 !\"#$%&\'()*+,-./:;<=>?[\\]^_`{|}~";
      const int placementsSize = placements.length();
      
      // password needs to repeat itself until it is the same size of text.
      // This way only adds on whatever is nessisary, so a long password won't grow too big
      // if it only needed 1 more char
      std::string alteredPassword = password;
      int passwordSize = alteredPassword.length();
      for(int i = password.length(); plainText.length() >= i; i++){
         char repeatChar = password[i % passwordSize];
         alteredPassword.push_back(repeatChar);
      }
      
      // look up string.find() if not familiar with it, this loop creates the encrypted string    
      for(int i = 0; plainText.length() > i; i++){
         int spot = placements.find(plainText[i]) + placements.find(alteredPassword[i]);
         // string.find() returns position of passed value beginning from 0, if we call this member function twice we will be short by 1 from the corresponding alphabet location
         spot++;
         spot = spot % placementsSize;
         cipherText.push_back(placements[spot]);
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
      char repeatChar = ' ';
      string alteredPassword = password;
      int passwordSize = alteredPassword.length();
      int spot = 0;

      // password needs to repeat itself until it is the same size of encrypted text
      for(int i = password.length(); i <= cipherText.length(); i++)
      {
         repeatChar = password[i % passwordSize];
         alteredPassword.push_back(repeatChar);
      }

      // alphabet will be in a string for use of string.find(), elements must be in same order as encrypt
      const std::string placements= "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 !\"#$%&\'()*+,-./:;<=>?[\\]^_`{|}~";
      const int placementsSize = placements.length();

      // look up string.find() if not familiar with it, this loop creates the encrypted string    
      for(int i = 0; i <= cipherText.length(); i++){
         spot = placements.find((cipherText[i]) + placements.find(password[i]) % placementsSize);

      // string.find() returns position of passed value beginning from 0, if we call this member function twice we will be short by 1 from the corresponding alphabet location
         spot++;
         spot = spot % placementsSize;
         plainText.push_back(placements[spot]);
      
      }
      

      return plainText;
   }
};

#endif // CIPHER07_H
