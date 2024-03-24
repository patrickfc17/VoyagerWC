#pragma once

#include <vector>
#include <filesystem>

using std::filesystem::path;
using std::filesystem::directory_iterator;
using std::filesystem::is_directory;
using std::string;
using std::vector;

namespace DirectoryManager
{
    vector<string> travel_subpaths(const path base_path);
    vector<string> get_files(const path base_path);
    vector<string> get_current_directories(const path current);
}
