#include "Skybox.h"
#include "stb/stb_image.h"

Skybox::Skybox(const std::vector<std::string>& faces) {
    Initialize();
    LoadCubemap(faces);
    SetupShader();
    CreateMesh(50.0f);
}

Skybox::~Skybox() {
    glDeleteVertexArrays(1, &m_VAO);
    glDeleteBuffers(1, &m_VBO);
    glDeleteTextures(1, &m_CubemapTexture);
    glDeleteProgram(m_ShaderProgram);
}

void Skybox::Draw(const glm::mat4& view, const glm::mat4& projection) {
    glUseProgram(m_ShaderProgram);

    glDepthFunc(GL_LEQUAL);

    glm::mat4 viewMatrix = glm::mat4(glm::mat3(view));
    glUniformMatrix4fv(glGetUniformLocation(m_ShaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(viewMatrix));
    glUniformMatrix4fv(glGetUniformLocation(m_ShaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

    glBindVertexArray(m_VAO);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, m_CubemapTexture);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);

    glDepthFunc(GL_LESS);
}

void Skybox::Initialize() {
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);

    glBindVertexArray(m_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glBindVertexArray(0);
}

void Skybox::LoadCubemap(const std::vector<std::string>& faces) {
    glGenTextures(1, &m_CubemapTexture);
    glBindTexture(GL_TEXTURE_CUBE_MAP, m_CubemapTexture);

    int width, height, nrChannels;
    for (GLuint i = 0; i < faces.size(); i++) {
        unsigned char* data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
        if (data) {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            stbi_image_free(data);
        }
        else {
            std::cerr << "Failed to load cubemap texture: " << faces[i] << std::endl;
        }
    }

    //Texture Parameters
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
}

void Skybox::SetupShader() {
    const char* vertexShaderSource = R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;
        out vec3 TexCoords;
        uniform mat4 view;
        uniform mat4 projection;
        void main() {
            TexCoords = aPos;  
            gl_Position =  projection * view * vec4(aPos, 1.0);
        })";

    const char* fragmentShaderSource = R"(
        #version 330 core
        in vec3 TexCoords;
        out vec4 FragColor;
        uniform samplerCube skybox;
        void main() {    
            FragColor = texture(skybox, TexCoords);
        })";

    GLuint vertexShader, fragmentShader;

    //Compile and link the shaders
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    CheckShaderCompileErrors(vertexShader, "VERTEX");

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    CheckShaderCompileErrors(fragmentShader, "FRAGMENT");

    m_ShaderProgram = glCreateProgram();
    glAttachShader(m_ShaderProgram, vertexShader);
    glAttachShader(m_ShaderProgram, fragmentShader);
    glLinkProgram(m_ShaderProgram);
    CheckShaderLinkingErrors(m_ShaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Skybox::CreateMesh(float scale) {
    // Scaled cube vertices
    float vertices[] = {
        // Scaled positions
        -scale,  scale, -scale,
        -scale, -scale, -scale,
         scale, -scale, -scale,
         scale, -scale, -scale,
         scale,  scale, -scale,
        -scale,  scale, -scale,

        -scale, -scale,  scale,
        -scale, -scale, -scale,
        -scale,  scale, -scale,
        -scale,  scale, -scale,
        -scale,  scale,  scale,
        -scale, -scale,  scale,

         scale, -scale, -scale,
         scale, -scale,  scale,
         scale,  scale,  scale,
         scale,  scale,  scale,
         scale,  scale, -scale,
         scale, -scale, -scale,

        -scale, -scale,  scale,
        -scale,  scale,  scale,
         scale,  scale,  scale,
         scale,  scale,  scale,
         scale, -scale,  scale,
        -scale, -scale,  scale,

        -scale,  scale, -scale,
         scale,  scale, -scale,
         scale,  scale,  scale,
         scale,  scale,  scale,
        -scale,  scale,  scale,
        -scale,  scale, -scale,

        -scale, -scale, -scale,
        -scale, -scale,  scale,
         scale, -scale, -scale,
         scale, -scale, -scale,
        -scale, -scale,  scale,
         scale, -scale,  scale
    };

    glBindVertexArray(m_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindVertexArray(0);
}


void Skybox::CheckShaderCompileErrors(GLuint shader, const std::string& type) {
    GLint success;
    GLchar infoLog[1024];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 1024, NULL, infoLog);
        std::cerr << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
    }
}

void Skybox::CheckShaderLinkingErrors(GLuint program) {
    GLint success;
    GLchar infoLog[1024];
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 1024, NULL, infoLog);
        std::cerr << "ERROR::PROGRAM_LINKING_ERROR\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
    }
}

