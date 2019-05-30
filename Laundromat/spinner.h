#ifndef POO_SPINNER_H
#define POO_SPINNER_H
#include "machines.h"


class Washer;
class NormalWasher;
class SpecialWasher;
class Spinner;
class Dryer;
class Ironer;


using namespace std;

class Spinner : public
        Machine <double> {               //Stoarcere

    void add(Cloth * this_cloth, vector<Dryer> * dryers, vector <Ironer> * ironers);
    void spin(vector <Dryer> * dryers, vector <Ironer> * ironers);

};
void Spinner :: add(Cloth * this_cloth, vector <Dryer> * dryers, vector <Ironer> * ironers)
{
    string p = "Spinner";
    p += ord_number + '1';
    this_cloth->history.push_back(p);

    current_capacity += this_cloth -> weight;
    v.push_back(this_cloth);
    if (current_capacity * 2 >= maximum_capacity || follow_clients.clients_done())
        spin(dryers, ironers);
}
void Spinner :: spin(vector <Dryer> * dryers, vector <Ironer> *ironers)
{
    current_capacity = 0;
    for (auto it : v) {
        for (int i = 0 ; i < dryers->size(); i++)
            if ((*dryers)[i].current_capacity < (*dryers)[i].maximum_capacity) {
                (*dryers)[i].add(it, ironers);
            }
    }
}


#endif
