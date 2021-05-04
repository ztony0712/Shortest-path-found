#include "unity.h"
#include "../src/file_management.h"
#include "../src/find_shortest.h"
#include "../src/interface.h"


extern Node *graph[4000];

void test_load_map() {
    FILE *file = fopen("../data/Final_Map.map", "r");
    int result = 1;
    result = load_map(file);
    

    TEST_ASSERT_EQUAL_INT(0, result);
    TEST_ASSERT_NOT_NULL(graph[0]);
    


}

void test_store_map() {
    FILE *file = fopen("../data/map_nodes.txt", "w+");
    
    int result = 1;
    result = store_map(file);
    

    TEST_ASSERT_EQUAL_INT(0, result);
    TEST_ASSERT_NOT_NULL(graph[0]);
    


}

void test_find_shortest (){
    long int begin = 298186510, end = -8761;
    int result = 1;

    result = find_shortest(begin, end);


    TEST_ASSERT_EQUAL_INT(0, result);
    
}

void test_store_shortest() {
    
    FILE *file = fopen("../data/shortest.txt", "w+");
    int result = 1;
    result = store_shortest(file, -8761);
    

    TEST_ASSERT_EQUAL_INT(0, result);
    TEST_ASSERT_NOT_NULL(graph[0]);
    
}


void setUp(){

}
void tearDown(){

}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_load_map);
    RUN_TEST(test_store_map);
    RUN_TEST(test_find_shortest);
    RUN_TEST(test_store_shortest);


  return UNITY_END();
}
