#include "priorityQueue.h"

int main()
{

    List<int> list;
    list.push_back(1);

    list.push_back(3);

    list.push_back(5);
    list.push_back(11);
    list.push_back(102);
    int k = 0;

    List<int>::Iterator it = list.begin();


    for (List<int>::Iterator it = list.begin(); it.getPointer() != NULL ; ++it)
        std::cout << it << '\n';

    //std::cout << list;
    //std::cout << list;


    Deque <int> deque;
    deque.push_front(4207223);
    deque.push_back(312);
    deque.push_back(31231);


    Deque<int>:: Iterator itd2 = deque.begin();
    std::cout << itd2 << '\n';

    Deque<int>:: Iterator itd = deque.end();
    std::cout << itd << '\n';


    PriorityQueue <int> pq;
    pq.push_back(312);
    pq.push_back(354);

    return 0;
}
