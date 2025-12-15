# Welcome to the Stalin Merge Sort repo

# What is the Stalin Sort
### Introduction
This is a AMAZING sorting algorithm that can always sort an array in O(n) performance.

Here is the origin repo [Stalin Sort](https://github.com/gustavo-depaula/stalin-sort).

# Then what is the Stalin Merge Sort
### Introduction
It is a sorting algorithm that combines [Stalin Sort](https://github.com/gustavo-depaula/stalin-sort), Merge Sort and Socialism.

### How it works
It is simple in theory and politics.  
Just  
-> Purge your citizens  
-> send to the Gulag  
-> LaborReform them  
-> merge those who are reformed back to the origin citizens  
-> keep 2, 3 step until there are no more prisoners in Gulag  
-> now you have a sorted array  
-> AMAZING!!!
![](example.png)

### Different sorting methods
We offer two sorting methods in this project.  
First is StalinMergeSort function.
```cpp
FlexibleArray StalinMergeSort(const FlexibleArray& old_citizens);
```
This is a normal sorting method.  
But this is not in line with socialism.  

So we have second kind of sorting method.  
You need to ...
```cpp
// Create an UnionofSovietSocialistRepublics.
Soviet::UnionofSovietSocialistRepublics soviet_socialist_republic_federation;

// Add some citizens.
soviet_socialist_republic_federation.AddCitizen(2);
soviet_socialist_republic_federation.AddCitizen(10);
soviet_socialist_republic_federation.AddCitizen(9);

// And do the StalinMergeSort. (The Purge)
soviet_socialist_republic_federation.StalinMergeSort();
```
The StalinMergeSort function will do a Purge to the citizens.  
Then send the people who purged to the Gulag and reform them into the "New Citizens".  
And finally, The "New Citizens" will merged into the citizens.  
Now you have a sorting method that is in line of socialism.

# More detail
### About the code
We made a dynamic array that call ```FlexibleArray``` in this project.  
This allows us to control the underlying memory management.  
However, this is an unsafe approach for a C++ project.

### C++ implementation
```cpp
FlexibleArray StalinMergeSort(const FlexibleArray& old_citizens) {
    if (old_citizens.Count() <= 1) {
        return old_citizens;
    }
    FlexibleArray new_citizens;
    new_citizens.Add(old_citizens[0]);
    FlexibleArray prisoners;
    for (int i = 1; i < old_citizens.Count(); i++) {
        if (new_citizens[new_citizens.Count() - 1] > old_citizens[i]) {
            prisoners.Add(old_citizens[i]);
        }
        else {
            new_citizens.Add(old_citizens[i]);
        }
    }
    FlexibleArray reformed_citizens = StalinMergeSort(prisoners);
    
    new_citizens.MergeByOrder(reformed_citizens);
    return new_citizens;
}
```

# References and Acknowledgements
This project references the [Stalin Sort repo](https://github.com/gustavo-depaula/stalin-sort) in the algorithm.
