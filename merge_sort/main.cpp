#include <iostream>
#include <vector>
#include <stack>

template<class T>
void merge(std::vector<T> &numbers, size_t low, size_t mid, size_t high){
    size_t left_size = mid-low+1;
    size_t right_size = high-mid;
    T left[left_size];
    T right[right_size];
    size_t left_index = 0;
    size_t right_index = 0;
    size_t numbers_index = low;

    for(size_t i=0; i<left_size; ++i){
        left[i] = numbers.at(low+i);
    }
    for(size_t i=0; i<right_size; ++i){
        right[i] = numbers.at(mid+1+i);
    }

    while(left_index < left_size && right_index < right_size){
        if(left[left_index] <= right[right_index]) {
            numbers.at(numbers_index) = left[left_index];
            ++left_index;
        }else{
            numbers.at(numbers_index) = right[right_index];
            ++right_index;
        }
        ++numbers_index;
    }

    while(left_index < left_size){
        numbers.at(numbers_index) = left[left_index];
        ++left_index;
        ++numbers_index;
    }
    while(right_index < right_size){
        numbers.at(numbers_index) = right[right_index];
        ++right_index;
        ++numbers_index;
    }
}

template< class T>
void merge_sort(std::vector<T> &numbers, size_t low, size_t high){
    if(low < high){
        size_t mid = (high+low)/2;
        merge_sort(numbers, low, mid);
        merge_sort(numbers, mid+1,high);
        merge<T>(numbers, low,mid,high);
    }
}

template< class T>
void merge_sort_iterative(std::vector<T> &numbers){
    size_t n = numbers.size();
    for (size_t curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
    {
        // Pick starting point of different subarrays of current size
        for (size_t left_start=0; left_start<n-1; left_start += 2*curr_size)
        {
            // Find ending point of left subarray. mid+1 is starting
            // point of right
            size_t mid = std::min(left_start + curr_size - 1, n-2);

            size_t right_end = std::min(left_start + 2*curr_size - 1, n-1);

            // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
            merge(numbers, left_start, mid, right_end);
        }
    }

}


int main() {
    std::vector<int> vec = {5,1,-1,401,4,2,2,2,15,60,10};
    merge_sort_iterative<int>(vec);
    for(int num : vec){
        std::cout<< num << " ";
    }
    std::cout << "\n";
    return 0;
}