/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H
#include <vector>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Tristan Barrow"; }
   virtual std::string getCipherName()  { return "TEA (Tiny Encryption Algorithm)"; }
   virtual std::string getEncryptAuth() { return "Tristan Barrow"; }
   virtual std::string getDecryptAuth() { return "Tristan Barrow"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "Wheeler, D. J., & Needham, R. M. (1994, December). TEA, a tiny ";
      s += "encryption algorithm. In International Workshop on Fast Software";
      s += " Encryption (pp. 363-366). Springer, Berlin, Heidelberg.";
      return s;
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;
      // The encrypt pseudocode
      str += "encrypt(message, password)\n";
      str += "   key = genKey(password)\n";
      str += "   paddingLength = 0\n";
      str += "   if message.length % 8 != 0\n";
      str += "      paddingLength = 8 - ( message.length % 8 )\n";
      str += "   message += char[paddingLength]\n";
      str += "   collection<string> message\n";
      str += "   While message !empty\n";
      str += "      sub = message[0 - 8]\n";
      str += "      stream.append(sub)\n";
      str += "      message.erase(0 - 8)\n";
      str += "   ForEach block in stream\n";
      str += "      int[2] block = block\n";
      str += "      encryptBlock(block, key)\n";
      str += "      char[8] block = block\n";
      str += "   ForEach block in stream\n";
      str += "      output += block\n";
      str += "RETURN output\n\n";

      // The decrypt pseudocode
      str += "decrypt(cypher, password)\n";
      str += "   key = genKey(password)\n";
      str += "   paddingLength = 0\n";
      str += "   if cypher.length % 8 != 0\n";
      str += "      paddingLength = 8 - ( cypher.length % 8 )\n";
      str += "   cypher += char[paddingLength]\n";
      str += "   collection<string> cypher\n";
      str += "   While cypher !empty\n";
      str += "      sub = cypher[0 - 8]\n";
      str += "      stream.append(sub)\n";
      str += "      cypher.erase(0 - 8)\n";
      str += "   ForEach block in stream\n";
      str += "      int[2] block = block\n";
      str += "      decryptBlock(block, key)\n";
      str += "      char[8] block = block\n";
      str += "   ForEach block in stream\n";
      str += "      output += block\n";
      str += "RETURN output\n\n";

      // The encrypt block pseudocode
      str += "encryptBlock(block, key)\n";
      str += "   v0 = block[0]\n";
      str += "   v1 = block[1]\n";
      str += "   sum = 0\n";
      str += "   delta=0x9e3779b9\n";
      str += "   k0 = key[0]\n";
      str += "   k1 = key[1]\n";
      str += "   k2 = key[2]\n";
      str += "   k3 = key[3]\n";
      str += "   Loop 32 times\n";
      str += "      sum += delta\n";
      str += "      a0 = (v1 << 4) + k0\n";
      str += "      a1 = v1 + sum\n";
      str += "      a2 = (v1 >> 5) + k1\n";
      str += "      v0 = a0 xor a1 xor a2\n";
      str += "      b0 = (v0 << 4) + k2\n";
      str += "      b1 = v0 + sum\n";
      str += "      b2 = (v0 >> 5) + k3\n";
      str += "      v1 = b0 xor b1 xor b2\n";
      str += "   block[0] = v0\n";
      str += "   block[1] = v1\n";
      str += "RETURN block\n\n";;

      // The decrypt block pseudocode
      str += "encryptBlock(block, key)\n";
      str += "   v0 = block[0]\n";
      str += "   v1 = block[1]\n";
      str += "   sum = 0\n";
      str += "   delta=0x9e3779b9\n";
      str += "   k0 = key[0]\n";
      str += "   k1 = key[1]\n";
      str += "   k2 = key[2]\n";
      str += "   k3 = key[3]\n";
      str += "   Loop 32 times\n";
      str += "      b0 = (v0 << 4) + k2\n";
      str += "      b1 = v0 + sum\n";
      str += "      b2 = (v0 >> 5) + k3\n";
      str += "      v1 = b0 xor b1 xor b2\n";
      str += "      a0 = (v1 << 4) + k0\n";
      str += "      a1 = v1 + sum\n";
      str += "      a2 = (v1 >> 5) + k1\n";
      str += "      v0 = a0 xor a1 xor a2\n";
      str += "      sum -= delta\n";
      str += "   block[0] = v0\n";
      str += "   block[1] = v1\n";
      str += "RETURN block\n\n";

      // generate key (probably over engineered)
      str += "keyGen(password)\n";
      str += "Loop 4 times\n";
      str += "   password.append(password)\n";
      str += "key = array[4] // 32 bit blocks \n";
      str += "While password is !empty\n";
      str += "   While password !empty and password.length < 4\n";
      str += "      password += char // padding\n";
      str += "   tempKey = array[4] // 32 bit blocks \n";
      str += "   ForEach block in tempKey\n";
      str += "      tempBlock = 0\n";
      str += "      Loop 4 times\n";
      str += "         if not first iteration\n";
      str += "            tempBlock << 8\n";
      str += "         tempBlock += last char of password\n";
      str += "         remove last char of password\n";
      str += "      block = tempBlock\n";
      str += "   ForEach block in key with index i\n";
      str += "      block = tempBlock at i\n";
      str += "[where p is a random prim]";
      str += "key[0] *= p\n";
      str += "key[1] *= p^2\n";
      str += "key[2] *= p^3\n";
      str += "key[3] *= p^4\n";
      str += "RETURN key\n\n";
      return str;
   }

   /**********************************************************
    * ENCRYPT
    * the encryption works but the processing doesn't
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText, 
                               const std::string & password)
   {

      uint32_t * key;
      key = genKey(password);

      std::string m = plainText;

      // add padding
      int p = 0;
      if (m.length() % 8 != 0)
      {
         p = 8 - (m.length() % 8);
      }
      m.append(p, (char)p);

      // split into blocks
      std::vector<std::string> stream;

      while(!m.empty())
      {
         std::string sub = m.substr(0,8);
         stream.push_back(sub);
         m.erase(m.begin(), m.begin()+8);
      }

      // encrypt each block
      for (std::vector<std::string>::iterator vIt = stream.begin(); vIt != stream.end(); vIt++)
      {
         char plainText[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
         
         for (int i = 0; i < 8; i++)
         {
            plainText[i] = vIt->at(i);
         }
         
         uint32_t * block = (uint32_t*)&plainText;
         encryptBlock(block, key);
         char * cypher = (char*)block;
         vIt->clear();
         (*vIt) += cypher;
      }

      // collect blocks
      std::string output;
      for (std::vector<std::string>::iterator vIt = stream.begin(); vIt != stream.end(); vIt++)
      {
         output += *vIt;
      }
      return output;
   }

   /**********************************************************
    * DECRYPT
    * The encryption works but the processing doesn't
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText, 
                               const std::string & password)
   {
      //cipherText;
      uint32_t * key;
      
      key = genKey(password);

      std::string c = cipherText;

      // add padding
      int p = 0;
      if (c.length() % 8 != 0)
      {
         p = 8 - (c.length() % 8);
      }
      c.append(p, (char)p);

      // split into blocks
      std::vector<std::string> stream;

      while(!c.empty())
      {
         std::string sub = c.substr(0,8);
         stream.push_back(sub);
         c.erase(c.begin(), c.begin()+8);
      }

      // decrypt each block
      for (std::vector<std::string>::iterator vIt = stream.begin(); vIt != stream.end(); vIt++)
      {
         char plainText[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
         
         for (int i = 0; i < 8; i++)
         {
            plainText[i] = vIt->at(i);
         }
         uint32_t * block = (uint32_t*)plainText;
         decryptBlock(block, key);
         char * cypher = (char*)block;
         vIt->clear();
         (*vIt) += cypher;
      }
      
      // collect blocks
      std::string output;
      for (std::vector<std::string>::iterator vIt = stream.begin(); vIt != stream.end(); vIt++)
      {
         output += *vIt;
      }
      return output;

   }
private:
   uint32_t* genKey(const std::string & password)
   {
      std::string s = password;
      // repeat password in case the password is very small
      for (uint32_t i = 0; i < 4; i++)
      {
         s += s;
      }
      
      // init key to be returned
      uint32_t* key = new uint32_t[4];
      
      // hash the password
      while (s.length() != 0)
      {

         uint32_t tempBlock[4] = {0,0,0,0};

         // fill each sub block with 4 chars
         for (int i = 0; i < 4; i++)
         {
            uint32_t tempInt = 0;
            // add padding if password length % 4 is not 0
            while (s.length() != 0 && s.length() < 4)
            {
               // random bit padding
               s.push_back(0x55);
            }
            
            // shift 4 chars into the sub block
            for (int j = 0; j < 4; j++)
            {
               if (j != 0) tempInt = tempInt << 8;
               tempInt += (uint32_t)s.back();
               s.pop_back();
            }
            
            // add the sub block to the block
            tempBlock[i] = tempInt;
         }
         
         // mash blocks together
         for (int i = 0; i < 4; i++) {
            key[i] += tempBlock[i];
         }
      }

      // in case sub blocks are the same
      key[0] *= 0x03ACA83F; // a prime "p"
      key[1] *= 0xfd3abf81; // p * p
      key[2] *= 0x0ccdc8bf; // p * p * p
      key[3] *= 0x4fb5bf01; // p * p * p * p
      
      return key;
   }

   void encryptBlock(uint32_t * block, uint32_t * key)
   {
      uint32_t b0 = block[0];
      uint32_t b1 = block[1];
      uint32_t sum = 0;
      uint32_t delta = 0x9e3779b9;
      
      uint32_t k0 = key[0];
      uint32_t k1 = key[1];
      uint32_t k2 = key[2];
      uint32_t k3 = key[3];
      
      for (uint32_t i = 0; i < 32; i++)
      {
         sum += delta;
         b0 += ((b1 << 4) + k0) ^ (b1 + sum) ^ ((b1 >> 5) + k1);
         b1 += ((b0 << 4) + k2) ^ (b0 + sum) ^ ((b0 >> 5) + k3);
      }
      block[0] = b0;
      block[1] = b1;
      
   }

   void decryptBlock(uint32_t * block, uint32_t * key)
   {
      uint32_t b0 = block[0];
      uint32_t b1 = block[1];
      uint32_t sum = 0xC6EF3720;
      uint32_t delta = 0x9e3779b9;
      
      uint32_t k0 = key[0];
      uint32_t k1 = key[1];
      uint32_t k2 = key[2];
      uint32_t k3 = key[3];
      
      for (uint32_t i = 0; i < 32; i++)
      {
         b1 -= ((b0 << 4) + k2) ^ (b0 + sum) ^ ((b0 >> 5) + k3);
         b0 -= ((b1 << 4) + k0) ^ (b1 + sum) ^ ((b1 >> 5) + k1);
         sum -= delta;
      }
      block[0] = b0;
      block[1] = b1;
      
   }
};

#endif // CIPHER01_H
