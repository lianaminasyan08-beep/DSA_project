#include <stdio.h>
#include "hash_map/c_hash_map.h"

int main() {
    printf("--- HashMap Module Demo ---\n\n");

    HashMap *map = create_hash_map(2);

    // 1. Console output showing insertion of keys
    printf("1. Insertion of Keys:\n\n");
    printf("  Inserting: 'apple' -> 'red'\n");
    hash_map_insert(map, "apple", "red");
    printf("  Inserting: 'banana' -> 'yellow'\n");
    hash_map_insert(map, "banana", "yellow");
    printf("  Inserting: 'grape' -> 'purple'\n");
    hash_map_insert(map, "grape", "purple");
    printf("\n");

    // 2. Console output showing retrieval of keys
    printf("2. Retrieval of Keys:\n\n");
    printf("  Getting 'apple': %s\n", hash_map_get(map, "apple"));
    printf("  Getting 'banana': %s\n", hash_map_get(map, "banana"));
    printf("  Getting 'grape': %s\n", hash_map_get(map, "grape"));
    printf("\n");

    // 3. Example of collision handling
    printf("3. Collision Handling:\n\n");
    printf("  Hash map capacity is 2, so collisions are expected.\n");
    printf("  'apple' and 'grape' have the same hash index.\n\n");
    printf("  Hash Map Contents:\n");
    for (int i = 0; i < map->capacity; i++) {
        printf("    Bucket %d: ", i);
        HashNode *node = map->buckets[i];
        while (node != NULL) {
            printf("[%s: %s] -> ", node->key, node->value);
            node = node->next;
        }
        printf("NULL\n");
    }
    printf("\n");

    destroy_hash_map(map);

    return 0;
}
