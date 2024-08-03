#pragma once
#include "TextureData.h"
#include <unordered_map>
#include <filesystem>
namespace fs = std::filesystem;

class TextureManager
{
public:
	void AddTexture(const std::string&, const fs::path&);
	void AddTexture(const std::string&, const TextureData&);
private:
	std::unordered_map<std::string, TextureData> textures;
};

