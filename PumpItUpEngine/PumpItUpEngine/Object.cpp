#include "Object.h"

Object::Object(int xc, int yc, sf::Texture texturec) {
	x = xc;
	y = yc;
	texture = texturec;
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

void Object::SetTexture(sf::Texture texturec) {
	texture = texturec;
}