#include "interface.h"
#include "find_shortest.h"
#include "file_management.h"


extern Node *graph[4000];


int find_shortest(long int begin, const long int end) {
    double tolerance = 0.000001;
    int result = 1, min = INF, next_ture = -1;

    // calculate the shortest path between begin node and
    // every other nodes. Store the lenth of path and parent id
    // in the tot_dis and par_id of relevent node
    for (int i = 0; graph[i] != NULL; ++i) {
        if (begin == graph[i]->id) {
            // set the first node visited
            graph[i]->visited = true;
            graph[i]->tot_dis = 0;
            graph[i]->par_id = -1;
            for (; graph[i]->id != end; ) {
                // go through neighbor
                Neighbor *current = graph[i]->near;
                for (; current != NULL; current = current->next) {
                    Node *target = graph[current->index];
                    if (graph[i]->tot_dis == INF)
                        graph[i]->tot_dis = 0;
                    // find node which is closest to the begin node in neighborhood
                    if (current->dis+graph[i]->tot_dis < target->tot_dis && target->visited == false && fabs(current->dis+graph[i]->tot_dis - target->tot_dis) > tolerance) {
                        
                        target->tot_dis = current->dis+graph[i]->tot_dis;
                        target->par_id = i;

                    }
                }
                
                // the node would be marked as "visited"
                // if it is the closest node to the source node
                
                for (int j = 0; graph[j] != NULL; ++j) {
                    if (graph[j]->visited == false)
                        if (graph[j]->tot_dis < min) {
                            min = graph[j]->tot_dis;
                            next_ture = j;
                        }                    
                }
                min = INF;
                graph[next_ture]->visited = true;
                
                // this node would be next source node
                i=next_ture;
            }
            result = 0;
            break;
        }
    }

    return result;
}

int store_shortest (FILE *file, const long int end) {
    int result = 1;
    // write shortest path into a txt file
    if (file == NULL)
        result = 1;
    else {
        for (int i = 0; graph[i] != NULL; ++i) {
            if (graph[i]->id == end) {
                while(i != -1) {
                    fprintf(file, "%lf %lf\n", graph[i]->lon, graph[i]->lat);
                    i = graph[i]->par_id;
                    if (i != -1)
                        fprintf(file, "%lf %lf\n\n", graph[i]->lon, graph[i]->lat);
                    else
                        break;
                }
                result = 0;
                break;
            }
        }
    }
    return result;
}
