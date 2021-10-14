
#include <iostream>
#include <string>

auto zapytaj_o_liczbe(std::string prompt) -> float {
    std::cout << prompt << "(float) ";
    auto liczba = std::string{};
    std::getline(std::cin, liczba);
    return std::stof(liczba);
}

auto main(int argc, char* argv[]) -> int {
    auto const a = zapytaj_o_liczbe("a = ");
    auto const b = zapytaj_o_liczbe("b = ");
    if(b == 0){
        std::cout << "Nie dziel przez 0!\n";
    } else {
        std::cout << (a / b) << "\n";
    }

    return 0;
}
