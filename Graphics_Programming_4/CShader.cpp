#include "CShader.h"
#include <stb/stb_image.h>
#include <filesystem>
int CShader::GetShaderID()
{
	return m_iShaderID;
}

int CShader::GetShaderProgramm()
{
	return *m_pShaderProgram;
}

void CShader::SendMAT4ToShader(const std::string& _sName, const glm::mat4& _mat)
{
	glUniformMatrix4fv(glGetUniformLocation(GetShaderProgramm(), _sName.c_str()), 1, GL_FALSE, glm::value_ptr(_mat));
}

void CShader::SendFloatToShader(const std::string& _sName, const float& _float)
{
	glUniform1f(glGetUniformLocation(GetShaderProgramm(), _sName.c_str()), _float);
}

int CShader::SetTexture(Texture* _texture)
{
    m_pTexture = _texture;

    int iWidth = 0, iHeight = 0, iChannelNumb = 0;
    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &m_pTexture->iTextureID);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_pTexture->iTextureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_set_flip_vertically_on_load(false);

    unsigned char* pData = stbi_load(m_pTexture->sTexturePath.c_str(), &iWidth, &iHeight, &iChannelNumb, 0);
    if (pData)
    {
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, iWidth, iHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, pData);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "ERROR: Failed Texture loading" << std::endl;
        return static_cast<int>(ErrorType::ET_FAILED_LOAD_TEXTURE);

    }
    stbi_image_free(pData);

    return static_cast<int>(ErrorType::ET_SUCCESS);
    return 0;
}

void CShader::SetLightPosition(const glm::vec3& _position)
{
    glUseProgram(*m_pShaderProgram);
    SendVEC3ToShader("lightPosition", _position);
    glUseProgram(0);
}

void CShader::SetLightColor(const glm::vec3& _color)
{
    glUseProgram(*m_pShaderProgram);
    SendVEC3ToShader("lightColor", _color);
    glUseProgram(0);
}

void CShader::SetObjectColor(const glm::vec3& _color)
{
    glUseProgram(*m_pShaderProgram);
    SendVEC3ToShader("objectColor", _color);
    glUseProgram(0);
}

void CShader::SetAmbientStrength(float _ambientStrength)
{
    glUseProgram(*m_pShaderProgram);
    SendFloatToShader("ambientStrength", _ambientStrength);
    glUseProgram(0);
}


void CShader::SendVEC3ToShader(const std::string& _sName, const glm::vec3& _vec)
{
	glUniform3fv(glGetUniformLocation(*m_pShaderProgram, _sName.c_str()), 1, glm::value_ptr(_vec));
}

int CShader::Initialize(void)
{
    const char* szVertexShader = m_sVertexShader.c_str();
    const char* szFragmentShader = m_sFragmentShader.c_str();

    // Vertex Shader
    unsigned int iVertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(iVertexShader, 1, &szVertexShader, nullptr);
    glCompileShader(iVertexShader);

    int iSuccess = 0;
    char sInfoLog[512];

    glGetShaderiv(iVertexShader, GL_COMPILE_STATUS, &iSuccess);

    if (!iSuccess)
    {
        glGetShaderInfoLog(iVertexShader, 512, nullptr, sInfoLog);
        std::cout << "Error: Vertex-Shader Compilation failed!" << std::endl;
        return static_cast<int>(ErrorType::ET_VERTEX_SHADER_COMPILATION_FAILED);
    }

    // Fragment Shader
    unsigned int iFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(iFragmentShader, 1, &szFragmentShader, nullptr);
    glCompileShader(iFragmentShader);
    glGetShaderiv(iFragmentShader, GL_COMPILE_STATUS, &iSuccess);

    if (!iSuccess)
    {
        glGetShaderInfoLog(iFragmentShader, 512, nullptr, sInfoLog);
        std::cout << "Error: Fragment-Shader Compilation failed!" << std::endl;
        return static_cast<int>(ErrorType::ET_FRAG_SHADER_COMPILATION_FAILED);
    }

    // Link Shaders

    *m_pShaderProgram = glCreateProgram();
    glAttachShader(*m_pShaderProgram, iVertexShader);
    glAttachShader(*m_pShaderProgram, iFragmentShader);
    glLinkProgram(*m_pShaderProgram);
    glGetProgramiv(*m_pShaderProgram, GL_LINK_STATUS, &iSuccess);

    if (!iSuccess)
    {
        glGetProgramInfoLog(*m_pShaderProgram, 512, nullptr, sInfoLog);
        std::cout << "Error: Shader Program Link failed!" << std::endl;
        return static_cast<int>(ErrorType::ET_SHADER_PROG_LINK_FAILED);
    }

    // Get the locations of the uniform variables
    GLint lightPosLoc = glGetUniformLocation(*m_pShaderProgram, "lightPosition");
    GLint lightColorLoc = glGetUniformLocation(*m_pShaderProgram, "lightColor");
    GLint objectColorLoc = glGetUniformLocation(*m_pShaderProgram, "objectColor");

    // Set initial values for the uniform variables
    glUseProgram(*m_pShaderProgram);
    glUniform3f(lightPosLoc, 0.0f, 0.0f, .0f);  
    glUniform3f(lightColorLoc, 0.5f, .5f, .5f);  
    glUniform3f(objectColorLoc, 1.0f, 1.0f, 1.0f);  
    glUseProgram(0);

    glDeleteShader(iVertexShader);
    glDeleteShader(iFragmentShader);
    return 0;
}

int CShader::Draw()
{
    glUseProgram(*m_pShaderProgram);
    glBindTexture(GL_TEXTURE_2D, m_pTexture->iTextureID);
    return 0;
}






