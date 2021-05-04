#include "interface.h"
#include "file_management.h"

extern Node *graph[4000];
static char line[200];

static void read_nodes(FILE *file){
    rewind(file);
    // read all nodes in graph array
    for(int i = 0; fgets(line, 200, file) != NULL; ) {

        if (strstr(line, "lon")) {
            graph[i] = (Node*) malloc(sizeof(Node));
            memset(graph[i], 0, sizeof(Node));
            graph[i]->visited = false;
            graph[i]->tot_dis = INF;

            sscanf(line, "%*[^=]=%ld %*[^=]=%lf %*[^=]=%lf", &graph[i]->id, &graph[i]->lat, &graph[i]->lon);
            ++i;
        }
    }
}

static void read_links(FILE *file){
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
                    // give distance and coordinates to both new_neighbor nodes
                    new_neighbor1->dis = new_neighbor2->dis = dis;
                    new_neighbor1->index = i;
                    // link second node to first node
                    if (graph[i]->near == NULL)
                        graph[i]->near = new_neighbor2;
                    else {
                        Neighbor *current = graph[i]->near;
                        for (; current->next != NULL; current = current->next);
                        current->next = new_neighbor2;

                    }
                    // go through the array again to find the second node
                    // and link the first node to second node
                    for (int j = 0; graph[j]; ++j) {
                        if (graph[j]->id == new_neighbor2->id) {
                            new_neighbor2->index = j;
                            if (graph[j]->near == NULL)
                                graph[j]->near = new_neighbor1;
                            else {
                                Neighbor *current = graph[j]->near;
                                for (; current->next != NULL; current = current->next);
                                current->next = new_neighbor1;
                            }
                            break;
                        }
                    }
                    break;
                }

            }
        }
    }
}

int load_map(FILE *file) {
    int result = 1;
    memset(graph, 0, sizeof(Node));
    
    if (file == NULL)
        result = 1;
    else {
        read_nodes(file);
        read_links(file);
        result = 0;
    }
    fclose(file);
    // for (int i = 0; graph[i] != NULL; ++i) {

    //     printf("%ld ", graph[i]->id);
    //     printf("%lf ", graph[i]->lat);
    //     printf("%lf\n", graph[i]->lon);
    // }

    return result;
}

int store_map(FILE *file) {
    int result = 1;
    if (graph[0] == NULL) 
        result = 1;
    else{
        
        rewind(file);
        // store nodes in file
        for (int i = 0; graph[i] != NULL; ++i) {
            if (graph[i]->near != NULL) {
                Neighbor *current = graph[i]->near;
                for (; current != NULL; current = current->next) {
                    fprintf(file, "%lf %lf\n", graph[i]->lon, graph[i]->lat);
                    fprintf(file, "%lf %lf\n\n", graph[current->index]->lon, graph[current->index]->lat);
                }
            }
            
        }
        result = 0;
    }
    fclose(file);

    return result;
}
