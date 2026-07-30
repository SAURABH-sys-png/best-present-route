#include <iostream>
#include "pugixml.hpp"

int main()
{
    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_file("../data/map.osm");

    if (!result)
    {
        std::cout << "Failed to load file\n";
        return 1;
    }

    std::cout << "Loaded Successfully!\n";

    pugi::xml_node osm = doc.child("osm");

    std::cout << "Root Node: " << osm.name() << "\n";

    for (pugi::xml_node child : osm.children())
    {
    std::cout << child.name() << '\n';
    }
    return 0;
}
