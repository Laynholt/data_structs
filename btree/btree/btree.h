#ifndef _BTREE_H_
#define _BTREE_H_

#include "entity.h"

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define T 3
#define M 2*T-1

typedef struct Node
{
    uint8_t size;
    uint8_t is_leaf;
    uint16_t id_node;
    struct Node* parent;
    struct Node** childs;
    Entity* entities;    
    
}Node;

typedef struct Btree
{
    Node* root;
    uint16_t tree_size;

}Btree;

extern void create_btree(Btree* tree);
extern void destroy_btree(Btree* tree);

extern void add_entity(Btree* tree, Entity* entity);
extern int16_t remove_entity(Btree* tree, uint64_t key);

extern Node* find_node(Node* node, uint16_t node_id);
extern Entity* find_entity(Btree* tree, uint64_t key);
extern void print_btree(Btree* tree);
extern void print_btree_modern(Btree* tree);
extern void print_btree_to_file(Btree* tree, char* path);
extern void print_btree_to_file_modern(Btree* tree, char* path);

#endif
