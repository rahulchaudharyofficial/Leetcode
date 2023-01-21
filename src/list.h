
#ifndef _LEETCODE_LIST_H_
#define _LEETCODE_LIST_H_ 1
#include "common.h"

#define DEFAULT_MAX_LIST_SIZE 25

typedef void (*printer)(void*);

size_t append(void*);
size_t get_list_size();
void print(printer p);

#endif