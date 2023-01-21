#include "list.h"


struct ListNode
{
    struct ListNode *top;
    struct ListNode *left;
    struct ListNode *right;
    struct ListNode *bottom;
    void *data;
};

struct ListHead
{
    size_t programCounter;
    size_t stackPointer;
    size_t size;
    struct ListNode *front;
    struct ListNode *rear;
};

lhead_t* createList()
{
    lhead_t *list = (lhead_t*) malloc(sizeof(lhead_t));
    assert(list != NULL);
    list->front = NULL;
    list->rear = NULL;
    list->size = LIST_DEFAULT_SIZE;
    list->programCounter = -1;
    list -> stackPointer = -1;
    return list;
}