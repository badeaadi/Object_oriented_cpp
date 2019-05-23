#ifndef POO_DRYERS_H
#define POO_DRYERS_H
#include "machines.h"
#include "spinner.h"
using namespace std;

class Dryer :
        Machine <int> {                 //Uscare

    void add(Cloth * this_cloth, vector<Ironer> *ironers);
    void dry(vector <Ironer> *ironers);
};

void Dryer :: add(Cloth * this_cloth, vector <Ironer> * ironers)
{
    current_capacity += 1;

    string p = "Dryer";
    p.push_back(ord_number + "1");
    this_cloth.push_back(p);

    v.push_back(this_cloth);
    if (current_capacity * 2 >= maximum_capacity || follow_clients.clients_done())
        dry(ironers));
}
void Dryer :: dry(vector <ironer> * ironers)
{
    for (auto it : v) {
        for (int i = 0 ; i < spinners->size(); i++)
            if (spinners[i].current_capacity < spinners[i].maximum_capacity) {
                spinners[i].addiron(it, ironers);
            }
    }
}

#endif
