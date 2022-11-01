#include <iostream>
#include "LStack.h"

int main() {
    LStack<int> test;
    for (int i = 0; i < 10; i++) { //pushes 10 items onto the stack
        test.push(i);
    }

    std::cout << test << std::endl;
    test.reverse();
    std::cout << test << std::endl;

    return 0;
}
