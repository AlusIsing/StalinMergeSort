#ifndef STALINMERGESORT_H
#define STALINMERGESORT_H

#include <algorithm>
#include <string>

namespace Soviet {
    class FlexibleArray {
    private:
        unsigned int capacity;
        unsigned int count;
        int* arr;
    public:
        FlexibleArray() {
            capacity = 10;
            count = 0;
            arr = new int[capacity];
        }

        FlexibleArray(const FlexibleArray& new_arr) {
            capacity = new_arr.capacity;
            count = new_arr.count;
            arr = new int[capacity];
            std::copy(new_arr.arr, new_arr.arr + new_arr.count, arr);
        }

        ~FlexibleArray() {
            delete[] arr;
        }

        void Add(int item) {
            UpdateCapacity();
            arr[count] = item;
            count++;
        }

        int Pop() {
            if (count <= 0) {
                throw "Can not pop a array that have nothing inside.";
            }

            count--;
            return arr[count];
        }

        void Remove(int index) {
            if (index < 0 || index >= count) {
                throw "Index out of range.";
            }

            std::copy(arr + index + 1, arr + count, arr + index);
            count--;
            UpdateCapacity();
        }

        void RemoveFromBack(int size = 1) {
            if (size > count) {
                throw "Size out of range.";
            }
            
            count -= size;
            UpdateCapacity();
        }
        
        int Count() {
            return count;
        }

        void Clean() {
            delete[] arr;
            capacity = 10;
            count = 0;
            arr = new int[capacity];
        }

        int& operator[](int index) {
            if (index < 0 || index >= count) {
                throw "Index out of range.";
            }

            return arr[index];
        }

        void operator=(const FlexibleArray& new_arr) {
            count = new_arr.count;
            capacity = count + 10;
            delete[] arr;
            arr = new int[capacity];
            std::copy(new_arr.arr, new_arr.arr + new_arr.count, arr);
        }
        
        void UpdateCapacity() {
            if (count == capacity) {
                capacity += 10;
                int* tmp = new int[capacity];
                std::copy(arr, arr + count, tmp);
                delete[] arr;
                arr = tmp;
            }
            else if (capacity >= 20 && count <= capacity - 20) {
                capacity -= 10;
                int* tmp = new int[capacity];
                std::copy(arr, arr + count, tmp);
                delete[] arr;
                arr = tmp;
            }
        }
        
        void Merge(const FlexibleArray& new_arr) {
            if (new_arr.count == 0) {
                return;
            }
            
            if (count == 0) {
                *this = new_arr;
                return;
            }

            int* final_arr = new int[count + new_arr.count + 10];
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
            capacity = arr_counter + new_arr_counter + 10;
            count = count + new_arr.count;
            arr = final_arr;
        }

        std::string ToString() {
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
    };

    class Gulag {
    private:
        FlexibleArray prisoners;
        FlexibleArray new_citizens;
    public:
        Gulag() {
            
        }
        
        ~Gulag() {
            
        }

        int Population() {
            return prisoners.Count() + new_citizens.Count();
        }
        
        void AddPrisoner(int prisoner_name) {
            prisoners.Add(prisoner_name);
        }

        void LaborReform() {
            if (prisoners.Count() == 0) {
                return;
            }

            unsigned int new_prisoner_population = 0;
            FlexibleArray reformed_person;
            reformed_person.Add(prisoners[0]);
            for (int i = 1; i < prisoners.Count(); i++) {
                if (reformed_person[reformed_person.Count() - 1] < prisoners[i]) {
                    reformed_person.Add(prisoners[i]);
                }
                else {
                    prisoners[new_prisoner_population] = prisoners[i];
                    new_prisoner_population++;
                }
            }
            prisoners.RemoveFromBack(prisoners.Count() - new_prisoner_population);

            new_citizens.Merge(reformed_person);
        }
        
        FlexibleArray NewCitizens() {
            return new_citizens;
        }
        
        void ReleaseNewCitizens() {
            new_citizens.Clean();
        }
    };
    
    class UnionofSovietSocialistRepublics {
    private:
        FlexibleArray citizens;
    public:
        Gulag gulag;

        UnionofSovietSocialistRepublics() {
            
        }

        ~UnionofSovietSocialistRepublics() {
            
        }

        void AddCitizen(int citizen_name) {
            citizens.Add(citizen_name);
        }

        void RemoveCitizen(int index) {
            citizens.Remove(index);
        }

        unsigned int Population() {
            return citizens.Count();
        }

        int& operator[](int index) {
            return citizens[index];
        }

        void StalinMergeSort() {
            Purge();
            while (gulag.Population() > 0) {
                gulag.LaborReform();
                AcceptNewCitizens();
            }
        }
        
        void Purge() {
            if (citizens.Count() <= 1) {
                return;
            }
            
            unsigned int new_population = 1;
            for (int i = 1; i < citizens.Count(); i++) {
                if (citizens[new_population - 1] > citizens[i]) {
                    gulag.AddPrisoner(citizens[i]);
                }
                else {
                    citizens[new_population] = citizens[i];
                    new_population++;
                }
            }
            citizens.RemoveFromBack(citizens.Count() - new_population);
        }
        
        void AcceptNewCitizens() {
            FlexibleArray new_citizens = gulag.NewCitizens();
            gulag.ReleaseNewCitizens();
            citizens.Merge(new_citizens);
        }
    };
}

#endif // STALINMERGESORT_H
