#include "lc_string.h"


struct Token {
    unsigned int size;
    char **tokens;
};

token_t* tokenizer(char *text, char *delimeter)
{
    if(isempty(text) && !delimeter) {
        return NULL;
    }

    const unsigned int DEFAULT_SIZE = 10;
    unsigned int current_size = DEFAULT_SIZE;
    unsigned int token_number = 0;
    bool reached_threshold = ((current_size - token_number) == 5) ? true : false;

    char **tokens = (char **) malloc(sizeof(char*) * DEFAULT_SIZE);
    char *token = strtok(text, delimeter);

    while(token != NULL)
    {
        //printf("token = %s, length = %lu\n", token, strlen(token));
	    char *__token = (char*) malloc(strlen(token)+1);
	    if(__token) {
		strcpy(__token, token);
		*(tokens + token_number) = __token;
		token_number++;
	    }
	    if(reached_threshold) {
	    	current_size += DEFAULT_SIZE;
		tokens = (char**) realloc(tokens, current_size);
	    }
	    token = strtok(NULL, delimeter);
    }

    token_t *result = NULL;
    if(tokens != NULL && token_number > 0)
    {
        result = (token_t*) malloc(sizeof(token_t));
        result->size = token_number;
        result -> tokens = tokens;
    }

    return result;
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

void cleanup(token_t* toks) {
    if(toks)
    {
        if(toks && toks->size > 0 && toks->tokens) {
            for(int i = 0;i < toks->size; i++) {
                if(*(toks->tokens + i)) {
                    free (*(toks->tokens + i));
                    *(toks->tokens + i) = NULL;
                }
            }
        }
        if(toks && toks->tokens) {
            toks->size = 0;
            free(toks->tokens);
            toks->tokens = NULL;
        }
    
        if(toks) {
            free(toks);
            toks = NULL;
        }
    }
}
