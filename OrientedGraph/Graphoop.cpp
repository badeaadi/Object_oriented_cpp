#include <fstream>
#include <stdexcept>
#include <cstring>
#include <iostream>
#include <assert.h>
#include "graph.h"

void VerificareVector()
{
    Vector<int> v;

    v.reserve(2);
    assert(v.capacity() == 2);

    Vector<std::string> v1(2);
    assert(v1.capacity() == 2);
    assert(v1.size() == 2);
    assert(v1[0].empty());
    assert(v1[1].empty());

    v1[0] = "hi";
    assert(v1[0] == "hi");

    Vector<int> v2(2, 7);
    assert(v2[0] == 7);

    Vector<int> v10(v2);
    assert(v10[1] == 7);

    Vector<std::string> v3(2, "hello");
    assert(v3.size() == 2);
    assert(v3.capacity() == 2);
    assert(v3[0] == "hello");
    assert(v3[1] == "hello");

    v3.resize(1);
    assert(v3.size() == 1);
    assert(v3[0] == "hello");

    Vector<std::string> v4 = v3;
    assert(v4.size() == 1);
    assert(v4[0] == v3[0]);
    v3[0] = "test";
    assert(v4[0] != v3[0]);
    assert(v4[0] == "hello");

    v3.pop_back();
    assert(v3.size() == 0);

    Vector<int> v5(7, 9);
    Vector<int>::iterator it = v5.begin();
    while (it != v5.end())
    {
        assert(*it == 9);
        ++it;
    }

    std::cout << "Succes with the vectors\n";

}
void VerificareGraph()
{

    Graph Graph1;
    f>>Graph1;
    Graph Graph2;
    f>>Graph2;

    Graph Graph3;
    f>>Graph3;

    Graph Graphplus = Graph1 + Graph2 + Graph3;
    std::cout << Graphplus<<'\n';

    std::cout<<Graph1<<'\n';
    std::cout<<Graph2<<'\n';

    bool cycles = Graphplus.existCycle();
    std::cout<<(cycles==1?"Yes, there are cycles\n":"No, there aren't any cycles\n");

    Vector <int> dfs = Graph1.depth_first_search(0);
    Vector <int> bfs = Graph2.breath_first_search(2);

    Vector <int> sorttop = Graph1.topological_sort();

    for (int i = 0; i < sorttop.size(); i++)
        std::cout << sorttop[i]<< ' ';
    std::cout<<'\n';
    for (int i = 0; i < dfs.size(); i++)
        std::cout << dfs[i]<< ' ';
    std::cout<<'\n';
    for (int i = 0; i < bfs.size(); i++)
        std::cout << bfs[i]<< ' ';
    std::cout<<'\n'<<"Now we're starting the Tarjan algorithm"<<'\n';

    std::cout<<(Graph2.is_single_component() == 1? "It's all strong connected" : "Not strong connected");


    std::cout << '\n' << "Succes with the graph\n";
}

int main()
{

    VerificareVector();
    VerificareGraph();

    return 0;
}