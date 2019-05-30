#ifndef MACHINES_H
#define MACHINES_H
#include <vector>
#include "cloth.h"
#include "clients.h"

using namespace std;

class Washer;
class NormalWasher;
class SpecialWasher;
class Spinner;
class Dryer;
class Ironer;

template <typename T>
class Machine {                         //Masina
    public :
        Machine();
        T current_capacity;             //Greutatea curenta/Numarul de articole
        T maximum_capacity;             //Greutatea totala/Numarul de articole
        vector <Cloth *> v;
        void set_ord_number(int new_ord_number);

        friend istream & operator >> (istream & in, Machine<T> & this_machine) {
            in >> this_machine.current_capacity;;
            return in;
        }
        int ord_number;

    private :
};
template <typename T>
Machine<T>::Machine() {
}
template <typename T>
void Machine<T> :: set_ord_number(int new_ord_number)
{
    ord_number = new_ord_number;
}


#endif
