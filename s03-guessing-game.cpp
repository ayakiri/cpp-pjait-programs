#include <iostream>
#include <stdlib.h>  

auto main() -> int {
    int wylosowana, zgadywana;
    srand (time(NULL));
    wylosowana = rand() % 100 + 1; 

    do {
        std::cout << "Your guess: ";
        std::cin >> zgadywana; 
        if (zgadywana > wylosowana){
            std::cout << "Your numer is higher than this number! \n";
        } else if (zgadywana < wylosowana){
            std::cout << "Your numer is smaller than this number! \n";
        }
    } while (zgadywana != wylosowana);

    std::cout << "You are right! \n";

    return 0;
}
