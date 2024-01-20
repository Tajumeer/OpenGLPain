#include "Engine.h"
#include "DataManager.h"

int main(int a_iArgV, const char* a_argsC[])
{
	CDataManager* pData = new CDataManager();
	CEngine* pEngine = new CEngine(pData);

	if (pEngine != nullptr) PROVE_RESULT(pEngine->Initialize());
	if (pEngine != nullptr) PROVE_RESULT(pEngine->Run());

	FINALIZE_DELETE(pEngine);
	SAFE_DELETE(pData);

	return 0;
}