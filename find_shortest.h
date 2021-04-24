#ifndef FIND_SHORTEST__H 
#define FIND_SHORTEST__H

typedef struct Path {
    long int cur_id; // current node id
    double lat; // latitude of node
    double lon; // longitude of node
    bool visited; // visted or not
    double dis; // distance between two nodes
    long int par_id; // parent node id
    struct Node *next; // Pointer to next node
}Path;


// use dijkstra algorithm to find shortest path
// Path would contain every node and it's nearest
// node with path length between begin node and
// current node
int find_shortest(int begin, int end);

void start_interface(void);


#endif