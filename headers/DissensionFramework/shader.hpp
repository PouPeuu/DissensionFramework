#ifndef SHADER_H
#define SHADER_H

#include <DissensionFramework/resource.hpp>
// This is opengl only for now...
#include <DissensionFramework/opengl_includes.hpp>

namespace DissensionFramework {
    class Shader {
        private:
            int _id;

            unsigned int _compileShader(Resource shader_resource, GLuint shader_type);
        public:
            Shader(Resource vertex_shader_resource, Resource fragment_shader_resource);

            void use() const;
    };
}

#endif