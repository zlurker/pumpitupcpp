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
	ScanDirectory(songFolderPath.string());
	
}

void FileLoader::ScanDirectory(std::string path) {
	try {
		for (const auto& entry : fs::directory_iterator(path)) {
			if (entry.is_directory()) {
				std::cout << "Scanning " << entry.path().filename().string() << " for SSC files" << std::endl;
				ScanDirectory(entry.path().string());
			}
			else {
				std::string ext = entry.path().extension().string();
				std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

				if (ext._Equal(".ssc"))
					std::cout << entry.path().string() << std::endl;
			}
		}
	}
	catch (const fs::filesystem_error& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}