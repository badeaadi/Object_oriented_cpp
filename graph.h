#ifndef CLIONNEW_GRAPH_H
#define CLIONNEW_GRAPH_H
#include <exception>
#include "node.h"

std::ifstream f("graph.in");

class Graph {
    int nr_of_vertices{};
    int nr_of_edges{};

public:

    Vector < Node >  list;

    Graph() = default;
    Graph(int vertices, int edges);

    Graph(Graph & second_graph);

    ~Graph();

    friend Graph operator +(const Graph &first_graph, const Graph & second_graph);


    Graph & operator =(const Graph & second_graph);

    friend std::istream& operator >>(std::istream & fin, Graph & read_graph);

    friend std::ifstream& operator >>(std::ifstream & fin, Graph & read_graph);

    friend std::ostream& operator <<(std::ostream & fout, const Graph & written_graph);

    friend std::ofstream& operator <<(std::ofstream & fout, const Graph & written_graph);

    virtual int get_nr_of_vertices() const;

    virtual int get_nr_of_edges() const;

    void set_nr_of_vertices(const int &vert);

    void set_nr_of_edges(const int &edges);

    Vector<int> depth_first_search(int starting_node);

    Vector<int> breath_first_search(int starting_node);

    void dfs_recursive(int node, int * viz, Vector<int> *order);

    bool operator == (Graph &second_graph);

    bool operator != (Graph &second_graph);

    bool operator < (const Graph &second_graph);

    bool existCycle();

    Vector<int> topological_sort();

    void dfs_strong_connected(int x, int * niv, int *low, int *in,  Vector<Vector<int> > * ctc);

    Vector <Vector <int> > strong_connected();

    bool is_single_component();

};
Graph::~Graph()
= default;

Graph::Graph(int vertices, int edges) {

    this->nr_of_vertices = vertices;
    this->nr_of_edges = edges;
}

Graph::Graph(Graph &second_graph) {

    this->nr_of_vertices =  second_graph.nr_of_vertices;
    this->nr_of_edges = second_graph.nr_of_edges;
    list = second_graph.list;
}


Graph &Graph::operator =(const Graph &second_graph) {

    nr_of_vertices = second_graph.nr_of_vertices;
    int i = 0;
    auto it2 = second_graph.list.begin();
    for (auto it = list.begin(); i < nr_of_vertices ; it++, i++, it2++)
        *it = *it2;
    return *this;
}

std::istream &operator>>(std::istream &fin, Graph & read_graph) {

    fin >> read_graph.nr_of_vertices;
    fin >> read_graph.nr_of_edges;

    read_graph.list.resize(static_cast<unsigned int>(read_graph.nr_of_vertices));

    int ver1, ver2;
    for (int i = read_graph.nr_of_edges; i; i--) {

        fin>>ver1>>ver2;
        read_graph.list[ver1].list.push_back(ver2);
    }
    for (int i = 0; i < read_graph.nr_of_vertices; i++)
        read_graph.list[i].set_current_node(i);

    return fin;
}
std::ifstream &operator >>(std::ifstream &fin, Graph & read_graph) {

    fin >> read_graph.nr_of_vertices;
    fin >> read_graph.nr_of_edges;

    read_graph.list.resize(static_cast<unsigned int>(read_graph.nr_of_vertices));

    int ver1, ver2;
    for (int i = read_graph.nr_of_edges; i; i--) {

        fin>>ver1>>ver2;
        read_graph.list[ver1].list.push_back(ver2);
    }
    for (int i = 0; i < read_graph.nr_of_vertices; i++)
        read_graph.list[i].set_current_node(i);

    return fin;
}

std::ostream & operator <<(std::ostream &fout, const Graph & written_graph)
{

    fout << written_graph.get_nr_of_vertices()<<' ';
    fout << written_graph.get_nr_of_edges()<<'\n';

    for (Vector<Node> :: iterator it = written_graph.list.begin(); it != written_graph.list.end(); it++)
        fout << *it;

    return fout;
}
std::ofstream & operator <<(std::ofstream &fout, const Graph & written_graph) {

    fout << written_graph.get_nr_of_vertices()<<' ';
    fout << written_graph.get_nr_of_edges()<<'\n';

    for (Vector<Node> :: iterator it = written_graph.list.begin(); it != written_graph.list.end(); it++)
        fout << *it;

    return fout;
}

