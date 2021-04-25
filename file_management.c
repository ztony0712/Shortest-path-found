#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_management.h"

extern Node *graph[4000];

int load_map(FILE *file) {
    char line[200];
    int i = 0;
    if (file == NULL) 
        return 1;   

    rewind(file);
    while(fgets(line, 200, file) != NULL) {

        if (strstr(line, "lon")) {
            graph[i] = (Node*) malloc(sizeof(Node));
            memset(graph[i], 0, sizeof(Node));
            sscanf(line, "%*[^=]=%ld %*[^=]=%lf %*[^=]=%lf", &graph[i]->id, &graph[i]->lat, &graph[i]->lon);
            i++;
        }
    }
    rewind(file);
    while(fgets(line, 200, file) != NULL) {
        if (strstr(line, "link")) {
            long int source_id = 0, container1 = 0, container2 = 0;
            Neighbor *new_neighbor = (Neighbor*) malloc(sizeof(Neighbor));
            memset(new_neighbor, 0, sizeof(Neighbor));
            sscanf(line, "%*[^=]=%ld %*[^=]=%ld %*[^=]=%ld %*[^=]=%ld %*[^=]=%lf", &container1, &source_id, &new_neighbor->id, &container2, &new_neighbor->dis);
            for (int i = 0; graph[i] != NULL; ++i) {
                
                if (graph[i]->id == source_id) {
                    // new_neighbor->next = graph[i]->near;
                    if (graph[i]->near == NULL) {
                        graph[i]->near = new_neighbor;
                    } else {
                        Neighbor *current = graph[i]->near;
                        for (; current->next != NULL; current = current->next);
                        current->next = new_neighbor;

                    }
                    
                }
            }
        }
    }

    for (int i = 0; graph[i] != NULL; ++i) {

        printf("%ld\n", graph[i]->id);
    }

    return 0;
}

int store_map(FILE *file) {
 return 1;
}
