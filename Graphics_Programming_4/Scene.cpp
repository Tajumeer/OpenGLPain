#include <glm/glm.hpp>
#include <string>
#include "Scene.h"
#include "ErrorType.h"
#include  "GameObject.h"
#include "Time.h" 

const int CScene::Initialize(void)
{
	if (m_pSkybox == nullptr) m_pSkybox = new Skybox(
		{ "Resource Files/Textures/skybox/px.png",
		  "Resource Files/Textures/skybox/nx.png",
		  "Resource Files/Textures/skybox/py.png",
		  "Resource Files/Textures/skybox/ny.png",
		  "Resource Files/Textures/skybox/pz.png",
		  "Resource Files/Textures/skybox/nz.png" 
		});

	if (m_pSunTextureShader == nullptr) m_pSunTextureShader = new CShader(m_pData, "Resource Files/Shader/AmbientVertex.glsl", "Resource Files/Shader/AmbientFragment.glsl");
	if (m_pEarthTextureShader == nullptr) m_pEarthTextureShader = new CShader(m_pData, "Resource Files/Shader/AmbientVertex.glsl", "Resource Files/Shader/AmbientFragment.glsl");
	if (m_pJupiterTextureShader == nullptr) m_pJupiterTextureShader = new CShader(m_pData, "Resource Files/Shader/AmbientVertex.glsl", "Resource Files/Shader/AmbientFragment.glsl");
	if (m_pMarsTextureShader == nullptr) m_pMarsTextureShader = new CShader(m_pData, "Resource Files/Shader/AmbientVertex.glsl", "Resource Files/Shader/AmbientFragment.glsl");
	if (m_pMercuryTextureShader == nullptr) m_pMercuryTextureShader = new CShader(m_pData, "Resource Files/Shader/AmbientVertex.glsl", "Resource Files/Shader/AmbientFragment.glsl");
	if (m_pNeptuneTextureShader == nullptr) m_pNeptuneTextureShader = new CShader(m_pData, "Resource Files/Shader/AmbientVertex.glsl", "Resource Files/Shader/AmbientFragment.glsl");
	if (m_pSaturnTextureShader == nullptr) m_pSaturnTextureShader = new CShader(m_pData, "Resource Files/Shader/AmbientVertex.glsl", "Resource Files/Shader/AmbientFragment.glsl");
	if (m_pUranusTextureShader == nullptr) m_pUranusTextureShader = new CShader(m_pData, "Resource Files/Shader/AmbientVertex.glsl", "Resource Files/Shader/AmbientFragment.glsl");
	if (m_pVenusTextureShader == nullptr) m_pVenusTextureShader = new CShader(m_pData, "Resource Files/Shader/AmbientVertex.glsl", "Resource Files/Shader/AmbientFragment.glsl");

	Texture* sunTexture = new Texture("Resource Files/Textures/2k_sun.jpg", 0);
	Texture* earthTexture = new Texture("Resource Files/Textures/2k_earth.jpg", 0);
	Texture* jupiterTexture = new Texture("Resource Files/Textures/2k_jupiter.jpg", 0);
	Texture* marsTexture = new Texture("Resource Files/Textures/2k_mars.jpg", 0);
	Texture* mercuryTexture = new Texture("Resource Files/Textures/2k_mercury.jpg", 0);
	Texture* neptuneTexture = new Texture("Resource Files/Textures/2k_neptune.jpg", 0);
	Texture* saturnTexture = new Texture("Resource Files/Textures/2k_saturn.jpg", 0);
	Texture* uranusTexture = new Texture("Resource Files/Textures/2k_uranus.jpg", 0);
	Texture* venusTexture = new Texture("Resource Files/Textures/2k_venus.jpg", 0);

	m_pSunTextureShader->SetTexture(sunTexture);
	m_pEarthTextureShader->SetTexture(earthTexture);
	m_pJupiterTextureShader->SetTexture(jupiterTexture);
	m_pMarsTextureShader->SetTexture(marsTexture);
	m_pMercuryTextureShader->SetTexture(mercuryTexture);
	m_pNeptuneTextureShader->SetTexture(neptuneTexture);
	m_pSaturnTextureShader->SetTexture(saturnTexture);
	m_pUranusTextureShader->SetTexture(uranusTexture);
	m_pVenusTextureShader->SetTexture(venusTexture);

	
	CCubeMesh m_pCubeMesh = CCubeMesh();
	if (m_pMesh == nullptr) m_pMesh = new CMesh(m_pCubeMesh.m_Vertices, m_pCubeMesh.m_Indicies);


	CGameObject* sun = new CGameObject(m_pMesh, m_pSunTextureShader, this);
	CGameObject* earth = new CGameObject(m_pMesh, m_pEarthTextureShader, this);
	CGameObject* jupiter = new CGameObject(m_pMesh, m_pJupiterTextureShader, this);
	CGameObject* mars = new CGameObject(m_pMesh, m_pMarsTextureShader, this);
	CGameObject* mercury = new CGameObject(m_pMesh, m_pMercuryTextureShader, this);
	CGameObject* neptune = new CGameObject(m_pMesh, m_pNeptuneTextureShader, this);
	CGameObject* saturn = new CGameObject(m_pMesh, m_pSaturnTextureShader, this);
	CGameObject* uranus = new CGameObject(m_pMesh, m_pUranusTextureShader, this);
	CGameObject* venus = new CGameObject(m_pMesh, m_pVenusTextureShader, this);



	m_GameObjects.push_back(sun);
	m_GameObjects.push_back(earth);
	m_GameObjects.push_back(jupiter);
	m_GameObjects.push_back(mars);
	m_GameObjects.push_back(mercury);
	m_GameObjects.push_back(neptune);
	m_GameObjects.push_back(saturn);
	m_GameObjects.push_back(uranus);
	m_GameObjects.push_back(venus);

	for (CGameObject* go : m_GameObjects)
	{
		go->Initialize();
	}

	sun->GetTransform()->Rotate(glm::vec3(glm::radians(2.5f), glm::radians(2.5f), 0.0f));

	earth->GetTransform()->m_position = glm::vec3(1.0f, .0f, 1.0f);
	earth->GetTransform()->m_scale *= 0.09f;
	earth->GetTransform()->Rotate(glm::vec3(glm::radians(10000.0f), glm::radians(-10000.0f), glm::radians(10000.0f)));

	jupiter->GetTransform()->m_position = glm::vec3(-4.0f, 0.0f, 0.0f);
	jupiter->GetTransform()->m_scale *= 1.03f;
	jupiter->GetTransform()->Rotate(glm::vec3(glm::radians(10000.0f), glm::radians(10000.0f), glm::radians(10000.0f)));

	mars->GetTransform()->m_position = glm::vec3(-2.0f, 0.0f, -2.0f);
	mars->GetTransform()->m_scale *= 0.05f;
	mars->GetTransform()->Rotate(glm::vec3(glm::radians(-10000.0f), glm::radians(-10000.0f), glm::radians(-10000.0f)));

	mercury->GetTransform()->m_position = glm::vec3(2.0f, 0.0f, 0.0f);
	mercury->GetTransform()->m_scale *= 0.35f;
	mercury->GetTransform()->Rotate(glm::vec3(glm::radians(10000.0f), glm::radians(-10000.0f), glm::radians(-10000.0f)));

	neptune->GetTransform()->m_position = glm::vec3(2.0f, 0.0f, -2.0f);
	neptune->GetTransform()->m_scale *= 0.35f;
	neptune->GetTransform()->Rotate(glm::vec3(glm::radians(-10000.0f), glm::radians(10000.0f), glm::radians(10000.0f)));

	saturn->GetTransform()->m_position = glm::vec3(-4.0f, 0.0f, -3.25f);
	saturn->GetTransform()->m_scale *= 0.87f;
	saturn->GetTransform()->Rotate(glm::vec3(glm::radians(10000.0f), glm::radians(-10000.0f), glm::radians(-10000.0f)));

	uranus->GetTransform()->m_position = glm::vec3(0.0f, 0.0f, 4.0f);
	uranus->GetTransform()->m_scale *= 0.37f;
	uranus->GetTransform()->Rotate(glm::vec3(glm::radians(-10000.0f), glm::radians(-10000.0f), glm::radians(10000.0f)));

	venus->GetTransform()->m_position = glm::vec3(-2.0f, 0.0f, 2.0f);
	venus->GetTransform()->m_scale *= 0.09f;
	venus->GetTransform()->Rotate(glm::vec3(glm::radians(-10000.0f), glm::radians(-0000.0f), glm::radians(-10000.0f)));



	return M_I_SUCCESS;
}

