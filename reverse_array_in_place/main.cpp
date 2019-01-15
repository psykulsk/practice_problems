#include <iostream>
#include <array>


template<class T, size_t size>
void reverse_array(std::array<T, size> &arr){
    if(arr.size() == 0)
        return;
    size_t front = 0;
    size_t back = arr.size() -1;

    while((front < back)){
       T tmp = arr.at(front);
       arr.at(front) = arr.at(back);
       arr.at(back) = tmp;
       ++front;
       --back;
    }
}

int main() {
    std::array<int, 4> arr = {1,2,3,4};
    reverse_array<int,4>(arr);
    for(int i : arr)
        std::cout << i << " ";
    std::cout << "\n";
    return 0;
}