#include <iostream>
#include "Viewport.h"


std::function<void(void)> m_pInputW = nullptr;
std::function<void(void)> m_pInputA = nullptr;
std::function<void(void)> m_pInputS = nullptr;
std::function<void(void)> m_pInputD = nullptr;
std::function<void(void)> m_pInputQ = nullptr;
std::function<void(void)> m_pInputE = nullptr;

const int I_OFFSET_X = 0;
const int I_OFFSET_Y = 0;

// Functions
void HandleFramebufferSize(GLFWwindow* a_pWindow, int a_iWidth, int a_iHeight)
{
	glViewport(I_OFFSET_X, I_OFFSET_Y, a_iWidth, a_iHeight);
}


// Methods
void ProcessInput(GLFWwindow* a_pWindow)
{
	if (glfwGetKey(a_pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(a_pWindow, true);
	}

	if (glfwGetKey(a_pWindow, GLFW_KEY_W) == GLFW_PRESS)
	{
		if (m_pInputW != nullptr) m_pInputW();
	}

	if (glfwGetKey(a_pWindow, GLFW_KEY_A) == GLFW_PRESS)
	{
		if (m_pInputA != nullptr) m_pInputA();
	}

	if (glfwGetKey(a_pWindow, GLFW_KEY_S) == GLFW_PRESS)
	{
		if (m_pInputS != nullptr) m_pInputS();
	}

	if (glfwGetKey(a_pWindow, GLFW_KEY_D) == GLFW_PRESS)
	{
		if (m_pInputD != nullptr) m_pInputD();
	}
	if (glfwGetKey(a_pWindow, GLFW_KEY_Q) == GLFW_PRESS)
	{
		if (m_pInputQ != nullptr) m_pInputQ();
	}
	if (glfwGetKey(a_pWindow, GLFW_KEY_E) == GLFW_PRESS)
	{
		if (m_pInputE != nullptr) m_pInputE();
	}
}

void CViewport::SetWInput(std::function<void(void)> a_pInputW)
{
	m_pInputW = a_pInputW;
}

void CViewport::SetAInput(std::function<void(void)> a_pInputA)
{
	m_pInputA = a_pInputA;
}

void CViewport::SetSInput(std::function<void(void)> a_pInputS)
{
	m_pInputS = a_pInputS;
}

void CViewport::SetDInput(std::function<void(void)> a_pInputD)
{
	m_pInputD = a_pInputD;
}

void CViewport::SetQInput(std::function<void(void)> a_pInputQ)
{
	m_pInputQ = a_pInputQ;
}

void CViewport::SetEInput(std::function<void(void)> a_pInputE)
{
	m_pInputE = a_pInputE;
}

const int CViewport::Initialize(void)
{
	// Config
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, m_iGlfwVersionMajor);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, m_iGlfwVersionMinor);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Window
	m_pWindow = glfwCreateWindow(m_iWidth, m_iHeight, m_sTitle.c_str(), nullptr, nullptr);

	if (m_pWindow == nullptr)
	{
		m_error = ErrorType::ET_WINDOW_CREATION_FAILED;
		std::cout << "ERROR: GLFW Window Creation failed!" << std::endl;
		glfwTerminate();
		return static_cast<int>(m_error);
	}
	glfwMakeContextCurrent(m_pWindow);
	glfwSetFramebufferSizeCallback(m_pWindow, HandleFramebufferSize);

	// GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		m_error = ErrorType::ET_GLAD_INITIALISATION_FAILED;
		std::cout << "ERROR: GLAD Initialisation failed" << std::endl;
		return static_cast<int>(m_error);
	}

	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

    return static_cast<int>(m_error);
}

void CViewport::Finalize(void)
{
	glfwTerminate();
}

const int CViewport::Update(void)
{
	ProcessInput(m_pWindow);
    return static_cast<int>(m_error);
}

const int CViewport::Draw(void)
{
	glClearColor(m_fRed, m_fGreen, m_fBlue, m_fAlpha);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    return static_cast<int>(m_error);
}

const int CViewport::LateDraw(void)
{
	glfwSwapBuffers(m_pWindow);
	glfwPollEvents();
	return static_cast<int>(m_error);
}
