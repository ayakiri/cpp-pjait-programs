#include <iostream>
#include <unistd.h>

auto main() -> int {
    std::cout << "Hello, " << getlogin() <<"!\n";
    return 0;
}

