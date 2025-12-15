#include "./StalinMergeSort.h"

Soviet::FlexibleArray Soviet::StalinMergeSort(const FlexibleArray& old_citizens) {
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
    
    new_citizens.Merge(reformed_citizens);

    return new_citizens;
}
