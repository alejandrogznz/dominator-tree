#include <iostream>
#include <fstream>
#include "Graph.hpp"
#include "dominator-tree.hpp"

int main() 
{
    gzn::DominatorTree graph(std::string("input.txt"));
    //graph.keys();
    //graph.traverse();
    return 0;
}
