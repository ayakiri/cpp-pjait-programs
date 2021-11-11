#include <iostream>

struct rectangle {
    float x; // szerokosc
    float y; // wysokosc
    float scale_x = 1; // skalowanie szerokosci
    float scale_y = 1; // skalowanie wysokosci
    
    auto area() const -> float;
    auto draw() const -> void;
    
    auto scale() -> void;
    
} newRectangle;

//funkcja liczaca pole prostokata
auto rectangle::area() const -> float {
    std::cout << (x * y);
    return (x * y);
}

//funkcja rysujaca prostokat
auto rectangle::draw() const -> void {
    for(int i = 1; i <= y; i++){
        //jeden rzad o szerokosci x
        for (int i = 1; i <= x; i++){
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

auto rectangle::scale() -> void {
    x = x * scale_x;
    y = y * scale_y;
}

int main (int argc, char* argv[]) {
    //przypisz wielkosci do prostokata
    newRectangle.x = std::stoi(argv[1]);
    newRectangle.y = std::stoi(argv[2]);

    //pzrypisz skalowanie, jesli podano
    if(argv[3]){
        newRectangle.scale_x = std::stoi(argv[3]);

        if (argv[4]){
            newRectangle.scale_y = std::stoi(argv[4]);
        }
    }

    newRectangle.scale();
    newRectangle.draw();
    
    return 0;
}
