#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_utils.h"

typedef enum {
    DAY,
    FEEL,
    OTHER

}question;

void dayResponse(FILE *day);

void feelResponse(FILE *feel);

void triggerStr(char* userStr, question);

int getFileForType(question);