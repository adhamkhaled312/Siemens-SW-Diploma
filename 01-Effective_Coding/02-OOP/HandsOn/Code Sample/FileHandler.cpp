#include "FileHandler.h"
#include <fstream>
#include <iterator>
#include <sys/stat.h>
#include <unistd.h>
#include <algorithm>

std::vector<std::string> FileHandler::ReadFileIntoPackets(const std::string& p_strFileName) const
{
	if (!PathExists(p_strFileName) || !PathReadable(p_strFileName))
		return { };

	std::vector<std::string> vecFileLines;
	std::ifstream oFile(p_strFileName);
	std::copy(std::istream_iterator<std::string>(oFile), std::istream_iterator<std::string>(), std::back_inserter(vecFileLines));

	return vecFileLines;
}

void FileHandler::WritePacketsIntoFile(const std::string& p_strFileName, std::vector<std::string>& p_vecPackets) const
{
	if (PathExists(p_strFileName) && !PathWriteable(p_strFileName))
		return;

	std::ofstream oFile(p_strFileName);
	std::ostream_iterator<std::string> output_iterator(oFile, "\n");
    std::copy(std::begin(p_vecPackets), std::end(p_vecPackets), output_iterator);
}

bool FileHandler::PathExists(const std::string& p_strPath) const
{	
	struct stat buffer;
	return (stat(p_strPath.c_str(), &buffer) == 0);
}

bool FileHandler::PathReadable(const std::string& p_strPath) const
{
	return (0 == access(p_strPath.c_str(), R_OK));
}

bool FileHandler::PathWriteable(const std::string& p_strPath) const
{
	return (0 == access(p_strPath.c_str(), W_OK));
}