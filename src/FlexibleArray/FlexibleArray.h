#ifndef FLEXIBLEARRAY_H
#define FLEXIBLEARRAY_H

#include <algorithm>
#include <string>

namespace Soviet {
    class FlexibleArray {
    private:
        bool auto_realloc;
        unsigned int capacity;
        unsigned int count;
        unsigned int reserved_capacity;
        int* arr;
    public:
        FlexibleArray(bool auto_realloc = true, int reserved_capacity = 10);

        FlexibleArray(const FlexibleArray& new_arr, int start = 0, int count = -1, bool auto_realloc = true, int reserved_capacity = -1);

        FlexibleArray(const int array[], int start, int count);

        ~FlexibleArray();

        void Add(int item);

        int Pop();

        void Remove(int index);

        void RemoveFromBack(int size = 1);
        
        int Count() const;

        void ReallocCapacity(unsigned int new_capacity);

        void SetAutoRealloc(bool auto_realloc);

        void SetReservedCapacity(unsigned int reserved_capacity);

        void Clean();

        int& operator[](int index);

        int operator[](int index) const;

        void operator=(const FlexibleArray& new_arr);

        int Back() const;
        
        void UpdateCapacity();
        
        void MergeByOrder(const FlexibleArray& new_arr);

        void ToPointer(int*& ptr) const;

        std::string ToString() const;
    };
}

#endif // FLEXIBLEARRAY_H
