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


    printf("How was your day? Please write about it and give me the file location!\n");
    if(getFileForType(DAY) == -1) {
        printf("Ok, I am here when you are ready to talk.\n");
        exit(0);
    }
    printf("How are you feeling today? Please write about it and give me the file location!\n");
    if(getFileForType(FEEL) == -1) {
        printf("Ok, I am here when you are ready to talk.\n");
        exit(0);
    }

    return 0;


}