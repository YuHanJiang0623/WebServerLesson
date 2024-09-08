#include <iostream>

int main() {

    char *str = "hello world";

    char *p = str;

    p++;

    std::cout << (char *)p << std::endl;
    std::cout << *str << std::endl;
    return 0;
}