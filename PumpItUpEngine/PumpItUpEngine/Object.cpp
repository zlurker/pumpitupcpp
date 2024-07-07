#include "Object.h"

Object::Object(int xc, int yc, sf::Texture* texturec, sf::IntRect* tR) {
	x = xc;
	y = yc;
	texture = texturec;
	textureRect = tR;
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

void Object::SetTexture(sf::Texture* texturec) {
	texture = texturec;
}

sf::Texture* Object::GetTexture() {
	return texture;
}

sf::IntRect* Object::GetTextureRect() {
	return textureRect;
}