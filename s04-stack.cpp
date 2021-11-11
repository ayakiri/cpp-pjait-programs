#include <iostream>
#include <stack>

auto main(int argc, char* argv[]) -> int {
    // sprawdz czy jest tylko jeden argument    
    if(argc > 2){
        std::cerr << "Input only ONE string";
        return 0;
    }

    std::stack<char> stackOfBrackets;
    std::string givenBrackets = argv[1];

    // kolejno przechodz po znakach w stringu givenBrackets
    for(int i = 0; i < givenBrackets.length(); i++){

        //jesli nawias otwierajacy - dorzuc go na gore stosu
        if (givenBrackets[i] == '(' || givenBrackets[i] == '{' || givenBrackets[i] == '['){
            stackOfBrackets.push(givenBrackets[i]);
        }

        //jesli nawias zamykajacy - sprzawdz co na gorze stosu
        else if (givenBrackets[i] == ')' || givenBrackets[i] == '}' || givenBrackets[i] == ']'){

            //sprawdz ktory to nawias i wedlug tego sprawdz czy "zamyka sie" z nawiasem z topu stosu
            // jesli tak - usun nawias otwierajacy z topu stosu
            // jesli nie - nawiasy sa bledne, czyli "ERROR"
            switch (givenBrackets[i]){
                case ')':
                    if(stackOfBrackets.top() == '('){
                        stackOfBrackets.pop();
                    } else {
                        std::cout << "ERROR";
                        return 0;
                    }
                    break;
                case '}':
                    if(stackOfBrackets.top() == '{'){
                        stackOfBrackets.pop();
                    } else {
                        std::cout << "ERROR";
                        return 0;
                    }
                    break;
                case ']':
                    if(stackOfBrackets.top() == '['){
                        stackOfBrackets.pop();
                    } else {
                        std::cout << "ERROR";
                        return 0;
                    }
                    break;
            }
        }
        //jesli podano nie nawias
        else {
            std::cerr << "Input ONLY brackets in your string";
        }
    }

    //sprawdz czy na pewno wszystkie nawiasy sie usunely
    if(!stackOfBrackets.empty()){
        std::cout << "ERROR";
    } else {
        std::cout << "OK";
    }

    return 0;
}
