#include<glad/glad.h>
#include<glm/gtx/euler_angles.hpp>
#include<glm/gtx/transform.hpp>
#include "Transform.h"
#include "GameObject.h"
#include "Time.h"
const int CTransform::Initialize(void)
{
	return 0;
}

void CTransform::Finalize(void)
{

}

void CTransform::Move(const glm::vec3& _deltaPosition)
{
	m_deltaTranslation += _deltaPosition;
}

void CTransform::Rotate(const glm::vec3& _deltaRotation)
{
	m_deltaRotation += _deltaRotation;
}

void CTransform::UpdateTransformMatrix()
{
	m_positionMatrix = glm::translate(m_position);
	m_rotationMatrix = glm::yawPitchRoll(m_rotation.y, m_rotation.x, m_rotation.z);
	m_scaleMatrix = glm::scale(m_scale);
	m_transformMatrix = m_positionMatrix * m_rotationMatrix * m_scaleMatrix;
}

const int CTransform::Update(CGameObject&)
{
	CTime::GetInstance()->Update();
	m_rotation += m_deltaRotation * CTime::GetInstance()->GetDeltaTime();
	m_position += m_deltaTranslation * CTime::GetInstance()->GetDeltaTime();

	UpdateTransformMatrix();

	return 0;
}

const int CTransform::Draw(CGameObject&)
{
	return 0;
}

