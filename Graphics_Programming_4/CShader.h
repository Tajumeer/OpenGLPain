#pragma once
#include<string>
#include<glad/glad.h>
#include<glm/glm.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glfw/glfw3.h>
#include<iostream>
#include"DataManager.h"
#include "Variables.h"

class CShader
{
public:
	inline CShader(CDataManager* a_pData, const char* a_szVertexShader, const char* a_szFragmentShader)
		: m_pData(a_pData),
		m_pShaderProgram(new unsigned int), m_pTexture(nullptr)
	{

		if (m_pData == nullptr) return;
		m_sVertexShader = m_pData->ReadFile(a_szVertexShader);
		m_sFragmentShader = m_pData->ReadFile(a_szFragmentShader);

	}

	int GetShaderID();
	int GetShaderProgramm();
	
	void SendMAT4ToShader(const std::string& _sName, const glm::mat4& _mat);
	void SendVEC3ToShader(const std::string& _sName, const glm::vec3& _vec);
	void SendFloatToShader(const std::string& _sName, const float& _float);

	int SetTexture(Texture* _texture);

	void SetLightPosition(const glm::vec3& _position);
	void SetLightColor(const glm::vec3& _color);
	void SetObjectColor(const glm::vec3& _color);
	void SetAmbientStrength(float _ambientStrength);

	int Initialize();
	int Draw();

private:
	CDataManager* m_pData = nullptr;

	Texture* m_pTexture;

	std::string m_sVertexShader{};
	std::string m_sFragmentShader{};

	GLsizei m_iShaderID{ 1 };
	unsigned int* m_pShaderProgram{};
};