void CScene::Finalize(void)
{
}

const int CScene::Update(void)
{

	for (CGameObject* go : m_GameObjects)
	{
		go->Update();
	}
	return 0;


}

const int CScene::Draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m_pCamera->Update();

	m_pSkybox->Draw(m_pCamera->GetViewMAT(), m_pCamera->GetProjectionMAT());


	m_pSunTextureShader->SetAmbientStrength(1.0f);
	m_pSunTextureShader->SetLightColor(glm::vec3(1.0f, 1.0f, 1.0f));

	m_pEarthTextureShader->SetAmbientStrength(0.3f);
	m_pEarthTextureShader->SetLightColor(glm::vec3(.2f, .2f, .2f));

	m_pJupiterTextureShader->SetAmbientStrength(0.3f);
	m_pJupiterTextureShader->SetLightColor(glm::vec3(1.0f, 1.0f, 1.0f));

	m_pMarsTextureShader->SetAmbientStrength(0.3f);
	m_pMarsTextureShader->SetLightColor(glm::vec3(.2f, .2f, .2f));

	m_pMercuryTextureShader->SetAmbientStrength(0.3f);
	m_pMercuryTextureShader->SetLightColor(glm::vec3(.6f, .6f, .6f));

	m_pNeptuneTextureShader->SetAmbientStrength(0.3f);
	m_pNeptuneTextureShader->SetLightColor(glm::vec3(.6f, .6f, .6f));

	m_pSaturnTextureShader->SetAmbientStrength(0.3f);
	m_pSaturnTextureShader->SetLightColor(glm::vec3(.8f, .8f, .8f));

	m_pUranusTextureShader->SetAmbientStrength(0.3f);
	m_pUranusTextureShader->SetLightColor(glm::vec3(.5f, .5f, .5f));

	m_pVenusTextureShader->SetAmbientStrength(1.0f);
	m_pVenusTextureShader->SetLightColor(glm::vec3(.2f, .2f, .2f));

	for (CGameObject* go : m_GameObjects)
	{
		go->Draw();
}
	return 0;
}

void CScene::AddGameObject(CGameObject* _object)
{
	if (_object == nullptr) return;
	m_GameObjects.push_back(_object);
}

void CScene::RemoveGameObject(CGameObject* _object)
{
	if (_object == nullptr) return;
	for (int i = 0; i < m_GameObjects.size(); i++)
	{
		if (m_GameObjects[i] == _object)
		{
			m_GameObjects.erase(m_GameObjects.begin() + i);
			break;
		}
	}
}

CGameObject* CScene::GetGameObject(const int& _index)
{
	return nullptr;
}
