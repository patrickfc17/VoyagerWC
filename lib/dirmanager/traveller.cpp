#include <iostream>
#include <string>

#include "traveller.hpp"

using std::filesystem::path;
using std::filesystem::directory_iterator;
using std::filesystem::is_directory;
using std::filesystem::current_path;
using std::string;
using std::vector;

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

        DirectoryManager::travel_subpaths_recursive(subpath.path(), paths_list);
    }

    return paths_list;
}

vector<string> DirectoryManager::get_files(const path base_path)
{
    vector<string> path_files;

    for (auto current : directory_iterator(base_path))
    {
        if (is_directory(current)) continue;

        path_files.push_back(current.path());
    }

    return path_files;
}

vector<string> DirectoryManager::current_dirs()
{
    auto current = current_path();

    vector<string> current_dirs;

    for (auto inner_path : directory_iterator(current))
    {
        if (!is_directory(inner_path)) continue;

        current_dirs.push_back(inner_path.path());
    }

    return current_dirs;
}
