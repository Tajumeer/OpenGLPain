#include "Camera.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/euler_angles.hpp>

glm::mat4 CCamera::GetViewMAT()
{
    glm::mat4 rotationMatrix = glm::yawPitchRoll(m_rotation.y, m_rotation.x, m_rotation.z);
    glm::vec3 newOrientation = glm::vec3(rotationMatrix * glm::vec4(m_orientation, 0.0f));
    glm::vec3 target = m_position + newOrientation;

    return glm::lookAt(m_position, target, m_up);
}

glm::mat4 CCamera::GetProjectionMAT()
{
    return glm::perspective(glm::radians(m_data.fFOVDegree), static_cast<float>(m_iWidth/m_iHeight), m_data.fNearPlane, m_data.fFarPlane);
}

glm::mat4 CCamera::GetCameraMAT()
{
    glm::mat4x4 view = GetViewMAT();
    glm::mat4x4 projection = GetProjectionMAT();
    return projection * view;
}

const int CCamera::Initialize(void)
{
    return 0;
}

void CCamera::Finalize(void)
{
}

const int CCamera::Update(void)
{
    return 0;
}

const int CCamera::Draw(void)
{
    return 0;
}
