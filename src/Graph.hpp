#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

namespace gzn
{
    typedef std::multimap<int, int> MapType;
    typedef std::set<int> SetType;

    class Graph
    {
        public:

        Graph(std::string filename);

        SetType keys();

        void traverse();

        private:

        int root;
        
        MapType vertices;
        
        void printSet(SetType &set);
    };
}
