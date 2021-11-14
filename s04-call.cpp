#include <iostream>

auto random_function(int const) -> void{
}

auto call_with_random_int(void (*fp)(int const)) -> void {
    (*fp)(99);
}
