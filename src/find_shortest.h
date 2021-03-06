#ifndef FIND_SHORTEST__H 
#define FIND_SHORTEST__H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


// use dijkstra algorithm to find shortest path
// Path would contain every node and it's nearest
// node with path length between begin node and
// current node
int find_shortest(long int begin, long int end);
int store_shortest(FILE *file, long int end);


#endif
