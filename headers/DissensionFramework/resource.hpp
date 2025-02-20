#ifndef RESOURCE_H
#define RESOURCE_H

#include <filesystem>
#include <vector>

namespace DissensionFramework {
    class Resource {
    private:
        std::filesystem::path _filepath;
    public:
        Resource(std::filesystem::path filepath);

        std::vector<unsigned char> getData();

        std::string getRealPath();

        unsigned int getSize();
    };
}

#endif