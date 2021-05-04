#include "interface.h"
#include "file_management.h"
#include "find_shortest.h"

Node *graph[4000];

static void load_store(){
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
        puts("No graph data!");
    else
        puts("Map stored.");
}

static void find_store(){
    FILE *file;
    long int begin, end;
    /* calculate the shortest path */
    // get a begin and an end node from users
    printf("input the id of begin node: ");
    scanf("%ld", &begin);
    getchar();
    printf("input the id of end node: ");
    scanf("%ld", &end);
    // find the shortest path between
    int result = find_shortest(begin, end);
    if (result == 1)
        printf("void file or graph!\n");
    else if (result == -1)
        printf("invalid begin or end node\n");
    else {
        printf("Shortest path found.\n");
        // and store them into another txt file
        file = fopen("../data/shortest.txt", "w+");
        if (store_shortest(file, end) == 1)
            puts("No path data!");
        else
            puts("Shortest path stored.");
    }
    
    
    
}

static void free_all() {
    /* free */
    // free the Adjacency table
    for (int i = 0; graph[i] != NULL; ++i)
        if (graph[i]->near != NULL)
            for (Neighbor *current = graph[i]->near; current != NULL; current = current->next)
                free(current);
}

void start_interface(void) {
    load_store();
    find_store();
    free_all();
    return;
}

