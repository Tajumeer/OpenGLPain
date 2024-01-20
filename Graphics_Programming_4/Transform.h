#pragma once
#include <glm/glm.hpp>
#include "Component.h"

class CTransform : public IComponent
{
public:

	glm::vec3 m_position{};
	glm::vec3 m_rotation{};
	glm::vec3 m_scale{ 1.0f, 1.0f, 1.0f };
	glm::vec3 m_deltaRotation{ 0.0f };
	glm::vec3 m_deltaTranslation{ 0.0f };

	glm::mat4x4 m_transformMatrix{};
	glm::mat4x4 m_positionMatrix{};
	glm::mat4x4 m_rotationMatrix{};
	glm::mat4x4 m_scaleMatrix{};

	float m_totalTime;

	const int Initialize(void) override;
	void Finalize(void) override;
	const int Update(CGameObject&) override;
	const int Draw(CGameObject&) override;

	void Move(const glm::vec3& _deltaPosition);
	void Rotate(const glm::vec3& _deltaRotation);

	void UpdateTransformMatrix();
};

