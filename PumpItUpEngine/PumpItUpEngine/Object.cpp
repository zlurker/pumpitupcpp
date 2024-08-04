#include "Object.h"

Object::Object(int xc, int yc, TextureData* tD, float startXRatio, float startYRatio, float lengthXRatio, float lengthYRatio) {
	x = xc;
	y = yc;
	textureData = tD;

	textureRect = sf::IntRect(
		startXRatio * textureData->GetWidth(), 
		startYRatio * textureData->GetHeight(), 
		lengthXRatio * textureData->GetWidth(), 
		lengthYRatio * textureData->GetHeight()
	);
}

int Object::GetX() {
	return x;
}

int Object::GetY() {
	return y;
}

void Object::SetX(int xc) {
	x = xc;
}

void Object::SetY(int yc) {
	y = yc;
}

void Object::SetTexture(TextureData* texturec) {
	textureData = texturec;
}

TextureData* Object::GetTextureData() {
	return textureData;
}

sf::IntRect* Object::GetTextureRect() {
	return &textureRect;
}