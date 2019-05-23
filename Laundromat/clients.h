#ifndef CLIENTS_H
#define CLIENTS_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "machines.h"
#include "cloth.h"
#include "washer.h"
#include "dryers.h"
using namespace std;

class Client_Singleton{

public :
    void increment();
    bool clients_done();
    void set_total_number_of_clients(int);

private :

    int current_client;
    int total_number_of_clients;
};

Client_Singleton follow_clients;

void Client_Singleton :: increment ()
{
    current_client ++;
}
bool Client_Singleton :: clients_done()
{
    return (current_client == total_number_of_clients);
}
void Client_Singleton :: set_total_number_of_clients(int new_number_of_clients)
{
    total_number_of_clients  = new_number_of_clients;
}

class Client {
    public :
        Client();

        vector <Cloth *> clothes;

        friend istream & operator >> (istream & in, Client & this_client);
        friend ostream & operator << (ostream & out, Client & this_client);
        int ord_number;

    private :

        int number_of_clothes;
};

Client :: Client()
{

}
istream & operator >> (istream & in, Client & this_client)
{
    in >> this_client.number_of_clothes;
    for (int i = 1; i <= this_client.number_of_clothes ; i++) {
        Cloth * a = new Cloth;
        this_client.clothes.push_back(a);
        in >> *a;

    }
    return in;
}
ostream & operator << (ostream & out, Client &this_client)
{
    out << "Pentru clientul numarul " << this_client.ord_number << "avem : " << '\n';
    out << this_client.number_of_clothes;
    for (auto it : this_client.clothes)
        cout << it;

    while (!this_client.clothes.empty()) {
        delete this_client.clothes[this_client.clothes.size()-1];
        this_client.clothes.pop_back();
    }
    return out;
}


#endif
