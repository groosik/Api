#pragma once
#include <string>
#include <fstream>
#include <vector>

class WebsiteFetcher
{
	std::wstring fetchedFilePath;
	std::wfstream fileHandler;
	std::vector<std::wstring> codeLines;

	std::wstring downloadWebsite(const std::wstring& link);
	void loadFileIntoMemory();
	void closeAndDeleteFile();
	void downloadAndOpenFile(std::wstring link);
	void deleteFile();
public:
	explicit WebsiteFetcher(std::wstring link); // throws std::exception;
	std::wstring getLineOfCode(int index);
	int getLinesQuantity() const;

};
