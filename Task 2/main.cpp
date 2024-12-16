#include <iostream>
#include "calculator.h"

int main() {
    int a = 7, b = 3;

    std::cout << "Addition: " << add(a, b) << std::endl;
    std::cout << "Subtraction: " << subtract(a, b) << std::endl;

    return 0;
}
