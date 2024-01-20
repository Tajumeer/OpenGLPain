#pragma once
#include <vector>
#include "Variables.h"

class CMeshData
{
public:
	std::vector<Vertex> m_Vertices{};
	std::vector<unsigned int> m_Indicies{};
};

