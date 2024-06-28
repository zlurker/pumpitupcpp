#include "FileLoader.h"
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

FileLoader::FileLoader() {
	sscFiles = new std::vector<SSCFile*>();
}

void FileLoader::LoadSSCFiles() {

	fs::path base_path = fs::current_path();
	std::cout << fs::current_path() << std::endl;
	std::string relative_song_path = "Songs";

	fs::path songFolderPath = base_path / relative_song_path;
	//std::string songFolderPath = "..\Songs";

	try {
		for (const auto& entry : fs::directory_iterator(songFolderPath)) {
			if (entry.is_directory()) {
				std::cout << entry.path().filename().string() << std::endl;
			}
		}
	}
	catch (const fs::filesystem_error& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}