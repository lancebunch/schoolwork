/********************************************************************
 * Header:
 *    Implement your cipher here. You can view 'example.h' to see the
 *    completed Caesar Cipher example.
 ********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
    virtual std::string getPseudoAuth()  { return "Jessica Smith"; }
    virtual std::string getCipherName()  { return "Hill Cipher"; }
    virtual std::string getEncryptAuth() { return "Alec Kaasa"; }
    virtual std::string getDecryptAuth() { return "Alec Kaasa"; }
    
    /***********************************************************
     * GET CIPHER CITATION
     * Returns the citation from which we learned about the cipher
     ***********************************************************/
    virtual std::string getCipherCitation()
    {
        return std::string("Hill Cipher. (2019). Retrieved 12 December 2019, from https://crypto.interactive-maths.com/hill-cipher.html#2x2encypt");
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
        str =  "encrypt() {\n";
        str += "GET first 4 chars of keyphrase\n";
        str += "GET message\n";
        str += "Convert keyphrase into numbers between 0-25 (conkey = convertAlpha(keyphrase))\n";
        str += "Find the inverse determinant of the keyphrase (findInDet(conkey))\n";
        str += "IF the inverse determinant cannot be found(findInDet(conkey) == 26)\n";
        str += "\tDO\n";
        str += "\t\tDISPLAY error\n";
        str += "\t\tPROMPT for new keyphrase\n";
        str += "\t\tConvert keyphrase into numbers between 0-25(conkey = convertAlpha(keyphrase))\n";
        str += "\t\tFind the inverse determinant of the keyphrase(findInDet(conkey))\n";
        str += "\tWHILE(findInDet(conkey) == 26)\n";
        str += "ELSE\n";
        str += "\tconvert message into numbers between 0-25 (convertAlpha(message))\n";
        str += "\tFOR each number in the converted message\n";
        str += "\t\tcipherNum += (converted message[i]*convertedkey[0] + ";
        str += "\t\t\tconvertedmessage[i++]*convertedkey[1]) % 26\n\n";
        str += "\t\tcipherNum += (converted message[i]*convertedkey[2]\n";
        str += "\t\t\t + convertedmessage[i++]*convertedkey[3]) % 26\n";
        str += "\tENDFOR\n";
        str += "\tcipherText = convertNum(cipherNum)\n";
        str += "RETURN cipherText\n";
        str += "}  \n\n\n";
        
        
        // The decrypt pseudocode
        str += "decrypt() {\n";
        str += "GET first 4 chars of keyphrase\n";
        str += "GET message\n";
        str += "Convert keyphrase into numbers between 0-25 (conkey = convertAlpha(keyphrase))\n";
        str += "Find the inverse determinant of the keyphrase (findInDet(conkey))\n";
        str += "IF the inverse determinant cannot be found(findInDet(conkey) == 26)\n";
        str += "\tDO\n";
        str += "\t\tDISPLAY error\n";
        str += "\t\tPROMPT for new keyphrase\n";
        str += "\t\tGET first 4 chars of keyphrase\n";
        str += "\t\tConvert keyphrase into numbers between 0-25(conkey = convertAlpha(keyphrase))\n";
        str += "\t\tFind the inverse determinant of the keyphrase(findInDet(conkey))\n";
        str += "\tWHILE(findInDet(conkey) == 26)\n";
        str += "ELSE\n";
        str += "\tadjMatrix = conkey\n";
        str += "\tadjMatrix[1] *= -1\n";
        str += "\tadjMatrix[2] *= -1\n";
        str += "\tstd::reverse(adjMatrix[0],adjMatrix[3])\n";
        str += "\tFOR each element in adjMatrix\n";
        str += "\t\tadjMatrix[i] = adjMatrix[i] % 26\n";
        str += "\t\tinKey[i] = adjMatrix[i]*inDet\n";
        str += "\tENDFOR\n";
        str += "\tconvert message into numbers between 0-25 (convertAlpha(message))\n";
        str += "\tFOR each number in the converted message\n";
        str += "\t\tdNum += (converted message[i]*inkey[0] + convertedmessage[i++]*inkey[1]) % 26\n";
        str += "\t\tdNum += (converted message[i]*inkey[2] + convertedmessage[i++]*inkey[3]) % 26\n";
        str += "\tENDFOR\n";
        str += "\tdecryptText = convertNum(dNum)\n";
        str += "RETURN decryptText\n";
        str += "}\n";
        
        
        //helper functions
        str += "convertAlpha(string) {\n";
        str += "FOR each char in string\n";
        str += "\tSWITCH(current char in string)\n";
        str += "\t\tCASE A, a:\n";
        str += "\t\t\tconStr[i] = 0\n";
        str += "\t\tCASE B, b:\n";
        str += "\t\t\tconStr[i] = 1\n";
        str += "\t\t...\n";
        str += "\t\tCASE Z,z:\n";
        str += "\t\t\tconStr[i] = 25\n";
        str += "ENDFOR\n";
        str += "RETURN conStr\n";
        str += "}\n";
        str += "convertNum(array of numbers) {\n";
        str += "FOR each element in array\n";
        str += "\tSWITCH(current number in array)\n";
        str += "\t\tCASE 0:\n";
        str += "\t\t\tconNum[i] = a\n";
        str += "\t\tCASE 1:\n";
        str += "\t\t\tconNum[i] = b\n";
        str += "\t\t...\n";
        str += "\t\tCASE 25:\n";
        str += "\t\t\tconNum += z\n";
        str += "ENDFOR\n";
        str += "RETURN conNum\n";
        str += "}\n";
        str += "findInDet(conkey) {\n";
        str += "\td = (conkey[0]*conkey[3] - conkey[1]*conkey[2])% 26\n";
        str += "\twhile (tmp != 1 OR count is 26) {\n";
        str += "\t\ttmp = (d*count of 0-25) % 26\n";
        str += "\t\tnext number in count\n";
        str += "\t}\n";
        str += "RETURN count\n";
        str += "}\n";
        return str;
    }
    
    /**********************************************************
     * ENCRYPT
     * TODO: ADD description
     **********************************************************/
    virtual std::string encrypt(const std::string & plainText,
                                const std::string & password)
    {
        std::cout << plainText;
        std::string cipherText = plainText;
        int cipherNum[4];
        
        // GET first 4 chars of keyphrase
        std::string keyString = password.substr (0,4);
        
        // Convert keyphrase into numbers between 0-25
        int conKey[keyString.length()];
        convertAlpha(keyString, conKey);
        
        // Find the inverse determinant of the keyphrase (findInDet(conKey))
        int inKey[4];
        findInDet(conKey, inKey);
        
        // IF the inverse determinant cannot be found(findInDet(conKey) == 26)
        /*if (findInDet(conKey, inKey) == 26) {
         // DO
         do {
         // DISPLAY error
         std::cout << "Inverse determinant cannot be found. Enter new password: ";
         // PROMPT for new keyphrase
         std::getline(std::cin, password);
         keyString = password.substr (0,4);
         // Convert keyphrase into numbers between 0-25 (conKey = convertAlpha(keyphrase))
         int conKey[] = convertAlpha(plainText);
         // Find the inverse determinant of the keyphrase(findInDet(conKey))
         int inKey[] = findInDet(conKey);
         }
         // WHILE(findInDet(conKey) == 26)
         while(findInDet(conKey) == "26");
         }*/
        // ELSE
        /*else {*/
        // Convert message into numbers
        int conMessage[plainText.length()];
        convertAlpha(keyString, conMessage);
        
        for (int i = 0; i < sizeof(conMessage); i++) {
            cipherNum[i] += (conMessage[i]*conKey[0] + conMessage[i++] * conKey[1]) % 26;
            
            cipherNum[i] += (conMessage[i]*conKey[2] + conMessage[i++] * conKey[3]) % 26;
        }
        cipherText = convertNum(cipherNum);
        //}
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
        int *cipherNum;
        
        // GET first 4 chars of keyphrase
        std::string keyString = password.substr (0,4);
        
        // Convert keyphrase into numbers between 0-25
        int conKey[keyString.length()];
        convertAlpha(keyString, conKey);
        
        // Find the inverse determinant of the keyphrase (findInDet(conKey))
        int inKey[4];
        findInDet(conKey, inKey);
        
        // IF the inverse determinant cannot be found(findInDet(conKey) == 26)
        /*if (findInDet(conKey) == (int*)26) {
         // DO
         do {
         // DISPLAY error
         std::cout << "Inverse determinant cannot be found. Enter new password: ";
         // PROMPT for new keyphrase
         std::getline(std::cin, password);
         // GET first 4 chars of keyphrase
         keyString = password.substr (0,4);
         // Convert keyphrase into numbers between 0-25 (conKey = convertAlpha(keyphrase))
         conKey = convertAlpha(keyString);
         // Find the inverse determinant of the keyphrase(findInDet(conKey))
         inKey = findInDet(conKey);
         }
         // WHILE(findInDet(conKey) == 26)
         while(findInDet(conKey) == (int*) 26);
         } else {*/
        
        int * adjMatrix;
        adjMatrix = conKey;
        
        adjMatrix[1] *= -1;
        adjMatrix[2] *= -1;
        //reverse(adjMatrix[0], adjMatrix[3]);
        
        for (int i = 0; i < sizeof(adjMatrix); i++) {
            adjMatrix[i] = adjMatrix[i] % 26;
            inKey[i] = adjMatrix[i] * findInDet(conKey, inKey);
        }
        
        // Convert message into numbers between 0-25 (convertAlpha(message))
        int conMessage[plainText.length()];
        convertAlpha(plainText, conMessage);
        
        // FOR each number in the converted message
        for (int i = 0; i < sizeof(conMessage); i++) {
            // dNum += (convertedMessage[i]*inKey[0] + convertedMessage[i++] * inKey[1]) % 26
            cipherNum += (conMessage[i]*conKey[0] + conMessage[i++] * conKey[1]) % 26;
            
            // cipherNum += (convertedMessage[i]*inKey[2] + convertedMessage[i++]*inKey[3]) % 26
            cipherNum += (conMessage[i]*conKey[2] + conMessage[i++]*conKey[3]) % 26;
            // ENDFOR
        }
        plainText = convertNum(cipherNum);
        //}
        return plainText;
    }
    
