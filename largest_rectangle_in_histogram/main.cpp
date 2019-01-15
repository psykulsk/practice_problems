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

int largest_rectangle_area_in_histogram(const std::vector<int> &histogram) {
    int largest_area = 0;
    std::vector<int> next_smaller_indices = next_smaller_element_indices(histogram);

    for(int i=0; i<histogram.size(); ++i){
        int rect_height = histogram.at(i);
        int rect_width;
        if(next_smaller_indices.at(i) == -1){
            rect_width = histogram.size() - i;
        }else
            rect_width = next_smaller_indices.at(i) - i;
        int rect_area = rect_height * rect_width;
        if(rect_area > largest_area)
            largest_area = rect_area;
    }

    return largest_area;
}


int main() {
    std::vector<int> hist = {1, 2, 3, 4, 5, 3, 3, 2, 1, 2, 3, 4, 5, 3, 3,3, 2};
    std::cout << largest_rectangle_area_in_histogram(hist) << "\n";
    return 0;
}
