#ifndef MESH_H
#define MESH_H

#include "Object.h"
#include "Variables.h"
#include <vector>

class CMesh : public IObject
{
public:
	CMesh(std::vector<Vertex> a_vertices, std::vector<unsigned int> a_indices)
		: m_vertices(a_vertices), m_indices(a_indices),
		m_pVBO(new unsigned int(M_I_EMPTY)), m_pEBO(new unsigned int(M_I_EMPTY)), m_pVAO(new unsigned int (M_I_EMPTY)) {}

private:

	// Bytegröße
	inline constexpr const int GetPositionSize(void) const { return sizeof(glm::vec3); }
	inline constexpr const int GetColorSize(void) const { return sizeof(glm::vec3); }
	inline constexpr const int GetUvSize(void) const { return sizeof(glm::vec2); }
	inline constexpr const int GetNormalSize(void) const { return sizeof(glm::vec3); }

	// Variabelanzahl
	inline constexpr const int GetPositionNum(void) const { return GetPositionSize() / sizeof(float); }
	inline constexpr const int GetColorNum(void) const { return GetColorSize() / sizeof(float); }
	inline constexpr const int GetUvNum(void) const { return GetUvSize() / sizeof(float); }
	inline constexpr const int GetNormalNum(void) { return GetNormalSize() / sizeof(float); }

public:
	// Inherited via IObject
	virtual const int Initialize(void) override;
	virtual void Finalize(void) override;
	virtual const int Update(void) override;
	virtual const int Draw(void) override;

	// Member-Variables
	unsigned int* m_pVBO = nullptr;
	unsigned int* m_pEBO = nullptr;
	unsigned int* m_pVAO = nullptr;

	void InitVertices();
	void InitBuffers();
private: 
	// Constants
	const int M_I_EMPTY = 0;
	const int M_I_BUF_SIZE = 1;
	const int M_I_POSITION_IDX = 0;
	const int M_I_COLOR_IDX = 1;
	const int M_I_UV_IDX = 2;
	const int M_I_NORMAL_IDX = 3;
	const int M_I_ARRAY_SIZE = 3;


	std::vector<Vertex> m_vertices = {};
	std::vector<unsigned int> m_indices = {};
};



#endif // !MESH_H