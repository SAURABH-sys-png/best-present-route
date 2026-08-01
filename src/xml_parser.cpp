#include "xml_parser.hpp"

NodeMap buildNodeMap(const pugi::xml_document &doc)
{
    NodeMap nodeMap;

    pugi::xml_node node = doc.child("osm");
    for (pugi::xml_node ind_node : node.children("node"))
    {
        pugi::xml_attribute id_atr = ind_node.attribute("id");
        pugi::xml_attribute lat_atr = ind_node.attribute("lat");
        pugi::xml_attribute lon_atr = ind_node.attribute("lon");
        Node nd;
        nd.lat = lat_atr.as_double();
        nd.lon = lon_atr.as_double();
        nodeMap[id_atr.as_llong()] = nd;
    }

    return nodeMap;
}
