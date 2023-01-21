#include "list.h"

size_t current_index = -1;
size_t list_size = DEFAULT_MAX_LIST_SIZE;
node_t *list[DEFAULT_MAX_LIST_SIZE] = {EMPTY};

void extend_list()
{
        
}


size_t append(void* data)
{
    node_t *node = create_data_node(data);
    list[++current_index] = node;
}


size_t get_list_size()
{
    return list_size;
}

void print(printer p)
{
    p(list);
}