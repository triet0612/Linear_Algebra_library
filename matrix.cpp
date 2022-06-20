#include <matrix.h>

//constructor-destructor
MATRIX::MATRIX(int _in_row, int _in_col){
    row = _in_row;
    col = _in_col;
    data = new float*[row];
    for (int i = 0; i < row; i++){
        data[i] = new float[col];
    }
    return;
}
MATRIX::~MATRIX(){
    for (int i = 0; i < row; i++){
        delete[]data[i];
    }
    delete[]data;
}

//operators
MATRIX MATRIX::operator+(MATRIX _sec_matrix){
            if (this->row != _sec_matrix.col)
                return *this;
            else if (this->row != _sec_matrix.col)
                return *this;
            for (int i = 0; i < this->row; i++){
                for (int j = 0; j < this->col; j++){
                    this->data[i][j] += _sec_matrix.data[i][j];
                }
            }
            return *this;
        }
MATRIX MATRIX::operator-(MATRIX _sec_matrix){
    if (this->row != _sec_matrix.col)
        return *this;
    else if (this->row != _sec_matrix.col)
        return *this;
    for (int i = 0; i < this->row; i++){
        for (int j = 0; j < this->col; j++){
            this->data[i][j] = _sec_matrix.data[i][j];
        }
    }
    return *this;
}
//this will both change the size of matrix and its data
MATRIX& MATRIX::operator=(const MATRIX& _copy_matrix){
    this->~MATRIX();
    this->row = _copy_matrix.row;
    this->col = _copy_matrix.col;
    this->data = _copy_matrix.data;
}
bool MATRIX::operator==(MATRIX _sec_matrix){
    bool ans = true;
    ans *= (_sec_matrix.col == this->col) && (_sec_matrix.row == this->row);
    for (int i = 0; i < this->row && ans; i++){
        for (int j = 0; j < this->col && ans; j++){
            ans *= (this->data[i][j] == _sec_matrix.data[i][j]);
        }
    }
    return ans;
}
bool MATRIX::operator!=(MATRIX _sec_matrix){
    bool ans = true;
    ans *= (_sec_matrix.col != this->col) || (_sec_matrix.row != this->row);
    for (int i = 0; i < this->row && ans; i++){
        for (int j = 0; j < this->col && ans; j++){
            ans *= (this->data[i][j] != _sec_matrix.data[i][j]);
        }
    }
    return ans;
}
//product
MATRIX MATRIX::operator*(MATRIX _sec_matrix){
    MATRIX ans = MATRIX(this->row, _sec_matrix.col);
    for (int i = 0; i < ans.row; i++){
        for (int j = 0; j < ans.col; j++){
            ans.data[i][j] = rowA_colB(this->data, _sec_matrix.data, i, j);
        }
    }
    return ans;
}        

//private functions
int MATRIX::rowA_colB(float **A, float **B, int row, int col){
    int ans = 0;
    for (int i = 0; i < row; i++){
        ans += A[row][i]*B[i][col];
    }
    return ans;
}

//public functions
bool MATRIX::Invert(MATRIX &Target){

}
bool MATRIX::IsSquare(MATRIX Target){
    return Target.col == Target.row;
}
int MATRIX::Determinant(MATRIX Target){

}
void MATRIX::Transpose(){
    swap(this->row, this->col);
    float **temp = this->data;
    this->data = new float*[row];
    for (int i = 0; i < this->row; i++){
        this->data[i] = new float[this->row];
        for (int j = 0; j < this->col; j++){
            this->data[i][j] = temp[j][i];
        }
    }
    for (int i = 0; i < this->col; i++){
        delete[]temp[i];
    }
    delete[]temp;
}
MATRIX MATRIX::ReduceEchelon(MATRIX Target){

}