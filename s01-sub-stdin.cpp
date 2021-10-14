#include <iostream>
#include <string>

auto zapytaj_o_liczbe(std::string prompt) -> int {
    std::cout << prompt << "(integer) ";
    auto liczba = std::string{};
    std::getline(std::cin, liczba);
    return std::stoi(liczba);
}

auto main(int argc, char* argv[]) -> int {
    auto const a = zapytaj_o_liczbe("a = ");
    auto const b = zapytaj_o_liczbe("b = ");
    std::cout << (a - b) << "\n";
    return 0;
}

