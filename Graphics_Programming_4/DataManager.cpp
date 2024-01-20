#include "DataManager.h"
#include <fstream>
#include <iostream>

std::string CDataManager::ReadFile(const char* a_sFilePath)
{
    std::fstream stream = std::fstream();
    stream.open(a_sFilePath, std::ios::in);

    if (!stream.is_open())
    {
        m_error = ErrorType::ET_FILE_READ_FAILED;
        std::cout << "Error: The file " << a_sFilePath << "could not be readed!" << std::endl;
        return "";
    }

    std::string sContent = "";
    std::string sLine = "";

    while (!stream.eof())
    {
        std::getline(stream, sLine);
        sContent.append(sLine + "\n");
    }

    stream.close();

    if (stream.is_open())
    {
        m_error = ErrorType::ET_STREAM_STILL_OPEN;
        std::cout << "Error: The Filestream is still open!" << std::endl;
        return "";
    }

    return sContent;
}
