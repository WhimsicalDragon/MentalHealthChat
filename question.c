#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer.h"
#include "string_utils.h"
//#include <time.h> Add time checking and remind for bedtime later

question qtype;


char name[100];

int main(int argc, char *argv[]) {

    int tm_hour;
    FILE *userProfile;


    //Check if the user is new
    if(!(userProfile = fopen("userprofile.txt", "r"))) {
        printf("Welcome new user!\n");
        userProfile = fopen("userprofile.txt", "w");


        printf("Could you please tell me your name!\n");

        char str1[100];

        scanf("%s", str1);

        fputs(str1, userProfile);
        //fclose(userProfile);


    } else {

        //Check that we can actually get the data from the file
        fgets(name, 100, userProfile);

        if(name[0] == 0) {
            //The data has been ruined somehow, so fix it.
            printf("There's a problem with the userprofile file!\n");

            userProfile = fopen("userprofile.txt", "w");

            printf("Could you please tell me your name again!\n");

            scanf("%s", name);
            fputs(name, userProfile);
        }
        printf("Welcome back %s!\n", name);
    }


    FILE *day;
    char fileLoc[100];
    int noTalk = 0;
    printf("How was your day? Please write about and give me the file location!\n");
    while(!(day = fopen(fileLoc, "r"))) {
        scanf("%s", fileLoc);
        noTalk++;

        if(noTalk < 5 && !(day = fopen(fileLoc, "r"))) {
            printf("I can't find the file you specified %s!\n",name);
        } else if(noTalk >= 5) {
            printf("I still can't find the file. Would you prefer not to talk about your day? Y/N\n");
            char str1[100];
            scanf("%s", str1);
            if(!strcmp(str1, "Y") || !strcmp(str1,"y")) {
                break;
            }
            printf("Ok, give me the file location again please!\n");
            noTalk = 0;
        }

    }

    if(noTalk >= 5) {
        printf("It's ok %s, you don't have to tell me if you don't want to. Would you rather talk about something else?\n", name);
    } else {

        dayResponse(day);
    }

    return 0;


}