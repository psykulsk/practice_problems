#include <iostream>
#include <vector>
#include <array>

template<size_t nr_of_nodes>
using Graph = std::array<std::array<int, nr_of_nodes>, nr_of_nodes>;


template<size_t nr_of_nodes>
std::vector<size_t> astar_shortest_path(Graph<nr_of_nodes> graph, size_t start_id, size_t end_id){

}

int main() {
    Graph<5> graph = {{
                              {1,1,1,1,1}.
                              {1,0,0,0,}
    }};
    std::cout << "Hello, World!" << std::endl;
    return 0;
}