#pragma once
#include "SFML/Graphics.hpp"

class Object
{
public:
	Object(int, int, sf::Texture);
	void SetX(int);
	void SetY(int);
	int GetX();
	int GetY();
	void SetTexture(sf::Texture);

private:
	int x;
	int y;
	sf::Texture texture;
};

