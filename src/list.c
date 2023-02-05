#include "list.h"

const unsigned int DEFAULT_LIST_SIZE = 10;

struct Record {
    void *data;
};

record_t* createList() {
    record_t *list = (record_t*) malloc(sizeof(record_t) * DEFAULT_LIST_SIZE);
    assert(list != NULL);
    return list;
}