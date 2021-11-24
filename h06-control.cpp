#include <iostream>
#include <cstdlib>

void printBoard(int height, int width, int currentHeight, int currentWidth){
    // rysuj plansze
    for(int h = -1; h <= height; h++){
        for(int w = -1; w <= width; w++){
            // jak wartosc wys i szer sa takie same jak ulozenie gwiazdki to drukuj gwiazdke, a jak nie to puste pole
            if(h == currentHeight && w == currentWidth){
                // kolory gwiazdki
                std::string color = "\033[0;32m";
                std::string normalColor = "\033[0;39m";

                std::cout << color << "*" << normalColor;
            } else {
                if(h == -1 || w == -1 || h == height || w == width){
                    std::cout << "#";
                } else {
                    std::cout << " ";
                }
            }
        }
        std::cout << "\n";
    }
}

int main(int argc, char* argv[]) {

    // wymiary planszy
    int width = 10;
    int height = 10;
    
    //jesli podano na argumencie to ustaw wymiary z argumentu
    if(argv[1]){
        width = std::stoi(argv[1]);
        
        if(argv[2]){
            height = std::stoi(argv[2]);
        }
    }

    // pozycja i kolor gwiazdki
    int currentHeight = 0;
    int currentWidth = 0;

    // zmienna na to co wciska uzytkownik
    char input;

    //wydrukuj plansze "0"
    printBoard(height, width, currentHeight, currentWidth);

    do{
        // wyjdz do terminala w raw, pobierz co kliknal uzytkownik i wyjdz z raw'a'
        system("stty raw");
        input = getchar();
        system("stty cooked");

        std::cout << "\n";

        // zedytuj wartosc obecnej pozycji gwiazdki
        switch(input){
            case 'w':
                if(currentHeight > 0){
                    currentHeight--;
                }
                break;
            case 's':
                if(currentHeight < (height-1)){
                    currentHeight++;
                }
                break;
            case 'a':
                if(currentWidth > 0){
                    currentWidth--;
                }
                break;
            case 'd':
                if(currentWidth < (width-1)){
                    currentWidth++;
                }
                break;
        }

        //wyczysc poprzednia plansze
        system("clear");

        //wydrukuj plansze
        printBoard(height, width, currentHeight, currentWidth);
    } while(input != 'q');

    return 0;
}
