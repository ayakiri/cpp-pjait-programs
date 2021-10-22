#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>


auto main(int argc, char* argv[]) -> int {
    std::vector<std::string> flagi {};
    std::vector<std::string> argumenty {};

    // przeniesienie argumentow do listy argumentow i flag

    for(int i = 1; i < argc; ++i){        
        if(argv[i][0] == '-'){
            flagi.push_back(argv[i]);
        }

        argumenty.push_back(argv[i]);
    }

    //oznaczenie ktore flagi sa wybrane

    bool noEOL = std::find(flagi.begin(), flagi.end(), "-n") != flagi.end();
    bool reverseOrder = std::find(flagi.begin(), flagi.end(), "-r") != flagi.end();
    bool endWithEOL = std::find(flagi.begin(), flagi.end(), "-l") != flagi.end();

    // magia

    if (reverseOrder){
        std::reverse(argumenty.begin(), argumenty.end());
    }

    for (std::string i: argumenty){
        std::cout << i << ' ';

        if (endWithEOL) {
            std::cout << std::endl;
        }
    }

    if (!noEOL){
        std::cout << std::endl;
    }


    return 0;
}
