#pragma once
#include <bits/stdc++.h>
#include <unordered_map>
#include "pugixml.hpp"
#include "xml_parser.hpp"

// only the function definations in here
// Our next job is to construct a graph out of this map

struct Graph
{
    long long way_id;
    std::vector<long long> connections;
};

std::unordered_map<long long,std::vector<long long>> buildData(const pugi::xml_document&doc);