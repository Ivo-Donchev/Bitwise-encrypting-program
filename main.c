#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 4096
int getBit(int, int);
void swapBits(int*, int, int);
void changeBitToNull(int*, int);
void changeBitToOne(int*, int);
char decryptChar(char);
void reverseString(char*);
void swap(char*, char*);
void kill(const char*);
void getLine(char*);
void printDecrypted(char *);
void crypt(char*);
int main(int argc, char** argv)
{
    char srcFileName[20];
    char destFileName[20];
    if(argc == 3)
    {
        strcpy(srcFileName, argv[1]);
        strcpy(destFileName, argv[2]);
    }
    else
    {
        printf("Enter source-file name: ");
        scanf("%s", srcFileName);
        printf("Enter destination-file name: ");
        scanf("%s", destFileName);
    }

    FILE *src = fopen(srcFileName, "r");
    if(!src)
    {
        kill("Source file not found!\n");
        return -1;
    }
    FILE *dest = fopen(destFileName, "w");

    char buffer[BUFFER_SIZE];

    while(!feof(src) && !ferror(src))
    {
        int readBytes = fread(buffer, 1, BUFFER_SIZE, src);
        buffer[readBytes] = '\0';
        crypt(buffer);
        fwrite(buffer, 1, readBytes, dest);
    }
    printf("SUCCESS!!!\n\n\n");
    return 0;
}


void swapBits(int *number, int fpos, int spos)
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
void getLine(char* text)
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
    printf("%s", msg);
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
        swapBits((int*)&ch,i,i+1);
    }
    return ch;
}
