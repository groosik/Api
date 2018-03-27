#include "WebsiteFetcher.h"
#include <codecvt>

std::wstring WebsiteFetcher::downloadWebsite(const std::wstring& link)
{
	//TODO: implement
	return L"..\\additional files\\dog.html";
}

void WebsiteFetcher::loadFileIntoMemory()
{
	int i=0;
	std::wstring line;
	while(getline(fileHandler, line))
		codeLines.push_back(line);
}

void WebsiteFetcher::closeAndDeleteFile()
{
	if(fileHandler.is_open())
		fileHandler.close();
	deleteFile();
}

void WebsiteFetcher::downloadAndOpenFile(std::wstring link)
{
	fetchedFilePath=downloadWebsite(link);
	fileHandler.open(fetchedFilePath, std::wfstream::in);

	if(fileHandler.good()==false)
		throw std::exception("Invalid link. ");

	const std::locale utf8_locale = std::locale(std::locale(), new std::codecvt_utf8<wchar_t>());
	fileHandler.imbue(utf8_locale);
}

WebsiteFetcher::WebsiteFetcher(std::wstring link) 
{
	downloadAndOpenFile(link);
	loadFileIntoMemory();
	closeAndDeleteFile();
}

void WebsiteFetcher::deleteFile()
{
	//TODO: implement
}



std::wstring WebsiteFetcher::getLineOfCode(int index)
{
	if(getLinesQuantity()<=index || index<0)
		throw std::out_of_range("Called function WebsiteFetcher::getLineOfCode() with invalid index.");

	return codeLines[index];
}

int WebsiteFetcher::getLinesQuantity() const
{
	return codeLines.size();
}

