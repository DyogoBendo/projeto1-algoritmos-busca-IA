#include "print.hpp"
#include "graph.hpp"
#include <vector>
#include <tuple>
#include <iostream>
#include <iomanip>
#include <algorithm>


void print_graph(Graph &g){
    for(auto [s, e] : g.node_edges){
        std::cout << s << '\n';
        for(auto [t, d] : e) std::cout << " " << t << " " << d << '\n';
    }
    BLOCK_SEPARATOR;
    std::cout << g.startNode << " - " << g.endNode << " orientado? " << g.is_oriented << '\n';
}


void print_result(std::string endNode, std::map<std::string, std::string> parent_map, int distance, int generated_nodes){
    BLOCK_SEPARATOR;
    std::cout << "Fim da execução\n";
    std::cout << "Distância: " << distance <<"\n";        

    std::vector<std::string> path;
    while(endNode != ""){
        path.push_back(endNode);
        endNode = parent_map[endNode];
    }
    std::reverse(path.begin(), path.end());
    std::cout << "Caminho: ";
    for(int i = 0; i < (int) path.size(); i++){
        std::string u = path[i];
        std::cout << u;
        if(i < (int) path.size() - 1) std::cout << " - ";
    }

    std::cout << "\nNós gerados: " << generated_nodes << "\n";   
    BLOCK_SEPARATOR;
}