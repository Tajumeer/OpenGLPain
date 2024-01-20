#include "Time.h"
#include <GLFW/glfw3.h>

CTime* CTime::s_instance = nullptr;

CTime::CTime() 
{
	m_lastFrame = glfwGetTime();
}

void CTime::Update()
{
	m_currentFrame = glfwGetTime();
	m_deltaTime = m_currentFrame - m_lastFrame;
	m_lastFrame = m_currentFrame;
}