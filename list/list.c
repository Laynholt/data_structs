#include "list.h"

List* list_create(void* data, size_t data_size)
{
    List* head = (List*)malloc(sizeof(List));
    head->data = malloc(data_size);
    head->next = NULL;
    memcpy(head->data, data, data_size);

    return head;
}

void list_destroy(List* head)
{
    clear_list(head);
    head = NULL;
}

int16_t list_push_back(List* head, void* data, size_t data_size)
{
    List* tail = head;

    while(tail->next != NULL)
        tail = tail->next;
    tail->next = (List*)malloc(sizeof(List));
    tail->next->data = malloc(data_size);
    memcpy(tail->next->data, data, data_size);
    tail->next->next = NULL;

    return 1;
}

int16_t list_erase(List* head, void* data, size_t data_size)
{
    List* prev, *next;
    prev = head;

    // if need delete head
    if (!memcmp(head->data, data, data_size))
    {
        head = head->next;
        free(prev->data);
        free(prev);
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
        return 1;
    }
    else
    {
        return 0;
    }
}

void list_clear(List* head)
{
    List* prev = head;

    // moving head
    while(head != NULL)
    {
        prev = head;
        head = head->next;

        free(prev->data);
        free(prev);
    }
}

void list_print(List* head, void (*_print_list_element)(void*))
{
    List* next = head; 
    while(next != NULL)
    {
        _print_list_element((void*)next->data);
        next = next->next;
    }
}


void* list_find(List* head, void* (*_check_element)(void*))
{
    List* next = head;
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
