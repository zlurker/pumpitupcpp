#include "TextureManager.h"
#include <iostream>

void TextureManager::AddTexture(const std::string& tN, const fs::path& fP) {
	sf::Texture* texture = new sf::Texture();
	if (!texture->loadFromFile(fP.string())) {
		std::cerr << "Failed to load image" << std::endl;
		return;
	}

	TextureData* textureData = new TextureData(texture);
	//textures[tN] = textureData;
	AddTexture(tN, *textureData);
}

void TextureManager::AddTexture(const std::string& tN, const TextureData& t) {
	textures[tN] = t;
}

TextureData* TextureManager::GetTextureData(const std::string& name) {
	return &textures[name];
}