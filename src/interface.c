#include "interface.h"
#include "file_management.h"
#include "find_shortest.h"

Node *graph[4000];

void start_interface(void) {
    long int begin, end;
    FILE *file;

    /* load and store */
    // load data from map file
    file = fopen("../data/Final_Map.map", "r");
    if (load_map(file) == 1)
        puts("No map file!");
    else
        puts("Data loaded.");
    // store all nodes into a txt file
    file = fopen("../data/map_nodes.txt", "w+");
    if (store_map(file) == 1)
        puts("No map file!");
    else
        puts("Map stored.");

    /* calculate the shortest path */
    // get a begin and an end node from users
    printf("input the id of begin node: ");
    scanf("%ld", &begin);
    getchar();
    printf("input the id of end node: ");
    scanf("%ld", &end);
    // find the shortest path between
    // and store them into another txt file
    if (find_shortest(begin, end) == 1)
        printf("No path found!\n");
    else
        printf("Shortest path found.\n");

    /* free */
    // free the Adjacency table
    for (int i = 0; graph[i] != NULL; ++i)
        if (graph[i]->near != NULL)
            for (Neighbor *current = graph[i]->near; current != NULL; current = current->next)
                free(current);
}

