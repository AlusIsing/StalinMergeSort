#include "./FlexibleArray.h"

Soviet::FlexibleArray::FlexibleArray() {
    reserved_capacity = 10;
    capacity = reserved_capacity;
    count = 0;
    arr = new int[capacity];
}

Soviet::FlexibleArray::FlexibleArray(const FlexibleArray& new_arr, int start, int count) {
    reserved_capacity = new_arr.reserved_capacity;
    int end = -1;
    if (count <= -1) {
        end = new_arr.count + start;
    }
    else {
        end = count + start;
    }

    if (end > new_arr.count) {
        throw "Count out of range";
    }
    
    this->count = end - start;

    capacity = this->count + reserved_capacity;
    
    arr = new int[capacity];
    
    std::copy(new_arr.arr + start, new_arr.arr + end, arr);
}

Soviet::FlexibleArray::FlexibleArray(const int array[], int start, int count) {
    reserved_capacity = 10;
    
    int end = count + start;

    this->count = count;

    capacity = this->count + reserved_capacity;

    arr = new int[capacity];
    
    std::copy(array + start, array + end, arr);
}

Soviet::FlexibleArray::~FlexibleArray() {
    delete[] arr;
}

void Soviet::FlexibleArray::Add(int item) {
    UpdateCapacity();
    if (count >= capacity) {
        throw "Have no enough capacity for a FlexibleArray to add item.";
    }
    
    arr[count] = item;
    count++;
}

int Soviet::FlexibleArray::Pop() {
    if (count <= 0) {
        throw "Can not pop a array that have nothing inside.";
    }
    count--;
    return arr[count];
}

void Soviet::FlexibleArray::Remove(int index) {
    if (index < 0 || index >= count) {
        throw "Index out of range.";
    }
    std::copy(arr + index + 1, arr + count, arr + index);
    count--;
    UpdateCapacity();
}

void Soviet::FlexibleArray::RemoveFromBack(int size) {
    if (size > count) {
        throw "Size out of range.";
    }
    
    count -= size;
    UpdateCapacity();
}

int Soviet::FlexibleArray::Count() const {
    return count;
}

void Soviet::FlexibleArray::Clean() {
    delete[] arr;
    capacity = reserved_capacity;
    count = 0;
    arr = new int[capacity];
}

int& Soviet::FlexibleArray::operator[](int index) {
    if (index < 0 || index >= count) {
        throw "Index out of range.";
    }
    return arr[index];
}

int Soviet::FlexibleArray::operator[](int index) const {
    if (index < 0 || index >= count) {
        throw "Index out of range.";
    }
    return arr[index];
}

void Soviet::FlexibleArray::operator=(const FlexibleArray& new_arr) {
    count = new_arr.count;
    capacity = count + reserved_capacity;
    delete[] arr;
    arr = new int[capacity];
    std::copy(new_arr.arr, new_arr.arr + new_arr.count, arr);
}

int Soviet::FlexibleArray::Back() const {
    if (count <= 0) {
        throw "Can not get back of a array that have nothing";
    }
    return arr[count - 1];
}

void Soviet::FlexibleArray::UpdateCapacity() {
    if (count == capacity) {
        capacity += reserved_capacity;
        int* tmp = new int[capacity];
        std::copy(arr, arr + count, tmp);
        delete[] arr;
        arr = tmp;
    }
    else if (capacity >= 20 && count <= capacity - 20) {
        capacity -= reserved_capacity;
        int* tmp = new int[capacity];
        std::copy(arr, arr + count, tmp);
        delete[] arr;
        arr = tmp;
    }
}
        
void Soviet::FlexibleArray::MergeByOrder(const FlexibleArray& new_arr) {
    if (new_arr.count <= 0) {
        return;
    }
    
    if (count <= 0) {
        *this = new_arr;
        return;
    }

    int* final_arr = new int[count + new_arr.count + reserved_capacity];
    unsigned int arr_counter = 0;
    unsigned int new_arr_counter = 0;
    while (count > arr_counter || new_arr.count > new_arr_counter) {
        if (count > arr_counter && new_arr.count > new_arr_counter) {
            int arr_num = arr[arr_counter];
            int new_arr_num = new_arr.arr[new_arr_counter];
            if (arr_num <= new_arr_num) {
                final_arr[arr_counter + new_arr_counter] = arr_num;
                arr_counter++;
            }
            else {
                final_arr[arr_counter + new_arr_counter] = new_arr_num;
                new_arr_counter++;
            }
        }
        else if (count > arr_counter) {
            final_arr[arr_counter + new_arr_counter] = arr[arr_counter];
            arr_counter++;
        }
        else if (new_arr.count > new_arr_counter) {
            final_arr[arr_counter + new_arr_counter] = new_arr.arr[new_arr_counter];
            new_arr_counter++;
        }
    }
    delete[] arr;
    capacity = arr_counter + new_arr_counter + reserved_capacity;
    count = count + new_arr.count;
    arr = final_arr;
}

void Soviet::FlexibleArray::ToPointer(int*& ptr) const {
    int* result = new int[count];
    std::copy(arr, arr + count, result);
    ptr = result;
}

std::string Soviet::FlexibleArray::ToString() const {
    std::string result = "";
    for (int i = 0; i < count; i++) {
        std::string num_str = std::to_string(arr[i]);
        if (i != count - 1) {
            num_str.append(", ");
        }
        result.append(num_str);
    }
    return result;
}
