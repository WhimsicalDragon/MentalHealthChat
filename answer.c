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


void feelResponse(FILE *feel) {

    char feelStr[7000];
    while(!feof(feel)) {
        char buffString[1000];
        fgets(buffString, 1000, feel);
        strcat(feelStr, buffString);
    }

    triggerStr(feelStr, FEEL);
    fclose(feel);
}


void triggerStr(char* userStr, question qtype) {
    char* good[10];
    good[0] = "good";
    good[1] = "Good";

    //Future: Get for words from like api or something and use them!

    //int good = 0;

    switch(qtype) {
        case DAY:
            for(int i = 0; i < 2; i++) {
                if(strContains(userStr,good[i])) {
                printf("I'm glad your day was good %s\n", name);
                break;
                }
            }
            break;
        case FEEL:
            for(int i = 0; i < 2; i++) {
                if(strContains(userStr,good[i])) {
                printf("I'm glad you are feeling good %s\n", name);
                break;
                }
            }
            break;
        default:
            for(int i = 0; i < 2; i++) {
                if(strContains(userStr,good[i])) {
                printf("Glad things are good %s\n", name);
                break;
                }
            }
            break;

    }
}

//Return types
//1 = Talked to the user and they answered the question
// 0 = The user doesn't want to talk about this question, but they may talk about another
// -1 = The user doesn't want to talk
int getFileForType(question qtype) {
    FILE *file;
    char fileLoc[100];
    int noTalk = 0;
    strcpy(fileLoc, "");
    while(noTalk < 2 && !(file = fopen(fileLoc, "r"))) {
        strcpy(fileLoc, "");
        scanf("%s", fileLoc);
        noTalk++;


        printf("File loc is %s\n", fileLoc);

        if(noTalk < 2 && !(file = fopen(fileLoc, "r"))) {
            printf("I can't find the file you specified %s!\n",name);
        } else if(noTalk >= 2 && !(file = fopen(fileLoc, "r"))) {


            switch(qtype) {
                case DAY:
                    printf("I still can't find the file. Would you prefer not to talk about your day? Y/N\n");
                    break;
                case FEEL:
                    printf("I still can't find the file. Would you prefer not to talk about how you are feeling right now? Y/N\n");
                    break;
                default:
                    printf("I still can't find the file. Would you prefer not to talk about this? Y/N\n");
                    break;
            }
            char resp;
            fflush(stdin);
            scanf(" %c", &resp);
            if(resp == 'Y' || resp == 'y') {
                break;
            } else {
                fflush(stdin);
                printf("Ok, give me the file location again please!\n");
                noTalk = 0;
            }
        } else if((file = fopen(fileLoc, "r"))) {
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
        switch(qtype) {
            case DAY:
                dayResponse(file);
                break;
            case FEEL:
                feelResponse(file);
                break;
            default:
                break;
        }
        return 1;
    }

}