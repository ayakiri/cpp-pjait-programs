#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int {
    auto const podana_liczba = std::stoi(argv[1]);

    for (auto i = podana_liczba; i >= 0; i--){
        std::cout << i << ", \n";
    }

    return 0;
}
