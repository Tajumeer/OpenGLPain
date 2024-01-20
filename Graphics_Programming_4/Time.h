#pragma once
#ifndef TIME_H
#define TIME_H

class CTime
{
public:
	static CTime* GetInstance()
	{
		if (!s_instance)
		{
			s_instance = new CTime();
		}
		return s_instance;
	}

	void Update();

	inline float GetDeltaTime() const
	{
		return m_deltaTime;
	}
	CTime();
private:
	float m_deltaTime;
	float m_lastFrame;
	float m_currentFrame;

	static CTime* s_instance;
};

#endif // TIME_H