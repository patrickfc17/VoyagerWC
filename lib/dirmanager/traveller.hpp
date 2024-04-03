#pragma once

#include <vector>
#include <filesystem>

namespace DirectoryManager
{
    std::vector<std::string> travel_subpaths(const std::filesystem::path base_path);

    std::vector<std::string> get_files(const std::filesystem::path base_path);

    std::vector<std::string> current_dirs();
}
