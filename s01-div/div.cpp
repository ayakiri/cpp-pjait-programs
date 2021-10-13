#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int {
    auto const a = std::stof(argv[1]);
    auto const b = std::stof(argv[2]);
    if (b == 0){
        std::cout << "Nie dziel przez 0\n";
    } else {
        std::cout << (a / b) << "\n";
    }
    return 0;
}
