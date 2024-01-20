#ifndef MATERIAL_H
#define MATERIAL_H

#include<glm/glm.hpp>
#include<stb/stb_image.h>
#include"Variables.h"

class CMaterial
{
public:
	glm::vec3 m_vAmbient{};
	glm::vec3 m_vDiffuse{};
	glm::vec3 m_vSpecular{};

	float m_Roughness{};
};

#endif





