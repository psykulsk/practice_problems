#include <iostream>
#include <vector>
#include <stack>


std::vector<int> next_smaller_element_indices(const std::vector<int> &vec) {
    std::stack<size_t> no_smaller_stack;
    std::vector<int> next_smaller_indices(vec.size(), -1);

    for (size_t i = 0; i < vec.size(); ++i) {
        while (!no_smaller_stack.empty() && vec.at(no_smaller_stack.top()) > vec.at(i)) {
            next_smaller_indices.at(no_smaller_stack.top()) = static_cast<int>(i);
            no_smaller_stack.pop();
        }
        no_smaller_stack.push(i);
    }
    return next_smaller_indices;
}

int main() {
    std::vector<int> vec = {2, 1, 4, 5, 3};
    for (int i : next_smaller_element_indices(vec)) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    return 0;
}