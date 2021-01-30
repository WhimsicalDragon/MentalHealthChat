#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer.h"
#include "string_utils.h"

extern char name[100];

question qtype;

void dayResponse(FILE *day) {

    char dayStr[7000];
    while(!feof(day)) {
        char buffString[1000];
        fgets(buffString, 1000, day);
        strcat(dayStr, buffString);
    }



    //printf("Strcontain says %d\n", strContains(dayStr,foo[0]));
    triggerStr(dayStr, DAY);
    fclose(day);
}


void triggerStr(char* userStr, question qtype) {
    char* foo[10];
    foo[0] = "good";
    foo[1] = "Good";

    //Future: Get for words from like api or something and use them!

    //int good = 0;


    for(int i = 0; i < 2; i++) {
        if(strContains(userStr,foo[i])) {
            printf("I'm glad your day was good %s\n", name);
        }
    }


}

//Return types
//1 = Talked to the user and they answered the question
// 0 = The user doesn't want to talk about this question, but they may talk about another
// -1 = The user doesn't want to talk
int getFileForType(question qtype) {
    FILE *file;
    char fileLoc[100];
    strcpy(fileLoc, "");
    int noTalk = 0;
    while(!(file = fopen(fileLoc, "r"))) {
        scanf("%s", fileLoc);
        noTalk++;
        if(noTalk < 2 && !(file = fopen(fileLoc, "r"))) {
            printf("I can't find the file you specified %s!\n",name);
        } else if(noTalk >= 2) {


            if(qtype == DAY) {
                printf("I still can't find the file. Would you prefer not to talk about your day? Y/N\n");
            } else {
                printf("I still can't find the file. Would you prefer not to talk about this? Y/N\n");
            }
            char resp;
            fflush(stdin);
            scanf(" %c", &resp);
            if(resp == 'Y' || resp == 'y') {
                break;
            }
            printf("Ok, give me the file location again please!\n");
            noTalk = 0;
        }

    }

    if(noTalk >= 2) {
        printf("It's ok %s, you don't have to tell me if you don't want to. Would you rather talk about something else? Y/N\n", name);
        char resp = 'b';
        fflush(stdin);
        scanf(" %c", &resp);

        if(resp == 'Y' || resp == 'y') {
            return 0;
        } else {
            return -1;
        }
    } else {
        if(qtype == DAY) {
            dayResponse(file);
        }
        return 1;
    }

}