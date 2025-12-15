#ifndef UNIONIFSOVIETSOCIALOSTREPUBLICS_H
#define UNIONIFSOVIETSOCIALOSTREPUBLICS_H

#include "../StalinMergeSort/StalinMergeSort.h"

namespace Soviet {
    class Gulag {
    private:
        FlexibleArray prisoners;
    public:
        Gulag();
        
        ~Gulag();

        int Population();
        
        void AddPrisoner(int prisoner_name);

        void LaborReform();
        
        FlexibleArray ReleaseReformedCitizens();
    };
    
    class UnionOfSovietSocialistRepublics {
    private:
        FlexibleArray citizens;
    public:
        Gulag gulag;

        UnionOfSovietSocialistRepublics();

        ~UnionOfSovietSocialistRepublics();

        void AddCitizen(int citizen_name);

        void RemoveCitizen(int index);

        unsigned int Population();

        FlexibleArray Citizens();

        int& operator[](int index);

        void StalinMergeSort();
        
        void Purge();
        
        void AcceptNewCitizens();
    };
}

#endif // UNIONIFSOVIETSOCIALOSTREPUBLICS_H
