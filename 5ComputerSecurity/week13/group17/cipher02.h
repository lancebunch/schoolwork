/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

#include <algorithm>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Jose Paredes"; }
   virtual std::string getCipherName()  { return "Affine cipher"; }
   virtual std::string getEncryptAuth() { return "Brett Jensen"; }
   virtual std::string getDecryptAuth() { return "Brett Jensen"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("Lyons J., Practical Cryptography 'Affine Cipher'\n URL: http://practicalcryptography.com/ciphers/classical-era/affine/");
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
      str =  "FUNCTION encrypt(string password, string message)\n";
      str += "    int a = getKeyA(password)\n";
      str += "    int b = getKeyB(password)\n";
      str += "    string cipher = ''\n";
      str += "    FOR i = 0 to < message.size()\n";
      str += "        cipher += (char) ((((a * (msg[i] - 32) ) + b) % 26) + 32) // add 32 to keep in range\n"; 
      str += "    END FOR\n";
      str += "    RETURN cipher\n";
      str += "END FUNCTION\n\n";

      // The decrypt pseudocode
      str += "FUNCTION decrypt(string password, string cipher)\n";
      str += "    int a = getKeyA(password)\n";
      str += "    int b = getKeyB(password)\n";
      str += "    int a_inv = 0\n";
      str += "    Int check = 0\n";
      str += "    string message = ''\n";
      str += "    FOR i = 0 to <  94\n";
      str += "        check = (a * i) mod 94\n";
      str += "        IF (check == 1)\n";
      str += "            a_inv = i\n";
      str += "            BREAK\n";
      str += "        END IF \n";
      str += "    END FOR \n";
      str += "    FOR i = 0 to < cipher.size()\n";
      str += "        message += ((char) (((a_inv * ((cipher[i] + 32 - b)) % 26)) + 32) // add 32 to keep in range\n"; 
      str += "    END FOR\n";
      str += "    RETURN message\n";
      str += "END FUNCTION\n\n";
      
      // The A key function pseudocode
      str += "FUNCTION getKeyA(string password) // create password for a using first half of password \n";
      str += "    int a = 0\n";
      str += "    FOR i = 0 to <= (password.size() / 2) // add char values of half of the password for password a\n";
      str += "        a += password[i] \n";
      str += "        IF (a > 94) // make sure it is smaller than m\n"; 
      str += "            a mod 94\n";
      str += "        END IF\n";
      str += "    END FOR\n";
      str += "    IF (__gcd(a, 94) == 1) // a must be coprime with 94\n";
      str += "        a -= 1\n";
      str += "    END IF\n";
      str += "    RETURN a\n"; 
      str += "END FUNCTION\n\n";
      
      // The B key function pseudocode
      str += "FUNCTION getKeyB(string password) // create password for b using other half of password\n"; 
      str += "int b = 0\n";
      str += "    For i = (password.size() + 1) to < password.size()\n"; 
      str += "        b += password[i]\n";
      str += "        IF (b > 94) // make sure it is smaller than m\n";
      str += "            b mod 94\n";
      str += "        END IF\n";
      str += "    END FOR\n";
      str += "    RETURN b\n";
      str += "END FUNCTION\n\n";

      return str;
   }

   int getKeyA(std::string password)
   {
	   int a = 0;

	   for (int i = 0; i <= password.size() / 2; i++)
	   {
		   a += password[i];
		   if (a > 94)
			   a %= 94;
	   }
	   if (std::__gcd(a, 94) != 1)
		   a -= 1;

	   return a;
   }

   int getKeyB(std::string password)
   {
	   int b = 0;

	   for (int i = password.size() / 2 + 1; i < password.size(); i++)
	   {
		   b += password[i];
		   if (b > 94)
			   b %= 94;
	   }

	   return b;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText = "";
      
	  int a = getKeyA(password);
	  int b = getKeyB(password);
	  std::string cipher = "";

	  for (int i = 0; i < plainText.size(); i++)
	  {
		  cipherText += (char)((((a * (plainText[i] - 32)) + b) % 94) + 32);
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
      
	  int a = getKeyA(password);
	  int b = getKeyB(password);
	  int a_inv = 0;
	  int check = 0;

	  for (int i = 0; i < 94; i++)
	  {
		  check = (a * i) % 94;
		  if (check == 1)
		  {
			  a_inv = i;
			  break;
		  }
	  }

	  for (int i = 0; i < cipherText.size(); i++)
	  {
		  //cipherText[i] - 32 - b may be negative... make it positive
		  check = cipherText[i] - 32 - b;
		  while (check < 0)
			  check += 94;

		  plainText += ((char)((a_inv * (check)) % 94) + 32);
	  }

      return plainText;
   }
};

#endif // CIPHER02_H
