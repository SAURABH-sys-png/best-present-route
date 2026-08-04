#include <iostream>
#include "pugixml.hpp"
#include "xml_parser.hpp"
#include "map_to_grp.hpp"

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
int main()
{
    pugi::xml_document doc;
    if (!doc.load_file("../data/map.osm"))
    {
        std::cout << "There was an error loading the file.\n";
        return -1;
    }
    std::cout << "File loaded successfully.\n";
    NodeMap mp = buildNodeMap(doc);
    std::unordered_map<long long, std::vector<long long>> way_id_arr_nodes = buildData(doc);
    printWayMap(way_id_arr_nodes);

    std::cout << "Loaded " << mp.size() << " nodes.\n";

    return 0;
}
