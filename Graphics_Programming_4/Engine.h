#ifndef ENGINE_H
#define ENGINE_H
#include "Scene.h"
#include "Viewport.h"
#include "Camera.h"
#include "Material.h"
#include "Mesh.h"
#include "Defines.h"
#include "DataManager.h"
#include "CCubeMesh.h"
#include "Time.h"


class CEngine
{
public:
	CEngine(CDataManager* _pData)
		: m_pData(_pData) {}

	int Initialize(void);
	int Run(void);
	void Finalize(void);

private:
	// Konstanten
	const int M_I_GLFW_VERSION_MAJOR = 3;
	const int M_I_GLFW_VERSION_MINOR = 3;
	const int M_I_WIDTH = 800;
	const int M_I_HEIGHT = 600;
	const std::string M_S_TITLE = "SAE_PAIN_Engine";
	const int M_I_OFFSET_X = 0;
	const int M_I_OFFSET_Y = 0;
	const float M_F_RED = 0.1f;
	const float M_F_GREEN = 0.1f;
	const float M_F_BLUE = 0.1f;
	const float M_F_ALPHA = 1.0f;
	const int M_I_SUCCESS = 0;

	CDataManager* m_pData = nullptr;
	CScene* m_scene = nullptr;
	CCamera* m_pCamera = nullptr;
	CViewport* m_pViewport = nullptr;
	CTime* m_pTime = nullptr;
};


#endif // !ENGINE_H