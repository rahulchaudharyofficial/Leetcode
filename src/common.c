#include "common.h"

struct NodeLink
{
    struct NodeLink *previous;
    struct NodeLink *next;
    void *data;
};

struct HeadLink
{
    struct NodeLink *front;
    struct NodeLink *rear;
    size_t size;
};


head_t* create_head()
{
    head_t *head = (head_t*) malloc(sizeof(head_t));
    if(head)
    {
        head->front = NULL;
        head->rear = NULL;
        head->size = 0;
    }
    return head;
}

node_t* create_node()
{
    node_t *node = (node_t*) malloc(sizeof(node_t));
    if(node)
    {
        node->data = NULL;
        node->previous = NULL;
        node->next = NULL;
    }
    return node;
}

node_t* create_data_node(void* data)
{
    node_t *node = (node_t*) malloc(sizeof(node_t));
    if(node)
    {
        node->data = data;
        node->previous = NULL;
        node->next = NULL;
    }
    return node;
}

node_t* create_full_node(node_t* previous, node_t* next, void* data)
{
    node_t *node = (node_t*) malloc(sizeof(node_t));
    if(node)
    {
        node->data = data;
        node->previous = previous;
        node->next = next;
    }
    return node;
}

void destroy(head_t* head)
{
    if(head)
    {
        node_t *node = head->front;
        while(node != EMPTY)
        {
            head->front = node->next;
            free(node);
            node = head->front;
        }
    }
}

void destroy_node(node_t* node)
{
    if(node)
        free(node);
}

bool is_empty(head_t* head)
{
    return (head != NULL && head->size > 0 && head->front != NULL && head->rear != NULL);
}

size_t size(head_t* head)
{
    if(head)
        return head->size;
    else
        return EMPTY_STACK_SIZE;
}

node_t* front(head_t* head)
{
    if(head)
        return head->front;
    else
        return EMPTY;
}

node_t* rear(head_t* head)
{
    if(head)
        return head->rear;
    else
        return EMPTY;
}