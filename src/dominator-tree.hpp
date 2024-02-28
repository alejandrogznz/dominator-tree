#pragma once

#include "Graph.hpp"
#include <string>
namespace gzn
{

    class DominatorTree: public Graph
    {
        public:
        DominatorTree(std::string filename);

        private:

        void generateTree();

        static void printMapSet(std::map<int, std::set<int>> mapset);
    };
}
