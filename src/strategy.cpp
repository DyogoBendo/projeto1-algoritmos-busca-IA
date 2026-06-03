#include "strategy.hpp"
#include "print.hpp"

#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <queue>
#include <functional>
#include <map>

void dfs_backtracking(Graph &g){
    std::vector<Node> st;    
    st.push_back(Node(g.startNode, 0, 0));
    std::set<std::string> generated_nodes;
    std::map<std::string, std::string> parent_map;
    
    int iteration = 0;
    bool found = false;
    int tot_dist = -1;        
    generated_nodes.insert(g.startNode);

    while(!st.empty() and !found){        
        auto [n, dist, h] = st.back(); st.pop_back();          
        if(n == g.endNode){
            tot_dist = dist;            
            found = true;
        } 
        
        if(!found){
            for(auto [u, d] : g.node_edges[n]) if(!generated_nodes.count(u)){                       
                generated_nodes.insert(u);
                parent_map[u] = n;
                st.push_back(Node(u, d + dist, 0));
            }
            iteration++;
            print_iteration(iteration, st, generated_nodes.size());
        }
    }
    
    print_result(g.endNode, parent_map, tot_dist, generated_nodes.size());
}

void a_star(Graph &g){
    std::set<Node> frontier;    
    frontier.insert(Node(g.startNode, 0, 0));

    std::map<std::string, int> generated_nodes;
    std::map<std::string, std::string> parent_map;
    generated_nodes[g.startNode] = g.node_heuristic[g.startNode];

    int iteration = 0;
    bool found = false;
    int tot_dist = -1;    

    while(!frontier.empty() and !found){        
        auto fbegin = frontier.begin();
        Node node = *fbegin;
        frontier.erase(fbegin);        
        
        if(node.state == g.endNode){
            tot_dist = node.g;            
            found = true;
        } 
        
        if(!found){
            for(auto [u, d] : g.node_edges[node.state]){                
                Node prox(u, d + node.g, g.node_heuristic[u]);                
                if(!generated_nodes.count(u) or generated_nodes[u] > prox.g){        
                    if(generated_nodes.count(u)) frontier.erase(Node(u, generated_nodes[u], g.node_heuristic[u]));
                    
                    generated_nodes[u] = prox.g;
                    parent_map[u] = node.state;                    
                    frontier.insert(prox);                    
                }                
            }     
                                
            iteration++;
            print_iteration(iteration, frontier, generated_nodes.size());
        }
    }
    
    print_result(g.endNode, parent_map, tot_dist, generated_nodes.size());
}