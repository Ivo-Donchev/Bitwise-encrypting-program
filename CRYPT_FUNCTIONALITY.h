#ifndef CRYPT_FUNCTIONALITY.h
#define CRYPT_FUNCTIONALITY.h

#include "CRYPT_FUNCTIONALITY.c"


int getBit(int, int);
void swapBits(char*, int, int);
void changeBitToNull(int*, int);
void changeBitToOne(int*, int);
char decryptChar(char);
void reverseString(char*);
void swap(char*, char*);
void kill(const char*);
void getline(char*);
void printDecrypted(char *);
void crypt(char*);

#endif
