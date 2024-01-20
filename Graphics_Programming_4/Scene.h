#pragma once
#include <vector>
#include "Object.h"
#include "Viewport.h"
#include "Camera.h"
#include "Material.h"
#include "Mesh.h"
#include "Defines.h"
#include "DataManager.h"
#include "CCubeMesh.h"
#include "CShader.h"
#include "Skybox.h"

class CGameObject;

class CScene : public IObject
{
public:
	virtual const int Initialize(void);
	virtual void Finalize(void);
	virtual const int Update(void);
	virtual const int Draw(void);

	inline CScene(CDataManager* _data, CCamera* _camera) : m_pData(_data), m_pCamera(_camera) {}
	
	inline CCamera* GetCamera() { return m_pCamera; }
	void AddGameObject(CGameObject* _object);
	// void AddGameObject(CGameObject* _object, Material, Mesh);
	void RemoveGameObject(CGameObject* _object);
	CGameObject* GetGameObject(const int& _index);
	CViewport* m_pViewport = nullptr;

private:
	const int M_I_SUCCESS = 0;

	CDataManager* m_pData = nullptr;
	CCamera* m_pCamera = nullptr;
	CMesh* m_pMesh = nullptr;
	Skybox* m_pSkybox = nullptr;
	CShader* m_pSunTextureShader = nullptr;
	CShader* m_pEarthTextureShader = nullptr;
	CShader* m_pJupiterTextureShader = nullptr;
	CShader* m_pMarsTextureShader = nullptr;
	CShader* m_pMercuryTextureShader = nullptr;
	CShader* m_pNeptuneTextureShader = nullptr;
	CShader* m_pSaturnTextureShader = nullptr;
	CShader* m_pUranusTextureShader = nullptr;
	CShader* m_pVenusTextureShader = nullptr;

protected:
	std::vector<CGameObject*> m_GameObjects{};
};

