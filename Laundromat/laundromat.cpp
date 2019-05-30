#include <fstream>
#include <vector>
using namespace std;

#include "clients.h"
#include "machines.h"
#include "cloth.h"
#include "ironer.h"
#include "dryers.h"
#include "washer.h"

class Washer;
class NormalWasher;
class SpecialWasher;
class Spinner;
class Dryer;
class Ironer;

int main() {
    int i, j, k;

    ifstream machines_file("machines.in");

    int nr_of_special_washers;
    machines_file >> nr_of_special_washers;
    vector<SpecialWasher *> special_washers;
    for (i = 0; i < nr_of_special_washers; i++) {
        SpecialWasher p;
        machines_file >> p;
        special_washers.push_back(&p);
    }

    int nr_of_normal_washers;
    machines_file >> nr_of_normal_washers;
    vector<NormalWasher *> normal_washers;
    for (i = 0; i < nr_of_normal_washers; i++) {
        NormalWasher p;
        machines_file >> p;
        normal_washers.push_back(&p);
    }

    int nr_of_spinners;
    machines_file >> nr_of_spinners;
    vector<Spinner *> spinners;
    for (i = 0; i < nr_of_spinners; i++) {
        Spinner p;
        machines_file >> p;
        spinners.push_back(&p);
    }

    int nr_of_dryers;
    machines_file >> nr_of_dryers;
    vector<Dryer *> dryers;
    for (i = 0; i < nr_of_dryers; i++) {
        Dryer p;
        machines_file >> p;
        dryers.push_back(&p);
    }

    int nr_of_ironers;
    machines_file >> nr_of_ironers;
    vector<Ironer *> ironers;
    for (i = 0; i < nr_of_ironers; i++) {
        Ironer p;
        p.set_ord_number(i);
        ironers.push_back(&p);
    }

    ifstream clients_file("clients.in");
    ofstream clients_file_out("clients.out");
    int nr_of_clients;
    Client client[100];
    clients_file >> nr_of_clients;

    follow_clients.set_total_number_of_clients(nr_of_clients);

    for (i = 0; i < nr_of_clients; i++) {
        clients_file >> client[i];
        client[i].ord_number = i;

        follow_clients.increment();

        for (auto it : client[i].clothes) {
            if (it->cloth_type < 3)
                for (k = 0; k < nr_of_normal_washers; k++) {

                   if ((normal_washers)[k]->current_color == it->color || normal_washers[k]->current_capacity == 0)
                        if (normal_washers[k]->maximum_capacity >= it->weight) {
                            normal_washers[k]->add(it, spinners, dryers, ironers);
                            break;
                        }
                }
            else
                for (k = 0; k < nr_of_special_washers; k++)
                    if (special_washers[k]->current_color == it->color || special_washers[k]->current_capacity == 0)
                        if (special_washers[k]->maximum_capacity >= it->weight) {
                            special_washers[k]->add(it, spinners, dryers, ironers);
                            break;
                        }
        }
    }
    for (i = 0; i < nr_of_clients; i++)
        clients_file_out << client;

    return 0;
}
