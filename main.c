#include "file_management.h"
#include <stdlib.h>
#include <stdio.h>

Node *graph[4000];

int main(int argc, char const *argv[])
{
    FILE *file;
    file = fopen("Final_Map.map", "r");
    if (load_map(file) == 1)
        puts("No map file!");
    else
        puts("Map loaded.");



    return 0;
}