#ifndef SKYBOX_H
#define SKYBOX_H
#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Skybox {
public:
    Skybox(const std::vector<std::string>& faces);
    ~Skybox();

    void Draw(const glm::mat4& view, const glm::mat4& projection);

private:
    GLuint m_VAO, m_VBO;
    GLuint m_CubemapTexture;
    GLuint m_ShaderProgram;

    void Initialize();
    void LoadCubemap(const std::vector<std::string>& faces);
    void SetupShader();
    void CreateMesh(float scale);
    void CheckShaderCompileErrors(GLuint shader, const std::string& type);
    void CheckShaderLinkingErrors(GLuint program);
};

#endif



