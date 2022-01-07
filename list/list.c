#include "list.h"

void list_create(List* list, void* data, size_t data_size)
{
    list->head = (List_node*)malloc(sizeof(List_node));
    list->head->data = malloc(data_size);
    list->head->next = NULL;
    memcpy(list->head->data, data, data_size);
    list->size = 1;
}

void list_destroy(List* list)
{
    list_clear(list);
    list->head = NULL;
}

void list_push_back(List* list, void* data, size_t data_size)
{
    List_node* tail = list->head;

    while(tail->next != NULL)
        tail = tail->next;
    
    tail->next = (List_node*)malloc(sizeof(List_node));
    tail->next->data = malloc(data_size);
    memcpy(tail->next->data, data, data_size);
    
    tail->next->next = NULL;
    list->size += 1;
}

int16_t list_erase(List* list, void* data, size_t data_size)
{
    List_node* prev, *next;
    prev = list->head;

    // if need delete head
    if (!memcmp(list->head->data, data, data_size))
    {
        list->head = list->head->next;

        free(prev->data);
        free(prev);

        list->size -= 1;
        return 1;
    }

    uint8_t found = 0;
    while(prev != NULL)
    {
        if(!memcmp(prev->next->data, data, data_size))
        {
            found = 1;
            break;
        }
        prev = prev->next;
    }

    if (found)
    {
        next = prev->next->next;
        
        free(prev->next->data);
        free(prev->next);

        prev->next = next;
        list->size -= 1;
        return 1;
    }
    else
    {
        return 0;
    }
}

void list_clear(List* list)
{
    List_node* prev = list->head;

    // moving head
    while(list->head != NULL)
    {
        prev = list->head;
        list->head = list->head->next;

        free(prev->data);
        free(prev);
    }
    list->size = 0;
}

void list_print(List* list, void (*_print_list_element)(void*))
{
    List_node* next = list->head; 
    while(next != NULL)
    {
        _print_list_element((void*)next->data);
        next = next->next;
    }
}


void* list_find(List* list, void* (*_check_element)(void*))
{
    List_node* next = list->head;
    uint8_t found = 0;

    while(next != NULL)
    {
        if (_check_element((void*)next->data) != NULL)
        {
            found = 1;
            break;
        } 
        next = next->next;
    }

    if (!found) return NULL;
    else        return (void*)next->data;
}
