#ifndef POO_WASHER_H
#define POO_WASHER_H
#include "machines.h"
#include "dryers.h"

using namespace std;

class Washer : Machine <double> {                      //Masina de spalat

public :

    Washer();
    int current_color;
    void add(Cloth * this_cloth, vector <Spinner> * spinners, vector<Dryer> * dryers, vector <Ironer> * ironers);
    void wash(vector <Spinner> * spinners, vector<Dryer> * dryers, vector <Ironer> * ironers);
};
Washer::Washer() {

    current_color = 0;
}
void Washer :: add(Cloth * this_cloth, vector <Spinner> * spinners, vector<Dryer> * dryers, vector <Ironer> * ironers)
{
    current_capacity += this_cloth -> weight;
    v.push_back(this_cloth);
    if (current_capacity * 2 >= maximum_capacity || follow_clients.clients_done())
        wash(spinners, dryers, ironers));
}
void Washer :: wash(vector <Spinner> * spinners, vector<Dryer> * dryers, vector <Ironer> * ironers)
{
    string p = type_of_washer; //Some crazy OOP workaround
    p.push_back(ord_number + "1");
    this_cloth.push_back(p);

    current_capacity = 0;
    for (auto it : v) {
        for (int i = 0 ; i < spinners->size(); i++)
            if (spinners[i].current_capacity < spinners[i].maximum_capacity) {
                spinners[i].add(it, dryers, ironers);
            }
    }
}
class SpecialWasher :
        Washer {          //Masina de spalat speciala
public :
    string type_of_washer = "SpecialWasher";
};
class NormalWasher :
        Washer {        //Masina de spalat normala
public :
    string type_of_washer = "NormalWasher";
};


#endif