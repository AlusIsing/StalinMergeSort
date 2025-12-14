#include <iostream>

#include "StalinMergeSort.h"

int main() {
    Soviet::UnionofSovietSocialistRepublics soviet_socialist_republic_federation;

    soviet_socialist_republic_federation.AddCitizen(2);
    soviet_socialist_republic_federation.AddCitizen(10);
    soviet_socialist_republic_federation.AddCitizen(9);
    soviet_socialist_republic_federation.AddCitizen(5);
    soviet_socialist_republic_federation.AddCitizen(1);
    soviet_socialist_republic_federation.AddCitizen(4);
    soviet_socialist_republic_federation.AddCitizen(6);
    soviet_socialist_republic_federation.AddCitizen(3);
    soviet_socialist_republic_federation.AddCitizen(8);
    soviet_socialist_republic_federation.AddCitizen(7);
    
    for (size_t i = 0; i < soviet_socialist_republic_federation.Population(); ++i) {
        std::cout << soviet_socialist_republic_federation[i] << " ";
    }
    std::cout << std::endl;

    soviet_socialist_republic_federation.StalinMergeSort();

    for (size_t i = 0; i < soviet_socialist_republic_federation.Population(); ++i) {
        std::cout << soviet_socialist_republic_federation[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
