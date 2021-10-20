#include <iostream>

auto main(int argc, char* argv[]) -> int {
    int liczba;

    if (argc == 1) {
        liczba = 99;
    } else {
        liczba = std::stoi(argv[1]);
    }

    for (auto i = liczba; i >= 0; i--) {
        if (i == 0) {
            std::cout << "No more bottles of beer on the wall, no more bottles of beer. \n";
            std::cout << "Go to the store and buy some more, 99 bottles of beer on the wall... \n" << std::endl;
        } else if (i == 1) {
            std::cout << i << " bottle of beer on the wall, " << i << " bottle of beer. \n";
            std::cout << "Take one down, pass it around, " << (i-1) << " bottles of beer on the wall... \n" << std::endl;
        } else {
            std::cout << i << " bottles of beer on the wall, " << i << " bottles of beer. \n";
            std::cout << "Take one down, pass it around, " << (i-1) << " bottles of beer on the wall... \n" << std::endl;
        }
    }

    return 0;
}
