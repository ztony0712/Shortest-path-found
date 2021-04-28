#ifndef FILE_MANAGEMENT__H 
#define FILE_MANAGEMENT__H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define INF 20000



typedef struct Node {
    long int id; // Node id
    double lat; // latitude of node
    double lon; // longitude of node
    struct Neighbor *near; // Pointer to near node

    bool visited; // visted or not
    double tot_dis; // distance between two nodes
    int par_id; // parent node id
}Node;

typedef struct Neighbor {
    long int id; // Neighbor id
    double dis; // distance between two nodes
    int index; // use this index to find relevent information
    struct Neighbor *next; // pointer to next Neighbor
}Neighbor;


// load the data set of map into an adjacency table
// returns 0 if data were loaded correctly, or -1 otherwise
int load_map(FILE *file);

//saves the data of map in a txt file
//returns 0 if data were stored correctly, or -1 otherwise
int store_map(FILE *file);



#endif