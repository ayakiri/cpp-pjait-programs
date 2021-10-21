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
        } else {
            argumenty.push_back(argv[i]);
        }
    }

    //oznaczenie ktore flagi sa wybrane

    bool noEOL, reverseOrder, endWithEOL;
    noEOL = false;
    reverseOrder = false;
    endWithEOL = false;

    if(std::find(flagi.begin(), flagi.end(), "-n") != flagi.end()){
        noEOL = true;
    }

    if(std::find(flagi.begin(), flagi.end(), "-r") != flagi.end()){
        reverseOrder = true;
    }

    if(std::find(flagi.begin(), flagi.end(), "-l") != flagi.end()){
        endWithEOL = true;
    }

    // magia

    if (reverseOrder == 1){
        std::reverse(argumenty.begin(), argumenty.end());
    }

    for (std::string i: argumenty){
        std::cout << i << ' ';

        if (endWithEOL == 1) {
            std::cout << std::endl;
        }
    }

    if (noEOL != 1){
        std::cout << std::endl;
    }


    return 0;
}
