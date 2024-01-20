#include <iostream>
#include "Engine.h"

// current Scene -> LoadScene();
int CEngine::Initialize(void)
{
	m_pTime = new CTime();
	if (m_pViewport == nullptr) m_pViewport = new CViewport(M_I_GLFW_VERSION_MAJOR, M_I_GLFW_VERSION_MINOR,
		M_I_WIDTH, M_I_HEIGHT, M_S_TITLE, M_F_RED, M_F_GREEN, M_F_BLUE, M_F_ALPHA);

	if (m_pCamera == nullptr) m_pCamera = new CCamera(M_I_WIDTH, M_I_HEIGHT, glm::vec3(0.0f, 0.0f, 2.0f), glm::vec3(0.0f, 0.0f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f));
	m_pCamera->SetData(CameraData{ 30.0f, 0.1f, 1000.0f });
	m_pCamera->Initialize();

	if (m_pViewport != nullptr && m_pCamera != nullptr)
	{
		// Move forward in camera's local space
		m_pViewport->SetWInput([&](void) {
			glm::vec3 forward = glm::normalize(glm::vec3(m_pCamera->GetViewMAT()[0][2], m_pCamera->GetViewMAT()[1][2], m_pCamera->GetViewMAT()[2][2]));
			m_pCamera->TranslatePosition(-forward * m_pTime->GetDeltaTime());
			});

		// Move backward in camera's local space
		m_pViewport->SetSInput([&](void) {
			glm::vec3 forward = glm::normalize(glm::vec3(m_pCamera->GetViewMAT()[0][2], m_pCamera->GetViewMAT()[1][2], m_pCamera->GetViewMAT()[2][2]));
			m_pCamera->TranslatePosition(forward * m_pTime->GetDeltaTime());
			});

		// Move left in camera's local space
		m_pViewport->SetAInput([&](void) {
			glm::vec3 right = glm::normalize(glm::vec3(m_pCamera->GetViewMAT()[0][0], m_pCamera->GetViewMAT()[1][0], m_pCamera->GetViewMAT()[2][0]));
			m_pCamera->TranslatePosition(-right * m_pTime->GetDeltaTime());
			});

		// Move right in camera's local space
		m_pViewport->SetDInput([&](void) {
			glm::vec3 right = glm::normalize(glm::vec3(m_pCamera->GetViewMAT()[0][0], m_pCamera->GetViewMAT()[1][0], m_pCamera->GetViewMAT()[2][0]));
			m_pCamera->TranslatePosition(right * m_pTime->GetDeltaTime());
			});

		// Rotate left
		m_pViewport->SetQInput([&](void) {
			m_pCamera->Rotate(glm::vec3(0.0f, glm::radians(90.0f), 0.0f) * m_pTime->GetDeltaTime());
			});

		// Rotate right
		m_pViewport->SetEInput([&](void) {
			m_pCamera->Rotate(glm::vec3(0.0f, -glm::radians(90.0f), 0.0f) * m_pTime->GetDeltaTime());
			});

	}

	if (m_pViewport != nullptr) PROVE_RESULT(m_pViewport->Initialize());

	m_scene = new CScene(m_pData, m_pCamera);
	m_scene->Initialize();

	return M_I_SUCCESS;
}

int CEngine::Run(void)
{
	while (!glfwWindowShouldClose(m_pViewport->GetWindow()))
	{
		m_pTime->Update();
		if (m_pViewport != nullptr) PROVE_RESULT(m_pViewport->Update());

		if (m_pViewport != nullptr) PROVE_RESULT(m_pViewport->Draw());

		m_scene->Update();
		m_scene->Draw();

		if (m_pViewport != nullptr) PROVE_RESULT(m_pViewport->LateDraw());
	}
	return M_I_SUCCESS;
}

void CEngine::Finalize(void)
{
	FINALIZE_DELETE(m_pViewport);
}
