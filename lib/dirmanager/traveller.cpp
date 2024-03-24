#include <iostream>
#include "traveller.hpp"

namespace DirectoryManager
{
    static vector<string> travel_subpaths_recursive(const path base_path, vector<string> &paths_list);
}

vector<string> DirectoryManager::travel_subpaths(const path base_path)
{
    auto paths_list = vector<string>();
    DirectoryManager::travel_subpaths_recursive(base_path, paths_list);

    return paths_list;
}

static vector<string> DirectoryManager::travel_subpaths_recursive(const path base_path, vector<string> &paths_list)
{
    if (base_path.empty()) return paths_list;

    for (const auto &subpath : directory_iterator(base_path))
    {
        if (!is_directory(subpath)) continue;

        paths_list.push_back(subpath.path());

        travel_subpaths_recursive(subpath.path(), paths_list);
    }

    return paths_list;
}
