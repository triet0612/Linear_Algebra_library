using namespace std;

class MATRIX{
    public:
        int row;
        int col;
        float **data;
        //constructor, destructor
        MATRIX(int _in_row, int _in_col);
        ~MATRIX();
        //operator
        MATRIX operator+(MATRIX _sec_matrix){
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
        MATRIX operator-(MATRIX _sec_matrix){
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
        MATRIX& operator=(const MATRIX& _copy_matrix){
            this->~MATRIX();
            this->row = _copy_matrix.row;
            this->col = _copy_matrix.col;
            this->data = _copy_matrix.data;
        }
        bool operator==(MATRIX _sec_matrix){
            bool ans = true;
            ans *= (_sec_matrix.col == this->col) && (_sec_matrix.row == this->row);
            for (int i = 0; i < this->row && ans; i++){
                for (int j = 0; j < this->col && ans; j++){
                    ans *= (this->data[i][j] == _sec_matrix.data[i][j]);
                }
            }
            return ans;
        }
        bool operator!=(MATRIX _sec_matrix){
            bool ans = true;
            ans *= (_sec_matrix.col != this->col) || (_sec_matrix.row != this->row);
            for (int i = 0; i < this->row && ans; i++){
                for (int j = 0; j < this->col && ans; j++){
                    ans *= (this->data[i][j] != _sec_matrix.data[i][j]);
                }
            }
            return ans;
        }
        //dot product
        float operator*(MATRIX _sec_matrix);
        //functions
        bool Invert(MATRIX &Target);
        bool IsSquare(MATRIX Target);
        int Determinant(MATRIX Target);
        void Transpose(MATRIX &Target);
        MATRIX ReduceEchelon(MATRIX Target);
};