#include "../UnionOfSovietSocialistRepublics/UnionOfSovietSocialistRepublics.h"

Soviet::Gulag::Gulag() {

}

Soviet::Gulag::~Gulag() {

}

int Soviet::Gulag::Population() {
    return prisoners.Count();
}
        
void Soviet::Gulag::AddPrisoner(int prisoner_name) {
    prisoners.Add(prisoner_name);
}
void Soviet::Gulag::LaborReform() {
    prisoners = StalinMergeSort(prisoners);
}
        
Soviet::FlexibleArray Soviet::Gulag::ReleaseReformedCitizens() {
    FlexibleArray tmp = prisoners;
    prisoners.Clean();
    return tmp;
}

// UnionOfSovietSocialistRepublics
Soviet::UnionOfSovietSocialistRepublics::UnionOfSovietSocialistRepublics() {

}

Soviet::UnionOfSovietSocialistRepublics::~UnionOfSovietSocialistRepublics() {
    
}

void Soviet::UnionOfSovietSocialistRepublics::AddCitizen(int citizen_name) {
    citizens.Add(citizen_name);
}

void Soviet::UnionOfSovietSocialistRepublics::RemoveCitizen(int index) {
    citizens.Remove(index);
}

unsigned int Soviet::UnionOfSovietSocialistRepublics::Population() {
    return citizens.Count();
}

Soviet::FlexibleArray Soviet::UnionOfSovietSocialistRepublics::Citizens() {
    return citizens;
}

int& Soviet::UnionOfSovietSocialistRepublics::operator[](int index) {
    return citizens[index];
}

void Soviet::UnionOfSovietSocialistRepublics::StalinMergeSort() {
    Purge();
    gulag.LaborReform();
    AcceptNewCitizens();
}
        
void Soviet::UnionOfSovietSocialistRepublics::Purge() {
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
        
void Soviet::UnionOfSovietSocialistRepublics::AcceptNewCitizens() {
    FlexibleArray new_citizens = gulag.ReleaseReformedCitizens();
    citizens.Merge(new_citizens);
}
