#include <iostream>
#include <array>
#include <queue>
#include <stack>

using std::array, std::cout,
std::queue;

struct Point {
    int row;
    int col;

    Point(int row, int col) : row(row), col(col) {}
};

template<int rows, int cols>
using Matrix = array<array<int, rows>, cols>;

const array<array<int, 2>, 4> neigh_modifiers = {{
                                                         {-1, 0},
                                                         {0, -1},
                                                         {0, 1},
                                                         {1, 0},
                                                 }};

template<int rows, int cols>
bool check_bounds(int row, int col) {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

template<int rows, int cols>
std::vector<Point> get_same_color_neighbours(const Matrix<rows, cols> &matrix,
                                             const Matrix<rows, cols> &mem, int row, int col) {
    int current_color = matrix[row][col];
    std::vector<Point> neighbours;
    for (const auto &modifiers : neigh_modifiers) {
        int neigh_row = row + modifiers[0];
        int neigh_col = col + modifiers[1];
        if (check_bounds<rows, cols>(neigh_row, neigh_col))
            if (current_color == matrix[neigh_row][neigh_col])
                if (mem[neigh_row][neigh_col] == 0)
                    neighbours.emplace_back(Point(neigh_row, neigh_col));
    }
    return neighbours;
}

template<int rows, int cols>
int bfs_connected_area(Matrix<rows, cols> &matrix, Matrix<rows, cols> &mem, int row, int col) {
    int connected_area = 0;
    queue <Point> to_search;
    to_search.emplace(Point(row, col));
    while (!to_search.empty()) {
        ++connected_area;
        Point point = to_search.front();
        to_search.pop();
        std::vector<Point> unvisited_same_colour_neighbours = get_same_color_neighbours<rows, cols>(
                matrix, mem,
                point.row,
                point.col);
        for (auto neigh : unvisited_same_colour_neighbours) {
            to_search.push(neigh);
            mem[neigh.row][neigh.col] = 1;
        }
        mem[point.row][point.col] = 1;
    }
    return connected_area;
}

template<int rows, int cols>
int dfs_connected_area(Matrix<rows, cols> &matrix, Matrix<rows, cols> &mem, int row, int col) {
    int connected_area = 0;
    std::stack<Point> to_search;
    to_search.emplace(Point(row, col));
    while (!to_search.empty()) {
        ++connected_area;
        Point point = to_search.top();
        to_search.pop();
        std::vector<Point> unvisited_same_colour_neighbours = get_same_color_neighbours<rows, cols>(
                matrix, mem,
                point.row,
                point.col);
        for (auto neigh : unvisited_same_colour_neighbours) {
            to_search.push(neigh);
            mem[neigh.row][neigh.col] = 1;
        }
        mem[point.row][point.col] = 1;
    }
    return connected_area;
}

template<int rows, int cols>
int largest_connected_component(Matrix<rows, cols> matrix) {
    Matrix<rows, cols> mem = {{0}};
    int largest_connected_area = 0;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (mem[row][col] == 0) {
                int area_size = dfs_connected_area<rows, cols>(matrix, mem, row, col);
                if (largest_connected_area < area_size)
                    largest_connected_area = area_size;
            }
        }
    }
    return largest_connected_area;
}


int main() {


    Matrix<5, 5> mat = {{
                                {1, 2, 1, 1, 1},
                                {1, 2, 1, 0, 1},
                                {1, 2, 1, 0, 1},
                                {1, 2, 1, 3, 1},
                                {1, 1, 1, 1, 1}
                        }};
    cout << largest_connected_component<5, 5>(mat) << "\n";
    return 0;
}