private:
    /**************************************************
     * CONVERT ALPHA
     * Converts letters to numbers.
     *************************************************/
    void convertAlpha(std::string text, int conStr[])
    {
        for (int i = 0; i < text.length(); i++) {
            switch (text[i]) {
                case 'A':
                    conStr[i] = 0;
                    break;
                case 'a':
                    conStr[i] = 0;
                    break;
                case 'B':
                    conStr[i] = 1;
                    break;
                case 'b':
                    conStr[i] = 1;
                    break;
                case 'C':
                    conStr[i] = 2;
                    break;
                case 'c':
                    conStr[i] = 2;
                    break;
                case 'D':
                    conStr[i] = 3;
                    break;
                case 'd':
                    conStr[i] = 3;
                    break;
                case 'E':
                    conStr[i] = 4;
                    break;
                case 'e':
                    conStr[i] = 4;
                    break;
                case 'F':
                    conStr[i] = 5;
                    break;
                case 'f':
                    conStr[i] = 5;
                    break;
                case 'G':
                    conStr[i] = 6;
                    break;
                case 'g':
                    conStr[i] = 6;
                    break;
                case 'H':
                    conStr[i] = 7;
                    break;
                case 'h':
                    conStr[i] = 7;
                    break;
                case 'I':
                    conStr[i] = 8;
                    break;
                case 'i':
                    conStr[i] = 8;
                    break;
                case 'J':
                    conStr[i] = 9;
                    break;
                case 'j':
                    conStr[i] = 9;
                    break;
                case 'K':
                    conStr[i] = 10;
                    break;
                case 'k':
                    conStr[i] = 10;
                    break;
                case 'L':
                    conStr[i] = 11;
                    break;
                case 'l':
                    conStr[i] = 11;
                    break;
                case 'M':
                    conStr[i] = 12;
                    break;
                case 'm':
                    conStr[i] = 12;
                    break;
                case 'N':
                    conStr[i] = 13;
                    break;
                case 'n':
                    conStr[i] = 13;
                    break;
                case 'O':
                    conStr[i] = 14;
                    break;
                case 'o':
                    conStr[i] = 14;
                    break;
                case 'P':
                    conStr[i] = 15;
                    break;
                case 'p':
                    conStr[i] = 15;
                    break;
                case 'Q':
                    conStr[i] = 16;
                    break;
                case 'q':
                    conStr[i] = 16;
                    break;
                case 'R':
                    conStr[i] = 17;
                    break;
                case 'r':
                    conStr[i] = 17;
                    break;
                case 'S':
                    conStr[i] = 18;
                    break;
                case 's':
                    conStr[i] = 18;
                    break;
                case 'T':
                    conStr[i] = 19;
                    break;
                case 't':
                    conStr[i] = 19;
                    break;
                case 'U':
                    conStr[i] = 20;
                    break;
                case 'u':
                    conStr[i] = 20;
                    break;
                case 'V':
                    conStr[i] = 21;
                    break;
                case 'v':
                    conStr[i] = 21;
                    break;
                case 'W':
                    conStr[i] = 22;
                    break;
                case 'w':
                    conStr[i] = 22;
                    break;
                case 'X':
                    conStr[i] = 23;
                    break;
                case 'x':
                    conStr[i] = 23;
                    break;
                case 'Y':
                    conStr[i] = 24;
                    break;
                case 'y':
                    conStr[i] = 24;
                    break;
                case 'Z':
                    conStr[i] = 25;
                    break;
                case 'z':
                    conStr[i] = 25;
                    break;
            }
        }
        //return (int)conStr;
    }
    
    /**************************************************
     * CONVERT NUM
     * Converts numbers to letters.
     *************************************************/
    std::string convertNum(int cipherNum[])
    {
        std::string conNum;
        
        for (int i = 0; i < sizeof(cipherNum); i++) {
            switch (cipherNum[i]) {
                case 0:
                    conNum[i] = 'a';
                    break;
                case 1:
                    conNum[i] = 'b';
                    break;
                case 2:
                    conNum[i] = 'c';
                    break;
                case 3:
                    conNum[i] = 'd';
                    break;
                case 4:
                    conNum[i] = 'e';
                    break;
                case 5:
                    conNum[i] = 'f';
                    break;
                case 6:
                    conNum[i] = 'g';
                    break;
                case 7:
                    conNum[i] = 'h';
                    break;
                case 8:
                    conNum[i] = 'i';
                    break;
                case 9:
                    conNum[i] = 'j';
                    break;
                case 10:
                    conNum[i] = 'k';
                    break;
                case 11:
                    conNum[i] = 'l';
                    break;
                case 12:
                    conNum[i] = 'm';
                    break;
                case 13:
                    conNum[i] = 'n';
                    break;
                case 14:
                    conNum[i] = 'o';
                    break;
                case 15:
                    conNum[i] = 'p';
                    break;
                case 16:
                    conNum[i] = 'q';
                    break;
                case 17:
                    conNum[i] = 'r';
                    break;
                case 18:
                    conNum[i] = 's';
                    break;
                case 19:
                    conNum[i] = 't';
                    break;
                case 20:
                    conNum[i] = 'u';
                    break;
                case 21:
                    conNum[i] = 'v';
                    break;
                case 22:
                    conNum[i] = 'w';
                    break;
                case 23:
                    conNum[i] = 'x';
                    break;
                case 24:
                    conNum[i] = 'y';
                    break;
                case 25:
                    conNum[i] = 'z';
                    break;
            }
        }
        return conNum;
    }
    
    /**************************************************
     * FIND INDET
     * Find the inverse determinant.
     *************************************************/
    int findInDet(int conKey[], int inKey[])
    {
        int tmp = 0;
        int d = (conKey[0] * conKey[3] - conKey[1] * conKey[2]) % 26;
        int count = 0;
        
        while (tmp != 1 || count == 26) {
            tmp = (d * count) % 26;
            count++;
        }
        
        return count;
    }
};

#endif // CIPHER02_H
