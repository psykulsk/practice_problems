#include <iostream>
#include <vector>
#include "MaxHeap.h"

int main() {
    std::vector<int> vec = {4,1,3,2,16,9,10,14,8,7};
//    std::vector<int> vec = {1};
    MaxHeap<int> heap(vec);

    for(size_t i=0; i<heap.size();++i){
       std::cout << heap.at(i) << " ";
    }
    std::cout << std::endl;
    size_t iterations = heap.size();
    for(int i=0; i<iterations;++i){
       std::cout << heap.extract_max() << " ";
    }
    std::cout << std::endl;

    std::cout << "Heap constructed by insertion: ";
    MaxHeap<int> heap_by_insert;

    for(int num : vec)
        heap_by_insert.insert(num);

    for(size_t i=0; i<heap_by_insert.size();++i){
        std::cout << heap_by_insert.at(i) << " ";
    }
    std::cout << std::endl;

    iterations = heap_by_insert.size();
    for(int i=0; i<iterations;++i){
        std::cout << heap_by_insert.extract_max() << " ";
    }
    std::cout << std::endl;

    std::cout << std::endl;
    return 0;
}