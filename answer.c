#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer.h"
#include "string_utils.h"

void dayResponse(FILE *day) {

    printf("That's cool!\n");


    char dayStr[7000];
    while(!feof(day)) {
        char buffString[1000];
        fgets(buffString, 1000, day);
        strcat(dayStr, buffString);
    }

    printf("%s is what you said\n", dayStr);


    char foo[] = "good";

    printf("Strcontain says %d\n", strContains(dayStr,foo));
}