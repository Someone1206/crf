#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <Windows.h>

bool doesStartWithDriveLetter(const char* path) {
	if (*path >= 'A' || *path <= 'Z')
		if (*(path + 1) == ':')
			if (*(path + 2) == '\\' || *(path + 2) == '/')
				return true;
	return false;
}

bool doesParDirExist(const char* _path) {
	std::filesystem::path path = _path, parDir = path.parent_path();
	
	if (parDir.string() == "")
		return true;
	if (!std::filesystem::exists(parDir)) {
		return false;
	}
	if (!std::filesystem::is_directory(parDir)) {
		return false;
	}

	return true;
}

bool isPathValid(std::string _path) {
	size_t len = _path.length();
	for (size_t i = 0; i < len; ++i) {
		switch (_path.at(i)) {
			case ':':
			case '*':
			case '?':
			case '"':
			case '<':
			case '>':
			case '|':
				return false;
		}
	}
	return true;
}

void createFile(const char* _path) {
	std::filesystem::path path = _path;
	if (!isPathValid(path.string())) {
		std::cout << "Error! " << _path << " is not valid!\n";
		return;
	}
	if (std::filesystem::exists(path)) {
		std::cout << "Error! " << _path << " already exists!\n";
		return;
	}
	std::ofstream file(path.string());
	std::cout << path.string() << " created.\n";
	file.close();
}

void remvQuotes(char* _path) {
	if (*_path == '"') _path++;
	if (*(_path + strlen(_path) - 2) == '"') *(_path + strlen(_path) - 2) = 0;
}

int main(int argc, char const *argv[])
{
	std::string currentPath = "", createdPath = "";
	{
		DWORD len = 0;
		len = GetCurrentDirectory(0, NULL);
		char* path = new char[len];
		GetCurrentDirectory(len, path);
		currentPath = path;
		delete[] path;
	}

	for (int i = 1; i < argc; ++i)
	{
		remvQuotes((char*)argv[i]);
		if (!doesStartWithDriveLetter(argv[i])) {
			if (doesParDirExist(argv[i])) {
				createFile(argv[i]);
			}
			else {
				std::cout << "Error: " << argv[i] << " has parent folders which don't exist\n";
			}
		}
		else {
			if (doesParDirExist(argv[i])) {
				createdPath = currentPath + argv[i];
				createFile(createdPath.c_str());
			}
			else {
				std::cout << "Error: " << argv[i] << " has parent folders which don't exist\n";
			}
		}
	}
	return 0;
}