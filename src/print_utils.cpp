#include "print_utils.hpp"

void printWayMap(const std::unordered_map<long long, std::vector<long long>> &wayMap)
{
    for (const auto &[wayId, nodeList] : wayMap)
    {
        std::cout << "Way ID: " << wayId << "\n";
        std::cout << "Nodes: ";

        for (long long nodeId : nodeList)
        {
            std::cout << nodeId << " ";
        }

        std::cout << "\n----------------------------------\n";
    }
}

void printGraph(const std::unordered_map<long long, std::vector<std::pair<long long, long long>>> &edges)
{
    for (const auto &[node, neighbours] : edges)
    {
        std::cout << "Node " << node << " -> ";

        for (const auto &[adjNode, weight] : neighbours)
        {
            std::cout << "(" << adjNode << ", weight=" << weight << ") ";
        }

        std::cout << '\n';
    }
}
