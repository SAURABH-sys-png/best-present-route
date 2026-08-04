#include <iostream>
#include "pugixml.hpp"
#include "xml_parser.hpp"
#include "map_to_grp.hpp"
#include "print_utils.hpp"

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
    std::unordered_map<long long, std::vector<std::pair<long long, long long>>> adjacency = buildAdjacencyList(way_id_arr_nodes);

    printWayMap(way_id_arr_nodes);
    printGraph(adjacency);

    std::cout << "Loaded " << mp.size() << " nodes.\n";

    return 0;
}
