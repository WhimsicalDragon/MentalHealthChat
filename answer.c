#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer.h"
#include "string_utils.h"

extern char name[100];

question qtype;

void dayResponse(FILE *day) {

    printf("That's cool!\n");


    char dayStr[7000];
    while(!feof(day)) {
        char buffString[1000];
        fgets(buffString, 1000, day);
        strcat(dayStr, buffString);
    }

    printf("%s is what you said\n", dayStr);



    //printf("Strcontain says %d\n", strContains(dayStr,foo[0]));
    triggerStr(dayStr, DAY);
}


void triggerStr(char* userStr, question qtype) {
    char* foo[10];
    foo[0] = "good";
    foo[1] = "Good";

    //int good = 0;


    for(int i = 0; i < 2; i++) {
        if(strContains(userStr,foo[i])) {
            printf("I'm glad your day was good %s\n", name);
        }
    }


}