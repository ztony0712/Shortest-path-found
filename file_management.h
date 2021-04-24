#ifndef FILE_MANAGEMENT__H 
#define FILE_MANAGEMENT__H


typedef struct Node {
    long int id; // Node id
    double lat; // latitude of node
    double lon; // longitude of node
    struct Node *next; // Pointer to next node
    struct Node *near; // Pointer to near node
}Node;

typedef struct Neighbor {
    long int id; // Neighbor id
    double lat; // latitude of Neighbor
    double lon; // longitude of Neighbor
    double dis; // distance between two nodes
    struct Neighbor *next // pointer to next Neighbor
}Neighbor;



// load the data set of map into an adjacency table
// returns 0 if data were loaded correctly, or -1 otherwise
int load_map(FILE *file);

//saves the data of map in a txt file
//returns 0 if data were stored correctly, or -1 otherwise
int store_map(FILE *file);



#endif