#include "graph.hpp"

Node::Node(std::string s, int g_cost, int h_cost){
    this->state = s;
    this->g = g_cost;
    this->h = h_cost;
}

int Node::f() const {
    return g + h;
}

bool Node::operator<(const Node& other) const {    
    return this->f() < other.f();
}