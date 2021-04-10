// Every line starting with # is a preprocessor directive
/*
    This is a directive that tells the processor to
    include the contents of file
*/
#include <iostream>

int main() {
    // std::endl = used to start a new line
    std::cout << "start!" << std::endl;
    std::cout << "end!";
    return 0;
}