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
   virtual std::string getPseudoAuth()  { return "Brett Jensen"; }
   virtual std::string getCipherName()  { return "Polybius Square"; }
   virtual std::string getEncryptAuth() { return "Jose Paredes"; }
   virtual std::string getDecryptAuth() { return "Jose Paredes"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("“Crypto,” Practical Cryptography. [Online]. Available: http://practicalcryptography.com/ciphers/classical-era/polybius-square/. [Accessed: 10-Dec-2019].");
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
	  str += "   grid <- generateGrid(password)\n";
	  str += "   FOR p is all values of plainText\n";
	  str += "      FOR rowIndex is 0 to 4\n";
	  str += "         FOR columnIndex is 0 to 4\n";
	  str += "             IF grid[rowIndex,columnIndex] == p OR grid[rowIndex,columnIndex == 'i' AND p == 'j'\n";
	  str += "                cipherText += rowIndex\n";
	  str += "                cipherText += columnIndex\n";
	  str += "   RETURN cipherText\n\n";

      // The decrypt pseudocode
      str += "decrypt(cipherText, password)\n";
	  str += "   grid <- generateGrid(password)\n";
	  str += "   FOR p is all values of cipherText - 1\n STEP 2";
	  str += "      plainText += grid[p, p+1]";
	  str += "   RETURN plainText\n\n";

	  //generateGrid function
	  str += "generateGrid(password)\n";
	  str += "   LET alphaList = list of all letters except 'j'\n";
	  str += "   FOR p is all values in password\n";
	  str += "      FOR rowIndex is 0 to 4\n";
	  str += "         FOR columnIndex is 0 to 4\n";
	  str += "            IF p is in alphalist\n";
	  str += "               grid[rowIndex,columnIndex] = p\n";
	  str += "               alphalist.remove(p)\n";
	  str += "            ELSE\n";
	  str += "               grid[rowIndex,columnIndex] = alphalist.first\n";
	  str += "               alphalist.remove(alphalist.first)\n";
	  str += "  RETURN grid\n\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText, 
                               const std::string & password)
   {  
      // alphabet to fill grid space
      std::string alphalist = " !\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
      char grid[10][10];
      // iterate through password
      std::string::const_iterator p = password.begin();
      int i = 0;
      int j = 0;
      int k = 0;
      int t = 0;
      bool b = false;

      // loop through rows
      for(i; i < 10; i++)
      {  

         if (b == true)
            break;
         //loop through columns
         std::cout << i << std::endl;
         for(j; j < 10; j++)
         {
            bool check = false;
            while(check == false && p != password.end())
            {
               // check to see if char from password is not put in yet
               std::size_t found = alphalist.find(*p, 0);
                  
               // if character was found
               if(found != std::string::npos)
               {
                     // insert character into grid as an integer
                     grid[i][j] = *p;
                     
                     // remove character from alpha string
                     alphalist.erase(found, 1);
                     ++p;
                     check = true;
               }
               else 
                  ++p;
            }
            if (p == password.end())
            {
              k = i;
              t = j;
              b = true;
              break;
            }
         }
      } 
      bool c = false;

      for(k; k < 10; k++)
      {  
         //loop through columns
         for(int l = 0; l < 10; l++)
         {
            if(c == false)
               l = t;
            if (!alphalist.empty())
            {
               //insert first character from alpha string into grid
               grid[k][l] = alphalist[0];
                   
               // remove character from alpha string
               alphalist.erase(0, 1);
            }
            c = true;
         }
      }
       
      std::string cipherText = "";
        
      // generate grid
      //generateGrid(password);
      
      // iterate through plainText
      for (std::string::const_iterator p = plainText.begin();
           p != plainText.end();
           ++p)
      {
         /* once character is found and ciphered break to increase performance
         bool check = false;
         if (check)
           break;*/
           
         // loop through rows: i = rowIndex
         for(int i = 0; i < 10; i++)
         {  
            //loop through columns: i = columnIndex
            for(int j = 0; j < 10; j++)
            {
               //once we find the character in the grid 
               if (grid[i][j] == *p)
               {
                  //add the rowIndex and columnIndex to the cipherText
                  cipherText += std::to_string(i);
                  cipherText += std::to_string(j);
                  //check = true;
                  //break;
               }
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
      std::string plainText = "";
      
      // alphabet to fill grid space
      std::string alphalist = " !\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
      char grid[10][10];
      // iterate through password
      std::string::const_iterator p = password.begin();
      int i = 0;
      int j = 0;
      int k = 0;
      int t = 0;
      bool b = false;

      // loop through rows
      for(i; i < 10; i++)
      {  

         if (b == true)
            break;
         //loop through columns
         std::cout << i << std::endl;
         for(j; j < 10; j++)
         {
            bool check = false;
            while(check == false && p != password.end())
            {
               // check to see if char from password is not put in yet
               std::size_t found = alphalist.find(*p, 0);
                  
               // if character was found
               if(found != std::string::npos)
               {
                     // insert character into grid as an integer
                     grid[i][j] = *p;
                     std::cout << grid[i][j] << std::endl;
                     // remove character from alpha string
                     alphalist.erase(found, 1);
                     std::cout << alphalist << std::endl;
                     ++p;
                     check = true;
               }
               else 
                  ++p;
            }
            if (p == password.end())
            {
              k = i;
              t = j;
              b = true;
              break;
            }
         }
      }
       
      bool c = false;
      
      for(k; k < 10; k++)
      {  
         //loop through columns
         for(int l = 0; l < 10; l++)
         {
            if(c == false)
               l = t;
            if (!alphalist.empty())
            {
               //insert first character from alpha string into grid
               grid[k][l] = alphalist[0];
                   
               // remove character from alpha string
               alphalist.erase(0, 1);
            }
            c = true;
         }
      }
      
      // iterate through the cipher
      for (std::string::const_iterator p = cipherText.begin();
           p != cipherText.end();
           ++p)
      {
           char a = *p;
           char b = *(p + 1);
           int ia = a - '0';
           int ib = b - '0';
           plainText += grid[ia][ib];
           //if ((p + 1) != cipherText.end())
           ++p;
      }  
      
      return plainText;
   }
private:

   /**********************************************************
    * generateGrid
    * This function will create a 10x10 grid to act as the 
    * polybius square. It will enter the first entries of the 
    * grid with unique characters from the password given.
    * When there is no more unique characters, the grid will
    * then be filled by the rest of the remaining characters
    * of the printable ASCII characters.
    **********************************************************/
    /*void generateGrid(const std::string & password)
    {
      // alphabet to fill grid space
      std::string alpha = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
      int grid[10][10];
      // iterate through password
      for (std::string::const_iterator p = password.begin();
           p != password.end();
           ++p)
      {
         // loop through rows
         for(int i = 0; i < 10; i++)
         {  
            //loop through columns
            for(int j = 0; j < 10; j++)
            {
               // check to see if char from password is not put in yet
               std::size_t found = alpha.find(*p);
               
               // if character was found
               if(found != std::string::npos)
               {
                  // insert character into grid as an integer
                  grid[i][j] = indexFromCharacter(*p);
                  
                  // remove character from alpha string
                  alpha.erase(found);
               }
               // if character is not found
               else
               {
                  //insert first character from alpha string into grid
                  grid[i][j] = indexFromCharacter(alpha[0]);
                  
                  // remove character from alpha string
                  alpha.erase(alpha[0]);
               }
            }
         }
      }
    }*/  
};

#endif // CIPHER01_H
