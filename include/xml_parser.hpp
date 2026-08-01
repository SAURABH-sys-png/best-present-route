#pragma once

#include <unordered_map>
#include "pugixml.hpp"

struct Node
{
    double lat;
    double lon;
};

using NodeMap = std::unordered_map<long long, Node>;

NodeMap buildNodeMap(const pugi::xml_document& doc);
