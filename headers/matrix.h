#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;
class Matrix
{
public:
    vector<vector<double>> elements;
    int rows, columns;

    Matrix(int rows, int columns);

    Matrix operator+(Matrix m);
    Matrix operator-(Matrix m);
    Matrix operator*(double a);
    Matrix operator*(Matrix m);
    
    void print();
    double getElementAt(int row, int column);
    void setElementAt(int row, int column, double element);
    
    void mult_row(int row, double scalar);
    void div_row(int row, double scalar);
    void mult_column(int row, double scalar);
    void div_column(int row, double scalar);

    Matrix transp();

    // static methods
    static Matrix identity(int rows, int columns);
};