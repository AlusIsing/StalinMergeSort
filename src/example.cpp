#include <iostream>

#include "./UnionOfSovietSocialistRepublics/UnionOfSovietSocialistRepublics.h"

int main() {
    Soviet::UnionOfSovietSocialistRepublics union_of_soviet_socialist_republics;
    
    std::cout << "create" << std::endl;
    
    try {

        union_of_soviet_socialist_republics.AddCitizen(2);
        union_of_soviet_socialist_republics.AddCitizen(10);
        union_of_soviet_socialist_republics.AddCitizen(9);
        union_of_soviet_socialist_republics.AddCitizen(5);
        union_of_soviet_socialist_republics.AddCitizen(1);
        union_of_soviet_socialist_republics.AddCitizen(4);
        union_of_soviet_socialist_republics.AddCitizen(6);
        union_of_soviet_socialist_republics.AddCitizen(3);
        union_of_soviet_socialist_republics.AddCitizen(8);
        union_of_soviet_socialist_republics.AddCitizen(7);
    
        std::cout << union_of_soviet_socialist_republics.Citizens().ToString() << std::endl;
    }
    catch (const char* e) {
        std::cout << e << std::endl;
    }

    try {
        union_of_soviet_socialist_republics.StalinMergeSort();
    }
    catch (const char* e) {
        std::cout << e << std::endl;
    }

    std::cout << union_of_soviet_socialist_republics.Citizens().ToString() << std::endl;

    Soviet::FlexibleArray arr;
    
    arr.Add(2);
    arr.Add(10);
    arr.Add(9);
    arr.Add(5);
    arr.Add(1);
    arr.Add(4);
    arr.Add(6);
    arr.Add(3);
    arr.Add(8);
    arr.Add(7);
    
    std::cout << arr.ToString() << std::endl;

    arr = Soviet::StalinMergeSort(arr);
    
    std::cout << arr.ToString() << std::endl;

    return 0;
}
