#ifndef _LIST_H_
#define _LIST_H_

#include <malloc.h>
#include <stdint.h>
#include <string.h>

typedef struct List
{
    void* data;
    struct List* next;
    
}List;

extern List* list_create(void* data, size_t data_size);
extern void list_destroy(List* head);
extern int16_t list_push_back(List* head, void* data, size_t data_size);
extern int16_t list_erase(List* head, void* data, size_t data_size);
extern void list_clear(List* head);

extern void list_print(List* head, void (*_print_list_element)(void*));
extern void* list_find(List* head, void* (*_check_element)(void*));

#endif
