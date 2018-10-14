#include <iostream>
#include "functionAdd.hpp"
#include "functionSubtract.hpp"

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << a << " + " << b << " = " << functionAdd(a, b) << std::endl;
    std::cout << a << " - " << b << " = " << functionSubtract(a, b) << std::endl;
    return 0;
}