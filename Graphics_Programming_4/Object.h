#ifndef OBJECT_H
#define OBJECT_H

class IObject
{
public:
	// pure virtual methods == abstract
	virtual const int Initialize(void) = 0;
	virtual void Finalize(void) = 0;
	virtual const int Update(void) = 0;
	virtual const int Draw(void) = 0;

};

#endif // !OBJECT_H

