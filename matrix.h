#include <iostream>
#include <vector>
using namespace std;

class MATRIX{
    private:
        int rowA_colB(vector<vector<float>> A, vector<vector<float>> B, int row, int col);
        void simpleOperations(vector<float> &row1, vector<float> &row2);
    public:
        int row;
        int col;
        vector<vector<float>>data;
        //constructor
        MATRIX(int _in_row, int _in_col);
        //operator
        MATRIX operator+(MATRIX _sec_matrix);
        MATRIX operator-(MATRIX _sec_matrix);
        //this will both change the size of matrix and its data
        MATRIX& operator=(const MATRIX& _copy_matrix);
        bool operator==(MATRIX _sec_matrix);
        bool operator!=(MATRIX _sec_matrix);
        MATRIX operator*(MATRIX _sec_matrix);
        //functions
        bool Invert(MATRIX &Target);
        bool IsSquare(MATRIX Target);
        bool Determinant(MATRIX Target, float &det);
        void Transpose();
        MATRIX ReduceEchelon(MATRIX Target);
};