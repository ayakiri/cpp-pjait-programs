#include <iostream>
#include <string>
#include <vector>

auto main(int argc, char* argv[]) -> int {
    std::string haselko = argv[1]; 
    std::vector<std::string> all_args;

    int dostep = 0;

    do {
        std::string drugaproba; 
        std::cout << "password: ";
        std::cin >> drugaproba;
        if (drugaproba == haselko) {
            std::cout << "Correct password. Welcome!\n";
            dostep = 1;
        }
    } while (dostep == 0);

    return 0;
}
