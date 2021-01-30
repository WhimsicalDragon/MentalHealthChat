#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {


    FILE *userProfile;
    char name[100];

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
    printf("The arg was %s\n", argv[1]);

   return 0;


}