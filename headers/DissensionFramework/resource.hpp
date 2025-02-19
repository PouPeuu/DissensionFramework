#ifndef RESOURCE_H
#define RESOURCE_H

#include <filesystem>

namespace DissensionFramework {
    class Resource {
    private:
        std::filesystem::path _filepath;
    public:
        Resource(std::filesystem::path filepath);
    };
}

#endif