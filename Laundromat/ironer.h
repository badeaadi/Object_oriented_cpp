#ifndef POO_IRONER_H
#define POO_IRONER_H
#include "machines.h"
#include "cloth.h"

class Ironer :
        Machine <int> {                //Calcare

    void addiron(Cloth * this_cloth);
};
void Ironer :: addiron (Cloth * this_cloth)
{
    string p = "Ironer";
    p.push_back(this_cloth->ord_number + "1");
    this_cloth.push_back(p);
}

#endif
