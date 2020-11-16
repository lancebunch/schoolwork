/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER05_H
#define CIPHER05_H

#include <iostream>
#include <string>

using namespace std;
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher05 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Avery Reed"; }
   virtual std::string getCipherName()  { return "rail fence"; }
   virtual std::string getEncryptAuth() { return "Matthew Wilson"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation() {
      std::string s;
      s += "PracticalCryptography.com (2012), ";
      s += "\"Classical Era - Rail Fence\", \n   retrieved: ";
      s += "\n  http://practicalcryptography.com/ciphers/classical-era/rail-fence$";
      s += "rail fence";
      return s;
   }

   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode() {
      std::string str;

      // TODO: please format your pseudocode
      // The encrypt pseudocode

      str =  "encryption pseudocode\n";
str += "string encrypt(string plainText, int password) \n";
str += "	char rail[password][(plainText.length())]\n";
str += "	bool direction = false\n";
str += "	int r = 0, c = 0\n";
str += "	for (int i=0; i < password; i++) \n";
str += "		for (int k = 0; k < plainText.length(); k++) \n";
str += "			rail[i][k] = 'x'\n"; 
str += "	for (int i=0; i < plainText.length(); i++)\n  ";
str += "		if (r == 0 || r == password-1) \n";
str += "			direction = !direction\n"; 
str += "		rail[r][c++] = plainText[i]\n"; 
str += "		if(direction) r++ else r--\n"; 
str += "	string cipherText\n"; 
str += "	for (int i=0; i < password; i++)\n ";
str += "		for (int k=0; k < plainText.length(); k++)\n"; 
str += "			if (rail[i][k]!='x') \n";
str += "				cipherText.push_back(rail[i][k])\n"; 
str += "	RETURN cipherText\n"; 

      // The decrypt pseudocode
      str += "decryption pseudocode\n";
str += "string decrypt(string cipherText, int password)\n  ";
str += "	char rail[password][cipherText.length()]\n"; 
str += "	bool direction\n"; 
str += "	int r = 0, c = 0\n"; 
str += "	for (int i=0; i < password; i++)\n ";
str += "		for (int k=0; k < cipherText.length(); k++)\n"; 
str += "			rail[i][k] = 'x'\n"; 
str += "	for (int i=0; i < cipherText.length(); i++)\n  ";
str += "		if (r == 0) \n";
str += "			direction = true\n"; 
str += "		if (r == password-1) \n";
str += "			direction = false\n"; 
str += "		rail[r][c++] = 'x'\n"; 
str += "		if(direction)r++ else r--\n";
	 
str += "	int index = 0\n"; 
str += "	for (int i=0; i<password; i++)\n ";
str += "		for (int k=0; k<cipherText.length(); k++)\n"; 
str += "			if (rail[i][k] == 'x' && index<cipherText.length())\n ";
str += "				rail[i][k] = cipherText[index++]\n"; 
str += "	string plainText\n"; 
str += "	r = 0, c = 0\n"; 
str += "	for (int i=0; i< cipherText.length(); i++) \n ";
str += "		if (r == 0) \n";
str += "			direction = true\n"; 
str += "		if (r == password-1) \n";
str += "			direction = false\n"; 
str += "		if (rail[r][c] != 'x')\n"; 
str += "			plainText.push_back(rail[r][c++])\n"; 
str += "		if(direction)r++ else r--\n";
str += "	RETURN plainText\n"; 
      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
   
   
    char rail[std::stoi(password)][plainText.length()];
    bool direction = false;
    int r = 0, c = 0;
    for (int i=0; i < std::stoi(password); i++) {
        for (int k = 0; k < plainText.length(); k++) {
            rail[i][k] = 'x';
        }
    }
    for (int i=0; i < plainText.length(); i++)  {
        if (r == 0 || r == std::stoi(password)-1) {
            direction = !direction;
        }
        rail[r][c++] = plainText[i];
        if(direction) {
            r++;
        } else {
            r--;
        }
    }
    string cipherText;
    for (int i=0; i < std::stoi(password); i++) {
        for (int k=0; k < plainText.length(); k++) {
            if (rail[i][k]!='x') {
                cipherText.push_back(rail[i][k]);
            }
        }
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
      // TODO - Add your code here
      return plainText;
   }
};

#endif // CIPHER05_H
