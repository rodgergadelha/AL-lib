#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "headers/matrix.h"

int main() {
    Matrix m(3, 3);
    m.elements[0] = {1, 2, 3};
    m.elements[1] = {4, 5, 6};
    m.elements[2] = {7, 8, 9};
    m.print();
    m.mult_row(0, 5);
    cout << endl;
    m.print();
    cout << endl;

    return 0;
}