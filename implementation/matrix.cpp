#include "../headers/matrix.h"

Matrix::Matrix(int rows, int columns) : rows(rows), columns(columns)
{
    this->elements.resize(rows, vector<double>(columns));
}

//
// OPERATORS
//

Matrix Matrix::Matrix::operator+(Matrix m)
{
    Matrix result(rows, columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            result.setElementAt(i, j, getElementAt(i, j) + m.getElementAt(i, j));
        }
    }
    return result;
}

Matrix Matrix::operator-(Matrix m)
{
    Matrix result(rows, columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            result.setElementAt(i, j, getElementAt(i, j) - m.getElementAt(i, j));
        }
    }
    return result;
}

Matrix Matrix::operator*(double a)
{
    Matrix result(rows, columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            result.setElementAt(i, j, result.getElementAt(i, j) * a);
        }
    }
    return result;
}

Matrix Matrix::operator*(Matrix m)
{
    Matrix result(rows, m.columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < m.columns; j++)
        {
            double curElement = 0;
            for (int k = 0; k < columns; k++)
            {
                curElement += getElementAt(i, k) * m.getElementAt(k, j);
            }
            result.setElementAt(i, j, curElement);
        }
    }
    return result;
}

//
// UTILS
//

void Matrix::mult_row(int row, double scalar)
{
    if (row > this->rows - 1 || row < 0) {
        cout << "\nThis Matrix does not have the " << row << " row" << endl;
        return;
    }

    for (int c = 0; c < this->columns; c++) {
        this->elements[row][c] *= scalar;
    }
}

void Matrix::div_row(int row, double scalar)
{
    if (row > this->rows - 1 || row < 0) {
        cout << "\nThis Matrix does not have the " << row << " row" << endl;
        return;
    }

    for (int c = 0; c < this->columns; c++) {
        this->elements[row][c] /= scalar;
    }
}

void Matrix::mult_column(int column, double scalar)
{
    if (column > this->columns - 1 || column < 0) {
        cout << "\nThis Matrix does not have the " << column << " column" << endl;
        return;
    }

    for (int r = 0; r < this->columns; r++) {
        this->elements[r][column] *= scalar;
    }
}

void Matrix::div_column(int column, double scalar)
{
    if (column > this->columns - 1 || column < 0) {
        cout << "\nThis Matrix does not have the " << column << " column" << endl;
        return;
    }

    for (int r = 0; r < this->columns; r++) {
        this->elements[r][column] /= scalar;
    }
}

void Matrix::setElementAt(int row, int column, double element)
{
    elements.at(row).at(column) = element;
}

double Matrix::getElementAt(int row, int column)
{
    return elements.at(row).at(column);
}

void Matrix::print()
{
    for (auto row : elements)
    {
        for (auto element : row)
        {
            std::cout << element << " ";
        }
        std::cout << "\n";
    }
}

Matrix Matrix::transp()
{
    Matrix transp(rows, columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            transp.setElementAt(i, j, getElementAt(j, i));
        }
    }
    return transp;
}

// static methods
Matrix Matrix::identity(int rows, int columns)
{
    Matrix identity(rows, columns);
    for (int i = 0; i < rows; i++)
    {
        identity.setElementAt(i, i, 1);
    }
    return identity;
}
