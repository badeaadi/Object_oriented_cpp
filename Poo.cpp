#include "deque.h"
#include <iostream>
using namespace std;

int main()
{
    List<int> list;
    list.push_back(10);

    list.push_back(13);

    list.push_back(27);
    list.push_back(32);
    list.push_back(41);
    int k = 0;


    for (List<int>::Iterator it = list.begin(); it.getPointer() != nullptr ; ++it)
        cout << it << '\n';


    cout << list;


    Deque <int> deque;
    deque.push_back(10);


    return 0;
}