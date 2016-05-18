
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define BUFFER_SIZE 4096

void swapBits(char *number, int fpos, int spos)
{
    int fbit = getBit(*number, fpos),
        sbit = getBit(*number, spos);
    if(fbit  != sbit)
    {

        if(fbit)
        {
            changeBitToOne(number, spos);
        }
        else
        {
            changeBitToNull(number, spos);
        }
        if(sbit)
        {
            changeBitToOne(number, fpos);
        }
        else
        {
            changeBitToNull(number, fpos);
        }

    }

}
void changeBitToNull(int *n, int p)
{
    int mask = ~(1 << p);
    *n = *n & mask;
}
void changeBitToOne(int *n, int p)
{
     int mask = 1 << p;
     *n = *n ^ mask;
}
int getBit(int n, int p)
{
    return ((n >> p) & 1);
}

void crypt(char* text)
{
    unsigned short i;
    reverseString(text);
    for(i = 0; i < strlen(text); i++)
    {
        text[i] = decryptChar(text[i]);
    }

}

void printDecrypted(char *message)
{
    unsigned short i;
    reverseString(message);
    for(i = 0; i < strlen(message); i++)
    {
        printf("%c", decryptChar(message[i]));
    }
    printf("\n");
}
void getline(char* text)
{
    int i = -1;
    do{
        i++;
        scanf("%c", &text[i]);
    }
    while(text[i] != '\n');
    text[i] = '\0';
}
void kill(const char* msg)
{
    fprintf(stderr,msg);
}
void reverseString(char* text)
{
    size_t len = strlen(text), i;
    for(i = 0; i < len / 2; i++)
    {
        swap(&text[i], &text[len - i - 1]);
    }
}
void swap(char *a, char *b)
{
    char c = *a;
    *a = *b;
    *b =c;
}
char decryptChar(char ch)
{
    int i;
    for(i = 0; i < 7; i+=2)
    {
        swapBits(&ch,i,i+1);
    }
    return ch;
}
