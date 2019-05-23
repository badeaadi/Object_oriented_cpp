#ifndef CLOTH_H
#define CLOTH_H
#include <vector>
#include <string>
#include "clients.h"
using namespace std;

class Cloth {

    public:
        friend istream &operator >> (istream & in, Cloth & this_cloth);
        friend ostream & operator << (ostream & out, const Cloth & this_cloth);
        vector <string> history;  //History of the cloth

        int cloth_type;
        double weight;
        int color;  //0 for light colors, 1 for dark ones
        string name_of_cloth;
};

istream & operator >>(istream & in, Cloth & this_cloth)
{
    string name_of;
    in >> name_of;
    in.get();
    in >> this_cloth.weight;
    in >> this_cloth.color;

    if (name_of == "pantaloni")
        this_cloth.cloth_type = 0;
    if (name_of == "rochie")
        this_cloth.cloth_type = 1;
    if (name_of == "camasa")
        this_cloth.cloth_type = 2;
    if (name_of == "palton")
        this_cloth.cloth_type = 3;
    if (name_of == "geaca")
        this_cloth.cloth_type = 4;
    if (name_of == "costum")
        this_cloth.cloth_type = 5;

    return in;
}
ostream & operator <<(ostream & out, const Cloth & this_cloth)
{
    out << "Cloth : " << this_cloth.name_of_cloth;
    out << "Passed through :\n";

    for (auto &it : this_cloth.history ) {
            out << it << '\n';
    }
    return out;
}

#endif
