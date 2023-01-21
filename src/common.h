#ifndef _LEETCODE_COMMON_H_
#define _LEETCODE_COMMON_H_ 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define EMPTY_STACK_SIZE -1
#define EMPTY NULL

typedef struct HeadLink head_t;
typedef struct NodeLink node_t;

head_t* create_head();

node_t* create_node();
node_t* create_data_node(void*);
node_t* create_full_node(node_t*, node_t*, void*);

void destroy(head_t*);
void destroy_node(node_t*);

bool is_empty(head_t*);
size_t size(head_t*);

node_t* front(head_t*);
node_t* rear(head_t*);
#endif