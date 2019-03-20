#ifndef CLIONNEW_NODE_H
#define CLIONNEW_NODE_H
#include "vector.h"

class Node {

    int current_node;
    int nr_of_edges{0};

public:

    Vector <int> list;
    Node();

    ~Node();

    Node(const Node & second_node);

    Node & operator =(const Node & second_node);

    void add_edges(const Node &second_node);

    int get_current_node() const;

    void set_current_node(int newnode);

    friend std::ostream & operator <<(std::ostream & fout,const Node &this_node);

    friend std::ofstream & operator <<(std::ofstream &fout, const Node &this_node);

    int get_number_of_edges() const;

    bool operator ==(Node second_node);
};
Node::~Node() {

}
Node ::Node() {

    current_node = 0;
    nr_of_edges = 0;
}
Node::Node (const Node & second_node)
{
    list = second_node.list;
    current_node = second_node.current_node;
}
Node & Node::operator =(const Node &second_node) = default;


//TODO + add_edges
void Node::add_edges(const Node &second_node) {


    for (int &it : second_node.list)
        if (list.contain(it) == 0)
            list.push_back(it);
}

int Node::get_current_node() const{

    return current_node;
}
void Node::set_current_node(int newnode) {

    current_node = newnode;
}
std ::ostream & operator <<(std::ostream &fout,const Node & this_node)
{
    for (int &it : this_node.list) {
        fout << this_node.get_current_node()<< ' '<< it<<'\n';
    }

    return fout;
}
std ::ofstream & operator <<(std::ofstream &fout,const Node & this_node)
{
    for (int &it : this_node.list) {
        fout << this_node.get_current_node()<< ' ' << it<< '\n';
    }
    return fout;
}

int Node::get_number_of_edges() const {
    return nr_of_edges;
}
bool Node::operator == (Node second_node)
{
    if (nr_of_edges != second_node.nr_of_edges)
        return false;
    this->list.sort();
    second_node.list.sort();
    for (int i = 0; i < nr_of_edges; i++)
        if (list[i] != this->list[i])
            return false;
    return true;

}

#endif //CLIONNEW_NODE_H
