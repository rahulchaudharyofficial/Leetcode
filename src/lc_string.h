#ifndef _LEETCODE_STRING_H_
#define _LEETCODE_STRING_H_

    #include "common.h"
    typedef struct Token token_t;
    bool isempty(char*);
    char* trim(char*);
    token_t* tokenizer(char*, char*);
    void print_tokens(token_t*);
    void cleanup(token_t*);
#endif
