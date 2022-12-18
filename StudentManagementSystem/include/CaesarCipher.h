//Guard Against Multiple Builds
#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

// Importing required libraries
#include <iostream>
#include <string>
#include<fstream>

//indicating standard namespace to use
using namespace std;

/* >>>> Caesar Cipher Algorithms : Replace the initial letter position with alphabet or called ROT3 algorithm. <<<< */ 

// Abstract Class for encryption
class ENCRYPTION {
public:
	virtual void ENCRYPT(const string& FILE_NAME) = 0;		 // Pure Virtual Function
};

// Abstract Class for de-encryption
class DECRYPTION {
public:
	virtual void DECRYPT(const string& FILE_NAME) = 0;		 // Pure Virtual Function
};

#endif 														 // !CAESAR_CIPHER_H 