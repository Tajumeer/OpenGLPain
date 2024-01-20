#ifndef VARIABLES_H
#define VARIABLES_H

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <string>


struct Vertex
{
	glm::vec3 position;
	glm::vec3 color;
	glm::vec2 texCoord;
	glm::vec3 normal;
};

struct CameraData
{
	float fFOVDegree{};
	float fNearPlane{};
	float fFarPlane{};
};

struct Texture
{
	inline Texture(std::string _texturePath, unsigned int _textureID) : sTexturePath(_texturePath), iTextureID(_textureID) {}

	std::string sTexturePath;
	unsigned int iTextureID;
};

#endif // !VARIABLES_H

