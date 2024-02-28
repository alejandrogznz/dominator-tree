#include "dominator-tree.hpp"

namespace gzn
{
    DominatorTree::DominatorTree(std::string filename)
        :Graph(filename)
    {
        for(auto it = vertices.begin(); it != vertices.end(); ++it)
        {
            auto &[first, second] = *it;
            std::cout << first << " -> " << second << std::endl;
        }

        // Build Tree from vertices
        generateTree();
    } 
    
    void DominatorTree::generateTree()
    {
        SetType visited;
        std::map<int, std::set<int>> doms;

        // All vertices dominate themselves;
        for (auto it = vertices.begin(); it != vertices.end(); ++it)
        {
            auto &[first, second] = *it;
            doms[first].insert(first);
            doms[second].insert(second);
        }


        printMapSet(doms);
    }

    void DominatorTree::printMapSet(std::map<int, std::set<int>> mapset)
    {
        for (auto it1 = mapset.begin(); it1 != mapset.end(); ++it1)
        {
            std::cout << it1->first << " doms ";
            // Print Dominated
            for (auto it2 = it1->second.begin(); it2 != it1->second.end(); ++it2)
            {
                std::cout << *it2 << " ";
            }
            std::cout << std::endl;
        }
    }
}
