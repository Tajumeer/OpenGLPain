#ifndef I_COMPONENT_H
#define I_COMPONENT_H

#pragma once

class CGameObject;
class IComponent
{
public:
	virtual const int Initialize(void) = 0;
	virtual void Finalize(void) = 0;
	virtual const int Update(CGameObject&) = 0;
	virtual const int Draw(CGameObject&) = 0;
};
#endif // I_COMPONENT_H
