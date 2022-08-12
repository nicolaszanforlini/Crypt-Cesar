#include <stdio.h>
#include <string.h>
#include "head.h"

int main()
{
    // jump 5 char in alphabet
    int jump = 5;

    // test with z and Z
    char c = 'z';
    printf("\ntest to crypt letter -%c- result : -%c-\n",c,cryptChar(c,jump));
    printf("\n----------------\n");
    printf("\ntest to decrypt letter -%c- result : -%c-\n",cryptChar(c,jump),decryptChar(cryptChar(c,jump),jump));
    printf("\n----------------\n");

    char cUpper = 'Z';
    printf("\ntest to crypt letter -%c- result : -%c-\n",cUpper,cryptChar(cUpper,jump));
    printf("\n----------------\n");
    printf("\ntest to decrypt letter -%c- result : -%c-\n",cryptChar(cUpper,jump),
           decryptChar(cryptChar(cUpper,jump),jump));
    printf("\n----------------\n");

    // read file
    char* file = "C:/Users/nicol/Desktop/projets/QtCreator/cesar/message.txt";
    readFile(file);
    printf("\n----------------\n");

    // get data in message.txt
    char* p = NULL;
    p = getData(file);
    printf("\npointer in main file :\n--%s--\n", p);
    printf("\n----------------\n");

    printf("\nlen pointer in main file : --%llu--\n",_mbstrlen(p));
    printf("\n----------------\n");

    // crypt data
    char array_c[strlen(p)];
    for(unsigned long long i=0;i<strlen(p);i++) {
        array_c[i] = cryptChar(p[i],jump);
        printf("\nchange --%c-- to --%c--",p[i],array_c[i]);
    }
    printf("\n----------------\n");
    printf("\nstring crypt :\n--%s--",array_c);
    printf("\n----------------\n");

    // write in file string crypt
    int size_c = sizeof (array_c);
    char* ptr_c[sizeof(array_c)];
    for(unsigned long long i=0;i<sizeof (array_c);i++) {
        ptr_c[i] = &array_c[i];
    }
    writeInFile(file,ptr_c,size_c);
    printf("\n----------------\n");
    readFile(file);
    printf("\n----------------\n");

    // get data in message.txt
    p = getData(file);
    printf("\npointer in main file :\n--%s--\n", p);
    printf("\n----------------\n");

    printf("\nlen pointer in main file : --%llu--\n",_mbstrlen(p));
    printf("\n----------------\n");

    // decrypt data
    char array_d[strlen(p)];
    for(unsigned long long i=0;i<sizeof(array_c);i++) {
        array_d[i] = decryptChar(array_c[i],jump);
        printf("\nchange --%c-- to --%c--",array_c[i],array_d[i]);
    }
    printf("\n----------------\n");
    printf("\nstring decrypt :\n--%s--",array_d);
    printf("\n----------------\n");

    // write in file string decrypt
    int size_d = sizeof (array_d);
    char* ptr_d[sizeof(array_d)];
    for(unsigned long long i=0;i<sizeof (array_d);i++) {
        ptr_d[i] = &array_d[i];
    }
    writeInFile(file,ptr_d,size_d);
    printf("\n----------------\n");
    readFile(file);
    printf("\n----------------\n");


    return 0;
}
