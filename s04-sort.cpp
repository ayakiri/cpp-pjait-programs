#include <iostream>
#include <array>

auto compareElements(int a[], int n) -> void {
    //sortowanie babelkowe
    for(int j = 0; j < n-1; j++){
        for(int i = 0; i < n-1; i++){
            if(a[i+1] < a[i]){
                // zamianka przy uzyciu dodatkowej zmiennej
                int change = a[i];
                a[i] = a[i+1];
                a[i+1] = change; 
            }
        }
    }
}

auto fpsort(void* a[], size_t n, int (*fp)(void*, void*)) -> void{
    (*fp)(a[], n);
}
