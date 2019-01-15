#include <iostream>
#include <array>

template< size_t size>
int max_sum(std::array<int, size> input){
    if(input.size() == 0 )
        return std::numeric_limits<int>::min();
    int max = input.at(0);
    int curr_max = input.at(0);
    for(size_t i=1; i < size; ++i){
       if(curr_max+input.at(i) > input.at(i))
           curr_max += input.at(i);
       else
           curr_max = input.at(i);
       if(curr_max > max)
           max = curr_max;
    }
    return max;
}


int main() {
    std::array<int, 3> arr = {1,2,3};
    std::array<int, 3> arr1 = {-1,-2,-3};
    std::array<int, 3> arr2 = {1,-2,3};
    std::array<int, 5> arr3 = {100,-2,-1,100};

    std::cout << "res " << max_sum<arr3.size()>(arr3) << std::endl;

    return 0;
}