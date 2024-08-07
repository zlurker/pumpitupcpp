#include "RatioRect.h"

RatioRect::RatioRect(float sXR, float sYR, float lXR, float lYR) {
	startXRatio = sXR;
	startYRatio = sYR;
	lengthXRatio = lXR;
	lengthYRatio = lYR;
}

const sf::IntRect& RatioRect::GenerateRect(float tW, float tH) {
	return sf::IntRect(
		startXRatio * tW,
		startYRatio * tH,
		lengthXRatio * tW,
		lengthYRatio * tH
	);
}