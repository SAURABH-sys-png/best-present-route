#include <iostream>
#include "pugixml.hpp"
#include "xml_parser.hpp"

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

    std::cout << "Loaded " << mp.size() << " nodes.\n";

    return 0;
}
