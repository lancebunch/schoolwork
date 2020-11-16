/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER04_H
#define CIPHER04_H


#include <cstring>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher04 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Pseudocode Author"; }
   virtual std::string getCipherName()  { return "Playfair Cipher"; }
   virtual std::string getEncryptAuth() { return "Rick Johnson"; }
   virtual std::string getDecryptAuth() { return "Elias Ramirez"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string citation = "Kowalczyk, C. 2019, \"Learn Cryptography\", [online]Available: https://learncryptography.com/classical-encryption/playfair-cipher"; 	
      return std::string(citation);
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      str += "The encrypt pseudocode:";
      str =  "function encrypt(messageInput, keyword) {\n";
      str += "set messageOutput to empty string\n";
      str += "var pos = 0;\n";
      str += "while (pos < messageInput.length) \n";
      str += "var m1 = messageInput[pos]\n";
      str += "var m2 = ''\n";
      str += "if (pos + 1 < messageInput.length)\n";
      str += "if (messageInput[pos + 1] != m1)\n";
      str += "m2 = messageInput[pos + 1]\n";
      str += "pos += 2\n";
      str += "else \n";
      str += "m2 = 'Q' or some dummy letter\n";
      str += "pos += 1\n";
      str += "else \n";
      str += "m2 = 'Q' or some dummy letter\n";
      str += "pos += 1\n";
      str += "var c1 = m1\n";
      str += "var c2 = m2\n";
      str += "var idx1 = keyword.indexOf(m1)\n";
      str += "var idx2 = keyword.indexOf(m2)\n";
      str += "var row1 = Math.floor(idx1 / 5)\n";
      str += "var col1 = idx1 % 5\n";
      str += "var row2 = Math.floor(idx2 / 5)\n";
      str += "var col2 = idx2 % 5\n";
      str += "if ((row1 !== row2) && (col1 !== col2)) {\n";
      str += "c1 = keyword[(5 * row1) + col2]\n";
      str += "c2 = keyword[(5 * row2) + col1]\n";
      str += "} else\n";
      str += "if ((row1 !== row2) && (col1 === col2)) {\n";
      str += "c1 = keyword[(5 * ((5 + row1 + 1) % 5)) + col1]\n";
      str += "c2 = keyword[(5 * ((5 + row2 + 1) % 5)) + col1]\n";
      str += "} else\n";
      str += "if ((row1 === row2) && (col1 !== col2)) {\n";
      str += "c1 = keyword[(5 * row1) + ((5 + col1 + 1) % 5)]\n";
      str += "c2 = keyword[(5 * row1) + ((5 + col2 + 1) % 5)]\n";
      str += "} else {\n";
      str += "messageOutput = messageOutput.concat(c1)\n";
      str += "messageOutput = messageOutput.concat(c2)\n";
      str += "return messageOutput\n";

      // The decrypt pseudocode
      str += "\n\ndecryption pseudocode:\n";
      str =  "function decrypt(cipherText, keyword) {\n";
      str += "const var n = cipherText.length; \n";
      str += "const var m = keyword.length; \n";
      str += "var str [n = 1]; \n";
      str += "var key[m + 1]; \n";
      str += "strcpy (str, cipherText.c_str); \n";
      str += "strcpy(key, password.c_str); \n";
      str += "var plainText = decryptByPlayfairCipher(str, key); \n";
      str += "messageOutput = cipherText \n";
      str += "messageOutput = password\n";
      str += "messageOutput = password\n";
      str += "return plainText;\n";
   }
   

  /**********************************************************
  * GET CONVERTTOSTRING
  * converts character array to string and returns it
  **********************************************************/ 
  string convertToString(char* a, int size)
  {
     int i;
     string s = "";
     for (i = 0; i < size; i++) {
        s = s + a[i];
     }
     return s;
  }

  // Function to convert the string to lowercase 
  void toLowerCase(char plain[], int ps)
  {
     int i;
     for (i = 0; i < ps; i++) {
        if (plain[i] > 64 && plain[i] < 91)
           plain[i] += 32;
     }
  }

  // Function to remove all spaces in a string 
  int removeSpaces(char* plain, int ps)
  {
     int i, count = 0;
     for (i = 0; i < ps; i++)
        if (plain[i] != ' ')
           plain[count++] = plain[i];
     plain[count] = '\0';
     return count;
  }

  // Function to generate the 5x5 key square 
  void generateKeyTable(char key[], int ks, char keyT[5][5])
  {
     int i, j, k, flag = 0, * dicty;
  
     // a 26 character hashmap 
     // to store count of the alphabet 
     dicty = (int*)calloc(26, sizeof(int));
     for (i = 0; i < ks; i++) {
        if (key[i] != 'j')
           dicty[key[i] - 97] = 2;
     }
  
     dicty['j' - 97] = 1;
  
     i = 0;
     j = 0;
  
     for (k = 0; k < ks; k++) {
        if (dicty[key[k] - 97] == 2) {
           dicty[key[k] - 97] -= 1;
           keyT[i][j] = key[k];
           j++;
           if (j == 5) {
              i++;
              j = 0;
           }
        }
     }
  
     for (k = 0; k < 26; k++) {
        if (dicty[k] == 0) {
           keyT[i][j] = (char)(k + 97);
           j++;
           if (j == 5) {
              i++;
              j = 0;
           }
        }
     }
  }

  /**********************************************************
  * SEARCH
  * Function to search for the characters of a digraph 
  * in the key square and return their position 
  **********************************************************/ 
  void search(char keyT[5][5], char a, char b, int arr[])
  {
     int i, j;
  
     if (a == 'j')
        a = 'i';
     else if (b == 'j')
        b = 'i';
  
     for (i = 0; i < 5; i++) {
  
        for (j = 0; j < 5; j++) {
  
           if (keyT[i][j] == a) {
              arr[0] = i;
              arr[1] = j;
           }
           else if (keyT[i][j] == b) {
              arr[2] = i;
              arr[3] = j;
           }
        }
     }
  }
   
  /**********************************************************
  * MOD5
  * Function to find the modulus with 5
  **********************************************************/ 
  int mod5(int a)
  {
     return (a % 5);
  }
  
  /**********************************************************
  * PREPARE
  * Function to make the plain text length to be even 
  **********************************************************/
  int prepare(char str[], int ptrs)
  {
     if (ptrs % 2 != 0) {
        str[ptrs++] = 'z';
        str[ptrs] = '\0';
     }
     return ptrs;
  }

  /**********************************************************
  * ENCRYPT
  * Function for performing the encryption 
  **********************************************************/
  string encrypt(char str[], char keyT[5][5], int ps)
  {
     int i, a[4];
  
     for (i = 0; i < ps; i += 2) {
  
        search(keyT, str[i], str[i + 1], a);
  
        if (a[0] == a[2]) {
           str[i] = keyT[a[0]][mod5(a[1] + 1)];
           str[i + 1] = keyT[a[0]][mod5(a[3] + 1)];
        }
        else if (a[1] == a[3]) {
           str[i] = keyT[mod5(a[0] + 1)][a[1]];
           str[i + 1] = keyT[mod5(a[2] + 1)][a[1]];
        }
        else {
           str[i] = keyT[a[0]][a[3]];
           str[i + 1] = keyT[a[2]][a[1]];
        }
     }
     
     int size;
      size = strlen(str) + 1;
     return convertToString(str, size);
  }
  
  /**********************************************************
  * ENCRYPTBYPLAYFAIRCIPHER
  * Function to encrypt using Playfair Cipher  
  **********************************************************/
  string encryptByPlayfairCipher(char str[], char key[])
  {
     char ps, ks, keyT[5][5];
  
     // Key 
     ks = strlen(key);
     ks = removeSpaces(key, ks);
     toLowerCase(key, ks);
  
     // Plaintext 
     ps = strlen(str);
     toLowerCase(str, ps);
     ps = removeSpaces(str, ps);
  
     ps = prepare(str, ps);
  
     generateKeyTable(key, ks, keyT);
  
     return encrypt(str, keyT, ps);
  }

   /**********************************************************
    * ENCRYPT
    * passes plaintext and password to encrytion function
    * returns the encrypted text
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {

     const int n = plainText.length();
     const int m = password.length();
  
     // declaring character array 
     char str[n + 1];
     char key[m + 1];
  
     // copying the contents of the a
     // string to char array 
     strcpy(str, plainText.c_str());
     strcpy(key, password.c_str());
  
     // encrypt using Playfair Cipher 
     std::string cipherText = encryptByPlayfairCipher(str, key);

     return cipherText;
   }
   
//// Function for performing the encryption 
string decrypt(char str[], char keyT[5][5], int ps)
{
   int i, a[4];

   for (i = 0; i < ps; i += 2) {

      search(keyT, str[i], str[i + 1], a);

      if (a[0] == a[2]) {
         str[i] = keyT[a[0]][mod5(a[1] - 1)];
         str[i + 1] = keyT[a[0]][mod5(a[3] + 4)];
      }
      else if (a[1] == a[3]) {
         str[i] = keyT[mod5(a[0] - 1)][a[1]];
         str[i + 1] = keyT[mod5(a[2] - 1)][a[1]];
      }
      else {
         str[i] = keyT[a[0]][a[3]];
         str[i + 1] = keyT[a[2]][a[1]];
      }
   }
   
  return str;
  
}

// Function to encrypt using Playfair Cipher 
string decryptByPlayfairCipher(char str[], char key[])
{
   char ps, ks, keyT[5][5];

   // Key 
   ks = strlen(key);
   ks = removeSpaces(key, ks);
   toLowerCase(key, ks);

   // ciphertext 
   ps = strlen(str);
   toLowerCase(str, ps);
   ps = removeSpaces(str, ps);

   generateKeyTable(key, ks, keyT);

   return decrypt(str, keyT, ps);
}
   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
     const int n = cipherText.length();
     const int m = password.length();
  
     // declaring character array 
     char str[n + 1];
     char key[m + 1];
  
     // copying the contents of the a
     // string to char array 
     strcpy(str, cipherText.c_str());
     strcpy(key, password.c_str());
 
     // encrypt using Playfair Cipher 
     std::string plainText = decryptByPlayfairCipher(str, key);
     std::cout << "This is the cipherText: " << cipherText << std::endl;
     std::cout << "This is the password: " << password << std::endl;
     std::cout << "This is the plaintext: " << plainText << std::endl;
     return plainText;
  
   }
};

#endif // CIPHER04_H
