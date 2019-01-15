#include <iostream>



void print_matrix(int rows, int cols, int* m){
    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            std::cout << *(m+i*cols+j) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void matrix_mult(int m1_rows, int m1_cols, int m2_rows, int m2_cols, int *m1 , int *m2){
    if(m1_cols != m2_rows){
       std::cout << "Wrong dimensions!\n";
       return;
    }
    int res[m1_rows][m2_cols];
    for(int i=0; i < m1_rows; ++i){
        for(int j=0; j<m2_cols; ++j){
            res[i][j] = 0;

            for(int k=0; k<m1_cols; ++k){
                int m1_factor = *(m1+i*m1_cols+k);
                int m2_factor = *(m2+k*m2_cols+j);
                res[i][j] += m1_factor*m2_factor;
            }
        }
    }

    print_matrix(m1_rows, m2_cols, (int *)res);
}

void matrix_rot_90(int m_rows, int m_cols, int *m, bool clockwise){
    int res[m_cols][m_rows];
    for(int row=0; row<m_rows; ++row){
        for(int col=0; col<m_cols; ++col){
            int val = *(m+row*m_cols+col);
            if(clockwise){
                res[col][m_rows-1-row] = val;
            }else {
                res[m_cols-1-col][row] = val;
            }
        }
    }
    print_matrix(m_cols,m_rows, (int*)res);
}


int main() {
    int m1[2][3] = {
            {0,3,5},
            {5,5,2}
    };
    int m2[3][2] = {
            {3,4},
            {3,-2},
            {4,-2}
    };

    print_matrix(2,3, (int *)m1);
    print_matrix(3,2, (int *)m2);

//    matrix_mult(2,3,3,2,(int *)m1, (int *)m2);
    matrix_rot_90(3,2, (int *)m2, false);


    return 0;
}