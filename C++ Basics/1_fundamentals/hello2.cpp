#include <iostream>
#include <cstdio>

int main() {
    // :: = scope resolution operator
    std::cout << "Hello C++ #01" << std::endl;
    std::cout << "Hello C++ #02\n";

    // print with <cstdio>
    printf("Hello C++ #03\n");
    puts("Hello C++ #04");
    return 0;
}