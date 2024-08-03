#include "TextureManager.h"
#include <iostream>

void TextureManager::AddTexture(const std::string& tN, const fs::path& fP) {
	sf::Texture texture;
	if (!texture.loadFromFile(fP.string())) {
		std::cerr << "Failed to load image" << std::endl;
		return;
	}

	TextureData textureData(&texture);
	//textures[tN] = textureData;
	AddTexture(tN, textureData);
}

void TextureManager::AddTexture(const std::string& tN, const TextureData& t) {
	textures[tN] = t;
}