#ifndef PRINT_H
#define PRINT_H
#include "graph.hpp"
#include <vector>
#include <tuple>
#include <iostream>
#include <iomanip>
#include <algorithm>

#define BLOCK_SEPARATOR std::cout << "-----------------------\n"
#define PRESENTATION 0

void print_graph(Graph &g);
void print_result(std::string endNode, std::map<std::string, std::string> parent_map, int distance, int generated_nodes);

template <typename T> void print_iteration(int iteration, T &frontier, int generated_nodes){    
    if(!PRESENTATION) return;
    BLOCK_SEPARATOR;
    std::cout << "Iteração: " << iteration << ":\n";
    std::cout << "Lista: ";
    for(auto [u, d, h] : frontier){
        std::cout << "(" << u << ": " << d << " + " << h << " = " << d + h << ") "; 
    }
    std::cout << "\nNós gerados: " << generated_nodes << "\n";   
    BLOCK_SEPARATOR;
}

#endif