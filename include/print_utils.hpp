#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>

void printWayMap(const std::unordered_map<long long, std::vector<long long>> &wayMap);
void printGraph(const std::unordered_map<long long, std::vector<std::pair<long long, long long>>> &edges);
