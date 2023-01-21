
#ifndef _LEETCODE_LIST_H_
#define _LEETCODE_LIST_H_ 1

#include "common.h"
#include <inttypes.h>

#define LIST_DEFAULT_SIZE 25
#define LIST_MAX_SIZE __LONG_MAX__ 

typedef struct ListHead lhead_t;
typedef struct ListNode lnode_t;

lhead_t* createList();
#endif