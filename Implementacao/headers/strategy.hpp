#ifndef STRATEGY_H
#define STRATEGY_H
#include "graph.hpp"

void bfs(Graph &g, int max_distance, bool is_test);
void a_star(Graph &g, bool is_test);

#endif