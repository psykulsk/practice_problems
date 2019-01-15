#include <iostream>
#include <algorithm>
#include <array>
#include <stack>

template <class T, size_t size>
void quick_sort(std::array<T,size> &numbers, size_t l, size_t r){
    if( l < r){
        // The last element in the processed chunk is selected as the pivot
        T pivot_val = numbers.at(r);
        size_t pivot_index = l;
        for(size_t i=l; i < r; ++i){
            if(numbers.at(i) < pivot_val){
                std::swap(numbers.at(i), numbers.at(pivot_index));
                ++pivot_index;
            }
        }
        std::swap(numbers.at(r), numbers.at(pivot_index));
        size_t next_r_index = pivot_index -1;
        if(pivot_index == 0){
            next_r_index = 0;
        }
        quick_sort(numbers, l, next_r_index);
        quick_sort(numbers, pivot_index+1, r);
    }
}


template <class T, size_t size>
void quick_sort_iterative(std::array<T,size> &numbers) {
    std::stack<size_t> tmp_stack;

    tmp_stack.push(0);
    tmp_stack.push(numbers.size()-1);


    while(!tmp_stack.empty()){
        size_t high = tmp_stack.top();
        tmp_stack.pop();
        size_t low = tmp_stack.top();
        tmp_stack.pop();

        size_t pivot_index = low;
        T pivot_val = numbers.at(high);
        for(size_t i = low; i<high; ++i){
            if(numbers.at(i) < pivot_val){
                std::swap(numbers.at(i), numbers.at(pivot_index));
                ++pivot_index;
            }
        }
        std::swap(numbers.at(high), numbers.at(pivot_index));

        if(pivot_index < high -1){
            tmp_stack.push(pivot_index+1);
            tmp_stack.push(high);
        }
        if(pivot_index > low + 1){
            tmp_stack.push(low);
            tmp_stack.push(pivot_index-1);
        }
    }

}

int main() {
    std::array<int,16> numbers = {3,4,2,1,10,9,9,1,3,1,4,1,2,1,-5, 10023};
//    quick_sort<int, static_cast<size_t>(numbers.size())>(numbers, 0, numbers.size()-1);
    quick_sort_iterative<int, numbers.size()>(numbers);
    std::cout << "Result: ";
    for(const auto& num : numbers){
        std::cout << num << " ";
    }
    std::cout<<std::endl;
    return 0;
}