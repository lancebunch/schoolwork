/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


using namespace std;

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Ethan Rawlins"; }
   virtual std::string getCipherName()  { return "Playfair"; }
   virtual std::string getEncryptAuth() { return "Dylan Doeling"; }
   virtual std::string getDecryptAuth() { return "Hyde Xu"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string strCite;
      strCite = "Source 1:\n";
      strCite += "URL: geeksforgeeks.org/playfair-cipher-with-examples/\n";
      strCite += "Citation Author: Abhay Bhat\n";
      strCite += "Article Title: Playfair Cipher with Examples\n";
      strCite += "Source 2:\n";
      strCite += "URL: learncryptography.com/classical-encryption/playfair";
      strCite += "-cipher\n";
      strCite += "Citation Author: LearnCryptography.com\n";
      strCite += "Article Title: Playfair Cipher\n";
      strCite += "Date: 2019\n";

      return strCite;
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
      str = "// Function to convert string to lowercase\n";
      str += "void toLowerCase(char message[], int ps)\n{\n\tint i;\n";
      str += "\tfor (i = 0; i < ps; i++)\n\t{\n\t\tif (message[i] > 64";
      str += " && message[i] < 91)\n\t\t\tmessage[i] += 32;\n\t}\n";

      str += "}\n\n// Function to remove all spaces in a string\n";
      str += "int removeSpaces(char* message, int ps)\n{\n\tint i, count = 0;";
      str += "\n\tfor (i = 0; i < ps; i++)\n\t\tif (message[i] != ' ')\n";
      str += "\t\t\tmessage[count++] = message[i];\n\treturn count;\n}\n\n";

      str +=  "// Step 1: Generate the key square (5 x 5):\n\n";
      str += "void generateKeySquare(char password[], int ks, char keyT\n";
      str += "[5][5]){\n\tint i, j, k, flag = 0, *alpha;\n";
      str += "alpha = (int*) calloc(26, sizeof(int));\nfor (i = 0;";
      str += " i < ks; i++)\n\t\tif (key[i] != 'j')\n";
      str += "alpha[key[i] - 97] = 2;\n\t}\n\nalpha['j' - 97] = 1;\n";
      str += "\n\ti = 0;\n\tj = 0;\n\n\tfor (k = 0; k < ks; k++)\n\t{\n";
      str += "\t\tif (alpha[key[k] - 97] == 2)\n\t\t{\n\t\t\talpha[key[k]";
      str += " - 97] -= 1;\n\t\t\tkeyT[i][j] = key[k];\n\t\t\tj++;\n\t\t\t";
      str += "if (j == 5)\n\t\t\t{\n\t\t\t\ti++;\n\t\t\t\tj = 0;\n\t\t\t}\n";
      str += "\t\t}\n\t}\n\tfor (k = 0; k < 26; k++)\n\t{\n\t\tif (alpha[k]";
      str += " == 0)\n\t\t{\n\t\t\tkeyT[i][j] = (char)(k + 97);\n\t\t\tj++;\n";
      str += "\t\t\tif (j == 5)\n\t\t\t{\n\t\t\t\ti++;\n\t\t\t\tj = 0;\n";
      str += "\t\t\t}\n\t\t}\n\t}\n}\n";

      str += "// Function to search for the characters of a digraph from ";
      str += "the key square and return the position\n";
      str += "void search(char keyT[5][5], char a, char b, int arr[])\n{\n";
      str += "int i, j;\n\tif (a == 'j')\n\t\ta = 'i';\n\telse if (b == 'j')";
      str += "\n\t\tb = 'i';\n\n\tfor (i = 0; i < 5; i++)\n\t\tfor (j = 0; ";
      str += "j < 5; j++)\n\t\t{\n\t\t\tif (keyT[i][j] == a)\n\t\t\t{\n\t\t\t";
      str += "\tarr[0] = i;\n\t\t\t\tarr[1] = j;\n\t\t\t}\n\t\t\telse if (";
      str += "keyT[i][j] == b)\n\t\t\t{\n\t\t\t\tarr[2] = i;\n\t\t\t\tarr[3]";
      str += " = j;\n\t\t\t}\n\t\t}\n\t}\n}\n\n";

      str += "// Function to find mod of 5\n";
      str += "int mod5(int a)\n{\n\treturn (a % 5);\n}\n\n";
      
      str += "// Function to make number of plaintext characters even\n";
      str += "int even(char str[], int ptrs)\n{\n\tif (ptrs % 2 != 0)\n";
      str += "\t\tstr[ptrs++] = 'z';\n\t\tstr[ptrs] = '\\0';\n\t}\n\t";
      str += "return ptrs;\n}\n\n";

      str += "// Function for encryption\n";
      str += "void encrypt(char str[], char keyT[5][5], int ps)\n\t{\n";
      str += "\tint i, a[4];\n\tfor (i = 0; i < ps; i += 2)\n\t{\n\t\t";
      str += "search(keyT, str[i], str[i + 1], a);\n\n\t\t";
      str += "if (a[0] == a[2])\n\t\t{\n\t\t\tstr[i] = keyT[a[0]][mod5(";
      str += "a[1] + 1)];\n\t\t\tstr[i + 1] = keyT[a[0]][mod5(a[3] + 1)];\n";
      str += "\t\t}\n\t\telse if (a[1] == a[3])\n\t\t{\n\t\t\tstr[i] = ";
      str += "keyT[mod5(a[0] + 1)]";
      str += "[a[1]];\n\t\t\tstr[i + 1] = keyT[mod5(a[2] + 1)][a[1]];";
      str += "\n\t\t}\n\t\telse\n\t\t{\n\t\t\tstr[i] = keyT[a[0]][a[3]];";
      str += "\n\t\t\tstr[i + 1] = keyT[a[2]][a[1]];\n\t\t}\n\t}\n}\n\n";

      str += "// Step 2: Perform the encryption:\n";
      str += "void performEncryption(char str[], char key[])\n{\n\t";
      str += "char ps, ks, keyT[5][5];\n\n\t// Key\n\tks = strlen(key);\n\t";
      str += "ks = removeSpaces(key, ks);\n\ttoLowerCase(key, ks);\n\n\t";
      str += "// Plaintext message\n\tps = strlen(str);\n\ttoLowerCase(";
      str += "str, ps);\n\tps = removeSpaces(str, ps);\n\n\t";
      str += "ps = even(str, ps);\n\n\tgenerateKeyTable(key, ks, keyT);\n";
      str += "\n\tencrypt(str, keyT, ps);\n}\n";

      str += "// Function to decrypt\nvoid decrypt(char str[], char keyT";
      str += "[5][5], int ps)\n{\n\tint i, a[4];\n\tfor (i = 0; i < ps; ";
      str += "i += 2)\n\t{\n\t\tsearch(keyT, str[i], str[i + 1], a);\n\t\t";
      str += "if (a[0] == a[2])\n\t\t{\n\t\t\tstr[i] = keyT[a[0]][mod5(a[1] ";
      str += "- 1)];\n\t\t\tstr[i + 1] = keyT[mod5(a[3] - 1)];\n\t\t}\n\t\t";
      str += "else if (a[1] == a[3])\n\t\t{\n\t\t\tstr[i] = keyT[mod5(a[0] -";
      str += " 1)][a[1]];\n\t\t\tstr[i + 1] = keyT[mod5(a[2] - 1)][a[1]];\n";
      str += "\t\t}\n\t\telse\n\t\t{\n\t\t\tstr[i] = keyT[a[0]][a[3]];\n\t\t";
      str += "\tstr[i + 1] = keyT[a[2]][a[1]];\n\t\t}\n\t}\n}\n\n";

      str += "// Function to call decrypt\n";
      str += "void performDecryption(char str[], char key[])\n{\n\t";
      str += "char ps, ks, keyT[5][5];\n\n\t// Key\n\tks = strlen(key);\n\t";
      str += "ks = removeSpaces(key, ks);\n\ttoLowerCase(key, ks);\n\n\t";
      str += "// ciphertext\n\tps = strlen(str);\n\ttoLowerCase(str, ps);\n\t";
      str += "ps = removeSpaces(str, ps);\n\n\tgenerateKeyTable(key, ks, ";
      str += "keyT);\n\n\tdecrypt(str, keyT, ps);\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * Encrypts the plainText
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText = plainText;
      char keyT[5][5];
      int ps = 0; 
      int ks = 0;
      // Key
      //ks = password.length();

      ks = removeSpaces(password, password.length());
      toLowerCase(password, ks);
      // Plaintext message
      //ps = plainText.length();
      toLowerCase(plainText, ps);
      ps = removeSpaces(plainText, plainText.length());
      ps = even(plainText, ps);
      generateKeyTable(password, ks, keyT);
      cerr << "line 165 \n";
      cipherText = encrypts(plainText, keyT, ps);
      cout << "test8\n";

      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * Decrypts the cipherText
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {  
      std::string plainText;
      char keyT[5][5]; 
      int ps, ks = 0;
 
      ks = password.length(); 
      ks = removeSpaces(password, ks); 
      toLowerCase(password, ks); 

      // ciphertext 
      ps = cipherText.length(); 
      toLowerCase(cipherText, ps); 
      ps = removeSpaces(cipherText, ps); 

      generateKeyTable(password, ks, keyT); 

      plainText = decrypts(cipherText, keyT, ps); 

      return plainText;
   }

private:

   /**********************************************************
    * TOLOWERCASE
    * Turns the password to all lower case
    **********************************************************/
    
   void toLowerCase(string plainText, int ps)
   {
      int i;
      for (i = 0; i < ps; i++)
      {
         if (plainText[i] > 64 && plainText[i] < 91)
            plainText[i] += 32;
      }
   }

   /**********************************************************
    * REMOVESPACES
    * Returns the number of spaces and removes the spaces
    * from password
    **********************************************************/
   
   int removeSpaces(string plainText, int ps)
   {
      plainText.erase(remove(plainText.begin(), plainText.end(), ' '), plainText.end());
      int length = plainText.length();
      return length;           
   }

   /**********************************************************
    * GENERATEKEYTABLE
    * Generates the table with right letters in them
    **********************************************************/
   
   void generateKeyTable(string password, int ks, char keyT[5][5])
   {
      int i, j, k, flag = 0;
      int *alpha;
      alpha = (int*) calloc(26,sizeof(int));
      for(i = 0; i < ks; i++)
      {
         if(password[i] != 'j');
         alpha[password[i] - 97] = 2;
      }
      alpha['j' - 97] = 1;
      i = 0;
      j = 0;

      for(k = 0; k < ks; k++)
      {
         if(alpha[password[i] - 97] == 2)
         {
            alpha[password[i] - 97] -= 1;
            keyT[i][j] = password[i];
            j++;
            if(j == 5)
            {
               i++;
               j = 0;
            }
         }  
      }
      for(k = 0; k < 26; k++)
      {
         if(alpha[k] == 0)
         {
            keyT[i][j] = char(k + 97);
            j++;
            if (j == 5)
            {
               i++;
               j=0;
            }
         }
      }
   }

   /**********************************************************
    * SEARCH
    * Searches the 5x5 table for the correct values
    **********************************************************/
   
   void search(char keyT[5][5], char a, char b, int arr[])
   {
      if (a == 'j')
         a = 'i';
      else if (b == 'j')
         b = 'i';
      for (int i = 0; i < 5; i++)
      {
         cerr << "check for first for" <<endl;
         for (int j = 0; j < 5; j++)
         {
            if (keyT[i][j] == a)
            {
               arr[0] = i;
               cerr << "arr[0] = " << arr[0];
               arr[1] = j;
               cerr << "arr[1] = " << arr[1];
            }
            else if (keyT[i][j] == b)
            {
               arr[2] = i;
               cerr << "arr[2] = " << arr[2];
               arr[3]= j;
               cerr << "arr[3] = " << arr[3];
            }
         }
      }
   }
          
   /**********************************************************
    * MOD5
    * Returns the mod 5 of a number
    **********************************************************/
   
   int mod5(int a)
   {
      return (a % 5);
   }

   /**********************************************************
    * EVEN
    * Checks to see if the plainText is even or not
    **********************************************************/
 
   int even(string plainText, int ptrs)
   {
      if(ptrs % 2 != 0)
      {
         plainText[ptrs++] = 'z';
         //plainText[ptrs] = '\0';  
      }
      return ptrs;
   }

   /**********************************************************
    * ENCRYPTS
    * Encrypts the plainText with the 5x5 key
    **********************************************************/
   
   string encrypts(string plainText, char keyT[5][5], int ps)
   {
      int i, a[4];
      for (i = 0; i < ps; i += 2)
      { 
         search(keyT, plainText[i], plainText[i], a);
         for (int i = 0; i < 5; i++)
          {
             for (int j = 0; j < 5; j++)
             {
               cerr << "keyT["<<i<<"]["<<j<<"] is: " << keyT[i][j] <<endl;
             }
          }
         cerr << "check 1\n"; 
         cerr << a[0] <<endl <<  a[1] << endl<< a[2] << endl<< a[3] <<endl;
         if (a[0] == a[2])
         {
            cerr << "check 2\n";
            plainText[i] = keyT[a[0]][(a[1] + 1)%5];
            cerr << "check 3\n";
            plainText[i+1] = keyT[a[0]][(a[3] + 1)%5];
            cerr << "check 4\n"; 
         }
         else if (a[1] == a[3])
         {
            cerr << "check 5\n";  
            plainText[i] = keyT[(a[0] + 1)%5][a[1]];
            cerr << "check 6\n";
            plainText[i+1] = keyT[(a[2] + 1)%5][a[1]];
            cerr << "check 7\n"; 
         }
         else
         {
            cerr << "check 8\n";
            plainText[i] = keyT[a[0]][a[3]];
            cerr << "check 9\n";
            plainText[i+1] = keyT[a[2]][a[1]];
            cerr << "check 10\n"; 
         }
      }
      return plainText;
   }

   /**********************************************************
    * DECRYPTS
    * Decrypts the cipherText with the 5x5 key
    **********************************************************/
   string decrypts(string cipherText, char keyT[5][5], int ps) 
   { 
      int i, a[4]; 
      for (i = 0; i < ps; i += 2) 
      { 
         search(keyT, cipherText[i], cipherText[i + 1], a); 
         if (a[0] == a[2]) 
         { 
            cipherText[i] = keyT[a[0]][mod5(a[1] - 1)]; 
            cipherText[i + 1] = keyT[a[0]][mod5(a[3] - 1)]; 
         } 
         else if (a[1] == a[3]) 
         { 
            cipherText[i] = keyT[mod5(a[0] - 1)][a[1]]; 
            cipherText[i + 1] = keyT[mod5(a[2] - 1)][a[1]]; 
         } 
         else 
         { 
            cipherText[i] = keyT[a[0]][a[3]]; 
            cipherText[i + 1] = keyT[a[2]][a[1]]; 
         } 
      } 
      return cipherText;
   } 

};

#endif // CIPHER02_H
