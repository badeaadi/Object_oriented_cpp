#ifndef MACHINES_H
#define MACHINES_H
#include "clients.h"
#include "cloth.h"
#include "spinner.h"
#include "dryers.h"
using namespace std;


template <typename T>
class Machine {                         //Masina
    public :
        Machine();
        T current_capacity;             //Greutatea curenta/Numarul de articole
        T maximum_capacity;             //Greutatea totala/Numarul de articole
        vector <Cloth *> v;
        void set_ord_number(int new_ord_number);

        friend ostream & operator >> (ostream & in, Machine<T> & this_machine) {
            in >> this_machine.current_capacity;;
            return in;
        }

    private :
        int ord_number;
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
