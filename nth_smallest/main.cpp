#include <iostream>
#include <algorithm>
#include <vector>

template<class T>
T nth_smallest(std::vector<T> &numbers, size_t n, size_t l, size_t r) {
    if (n > l - r + 1)
        throw std::domain_error("N too large");
    size_t pivot_index = l;
    size_t pivot_val = numbers.at(r);
    for (size_t i = l; i < r; ++i) {
        if (numbers.at(i) < pivot_val) {
            std::swap(numbers.at(i), numbers.at(pivot_index));
            ++pivot_index;
        }
    }
    std::swap(numbers.at(pivot_index), numbers.at(r));
    if (pivot_index == n - 1) {
        return pivot_val;
    } else if (pivot_index > n - 1) {
        size_t next_r_index = pivot_index - 1;
        if (pivot_index == 0)
            next_r_index = 0;
        return nth_smallest(numbers, n, l, next_r_index);
    } else if (pivot_index < n - 1)
        return nth_smallest(numbers, n, pivot_index + 1, r);
}


int main() {
    std::vector<int> numbers = {5, 14,13, 3, 6, 10,12,1,2};
    std::cout << nth_smallest<int>(numbers, 8, 0, numbers.size() - 1) << std::endl;
    return 0;
}