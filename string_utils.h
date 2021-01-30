#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


//Takes in a string and determines if the given subStr is in it
int strContains(const char *str, const char *subStr);

//Takes in a string and forms and acronym based on the first letter of each word.
char * acronymizer(const char *s);


//Takes a string and replaces every instance of the oldChar with the newChar
void replaceChar(char *src, char oldChar, char newChar);

//Takes a string and removes every instance of the char c
void removeChar(char *src, char c);

//Takes in a string and splits it into n size pieces
char **lengthSplit(const char *s, int n);