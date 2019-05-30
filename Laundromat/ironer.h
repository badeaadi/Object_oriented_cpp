#ifndef POO_IRONER_H
#define POO_IRONER_H
//#include "machines.h"
//#include "cloth.h"



class Washer;
class NormalWasher;
class SpecialWasher;
class Spinner;
class Dryer;
class Ironer;

class Ironer : public
        Machine <int> {                //Calcare

    void addiron(Cloth * this_cloth);
};
void Ironer :: addiron (Cloth * this_cloth)
{
    string p = "Ironer";
    p.push_back(ord_number + '1');
    this_cloth->history.push_back(p);
}

#endif
