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
        std::cout << "(1) DFS com backtracking\n";
        std::cout << "(2) A*\n";
        int option;
        std::cin >> option;

        if(option == 1) dfs_backtracking(g);
        else if(option == 2) a_star(g);
        else break;
    }    
}