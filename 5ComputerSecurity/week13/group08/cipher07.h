/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER07_H
#define CIPHER07_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher07 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Daniel Nacher"; }
   virtual std::string getCipherName()  { return "Improved Caesar-like ciphers(I took this ideas and I made my own idea"; }
   virtual std::string getEncryptAuth() { return "Scott Sutherland"; }
   virtual std::string getDecryptAuth() { return "Scott Sutherland"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("http://www.math.stonybrook.edu/~scott/Book331/Improved_Caesar_like_cipher.html");
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
      str =  "Caesar improved V2 Pseudocode\n";

      // The decrypt pseudocode
      str += "the cipher will split the password into 4 numbers (the password should be a 4 number string split by '-'";
      str += "the function will shift each letter with the number of the array";
      str += "the function will return the new string";
      

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      vector<std::string> abc={"A","B";"C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
      std::string cipherText = plainText;
      
      std::replace(password.begin(), password.end(), '-', ' '); 

      vector<int> array;
      stringstream ss(str);
      int temp;
      while (ss >> temp)
        array.push_back(temp); 
        
      
      
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

#endif // CIPHER07_H
