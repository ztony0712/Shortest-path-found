#include "file_management.h"
#include "find_shortest.h"
#include <stdlib.h>
#include <stdio.h>

Node *graph[4000];

int main(int argc, char const *argv[])
{
    long int begin, end;
    FILE *file;
    file = fopen("Final_Map.map", "r");
    if (load_map(file) == 1)
        puts("No map file!");
    else
        puts("Map loaded.");

    file = fopen("map_nodes.txt", "w+");
    if (store_map(file) == 1)
        puts("No map file!");
    else
        puts("Map stored.");

    printf("input the id of begin node: ");
    scanf("%ld", &begin);
    getchar();
    printf("input the id of end node: ");
    scanf("%ld", &end);
    if (find_shortest(begin, end) == 1)
        printf("No path found!\n");
    else
        printf("shortest path found.\n");

    return 0;
}
