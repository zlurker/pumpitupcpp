#pragma once
#include "SFML/Graphics.hpp"

class RatioRect
{
public:
	RatioRect(float, float, float, float);
	const sf::IntRect& GenerateRect(float, float);
private:
	float startXRatio;
	float startYRatio;
	float lengthXRatio;
	float lengthYRatio;
};

