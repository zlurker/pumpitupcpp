#include "TextureData.h"

TextureData::TextureData() {

}

TextureData::TextureData(sf::Texture* t) {
	texture = t;

	sf::Vector2u size = t->getSize();
	width = size.x;
	height = size.y;
}

unsigned int TextureData::GetWidth() {
	return width;
}

unsigned int TextureData::GetHeight() {
	return height;
}