#include <DissensionFramework/resource.hpp>
#include <config.hpp>
#include <iostream>

DissensionFramework::Resource::Resource(std::filesystem::path filepath) {
    std::string topmost = (*filepath.begin()).filename();
    if (topmost == "") {
        topmost = ((*++filepath.begin()).filename());
    }
    if (topmost == "builtin"){
        _filepath = BUILTIN_RESOURCE_PATH / filepath;
    } else {
        _filepath = "res" / filepath;
    }
}