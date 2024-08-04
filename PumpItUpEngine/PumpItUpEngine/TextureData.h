#pragma once
#include "SFML/Graphics.hpp"

class TextureData
{
public:
	TextureData();
	TextureData(const sf::Texture&);
	unsigned int GetWidth();
	unsigned int GetHeight();
	sf::Texture* GetTexture();

private:
	sf::Texture texture;
	unsigned int width;
	unsigned int height;
};

