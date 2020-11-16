/********************************************************************
* Header:
*    This is a stream cipher, which means that one byte will be 
*    encrypted/decrypted at a time. First, this cipher generate the
*    state array(s[]) from the user's password and the Key-Scheduling 
*    Algorithm (KSA). Then, it either encrypts or decrypts the 
*    received text one character at a time based on the state array 
*    and the Pseudo-Random Generation Algorithm (PRGA). PRGA uses an 
*    XOR operator, therefore, it can be used to both encrypt and 
*    decrypt the text.
*
* Cipher: Rivest Cipher 4(RC4) 
********************************************************************/
#ifndef CIPHER03_H
#define CIPHER03_H
#include <string>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Daniel Hansen"; }
   virtual std::string getCipherName()  { return "Rivest Cipher 4 (RC4)"; }
   virtual std::string getEncryptAuth() { return "Ethan Rawlins"; }
   virtual std::string getDecryptAuth() { return "Dylan Doelling"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string strCite;
      strCite = "URLs:\n";
      strCite += "\thttps://www.geeksforgeeks.org/rc4-encryption-algorithm/\n";
      strCite += "\thttps://www.youtube.com/watch?v=jjjq41bGzps\n";
      strCite += "\thttps://en.wikipedia.org/wiki/RC4\n";
      strCite += "\t\t(Wikipedia wound up helping the most, I couldn't find\n";
      strCite += "\t\ta citation for the pseudo-code they provided)\n";
      strCite += "Citation Author:\n";
      strCite += "\tGeeks for Geeks: Sally Jarkas\n";
      strCite += "\tVidya-Mitra: Only found Youtube channel's name, which is\n";
      strCite += "\t\tVidya Mitra\n";
      strCite += "\tWikipedia: N/A\n";
      strCite += "Article Title:\n";
      strCite += "\tGeeks for Geeks: RC4 Encryption Algorithm\n";
      strCite += "\tVidya-Mitra: RC4\n";
      strCite += "\tWikipedia: RC4\n";
      strCite += "Date:\n";
      strCite += "\tNot Available\n";
      strCite += "\tVidya-Mitra: September 21, 2017\n";
      strCite += "\tWikipedia: November 30, 2019\n";
                
      return strCite;
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;
      
      // Please format your pseudocode
      // Other methods/member variables that will be used for both encrypt 
      // and decrypt
      str = "\n// Other necessary methods and member variables before\n";
      str += "// encryption/decryption\n";
      str += "\nint s[256];  // State array\n\n";
      str += "/***********************************************************\n";
      str += "* KEY-SCHEDULING ALGORITHM (KSA)\n";
      str += "* Generate the state array s[] based on the password and KSA\n";
      str += "* This state array will be created both to encrypt and decrypt\n";
      str += "* the data\n";
      str += "**********************************************************/\n";
      str += "void ksa(string password) {\n";
      str += "\t// Initialize s[]\n";
      str += "\tfor(int i = 0; i < 256; i++)\n";
      str += "\t\ts[index] = index;\n\n";
      str += "\t// Change s[] order using the password and KSA\n";
      str += "\tfor(int i = 0; i < 256; i++)\n\t{\n";
      str += "\t\tj = (j + s[i] + key[i mod keylength]) mod 256;\n";
      str += "\t\tswap(s[i],s[j]);\n\t}\n}\n\n";
      str += "/***********************************************************\n";
      str += "* PSEUDO-RANDOM GENERATION ALGORITHM (PRGA)\n";
      str += "* Use the generated state array and the PRGA to encrypt or\n";
      str += "* decrypt the text\n";
      str += "* Decrypt or encrypt the data one char at a time\n";
      str += "**********************************************************/\n";
      str += "string prga()\n{\n";
      str += "\tint i, j = 0;\n";
      str += "\tstring outputText[numElements in plain or cipher text];\n";
      str += "\t// Generate semi-random byte based on s[] to XOR text char\n";
      str += "\tfor (index = 0;\n";
      str += "\t\tindex < numElements in plain or cipher text;\n";
      str += "\t\tindex++)\n\t{\n";
      str += "\t\ti = (++i) mod 256;\n";
      str += "\t\tj = (j + s[i]) mod 256;\n";
      str += "\t\tswap(s[i] and s[j]);\n";
      str += "\t\tk = s[(s[i] + s[j]) mod 256];\n";
      str += "\t\tplain or cipher text[index] XOR k;\n\t}\n";
      str += "\treturn outputText;\n}\n\n";
      
      // The encrypt pseudocode
      str += "Encrypt\n";
      str += "/***********************************************************\n";
      str += "* ENCRYPT\n";
      str += "* Call ksa() to generate state array\n";
      str += "* Then call prga() to encrypt the data one char at a time\n";
      str += "**********************************************************/\n";
      str += "string encrypt(string plainText, string password) \n{\n";
      str += "\tksa(string password);\n";
      str += "\treturn prga(string plainText);\n";
      str += "}\n\n";

      // The decrypt pseudocode
      str += "Decrypt\n";
      str += "/***********************************************************\n";
      str += "* DECRYPT\n";
      str += "* Call ksa() to generate state array\n";
      str += "* Then call prga() to decrypt the data one char at a time\n";
      str += "**********************************************************/\n";
      str += "string decrypt(string cipherText, string password) \n{\n";
      str += "\tksa(string password);\n";
      str += "\treturn prga(string cipherText);\n";
      str += "}\n\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * Encrypts the plainText by calling KSA and PRGA
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText = plainText;
      ksa(password);
      
      return prga(plainText);
   }

   /**********************************************************
    * DECRYPT
    * Decrypts the cipherText by calling KSA and PRGA
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText = cipherText;
      ksa(password);
      return prga(cipherText);
      //return plainText;
   }

private:

   int s[256];

   /**********************************************************
    * SWAP
    * Swaps two integers with each other
    **********************************************************/
   void swap(int x, int y)
   {
      int z = x;
      x = y;
      y = z;
   }

   /**********************************************************
    * KSA
    * Key(password)-scheduling algorithm
    * Generate the state array s[] based on the password and KSA
    * This state array will be created both to encrypt and decrypt
    * the data.
    **********************************************************/
   void ksa(std::string pass)
   {
      int j = 0;
      for(int i = 0; i < 256; i++)
         s[i] = i;
      for(int i = 0; i < 256; i++)
      {
         j = (j + s[i] + pass[i % pass.length()]) % 256;
         swap(s[i], s[j]);
      }
   }

   /**********************************************************
    * PRGA
    * Pseudo-random generation algorithm
    * Use the generated state array and the PRGA to encrypt or
    * decrypt the text.
    * Decrypt or encrypt the data one char at a time.
    **********************************************************/
   std::string prga(std::string text)
   {
      int i, j = 0;
      std::string outputText = "";
      // Generate semi-random byte based on s[] to XOR text char
      for (int x = 0; x < text.length(); x++)
      {
         i = (++i) % 256;
         j = (j + s[i]) % 256;
         swap(s[i], s[j]);
         int k = s[(s[i] + s[j]) % 256];
         text[x] = text[x] ^ k;
      }
      outputText = text;
      return outputText;
   }
};

#endif // CIPHER03_H
