//
// Created by pitersk on 27.12.18.
//

#ifndef MAX_HEAP_MAXHEAP_H
#define MAX_HEAP_MAXHEAP_H


#include <vector>
#include <stdexcept>

template<class T>
class MaxHeap {
    std::vector<T> heap_data;
    void build_heap(std::vector<T> unsorted_data){
        heap_data = unsorted_data;
        if(unsorted_data.empty())
            return;
        for(size_t i=parent_index(heap_data.size()); i > 0; --i){
            heapify(i-1);
        }
    }

    inline size_t left_index(size_t i) const{
        return (i<<1) + 1;
    }
    inline size_t right_index(size_t i) const {
        return (i<<1) + 2;
    }
    inline size_t parent_index(size_t i) const {
        return (i-1)>>1;
    }

public:


    MaxHeap(std::vector<T> data_to_heap){
        build_heap(data_to_heap);
    }

    MaxHeap(){}

    void heapify(size_t i){
        if(i >= heap_data.size())
            throw std::runtime_error("Index too large");
        size_t left = left_index(i);
        size_t right = right_index(i);
        size_t largest = i;
        if(left < heap_data.size() && heap_data.at(left) > heap_data.at(i))
            largest = left;
        if(right < heap_data.size() && heap_data.at(right) > heap_data.at(largest))
            largest = right;
        if( largest != i){
            std::swap(heap_data.at(i), heap_data.at(largest));
            heapify(largest);
        }

    }

    T max() {
        if(heap_data.empty())
            throw std::runtime_error("Max called on empty heap");
        return heap_data.at(0);
    }
    T extract_max(){
        if(heap_data.empty())
            throw std::runtime_error("Max called on empty heap");
        T max = heap_data.at(0);
        std::swap(heap_data.at(0), heap_data.at(heap_data.size()-1));
        heap_data.pop_back();
        if(!heap_data.empty())
            heapify(0);
        return max;
    }
    void insert(T to_insert){
        heap_data.push_back(to_insert);
        size_t index = heap_data.size()-1;
        while(index > 0 && heap_data.at(parent_index(index)) < to_insert){
            std::swap(heap_data.at(index), heap_data.at(parent_index(index)));
            index = parent_index(index);
        }
    }

    T& operator [](const size_t &index) {
        return heap_data.at(index);
    }

    const T& operator [](const size_t &index) const {
        return heap_data.at(index);
    }

    T& at(const size_t &index) {
        return operator[](index);
    }

    T& at(const size_t &index) const{
        return operator[](index);
    }

    size_t size() const {
        return heap_data.size();
    }
};


#endif //MAX_HEAP_MAXHEAP_H