int Graph::get_nr_of_vertices() const {

    return nr_of_vertices;

}
int Graph::get_nr_of_edges() const {

    return nr_of_edges;
}

void Graph::set_nr_of_vertices(const int &vertices) {

    nr_of_vertices = vertices;
}

void Graph::set_nr_of_edges(const int &edges) {

    nr_of_edges = edges;
}

Graph operator+(const Graph &first_graph, const Graph &second_graph) {

    Graph newGraph;
    if (first_graph.get_nr_of_vertices() != second_graph.get_nr_of_vertices())
        throw std::invalid_argument("Received graphs with different number of vertices");
    newGraph.set_nr_of_vertices(first_graph.get_nr_of_vertices());
    newGraph.set_nr_of_edges(first_graph.get_nr_of_edges() + second_graph.get_nr_of_edges());

    newGraph.list.resize(static_cast<unsigned int>(newGraph.get_nr_of_vertices()));
    unsigned int i = 0, j = 0 ;


    for (auto it = first_graph.list.begin(); it!= first_graph.list.end(); it++, i++)
         newGraph.list[i].add_edges(*it);
    i = 0;
    for (auto it = second_graph.list.begin(); it!= second_graph.list.end(); it++, i++)
        newGraph.list[i].add_edges(*it);

    newGraph.set_nr_of_edges(0);
    for (i = 0; i < newGraph.get_nr_of_vertices(); i++) {
        j = static_cast<unsigned int>(newGraph.get_nr_of_edges() + newGraph.list[i].list.size());
        newGraph.set_nr_of_edges(j);
    }

    for (i = 0 ; i< newGraph.get_nr_of_vertices(); i++)
        newGraph.list[i].set_current_node(i);


    return  newGraph;
}

void Graph::dfs_recursive(int current_node, int viz[], Vector <int> * order)
{
    viz[current_node] = 1;
    order->push_back(current_node);
    for (int i = 0; i < this->list[current_node].list.size(); i++)
        if (viz[this->list[current_node].list[i]] == 0)
            dfs_recursive(this->list[current_node].list[i], viz, order);
}
Vector <int> Graph::depth_first_search(int starting_node) {

    Vector <int> dfs_order;
    int viz[nr_of_vertices];
    for (int i = 0 ; i < nr_of_vertices; i++)
        viz[i] = 0;
    dfs_recursive(starting_node, viz, &dfs_order);

    while (dfs_order.size() < nr_of_vertices)
        dfs_order.push_back(-1);

    return dfs_order;

}
Vector <int> Graph::breath_first_search(int starting_node) {

    int viz[nr_of_vertices];
    int queue[nr_of_vertices];
    for (int i = 0 ; i < nr_of_vertices; i++)
        viz[i] = 0, queue[i] = 0;

    queue[0] = starting_node;
    viz[0] = 1;
    for (int i = 0, j = 1; i < j ; i++) {
        for (int t = 0; t < this->list[queue[i]].list.size(); t++)
            if (viz[this->list[queue[i]].list[t]] == 0) {
                viz[this->list[queue[i]].list[t]] = 1;
                queue[j++] = this->list[queue[i]].list[t];
            }
    }
    Vector <int> order;
    for (int i = 0; i < nr_of_vertices; i++)
        order.push_back(queue[i]);
    return order;
}
bool Graph::operator ==(Graph & second_graph)
{
    if (this->nr_of_vertices != second_graph.nr_of_vertices)
      return false;
    if (this->nr_of_edges != second_graph.nr_of_edges)
      return false;
    for (int i = 0 ; i < this->nr_of_vertices; i++)
      if (!(this->list[i] == second_graph.list[i]))
          return false;
    return true;
}
bool Graph::operator != (Graph &second_graph)
{
  return static_cast<bool>(1 - (*this == second_graph));
}
bool Graph::operator < (const Graph & second_graph)
{
    if (this->nr_of_vertices != second_graph.nr_of_vertices)
      return this->nr_of_vertices < second_graph.nr_of_vertices;

    if (this->nr_of_edges != second_graph.nr_of_edges)
      return this->nr_of_edges < second_graph.nr_of_edges;

    throw std::invalid_argument("Graphs are something far too complex to compare below this point");
}

