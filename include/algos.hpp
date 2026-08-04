#pragma once

#include <bits/stdc++.h>

#define Path std::vector<long long>


Path findPath(long long st,long long end,std::unordered_map<long long, std::vector<std::pair<long long, long long>>> adjacency);