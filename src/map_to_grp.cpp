#include <bits/stdc++.h>
#include "map_to_grp.hpp"

std::unordered_map<long long, std::vector<long long>> buildData(const pugi::xml_document &doc)
{
    pugi::xml_node way_node = doc.child("osm");
    std::unordered_map<long long, std::vector<long long>> mp;

    for (pugi::xml_node ind_way : way_node.children("way"))
    {
        bool isHighway = false;
        for (pugi::xml_node tag : ind_way.children("tag"))
        {
            if (std::string(tag.attribute("k").value()) == "highway")
            {
                isHighway = true;
                break;
            }
        }
        if (!isHighway)
            continue;
        std::vector<long long> arr_of_nodes;
        for (pugi::xml_node nd : ind_way.children("nd"))
        {
            arr_of_nodes.push_back(nd.attribute("ref").as_llong());
        }
        long long id = ind_way.attribute("id").as_llong();
        mp[id] = arr_of_nodes;
    }

    return mp;
}

std::unordered_map<long long, std::vector<std::pair<long long, long long>>> buildAdjacencyList(
    const std::unordered_map<long long, std::vector<long long>> &way_id_arr_nodes)
{
    std::unordered_map<long long, std::vector<std::pair<long long, long long>>> adjacency;

    for (const auto &[wayId, nodeList] : way_id_arr_nodes)
    {
        (void)wayId;
        for (std::size_t i = 0; i + 1 < nodeList.size(); ++i)
        {
            const long long fromNode = nodeList[i];
            const long long toNode = nodeList[i + 1];

            adjacency[fromNode].push_back({toNode, 1});
            adjacency[toNode].push_back({fromNode, 1});
        }
    }

    return adjacency;
}