class Matrix{

private:
    int nr_of_edges = {};

public:
    Vector < Vector <char> > v;

    explicit Matrix(Graph & graph);

    ~Matrix() = default;
};

Matrix::Matrix(Graph &graph)
{
    int i, j;


    this->v.resize(static_cast<unsigned int>(graph.get_nr_of_vertices()));
    for (i = 0 ; i < graph.get_nr_of_vertices(); i++)
      for (j = 0; j < graph.get_nr_of_vertices(); j++)
            this->v[i].push_back(0);


    Vector <int> order;

    for (i = 0 ; i < graph.get_nr_of_vertices(); i++) {
        order = graph.depth_first_search(i);
        for (j = 0; j < graph.get_nr_of_vertices(); j++) {
            int k = order[j];
            if (k==-1)
                continue;
            if (i==k)
                continue;
            this->v[i][k] = 1;
        }
    }
};

bool Graph::existCycle() {

    Matrix newmat(*this);
    int i, j;
    for (i = 0; i < this->get_nr_of_vertices(); i++)
        for (j = 0; j < this->get_nr_of_vertices(); j++)
            if (newmat.v[i][j] == 1 && newmat.v[j][i]==1)
                return true;
    return false;
}
Vector <int> Graph:: topological_sort()
{
    if (this->existCycle())
        throw std::invalid_argument("There are cycles hiding around here!");

    Vector <int> order;

    Matrix newmat(*this);

    int i, j, k;
    int n = this->get_nr_of_vertices();

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int ok = 1;
            for (k = 0; k < n; k++)
                if (newmat.v[k][j]) {
                    ok = 0;
                    break;
                }
            if (ok)
                break;
        }
        for (k = 0; k < n ; k++)
            newmat.v[j][k] = 0 ;
        order.push_back(j);
        newmat.v[j][j] = 1;
    }
    return order;
}
//TODO ++

void Graph::dfs_strong_connected(int x, int *niv, int * low, int *in, Vector<Vector<int> > * ctc)
{
    static int k = 0;
    static Vector<int> st;

    int i, y;
    Vector <int> nullvector;

    ++k;
    niv[x]=k;
    low[x]=k;
    st.push_back(x);
    in[x]=1;
    for (i=0 ; i < this->list[x].list.size();i++) {
        y = this->list[x].list[i];
        if (niv[y]==0) {
            dfs_strong_connected(y, niv, low, in, ctc);
            if (low[y] < low[x])
                low[x] = low[y];
        }
        else
            if (in[y])
                low[x] = std::min(low[x], low[y]);
    }
    if (niv[x]==low[x]) {
        ctc->push_back(nullvector);
        do {
            y=st[st.size()-1];
            st.pop_back();
            in[y]=0;
            ctc->back().push_back(y);
        } while (x != y);

    }
}
Vector< Vector<int> > Graph::strong_connected()
{
    int i, j;
    int n = this->get_nr_of_vertices();
    int niv[n], low[n], in[n];
    for (i = 0; i< n ; i++)
        niv[i] = low[i] = in[i] = 0;

    Vector<Vector<int> > ctc;


    for (i = 0 ; i < n ;i++)
        if ( !niv[i])
            dfs_strong_connected(i, niv, low, in, &ctc);

    std::cout<<ctc.size()<<'\n';

    for (i = 0; i < ctc.size(); i++) {
        for (j = 0; j < ctc[i].size(); j++)
            std::cout<<ctc[i][j]<<' ';
        std::cout<<'\n';
    }
    return ctc;
}
bool Graph::is_single_component()
{
    Vector <Vector<int> > ctc = strong_connected();
    return ctc.size() == 1;
}

#endif //CLIONNEW_GRAPH_H
