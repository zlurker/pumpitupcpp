#pragma once
#include "SFML/Graphics.hpp"

class TextureData
{
public:
	TextureData();
	TextureData(sf::Texture*);
	unsigned int GetWidth();
	unsigned int GetHeight();

private:
	sf::Texture * texture;
	unsigned int width;
	unsigned int height;
};

