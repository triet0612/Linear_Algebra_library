#include <matrix.h>

//constructor-destructor
MATRIX::MATRIX(int _in_row, int _in_col){
    row = _in_row;
    col = _in_col;
    return;
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
int MATRIX::rowA_colB(vector<vector<float>> A, vector<vector<float>> B, int row, int col){
    int ans = 0;
    for (int i = 0; i < row; i++){
        ans += A[row][i]*B[i][col];
    }
    return ans;
}

//public functions
bool MATRIX::Invert(MATRIX &Target){
    float det;
    if (Determinant(*this, det) == false){
        return false;
    }
    else if (det == 0){
        return false;
    }

}
bool MATRIX::IsSquare(MATRIX Target){
    return Target.col == Target.row;
}
bool MATRIX::Determinant(MATRIX Target, float &det){
    if (!IsSquare(Target)){
        return false;
    }
    MATRIX temp = ReduceEchelon(Target);
    det = 1;
    for (int i = 0; i < Target.col; i++){
        det *= Target.data[i][i];
    }
    return true;
}
void MATRIX::Transpose(){
    swap(this->row, this->col);
    MATRIX temp = *this;
    this->data.clear();
    for (int i = 0; i < this->row; i++){
        vector<float> row_temp;
        for (int j = 0; j < this->col; j++){
            row_temp.push_back(temp.data[j][i]);
        }
        this->data.push_back(row_temp);
    }
}
MATRIX MATRIX::ReduceEchelon(MATRIX Target){
    MATRIX temp = Target;
    for (int i = 0; i < temp.row-1; i++){
        for (int j = i+1; j < temp.row; i++){
            simpleOperations(temp.data[i], temp.data[j]);
        }
    }
    return temp;
}

void MATRIX::simpleOperations(vector<float> &row1, vector<float> &row2){
    if (row2[0] == 0)
        return;
    float d = row1[0]/row2[0];
    for (int i = 0; i < row1.size(); i++){
        row2[i] = row1[i] - row2[i]*d;
    }
}
