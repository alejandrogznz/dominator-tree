#include "Graph.hpp"

namespace gzn
{
    Graph::Graph(std::string filename)
        :root(0)
    {
        std::ifstream stream(filename, std::ios::in);
        int a, b;
        while (stream >> a >> b)
        {
            vertices.insert(MapType::value_type(a,b));
        }
        stream.close();
    }

    SetType Graph::keys()
    {
        SetType k;
        for (auto it = vertices.begin(); it != vertices.end(); ++it)
        {
            k.insert(it->first);
            k.insert(it->second);
        }

        for (auto it: k)
        {
            std::cout << it << std::endl;
        }
        return k;
    }

    void Graph::traverse()
    {
        int start = root;
        SetType visited;
        SetType workSet{root};
        while(!workSet.empty())
        {
            int current = *(workSet.begin());
            workSet.erase(current);
            visited.insert(current);
            for (auto it = vertices.find(current); it != vertices.end(); ++it)
            {
                if (it->first != current) continue;
                if (visited.count(it->second) > 0) continue;
                workSet.insert(it->second);
            }
            workSet.erase(current);
            std::cout << "WorkSet after " << current << ":" << std::endl;
            printSet(workSet);
        }
    }

    void Graph::printSet(SetType &s)
    {
        for (auto it = s.begin(); it != s.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
}
