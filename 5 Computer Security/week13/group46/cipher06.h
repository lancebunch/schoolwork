/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER06_H
#define CIPHER06_H
#include <string>
#include <map>
#include <set>

using namespace std;
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher06 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Jonathon Dawson"; }
   virtual std::string getCipherName()  { return "Playfair cipher"; }
   virtual std::string getEncryptAuth() { return "Marius Corca"; }
   virtual std::string getDecryptAuth() { return "Joshua Hellewell"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string citations = "\"Playfair Cipher,\" Learn Cryptography. [Online]. Available: https://learncryptography.com/classical-encryption/playfair-cipher. [Accessed: 12-Dec-2019].\n";
      citations += "AbhayBhatCheck, \"Playfair Cipher with Examples,\" GeeksforGeeks, 26-Aug-2019. [Online]. Available: https://www.geeksforgeeks.org/playfair-cipher-with-examples/. [Accessed: 12-Dec-2019].\n";
      citations += "Playfair Cipher. [Online]. Available: http://rumkin.com/tools/cipher/playfair.php. [Accessed: 12-Dec-2019].\n";
      citations += "\"Escape sequences,\" cppreference.com. [Online]. Available: https://en.cppreference.com/w/cpp/language/escape. [Accessed: 12-Dec-2019].\n";
      return citations;
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
      str =  "encrypt(plainText, password)\n";
      str += "   string encrypted";
      str += "   int[10][10] keyTable\n";
      str += "   map<char, int[2]> keyMap\n";
      str += "   bool valid <- KeyTable(password, keyTable, keyMap\n";
      str += "   ERROR if !valid\n\n";

      str += "   FOR c is every other char in plainText starting at 0\n";
      str += "      leftChar <- c\n";
      str += "      leftSpot <- keyMap.at(leftChar)\n";
      str += "      rightChar\n";
      str += "      IF leftChar == rightChar OR no char after c\n";
      str += "         rightChar <- last value in charSet";
      str += "      ELSE\n";
      str += "         rightChar <- spot after c\n";
      str += "      rightSpot <- keyMap.at(rightChar)\n\n";

      str += "      IF leftSpot[0] == rightspot[0]\n";
      str += "         leftSpot[0] <- (leftSpot[0] + 1)mod 10\n";
      str += "         rightSpot[0] <- (rightSpot[0] + 1)mod 10\n";
      str += "      ELSE IF leftSpot[1] == rightspot[1]\n";
      str += "         leftSpot[1] <- (leftSpot[1] + 1)mod 10\n";
      str += "         rightSpot[1] <- (rightSpot[1] + 1)mod 10\n";
      str += "      ELSE\n";
      str += "         holder <- leftSpot[0]\n";
      str += "         leftSpot[0] <- rightSpot[0]\n";
      str += "         rightSpot[0] <- holder\n\n";

      str += "      encrypted += keyTable[leftSpot[0]][leftSpot[1]]\n";
      str += "      encrypted += keyTable[rightSpot[0]][rightSpot[1]]\n\n";

      str += "   return encrypted\n\n";



      

      // The decrypt pseudocode
      str =  "decrypt(plainText, password)\n";
      str += "   string decrypted";
      str += "   int[10][10] keyTable\n";
      str += "   map<char, int[2]> keyMap\n";
      str += "   bool valid <- KeyTable(password, keyTable, keyMap\n";
      str += "   ERROR if !valid\n\n";

      str += "   FOR c is every other char in cipherText starting at 0\n";
      str += "      leftChar <- c\n";
      str += "      leftSpot <- keyMap.at(leftChar)\n";
      str += "      rightChar\n";
      str += "      IF leftChar == rightChar OR no char after c\n";
      str += "         rightChar <- last value in charSet";
      str += "      ELSE\n";
      str += "         rightChar <- spot after c\n";
      str += "      rightSpot <- keyMap.at(rightChar)\n\n";

      str += "      IF leftSpot[0] == rightspot[0]\n";
      str += "         leftSpot[0] <- (leftSpot[0] - 1)mod 10\n";
      str += "         rightSpot[0] <- (rightSpot[0] - 1)mod 10\n";
      str += "      ELSE IF leftSpot[1] == rightspot[1]\n";
      str += "         leftSpot[1] <- (leftSpot[1] - 1)mod 10\n";
      str += "         rightSpot[1] <- (rightSpot[1] - 1)mod 10\n";
      str += "      ELSE\n";
      str += "         holder <- leftSpot[0]\n";
      str += "         leftSpot[0] <- rightSpot[0]\n";
      str += "         rightSpot[0] <- holder\n\n";

      str += "      decrypted += keyTable[leftSpot[0]][leftSpot[1]]\n";
      str += "      IF keyTable[rightSpot[0]][rightSpot[1]] != dummy char (last three in charSet";
      str += "         decrypted += keyTable[rightSpot[0]][rightSpot[1]]\n\n";

      str += "   return decrypted\n\n";

      // The KeyTable Generator shared between both
      str += "createKeyTable(&password, &keyTable, &keyMap)\n";
      str += "   iteration = 0\n";
      str += "   available <- charSet copy\n\n";

      str += "   FOR c is each char of password\n";
      str += "      IF c in available\n";
      str += "         keyTable[iteration%10][iteration/10] <- c\n";
      str += "         keyMap[c] <- {iteration%10, iteration/10}\n";
      str += "         available.remove(c)";
      str += "         iteration++\n";
      str += "      ELSE IF c not in charSet\n";
      str += "         THROW invalidArgument\n\n";

      str += "   FOR h is each char in available\n";
      str += "      keyTable[iteration%10][iteration/10] <- h\n";
      str += "      keyMap[h] <- {iteration%10, iteration/10}\n";
      str += "      iteration++\n";

      return str;
   }

   /**********************************************************
    * KEYSTRUCT
    * This is used for declaring a map of char and 2 ints.
    * This struct is for the 2 ints
    **********************************************************/
   struct keyStruct
   {
      int a;
      int b;
   };

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      // Set of chars that are used in the key table
      // The last three are just placeholders for the encrypted string
      const char temp[100] = {' ', '!', '\"', '#', '$', '%', '&', '\'', '(', ')'
                             ,'*', '+', ',', '-', '.', '/', '0', '1', '2', '3'
                             ,'4', '5', '6', '7', '8', '9', ':', ';', '<', '='
                             ,'>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G'
                             ,'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q'
                             ,'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '['
                             ,'\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e'
                             ,'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o'
                             ,'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y'
                             ,'z', '{', '|', '}', '~', '\n', '\t', '\131', '\136', '\147'};

      //For better search
      const set<char> charSet (temp, temp+100);

      std::string cipherText = plainText;
      set<char>::iterator it = charSet.begin();
      set<char>::reverse_iterator rit = charSet.rbegin();
      int keyTable[10][10];
      map<char, keyStruct> keyMap;
      char c = ' ';
      char cNext = ' ';
      char leftChar = ' ';
      char rightChar = ' ';
      keyStruct leftSpot;
      keyStruct rightSpot;

      bool valid = createKeyTable(password, keyTable, keyMap, charSet);
      if (!valid)
      {
         cerr << "Key Table creation failed," <<endl;
         return "";
      }

      cipherText = "";
      for (int i = 0; i < plainText.length(); i+=2)
      {
         c = plainText[i];
         cNext = plainText[i + 1];
         leftChar = c;
         leftSpot = keyMap.at(leftChar);
         if (leftChar == rightChar || cNext == '\0')
         {
            rightChar = *rit;  
         }
         else
         {
            rightChar = cNext;
         }
         rightSpot = keyMap.at(rightChar);
         
         if (leftSpot.a == rightSpot.a)
         {
            leftSpot.a = (leftSpot.a + 1) % 10;
            rightSpot.a = (rightSpot.a + 1) % 10;
         }
         else if (leftSpot.b == rightSpot.b)
         {
            leftSpot.b = (leftSpot.b + 1) % 10;
            rightSpot.b = (rightSpot.b + 1) % 10;
         }
         else
         {
            int holder = leftSpot.a;
            leftSpot.a = rightSpot.a;
            rightSpot.a = holder;
         }
         
         cipherText += keyTable[leftSpot.a][leftSpot.b];
         cipherText += keyTable[rightSpot.a][rightSpot.b];
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
      const char temp[100] = {' ', '!', '\"', '#', '$', '%', '&', '\'', '(', ')'
                             ,'*', '+', ',', '-', '.', '/', '0', '1', '2', '3'
                             ,'4', '5', '6', '7', '8', '9', ':', ';', '<', '='
                             ,'>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G'
                             ,'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q'
                             ,'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '['
                             ,'\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e'
                             ,'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o'
                             ,'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y'
                             ,'z', '{', '|', '}', '~', '\n', '\t', '\131', '\136', '\147'};

      //For better search                                                       
      const set<char> charSet (temp, temp+100);

      set<char>::iterator it = charSet.begin();
      set<char>::reverse_iterator rit = charSet.rbegin();
      int keyTable[10][10];
      map<char, keyStruct> keyMap;
      char leftChar = ' ';
      char rightChar = ' ';
      keyStruct leftSpot;
      keyStruct rightSpot;

      bool valid = createKeyTable(password, keyTable, keyMap, charSet);
      if (!valid)      

      if (!valid)
      {
         cerr << "Key Table creation failed," <<endl;
         return "";
      }

      plainText = "";
      for (int c = 0; c < cipherText.length(); c += 2)
      {
         char cNext = cipherText[c + 1];
         leftChar = cipherText[c];
         leftSpot = keyMap.at(leftChar);
         if (leftChar == rightChar || cNext == '\0')
         {
            rightChar = *rit;
         }
         else
         {
            rightChar = cNext;
         }
         rightSpot = keyMap.at(rightChar);

         if (leftSpot.a == rightSpot.a)
         {
            leftSpot.a = (leftSpot.a - 1) % 10;
            rightSpot.a = (rightSpot.a - 1) % 10;
         }
         else if (leftSpot.b == rightSpot.b)
         {
            leftSpot.b = (leftSpot.b - 1) % 10;
            rightSpot.b = (rightSpot.b - 1) % 10;
         }
         else
         {
            int holder = leftSpot.a;
            leftSpot.a = rightSpot.a;
            rightSpot.a = holder;
         }

         plainText += keyTable[leftSpot.a][leftSpot.b];
         
         plainText += keyTable[rightSpot.a][rightSpot.b];
      }


      return plainText;
   }
   private:

   /**********************************************************
    * CreateKeyTable
    * creates the key table that the cipher uses along with
    * a mapping of where each char 
    * 
    * input:
    * * &string password: the string used to generate the key table
    * * &map<char, int[2]> keyMap: A mapping of where each char is in the table
    * * &int[10][10] keyTable: a 2D array holding the key table
    * 
    * output:
    * * boolean indicating success
    **********************************************************/

   // Made private since the table will not be shared with any other program
   // Just for the encrypting and decrypting parts
   bool createKeyTable(const string &password, int keyTable[][10], map<char, keyStruct> &keyMap, set<char> charSet)
   {
      // The KeyTable Generator shared between both

      int iteration = 0;
      char c = ' ';
      set<char> available = charSet;
      set<char>::iterator it;

      for (int i = 0; i < password.length(); i++)
      {
         c = password[i];
         it = available.find(c);
         if (it != available.end())
         {
            keyTable[iteration % 10][iteration / 10] = c;
            // For "keyMap[c] <- {iteration%10, iteration/10}\n" pseudocode I changed the declaration of the keyMap
            // from map<char, int[2]> &keyMap to map<char, keyStruct> &keyMap since the int[2] only works in C++ 11
            // A struct holding 2 ints named keyStruct was created as well
            keyMap[c].a = iteration % 10;
            keyMap[c].b = iteration / 10;
            available.erase(c);
            iteration++;
         }
         else
         {
            if(charSet.find(c) == charSet.end()){
               cerr << "Invalid Argument..." << endl;
               return false;
            }
         }
      }

      for (it = available.begin(); it != available.end(); ++it)
      {
         // *it is our h from pseudocode
         keyTable[iteration % 10][iteration / 10] = *it;
         keyMap[*it].a = iteration % 10;
         keyMap[*it].b = iteration / 10;
         iteration++;
      }

      return true;
   }
};

#endif // CIPHER06_H
