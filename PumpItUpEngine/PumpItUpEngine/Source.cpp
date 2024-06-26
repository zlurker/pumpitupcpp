#include "SFML/Graphics.hpp"
#include <iostream>

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 800), "Pump it up");
	sf::Event e;
	int i = 0;

	sf::Texture texture;
	if (!texture.loadFromFile("../ArrowTextures/BASE 1x2.PNG")) {
		std::cerr << "Failed to load image" << std::endl;
		return -1;
	}

	// Create a sprite
	sf::Sprite sprite(texture);
	sprite.setPosition(200, 150);

	while (window.isOpen()) {
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		sf::CircleShape shape(50);
		shape.setFillColor(sf::Color::Green);
		shape.setPosition(i, i);

		window.draw(shape);
		window.draw(sprite);

		// Display the content
		window.display();
		//i++;
		std::cout << i << std::endl;
	}
	
	return 0;
}