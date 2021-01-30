#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "string_utils.h"


int strContains(const char *str, const char *subStr) {
    if(strlen(str) < 0) {
        return 0;
    }
    if(strlen(subStr) < 0) {
        return 0;
    }
    
    if(strlen(str) < strlen(subStr)) {
        return 0;
    }

    if(strlen(str) == strlen(subStr)) {
        return (strcmp(str, subStr) == 0);
    }

    // Look from start - end but if the totatl number of element from start to end is less that strlen(subStr) give up
    // Example 123 length 3
    int start = 0;
    int end = strlen(subStr) - 1;
    int size = strlen(str);
    while(end <= size - 1) {

        if(strncmp(str + start, subStr, strlen(subStr)) == 0) {
            return 1;
        }

        start++;
        end++;
    }
    return 0;

}

char * acronymizer(const char *s) {
    
    char *acronymStr = (char *) malloc(sizeof(char) * strlen(s));
    
    if(s[0] != ' ') {
        acronymStr[0] = toupper(s[0]);
    }
    
    int count = 1;
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] == ' ') {
            acronymStr[count] = toupper(s[i+1]);
            count++;
        }
    }
    
    
    
    return acronymStr;
}


void replaceChar(char *src, char oldChar, char newChar) {
    if(strlen(src) < 1 || oldChar == '\0' || newChar == '\0') {
        printf("Error!\n");
        return;
    }
    
    
    
    
    
    for (int i = 0; src[i] != '\0'; i++) {
        if(src[i] == oldChar) {
            src[i] = newChar;
        }
    }
    

}


void removeChar(char *src, char c) {
    
    if(strlen(src) < 1 || c == '\0') {
        printf("Error!\n");
        return;
    }
    
        for (int i = 0; src[i] != '\0'; i++) {
        if(src[i] == c) {
        
            for(int k = i; src[k] != '\0'; k++) {
                src[k] = src[k+1];
            }
            i--;
        }
        
    }

}

char **lengthSplit(const char *s, int n) {
    if(strlen(s) < 1 || n < 1 || (int) strlen(s) < n) {
        printf("Error!\n");
        char **Error = (char**) malloc(sizeof(char) * 1);
        Error[0] = (char*) malloc(sizeof(char) * 1);
        return Error;
    }
    
    
    
    int buffer = 0;
    
    char **Final = (char**) malloc(sizeof(char*) * (int) ceil((strlen(s) / (double) n)));
    for(int i = 0; i < ((int) ceil((strlen(s) / (double) n))); i++) {
        Final[i] = (char*) malloc(sizeof(char) * (n + 1));
        if(buffer < strlen(s) && buffer != strlen(s)) {
            strncpy(Final[i], s + buffer, n);
        } else {
            strncpy(Final[i], "\0", n);
        }
        Final[i][n] = '\0';
        buffer += n;
        
    }
    
    return Final;
    
}