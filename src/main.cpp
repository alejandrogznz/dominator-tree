#include <iostream>
#include <fstream>
#include "Graph.hpp"


int main() 
{
    gzn::Graph graph(std::string("input.txt"));
    graph.keys();
    graph.traverse();
    return 0;
}
