#ifndef POO_WASHER_H
#define POO_WASHER_H
using namespace std;
#include "cloth.h"

class Washer;
class NormalWasher;
class SpecialWasher;
class Spinner;
class Dryer;
class Ironer;




class Washer : public Machine <double> {                      //Masina de spalat

public :

    Washer();
    int current_color;
    void add(Cloth * this_cloth, vector <Spinner * > * spinners, vector<Dryer *> * dryers, vector <Ironer* > * ironers);
    void wash(vector <Spinner *> * spinners, vector<Dryer *> * dryers, vector <Ironer* > * ironers);

    virtual string get_string_s() = 0;
};
Washer::Washer() {

    current_color = 0;
}
void Washer :: add(Cloth * this_cloth, vector <Spinner * > * spinners, vector<Dryer * > * dryers, vector <Ironer *> * ironers)
{
    current_capacity += this_cloth -> weight;

    string p = get_string_s(); //Some crazy OOP workaround
    p.push_back(ord_number + '1');

    this_cloth->history.push_back(p);


    v.push_back(this_cloth);
    if (current_capacity * 2 >= maximum_capacity || follow_clients.clients_done())
        wash(spinners, dryers, ironers);
}
void Washer :: wash(vector <Spinner *> * spinners, vector<Dryer * > * dryers, vector <Ironer *> * ironers)
{

    current_capacity = 0;
    for (auto it : v) {
        for (int i = 0 ; i < spinners->size(); i++)
            if ((*spinners)[i]->current_capacity < (*spinners)[i].maximum_capacity) {
                (*spinners)[i].add(it, dryers, ironers);
            }
    }
}
class SpecialWasher :
        public Washer {          //Masina de spalat speciala
public :

    string get_string_s() override {
        return "SpecialWasher";
    }
};
class NormalWasher :
      public Washer {        //Masina de spalat normala
public :

    string get_string_s() override {
        return "NormalWasher";
}
};



#endif