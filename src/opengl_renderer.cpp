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

    unsigned int indices_size = (points.size() - 2) * 3;
    unsigned int* indices = new unsigned int[indices_size];
    for (unsigned int i = 0; i < points.size() - 2; i++) {
        indices[3 * i] = 0;
        indices[3 * i + 1] = i + 1;
        indices[3 * i + 2] = i + 2;
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
    
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    Shaders::WHITE_2D.use();

    glDrawElements(GL_TRIANGLES, indices_size, GL_UNSIGNED_INT, 0);

    delete[] vertices;
    delete[] indices;
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}