#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * method to crypt a char
 */
char cryptChar(char c, int jump) {
    int overflow = 0;
    char res = c;
    char tabChars[26][26] = {{'a','b','c','d','e','f','g','h',
                       'i','j','k','l','m','n','o','p','q',
                       'r','s','t','u','v','w','x','y','z'},
                              {'A','B','C','D','E','F','G','H',
                               'I','J','K','L','M','N','O','P','Q','R','S',
                               'T','U','V','W','X','Y','Z'}};

    for(unsigned long long i=0;i<sizeof (tabChars[0]);i++) {
        if(c == tabChars[0][i]) {
            if(i+jump > 25) {
                overflow = i+jump - 26;
                res = tabChars[0][overflow];
            } else if(i+jump <= 25) {
                res = tabChars[0][i+jump];
            }
        } else if(c == tabChars[1][i]) {
            if(i+jump > 25) {
                overflow = i+jump - 26;
                res = tabChars[1][overflow];
            } else if(i+jump <= 25) {
                res = tabChars[1][i+jump];
            }
        }
    }

    return res;
};

/*
 * method to decrypt a char
 */
char decryptChar(char c, int jump) {
    int overflow = 0;
    char res = c;
    char tabChars[26][26] = {{'a','b','c','d','e','f','g','h',
                       'i','j','k','l','m','n','o','p','q',
                       'r','s','t','u','v','w','x','y','z'},
                              {'A','B','C','D','E','F','G','H',
                               'I','J','K','L','M','N','O','P','Q','R','S',
                               'T','U','V','W','X','Y','Z'}};

    for(int i=0;i<sizeof (tabChars[0]);i++) {
        if(c == tabChars[0][i]) {
            if(i-jump < 0) {
                overflow = i-jump + 26;
                res = tabChars[0][overflow];
            } else if(i-jump >= 0) {
                res = tabChars[0][i-jump];
            }
        } else if(c == tabChars[1][i]) {
            if(i-jump < 0) {
                overflow = i-jump + 26;
                res = tabChars[1][overflow];
            } else if(i-jump >= 0) {
                res = tabChars[1][i-jump];
            }
        }
    }
    return res;
};

/*
 * method to write in a file
 */
void writeInFile(char* file, char *array[], int size) {
    FILE * f = NULL;
    f = fopen(file, "w");
    printf("\nopen file to write data : %s\n", file);
    int i = 0;
    while(i<size) {
       fwrite(array[i],sizeof (*array[i]),1,f);
       i++;
    }
    fclose(f);
};

/*
 * method to get data of file
 */
char* getData(char* file) {
    FILE* f = fopen(file, "r");
    char *string = malloc(250);
    int i = 0;
    if(f) {
        int c;
        printf("\nopen file to get data : %s\n", file);
        while((c = getc(f)) != EOF) {
            string[i] = c;
            i++;
        }
        string[i] = '\0';
        fclose(f);
    } else {
        printf("\nopen file to get data error...\n");
    }
    return string;
};

/*
 * method to read a file
 */
void readFile(char* file) {
    FILE* f = fopen(file, "r");
    if(f) {
        printf("\nopen file to read : %s\n", file);
        int c;
        while((c = getc(f)) != EOF) {
            putchar(c);
        }
        fclose(f);
    } else {
        printf("\nopen file to read error...\n");
    }
};

#endif // HEAD_H
