#pragma once
#include "SFML/Graphics.hpp"

class Object
{
public:
	Object(int, int, sf::Texture*, sf::IntRect* tR);
	void SetX(int);
	void SetY(int);
	int GetX();
	int GetY();
	void SetTexture(sf::Texture*);
	sf::Texture* GetTexture();
	sf::IntRect* GetTextureRect();

private:
	int x;
	int y;
	sf::Texture* texture;
	sf::IntRect* textureRect;
};

