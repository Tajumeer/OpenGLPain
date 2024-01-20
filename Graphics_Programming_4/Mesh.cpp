#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Mesh.h"
#include "Defines.h"

const int CMesh::Initialize(void)
{
   
    InitBuffers();
    InitVertices();

    return 0;
}

void CMesh::Finalize(void)
{
    if(m_pEBO != nullptr)glDeleteBuffers(1, m_pEBO);
    if(m_pVBO != nullptr)glDeleteBuffers(1, m_pVBO);
    if (m_pVAO != nullptr)glDeleteVertexArrays(1, m_pVAO);
}

const int CMesh::Update(void)
{
    return 0;
}

const int CMesh::Draw(void)
{
    glBindVertexArray(*m_pVAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *m_pEBO);

    glDrawArrays(GL_TRIANGLES, M_I_POSITION_IDX, M_I_ARRAY_SIZE);
    glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, (void*)M_I_EMPTY);
    return 0;
}

void CMesh::InitVertices()
{
    // Vertex-Liste erstellen
                                   // Mem-Größe   *   Anzahl
    glBufferData(GL_ARRAY_BUFFER, (sizeof(Vertex) * m_vertices.size()), &m_vertices[0], GL_STATIC_DRAW);

    // Index-Liste
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, (sizeof(unsigned int) * m_indices.size()), &m_indices.front(), GL_STATIC_DRAW);

    // Iterierkopf für Vertex-Position
    glVertexAttribPointer(M_I_POSITION_IDX, GetPositionNum(), GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(M_I_EMPTY));
    glEnableVertexAttribArray(M_I_POSITION_IDX);

    //// Iterierkopf für Farbwerte
    //auto i = GetPositionSize();
    glVertexAttribPointer(M_I_COLOR_IDX, GetColorNum(), GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(M_I_EMPTY + GetPositionSize()));
    glEnableVertexAttribArray(M_I_COLOR_IDX);

    ////Iterierkopf für UVs
    glVertexAttribPointer(M_I_UV_IDX, GetUvNum(), GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(M_I_EMPTY + GetPositionSize() + GetColorSize()));
    glEnableVertexAttribArray(M_I_UV_IDX);

    ////Iterierkopf für Nomral
    glVertexAttribPointer(M_I_NORMAL_IDX, GetNormalNum(), GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(M_I_EMPTY + GetPositionSize() + GetColorSize() + GetUvSize()));
    glEnableVertexAttribArray(M_I_NORMAL_IDX);
}

void CMesh::InitBuffers()
{
    glGenVertexArrays(M_I_BUF_SIZE, m_pVAO);
    glBindVertexArray(*m_pVAO);

    glGenBuffers(M_I_BUF_SIZE, m_pVBO);
    glBindBuffer(GL_ARRAY_BUFFER, *m_pVBO);

    glGenBuffers(M_I_BUF_SIZE, m_pEBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *m_pEBO);
}
