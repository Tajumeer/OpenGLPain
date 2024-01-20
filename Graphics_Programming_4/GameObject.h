#pragma once
#include <type_traits>
#include <vector>
#include "Object.h"
#include "Component.h"
#include "Transform.h"
#include "Mesh.h"
#include "Material.h"
#include "CShader.h"
#include "Defines.h"
#include "Scene.h"


class CGameObject : public IObject
{
public:
	CMesh* m_pMesh = nullptr;
	CShader* m_pShader = nullptr;

	inline CGameObject(CScene* _pScene) : m_pScene(_pScene) {};
	inline CGameObject(CMesh* _pMesh, CShader* _pShader, CScene* _pScene) : m_pMesh(_pMesh), m_pShader(_pShader), m_pScene(_pScene) {};

	const int Initialize(void) override;
	void Finalize(void) override;
	const int Update(void) override;
	const int Draw(void) override;

	void AddComponent(IComponent* _component);
	void DeleteComponent(IComponent* _component);
	CTransform* GetTransform();

	template<class T>
	T* GetComponent();

	std::vector<IComponent*> m_components{};

private:
	CTransform* m_pTransform{};
	CScene* m_pScene{};
};

template<class T> 
inline T* CGameObject::GetComponent()
{
	// checks if T* is an CComponent --> if not returns string and breaks out of function
	static_assert(std::is_base_of<IComponent, T*>, "No Component");	

	// go through all CComponents in the list
	for (IComponent* component:m_components)
	{
		// cast the Component --> if its the wanted Component return it
		auto tmp = dynamic_cast<T*>(component);
		if (tmp != nullptr)
			return tmp;
	}
	return nullptr;	// if the Component does not exist, return nullptr
}