#include "SFML/Graphics.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 800), "Pump it up");
	sf::Event e;

	while (window.isOpen()) {
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				window.close();
		}
	}
	
	return 0;
}