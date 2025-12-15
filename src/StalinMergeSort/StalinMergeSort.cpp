#include "./StalinMergeSort.h"

#include <iostream>

Soviet::FlexibleArray Soviet::StalinMergeSort(const FlexibleArray& old_citizens) {
    if (old_citizens.Count() <= 1) {
        return old_citizens;
    }

    FlexibleArray new_citizens(old_citizens.ToPointer(), 1);
    
    FlexibleArray prisoners;
    for (int i = 1; i < old_citizens.Count(); i++) {
        if (new_citizens.Back() > old_citizens[i]) {
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

Soviet::FlexibleArray Soviet::BidirectionalStalinMergeSort(const FlexibleArray& old_citizens) {
    if (old_citizens.Count() <= 1) {
        return old_citizens;
    }

    FlexibleArray new_citizens1(old_citizens.ToPointer(), 1);
    
    std::cout << new_citizens1.ToString() << std::endl;

    FlexibleArray prisoners1;
    for (int i = 1; i < old_citizens.Count(); i++) {
        if (new_citizens1.Back() > old_citizens[i]) {
            prisoners1.Add(old_citizens[i]);
        }
        else {
            new_citizens1.Add(old_citizens[i]);
        }
    }

    FlexibleArray new_citizens2;
    new_citizens2.Add(prisoners1.Back());

    FlexibleArray prisoners2;
    for (int i = prisoners1.Count() - 2; i >= 0; i--) {
        if (new_citizens2.Back() > prisoners1[i]) {
            prisoners2.Add(prisoners1[i]);
        }
        else {
            new_citizens2.Add(prisoners1[i]);
        }
    }

    new_citizens1.Merge(new_citizens2);

    new_citizens1.Merge(BidirectionalStalinMergeSort(prisoners2));

    return new_citizens1;
}
