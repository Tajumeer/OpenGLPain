#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <functional>
#include "ErrorType.h"
#include "Object.h"

class CViewport : public IObject
{
public:
    inline CViewport(int a_iVersionMajor, int a_iVersionMinor, int a_iWidth, int a_iHeight, std::string a_sTitle,
                     float a_fRed, float a_fGreen, float a_fBlue, float a_fAlpha)
        : m_iGlfwVersionMajor(a_iVersionMajor), m_iGlfwVersionMinor(a_iVersionMinor),
            m_iWidth(a_iWidth), m_iHeight(a_iHeight), m_sTitle(a_sTitle),
            m_fRed(a_fRed), m_fGreen(a_fGreen), m_fBlue(a_fBlue), m_fAlpha(a_fAlpha)
    {
        
    }

  
    inline GLFWwindow* GetWindow(void) { return m_pWindow; }

    void SetWInput(std::function<void(void)> a_pInputW);
    void SetAInput(std::function<void(void)> a_pInputA);
    void SetSInput(std::function<void(void)> a_pInputS);
    void SetDInput(std::function<void(void)> a_pInputD);
    void SetQInput(std::function<void(void)> a_pInputQ);
    void SetEInput(std::function<void(void)> a_pInputE);

    // Inherited via IObject
    virtual const int Initialize(void) override;
    virtual void Finalize(void) override;
    virtual const int Update(void) override;
    virtual const int Draw(void) override;
    const int LateDraw(void);

private:
    // Member-Variables
    GLFWwindow* m_pWindow = nullptr;
    ErrorType m_error = ErrorType::ET_SUCCESS;

    int m_iGlfwVersionMajor = 0;
    int m_iGlfwVersionMinor = 0;
    int m_iWidth = 0;
    int m_iHeight = 0;
    std::string m_sTitle = "Unicorn Engine";
    int m_iOffsetX = 0;
    int m_iOffsetY = 0;
    float m_fRed = 0.0f;
    float m_fGreen = 0.0f;
    float m_fBlue = 0.0f;
    float m_fAlpha = 0.0f;
};


#endif // !VIEWPORT_H

