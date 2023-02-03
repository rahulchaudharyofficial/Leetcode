#include "lc_string.h"

char** tokenizer(char *text, char *delimeter)
{
    return NULL;
}

bool isempty(char *str)
{
    bool result = true;
    if(str)
    {
        while(isspace((unsigned char) *str)) str++;
        if(*str != '\0')
            result = false;
    }
    return result;
}

char* trim(char *str)
{
    char *start = str, *end = NULL;
    if(str)
    {
        bool rm = false;
        while(isspace((unsigned char) *start)) {
            start++;
        }
        
        end = str + strlen(str) -1; //point to last location in string
        while(isspace((unsigned char) *end) && end != start) { // backtrack till its no more space and both start and end meet
            end--;
            rm = true;
        }

        if(rm) {
            str = start;
            end[1]='\0';
        }
    }
    return str;
}