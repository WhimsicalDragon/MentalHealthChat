#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_utils.h"

typedef enum {
    DAY,
    OTHER

}question;

void dayResponse(FILE *day);

void triggerStr(char* userStr, question);