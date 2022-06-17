#include <matrix.h>

//constructor
MATRIX::MATRIX(int _in_row, int _in_col){
    row = _in_row;
    col = _in_col;
    data = new float*[row];
    for (int i = 0; i < row; i++){
        data[i] = new float[col];
    }
    return;
}
//destructor
MATRIX::~MATRIX(){
    for (int i = 0; i < row; i++){
        delete[]data[i];
    }
    delete[]data;
}
