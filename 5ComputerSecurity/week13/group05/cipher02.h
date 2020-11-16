/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

using namespace std;
#include <cstring>
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Rick Johnson"; }
   virtual std::string getCipherName()  { return "Beaufort Cipher"; }
   virtual std::string getEncryptAuth() { return "Jonathan Carlson"; }
   virtual std::string getDecryptAuth() { return "Elias Ramirez"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string citation = "Lyon, J. 2012, Practical Cryptology,\" Beaufort Ciper\",[online]Available: http://practicalcryptography.com/ciphers/beaufort-cipher/";  
      return citation;
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
      str += "   /*Before Encryption can begin, the password must be the same length of text*/\n";
      str += "   while (password.length() < plainText.length())\n";
	    str += "   {\n";
      str += "      password += password[index];\n";
		  str += "      index++;\n";
    	str += "   }\n";
      str += "   for\n";
      str += "   {\n";
      str += "      cipherText[i] = (plaintext[i] - password[i]) mod(possible characters) + (minimum Character value)\n";
      str += "   }\n";
      str += "   def encrypt_or_decrypt(key, input_txt):\n";
      str += "   output_txt = []\n";
      str += "  for pos in range(0, len(input_txt)):\n";
      str += "     letter_row = 'A'\n";
      str += "     letter_txt = input_txt[pos]\n";
      str += "     while letter_txt != key[pos%len(key)]:\n";
      str += "        letter_txt = chr((ord(letter_txt)-ord('A')+1)%26\n";
      str += "                     + ord('A'))\n";
      str += "        letter_row = chr((ord(letter_row)-ord('A')+1)%26\n";
      str += "                     + ord('A'))\n";
      str += "     output_txt.append(letter_row)\n";
      str += "     return ''.join(output_txt)\n";
      str += "     RETURN cipherText\n\n";

      // The decrypt pseudocode
      str +=  "decrypt(plainText, password)\n";
      str += "   /*Before Encryption can begin, the password must be the same length of text*/\n";
      str += "   while (password.length() < cipherText.length())\n";
	    str += "   {\n";
      str += "      password += password[index];\n";
		  str += "      index++;\n";
    	str += "   }\n";
      str += "   for\n";
      str += "   {\n";
      str += "      for the length of the original text message\n";
      str += "         set orig_text[i] = (orig_text[i] + key[i] + 94) % 94\n";
      str += "      if orig_text[i] == 64, write a space.\n";
      str += "    else {\n";
      str += "      int y = orig_text[i]\n";
      str += "      int charValue = y + 62\n";
      str += "    check for value greater than max character value of 126\n";
      str += "		if (charValue > 126)\n";
      str += "      charValue = charValue % 94\n";
      str += "      orig_text[i] = (char)charValue\n";
      str += "    RETURN orig_text\n\n";

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
      std::string key = password;
      int index = 0;
	
      // Here we have to obtain a key by repeating the given key till its length 
      // becomes equal to original message length.
      while ( key.length() < plainText.length())	
      {
         key += key[index];
         index++;
      }

      // encrytion of data Ei = (Pi - Ki) mod 94 + min character value
      for (int i = 0; i < plainText.length(); i++)
      {
         cipherText[i] = (cipherText[i] - key[i]) % 94 + 32 ;
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
		//Declaration
		string orig_text = cipherText;
		std::string key = password;
		int index = 0;
		
		// Here we have to obtain a key by repeating the given key till its length 
		// becomes equal to original message length.
		while (key.length() < cipherText.length()){
			key += key[index];
			index++;
		}

		
		// encrytion of data Ei = (Pi - Ki +94) mod 94 + 64
		for (int i = 0; i < orig_text.length(); i++)
		{
			orig_text[i] = (orig_text[i] + key[i] + 94) % 94;
			// if value is 64 space character        
			if (orig_text[i] == 64)
				orig_text[i] = ' ';
			else
			{
				// next two lines are for number char vlaues 
				// only way I could get it to work
				int y = orig_text[i];
				int charValue = y + 62;
				// if value is greater than the max character value 
				// mod 94 to get correct char value 
				if (charValue > 126)
					charValue = charValue % 94;
				orig_text[i] = (char)charValue;
			}
		}
	
		return orig_text;
	}
};

#endif // CIPHER02_H
