#include <DissensionFramework/opengl_renderer.hpp>

#include <DissensionFramework/shaders.hpp>

void DissensionFramework::OpenGLRenderer::clear() const {
    glClear(GL_COLOR_BUFFER_BIT);
}

void DissensionFramework::OpenGLRenderer::drawPolygon(std::vector<glm::vec2> points, Color color) const {
    unsigned int vertices_size = points.size() * 2;
    float* vertices = new float[vertices_size];
    for (unsigned int i = 0; i < points.size(); i++) {
        vertices[2 * i] = points[i].x;
        vertices[2 * i + 1] = points[i].y;
    }

    unsigned int indices_size = (vertices_size - 2) * 3;
    unsigned int* indices = new unsigned int[indices_size];
    for (unsigned int i = 0; i < vertices_size - 2; i++) {
        indices[i] = 0;
        indices[i + 1] = i + 1;
        indices[i + 2] = i + 2;
    }

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    unsigned int VBO, EBO;
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices_size, vertices, GL_DYNAMIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * indices_size, indices, GL_DYNAMIC_DRAW);
    
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    Shaders::WHITE_2D.use();

    glDrawElements(GL_TRIANGLES, indices_size, GL_UNSIGNED_INT, 0);
}

void DissensionFramework::OpenGLRenderer::drawEquilateralPolygon(unsigned int count, float radius, Color color) const {
    
}