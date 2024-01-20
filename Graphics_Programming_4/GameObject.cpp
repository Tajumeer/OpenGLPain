#include "GameObject.h"

const int CGameObject::Initialize(void)
{
	m_pTransform = new CTransform;
	m_pMesh->Initialize();
	m_pShader->Initialize();

	for (IComponent* comp : m_components)
	{
		comp->Initialize();
	}
    return 0;
}

void CGameObject::Finalize(void)
{

}

const int CGameObject::Update(void)
{
	m_pTransform->Update(*this);

	if (m_pMesh != nullptr) PROVE_RESULT(m_pMesh->Update());

	for (IComponent* comp : m_components)
	{
		comp->Update(*this);
	}

	return 0;
}

const int CGameObject::Draw(void)
{
	m_pTransform->Draw(*this);

	if (m_pShader != nullptr) PROVE_RESULT(m_pShader->Draw());

	m_pShader->SendMAT4ToShader("camMatrix", m_pScene->GetCamera()->GetCameraMAT());
	m_pShader->SendVEC3ToShader("camPosition", m_pScene->GetCamera()->GetPosition());
	m_pShader->SendMAT4ToShader("transform", m_pTransform->m_transformMatrix);

	if (m_pMesh != nullptr) PROVE_RESULT(m_pMesh->Draw());

	for (IComponent* comp : m_components)
	{
		comp->Draw(*this);
	}

	return 0;
}

void CGameObject::AddComponent(IComponent* _component)
{
    if (_component == nullptr) return;
    m_components.push_back(_component);
}

void CGameObject::DeleteComponent(IComponent* _component)
{
	if (_component == nullptr) return;
	for (int i = 0; i < m_components.size(); i++)
	{
		if (m_components[i] == _component)
		{
			m_components.erase(m_components.begin() + i);
			break;
		}
	}
}

CTransform* CGameObject::GetTransform()
{
    return m_pTransform;
}
