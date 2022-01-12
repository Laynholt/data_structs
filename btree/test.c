#include "btree/btree.h"
#include "hash/hash.h"

int16_t read_data_from_file(char* str, Btree* tree)
{
    FILE* file = fopen(str, "r");

    if (file == NULL)
    {
        perror("Error opening file: ");
        return -1;
    }

    char buf[100];
    unsigned char key_str[30];
    Entity entity;

    while(fgets(buf, 100, file) != NULL)
    {
        sscanf(buf, "%s %s %s %u", key_str, entity.data.name, entity.data.surname, &entity.data.age);
        entity.key = hash(key_str);

        add_entity(tree, &entity);
    }

    fclose(file);
    return 1;
}

void print_entity(const Entity* entity)
{
    printf("Key - [%lu], Name - [%s], Surname - [%s], Age - [%u]\n", entity->key, entity->data.name, entity->data.surname, entity->data.age);
}

int main()
{
    Btree tree;

    create_btree(&tree);
    read_data_from_file("data.txt", &tree);
//   print_btree(&tree);
    print_btree_modern(&tree);
    destroy_btree(&tree);

    return 0;
}
