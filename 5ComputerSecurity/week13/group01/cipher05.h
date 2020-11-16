/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER05_H
#define CIPHER05_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher05 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Peter Flickinger"; }
   virtual std::string getCipherName()  { return "Tiny Encryption Algorithm"; }
   virtual std::string getEncryptAuth() { return "Thomas Rosales"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("Veness, C. (2016). Block TEA ‘Tiny Encryption Algorithm’ (xxtea) implemented in JavaScript. [online] Movable-type. Available at: https://www.movable-type.co.uk/scripts/tea-block.html [Accessed 13 Dec. 2019].");
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
      str =  "//General setup\n";

      // 4-word key; simply convert first 16 chars of password to integers
      str += "keyArray = [(int)password[0-4],\n";
      str += "            (int)password[4-8],\n";
      str += "            (int)password[8-12],\n";
      str += "            (int)password[12-16]]\n";

      str += "int data_len = length of text\n";
      str += "char pointer bytes = (char pointer)malloc(data_len+15)\n";
      str += "for each letter at i in text\n";
      str += "   bytes[i] = text[i]\n";

      str += "uint8_t   pointer data = (uint8_t  pointer ) bytes\n";
      str += "uint32_t  pointer len  = (uint32_t pointer )& data_len\n";
      str += "uint32_t  pointer key  = (uint32_t pointer ) keyArray\n";

      // Encrypt
      str += "\n\n\n";

      str += "encrypt_Data ( uint8_t * data, uint32_t * len, uint32_t * key)\n";
      str += "uint32_t blocks, i\n";
   	str += "uint32_t pointer -> data32\n";
   	str += "data32 = data as uint32_t\n";
   	str += "blocks = (((*len) + 7) / 8) + 1\n";

   	str += "data32[(blocks * 2) - 1] = *len\n";
   	str += "*len = blocks * 8\n";
   	str += "for each block\n";
   	str += "	encrypt64(&data32[blocknum * 2], key)\n";

      str += "\n\n\n";

      str += "encrypt64(uint32_t* v, uint32_t* k) {\n";
      str += "	uint32_t v0 = v[0], v1 = v[1], sum = 0, i\n";
      str += "	uint32_t delta = 0x9e3779b9\n";
      str += "	uint32_t k0 = k[0], k1 = k[1], k2 = k[2], k3 = k[3]\n";
      str += "	do 32 times\n";
      str += "		sum += delta\n";
      str += "		v0 += ((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1)\n";
      str += "		v1 += ((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3)\n";
      str += "	v[0] = v0 v[1] = v1\n";


      str += "\n\n\n";
      str += "\n\n\n";

      // The decrypt pseudocode
      str += "decryptData(uint8_t * data, uint32_t * len, uint32_t * key)\n";
      str += "	uint32_t blocks, i\n";
      str += "	uint32_t pointer data32\n";
      str += "	data32 = data as uint32_t\n";
      str += "	blocks = (*len) / 8\n";
      str += "	for each block\n";
      str += "		decrypt64(&data32[block * 2], key)\n";
      str += "	*len = data32[(blocks * 2) - 1]\n";

      str += "\n\n\n";

      str += "decrypt64(uint32_t pointer v, uint32_t pointer k) {\n";
      str += "	uint32_t v0 = v[0], v1 = v[1], sum = 0xC6EF3720, i\n";
      str += "	uint32_t delta = 0x9e3779b9\n";
      str += "	uint32_t k0 = k[0], k1 = k[1], k2 = k[2], k3 = k[3]\n";
      str += "	do 32 times\n";
      str += "		v1 -= ((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3)\n";
      str += "		v0 -= ((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1)\n";
      str += "		sum -= delta\n";
      str += "	v[0] = v0 v[1] = v1;\n";


      return str;
   }

    /**********************************************************
    * ENCRYPT64
    * Encrryption Algorithm used in the Timy Encryption Algorithm
    **********************************************************/
   void encrypt64(uint32_t* v, uint32_t* k)
   {
      uint32_t v0 = v[0], v1 = v[1], sum = 0, i;
      uint32_t delta = 0x9e3779b9;
      	uint32_t k0 = k[0], k1 = k[1], k2 = k[2], k3 = k[3];
      	for (i = 0; i < 32; i++)
        {
           sum += delta;
           v0 += ((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1);
           v1 += ((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3);
        }
        v[0] = v0;
        v[1] = v1;

   }
   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      // Initial Setup
      int keyArray[4] = {(int)password[0-4],
                      (int)password[4-8],
                      (int)password[8-12],
                      (int)password[12-16]};

      int data_len = plainText.length();
      char *bytes = (char*)malloc(data_len+15);
      for (int j = 0; j < data_len; j++)
      {
         bytes[j] = plainText[j];
      }

      uint8_t * data = (uint8_t *) bytes;
      uint32_t * len  = (uint32_t *)& data_len;
      uint32_t * key  = (uint32_t *) keyArray;

      // Encrypt
      //encrypt_Data ( uint8_t * data, uint32_t * len, uint32_t * key);
      uint32_t blocks, i;
      uint32_t * data32;
      data32 = (uint32_t*)data;
      blocks = (((*len) + 7) / 8) + 1;

      data32[(blocks * 2) - 1] = *len;
      *len = blocks * 8;
      for (int i = 0; i < blocks; i++)
      {
      	encrypt64(&data32[i * 2], key);
      }

      return 0;
      //return cipherText;
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
