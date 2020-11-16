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
   virtual std::string getPseudoAuth()  { return "Alec Kaasa"; }
   virtual std::string getCipherName()  { return "Running Key Cipher"; }
   virtual std::string getEncryptAuth() { return "Jessica Smith"; }
   virtual std::string getDecryptAuth() { return "Jessica Smith"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("'Running Key Cipher.' Practical Cryptography, Practical Cryptography, 2012, practicalcryptography.com/ciphers/classical-era/running-key/.");
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
      str += "   IF password length < input length\n";
      str += "      Print 'The encryption password must be longer than the message.'\n";
      str += "      Exit program\n";
      str += "   ENDIF\n";
      str += "   Initialize passwordIt string::iterator\n";
      str += "   Initialize plainTextIt string::iterator\n";
      str += "   cipherText <- ''\n";
      str += "   FOR i is all values of password, j is all values of plainText\n";
      str += "      Remove non-letters\n";
      str += "      cipherText += ( ( j - 'a' ) + ( i - 'a' ) ) % 26 + 'a'\n";
      str += "      Increment both iterators\n";
      str += "   ENDFOR\n";
      str += "   RETURN cipherText\n\n";
       
      // The decrypt pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   Initialize passwordIt string::iterator\n";
      str += "   Initialize cipherTextIt string::iterator\n";
      str += "   plainText <- ''\n";
      str += "   FOR i is all values of password, j is all values of cipherText\n";
      str += "      plainText += ( ( j - 'a' ) - ( i - 'a' ) + 26) % 26 + 'a'\n";
      str += "      Increment both iterators\n";
      str += "   ENDFOR\n\n";
      str += "   RETURN plainText\n\n";

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
      std::string tempText = plainText;
      
      if(password.length() < plainText.length()) 
      {
        cipherText = "The encryption password must be longer than the message.\n";
        return cipherText;
      }
      
      auto passIt = password.begin();
      auto msgIt = tempText.begin();
      
      for(passIt, msgIt; passIt != password.end(),msgIt != tempText.end();)
      {
        //remove non-letters
        if(!isalpha((char)*msgIt))
        { 
          std::cout << "Found a non-Alpha char in encrypt\n";
          //tempText.erase(msgIt);
          msgIt++;
          continue;
          
        }

          cipherText += ((*msgIt - 'a') + (*passIt - 'a')) % 26 + 'a';
       passIt++;
       msgIt++; 
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
      std::string plainText = "";
      std::string tempText = cipherText;
      
      auto passIt = password.begin();
      auto msgIt = tempText.begin();
      
      for(passIt, msgIt; msgIt < tempText.end();)
      {
        plainText += ((*msgIt - 'a') - (*passIt - 'a')+ 26) % 26 + 'a';
        passIt++;
       msgIt++;
      }
      
      return plainText;
   }
};

#endif // CIPHER01_H
