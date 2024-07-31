#pragma once

#include <string>
#include <vector>

class FileHandler
{
public:
	explicit FileHandler() =  default;
	~FileHandler() =  default;
	std::vector<std::string> ReadFileIntoPackets(const std::string& p_strFileName) const;
	void WritePacketsIntoFile(const std::string& p_strFileName, std::vector<std::string>& p_vecPackets) const;

protected:
	bool PathExists(const std::string& p_strPath) const;
	bool PathReadable(const std::string& p_strPath) const;
	bool PathWriteable(const std::string& p_strPath) const;
};