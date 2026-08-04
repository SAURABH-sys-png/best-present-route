#pragma once
#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>
#include <vector>
#include "pugixml.hpp"
#include "xml_parser.hpp"

struct Graph
{
    long long way_id;
    std::vector<long long> connections;
};

std::unordered_map<long long, std::vector<long long>> buildData(const pugi::xml_document &doc);
std::unordered_map<long long, std::vector<std::pair<long long, long long>>> buildAdjacencyList(
    const std::unordered_map<long long, std::vector<long long>> &way_id_arr_nodes);
