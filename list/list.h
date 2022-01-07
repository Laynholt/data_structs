#ifndef _LIST_H_
#define _LIST_H_

#include <malloc.h>
#include <stdint.h>
#include <string.h>

typedef struct List_node
{
    void* data;
    struct List_node* next;

}List_node;

typedef struct List
{
    struct List_node* head;
    uint16_t size;
    
}List;

extern void list_create(List* list, void* data, size_t data_size);
extern void list_destroy(List* list);
extern void list_push_back(List* list, void* data, size_t data_size);
extern int16_t list_erase(List* list, void* data, size_t data_size);
extern void list_clear(List* list);

extern void list_print(List* list, void (*_print_list_element)(void*));
extern void* list_find(List* list, void* (*_check_element)(void*));

#endif
