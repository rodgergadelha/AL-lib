#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "headers/matrix.h"

int main() {
    Matrix m(5, 5);
    Matrix n(5, 5);
    Matrix i = Matrix::identity(5, 5);
    m.setElementAt(0, 0, 1);
    m.setElementAt(0, 1, 2);
    Matrix p = m.transp();

    m.print();
    std::cout << "\n\n";
    p.print();

    return 0;
}