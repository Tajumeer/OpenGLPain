#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include <string>
#include "ErrorType.h"

class CDataManager
{
public:
	std::string ReadFile(const char* a_sFilePath);
	
	inline const ErrorType GetError(void) const { return m_error; }

private:
	ErrorType m_error = ErrorType::ET_SUCCESS;
};




#endif // !DATA_MANAGER_H