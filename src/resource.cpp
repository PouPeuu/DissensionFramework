#include <DissensionFramework/resource.hpp>
#include <config.hpp>
#include <iostream>
#include <fstream>

DissensionFramework::Resource::Resource(std::filesystem::path filepath) {
    std::string topmost = (*filepath.begin()).filename();

    if (topmost == "") {
        topmost = ((*++filepath.begin()).filename());
    }
    if (topmost == "builtin"){
        std::filesystem::path new_filepath;
        bool builtin_found = false;
        for (auto it = filepath.begin(); it != filepath.end(); ++it) {
            if ((*it).filename() != "builtin" || builtin_found) {
                if (!(*it).filename().empty()) {
                    new_filepath /= *it;
                }
            } else {
                builtin_found = true;
            }
        }

        _filepath = BUILTIN_RESOURCE_PATH / new_filepath;
    } else {
        _filepath = "res" / filepath;
    }

    if (!std::filesystem::exists(_filepath))
        throw std::runtime_error(_filepath.string() + " doesn't exist");
}

std::vector<unsigned char> DissensionFramework::Resource::getData() {
    std::ifstream data(_filepath, std::ios::binary);
    return std::vector<unsigned char>(std::istreambuf_iterator<char>(data), {});
}

std::string DissensionFramework::Resource::getRealPath() {
    return _filepath.string();
}