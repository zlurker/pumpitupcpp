#include "Object.h"

Object::Object(int xc, int yc, TextureData* tD, RatioRect* ratioRect) {
	x = xc;
	y = yc;
	textureData = tD;

	textureRect = ratioRect->GenerateRect(tD->GetWidth(), tD->GetHeight());
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