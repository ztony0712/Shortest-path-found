#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_management.h"

extern Node *graph[4000];

int load_map(FILE *file) {
    memset(graph, 0, sizeof(Node));
    char line[200];
    int i = 0;
    if (file == NULL) 
        return 1;   

    rewind(file);
    // read all nodes in graph array
    while(fgets(line, 200, file) != NULL) {

        if (strstr(line, "lon")) {
            graph[i] = (Node*) malloc(sizeof(Node));
            memset(graph[i], 0, sizeof(Node));
            sscanf(line, "%*[^=]=%ld %*[^=]=%lf %*[^=]=%lf", &graph[i]->id, &graph[i]->lat, &graph[i]->lon);
            i++;
        }
    }
    rewind(file);
    // read all links and connect them to relevant nodes
    while(fgets(line, 200, file) != NULL) {
        if (strstr(line, "link")) {
            long int container1 = 0, container2 = 0;
            double dis;
            Neighbor *new_neighbor1 = (Neighbor*) malloc(sizeof(Neighbor));
            memset(new_neighbor1, 0, sizeof(Neighbor));
            Neighbor *new_neighbor2 = (Neighbor*) malloc(sizeof(Neighbor));
            memset(new_neighbor2, 0, sizeof(Neighbor));
            
            sscanf(line, "%*[^=]=%ld %*[^=]=%ld %*[^=]=%ld %*[^=]=%ld %*[^=]=%lf", &container1, &new_neighbor1->id, &new_neighbor2->id, &container2, &dis);
            for (int i = 0; graph[i] != NULL; ++i) {
                
                // find first node id in graph array
                if (graph[i]->id == new_neighbor1->id) {
                    // give distance to both new_neighbor nodes
                    new_neighbor1->dis = new_neighbor2->dis = dis;
                    // link second node to first node
                    if (graph[i]->near == NULL) {
                        graph[i]->near = new_neighbor2;
                    } else {
                        Neighbor *current = graph[i]->near;
                        for (; current->next != NULL; current = current->next);
                        current->next = new_neighbor2;

                    }
                    // go through the array again to find the second node
                    // and link the first node to second node
                    for (int j = 0; graph[j]; ++j) {
                        if (graph[j]->id == new_neighbor2->id) {
                            if (graph[j]->near == NULL) {
                                graph[j]->near = new_neighbor1;
                            } else {
                                Neighbor *current = graph[j]->near;
                                for (; current->next != NULL; current = current->next);
                                current->next = new_neighbor1;
                            }
                        }
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
