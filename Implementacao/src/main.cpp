#include "build.hpp"
#include "graph.hpp"
#include "print.hpp"
#include "strategy.hpp"
#include <iostream>

int main(){
    std::string filename;
    std::cout << "Digite o nome do arquivo de entrada: ";
    std::cin >> filename;
    
    Graph g = build(filename);        

    while(1){
        std::cout << "Escolha uma das opções abaixo:\n";
        std::cout << "(0) Sair\n";
        std::cout << "(1) BFS\n";
        std::cout << "(2) A*\n";
        std::cout << "(3) BFS - distância máxima\n";
        int option;
        std::cin >> option;

        if(option == 1) bfs(g, -1, false);
        else if(option == 2) a_star(g, false);
        else if (option == 3){
            int max_distance;
            std::cout << "Qual a distância máxima?\n";
            std::cin >> max_distance;
            bfs(g, max_distance, false);
        }
        else break;
    }    
}