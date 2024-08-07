#pragma once
#include "SFML/Graphics.hpp"
#include "TextureData.h"
#include "RatioRect.h"

class Object
{
public:
	Object(int, int, TextureData*, RatioRect*);
	void SetX(int);
	void SetY(int);
	int GetX();
	int GetY();
	void SetTexture(TextureData*);
	TextureData* GetTextureData();
	sf::IntRect* GetTextureRect();

private:
	int x;
	int y;
	TextureData* textureData;
	sf::IntRect textureRect;
};

