#include "list.h"
#include <stdio.h>

typedef struct Client
{
    uint32_t client_id;
    int32_t threads;
    uint8_t is_empty;

}Client;

void print_element(void* elem)
{
    Client* cli = (Client*)elem;
    printf("ID [%u], TID [%d], E [%d]\n", cli->client_id, cli->threads, cli->is_empty);
}

void* check_element(void* elem)
{
    Client* cli = (Client*)elem;

    if (cli->is_empty == 0) return NULL;
    else                    return elem;
}

int main()
{
    Client cli;
    cli.client_id = 5;
    cli.threads = 11;
    cli.is_empty = 0;

    List* head = list_create(&cli, sizeof(cli));    
    
    for(uint16_t i = 0; i < 5; ++i)
    {
        cli.client_id++;
        cli.threads++;
        cli.is_empty = 0;
        
        if (i == 3)
            cli.is_empty = 1;

        list_push_back(head, &cli, sizeof(cli));
    }

    list_print(head, print_element);
    printf("------------------------------------\n");

    Client* _cli;
    _cli = (Client*)list_find(head, check_element);
    if (_cli != NULL)
    {
        _cli->client_id = 999;
        _cli->threads = 555;
        _cli->is_empty = 0;
    }

    list_print(head, print_element);

    list_destroy(head);

    return 0;
}
