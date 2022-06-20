#include <iostream>
using namespace std;

class MATRIX{
    private:
        int rowA_colB(float **A, float **B, int row, int col);
    public:
        int row;
        int col;
        float **data;
        //constructor, destructor
        MATRIX(int _in_row, int _in_col);
        ~MATRIX();
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
        int Determinant(MATRIX Target);
        void Transpose();
        MATRIX ReduceEchelon(MATRIX Target);
};