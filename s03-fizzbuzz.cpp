#include <iostream>

auto main(int argc, char* argv[]) -> int {
    auto const liczba = std::stoi(argv[1]);

    for (auto i = 1; i <= liczba; i++){
        std::cout << "Liczba: " << i << " - ";

        if (i%3 == 0){
            std::cout << "Fizz";
        } 

        if (i%5 == 0) {
            std::cout << "Buzz";
        }

        std::cout << "\n";
    }

    return 0;
}
