#include <iostream>

int binary_gap(int number){
    int max_gap = 0;
    int current_gap = 0;
    bool first_one_seen = false;
    while(number != 0){
        bool current_bit = (number & 1) == 1;
        if(!first_one_seen){
            if(current_bit)
                first_one_seen = true;
        }else{
            if(current_bit){
                max_gap = std::max(max_gap, current_gap);
                current_gap=0;
            }else{
                ++current_gap;
            }
        }
        number = number >> 1;

    }
    return max_gap;
}


int main() {
    std::cout << binary_gap(1) << std::endl;
    return 0;
}