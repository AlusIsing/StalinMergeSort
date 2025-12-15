#ifndef FLEXIBLEARRAY_H
#define FLEXIBLEARRAY_H

#include <algorithm>
#include <string>

namespace Soviet {
    class FlexibleArray {
    private:
        unsigned int capacity;
        unsigned int count;
        unsigned int reserved_capacity;
        int* arr;
    public:
        FlexibleArray();

        FlexibleArray(const FlexibleArray& new_arr);

        FlexibleArray(const int* pointer, int count);

        ~FlexibleArray();

        void Add(int item);

        int Pop();

        void Remove(int index);

        void RemoveFromBack(int size = 1);
        
        int Count() const;

        void Clean();

        int& operator[](int index);

        int operator[](int index) const;

        void operator=(const FlexibleArray& new_arr);
        
        void UpdateCapacity();
        
        void Merge(const FlexibleArray& new_arr);

        int* ToPointer();

        std::string ToString();
    };
}

#endif // FLEXIBLEARRAY_H
