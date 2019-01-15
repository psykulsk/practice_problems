#include <iostream>
#include <array>

using std::array, std::cout;


template<size_t rows, size_t cols>
using Matrix = array<array<int,rows>, cols>;


template<size_t rows, size_t cols>
int largest_square_of_ones(const Matrix<rows,cols> &matrix){
    int max_size = 0;
    Matrix<rows,cols> tmp = matrix;
    for(size_t row=0; row<matrix.size(); ++row){
        for(size_t col=0; col<matrix.at(row).size(); ++col){
            if(row > 0 && col > 0 && matrix.at(row).at(col) > 0){
                int min_neighbour = std::min(tmp.at(row-1).at(col),
                        std::min(tmp.at(row-1).at(col-1), tmp.at(row).at(col-1)));
                tmp.at(row).at(col) = min_neighbour + 1;
            }else{
                tmp.at(row).at(col) = matrix.at(row).at(col);
            }
//            cout << tmp.at(row).at(col) << " ";
            if(max_size < tmp.at(row).at(col))
                max_size = tmp.at(row).at(col);
        }
//        cout << "\n";
    }
    return max_size;
}


int main() {

    Matrix<5,5> mat = {{
            {1,1,1,1,1},
            {1,1,1,0,1},
            {1,1,1,1,1},
            {0,1,1,1,1},
            {0,0,1,1,1}
    }};

    cout << largest_square_of_ones(mat);
    return 0;
}