#include <iostream>
#include <cstdlib>

void printBoard(int height, int width, int currentHeight, int currentWidth){
    // rysuj plansze
    for(int h = 0; h < height; h++){
        for(int w = 0; w < width; w++){
            // jak wartosc wys i szer sa takie same jak ulozenie gwiazdki to drukuj gwiazdke, a jak nie to puste pole
            if(h == currentHeight && w == currentWidth){
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}

int main() {

    // wymiary planszy
    int height = 10;
    int width = 10;

    // pozycja gwiazdki
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
    } while(input != 'e');

    return 0;
}
