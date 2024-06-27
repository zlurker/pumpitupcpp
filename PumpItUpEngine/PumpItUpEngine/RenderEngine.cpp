#include "RenderEngine.h"

#include "SFML/Graphics.hpp"
#include <iostream>
#include "ObjectList.h"

RenderEngine::RenderEngine(ObjectList* objectListSingletonInst) {
	objectListSingleton = objectListSingletonInst;
}

void RenderEngine::render() {
	sf::RenderWindow window(sf::VideoMode(800, 800), "Pump it up");
	sf::Event e;

	/*sf::Texture texture;
	if (!texture.loadFromFile("../ArrowTextures/BASE 1x2.PNG")) {
		std::cerr << "Failed to load image" << std::endl;
		return;
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
		shape.setPosition(0, 0);

		window.draw(shape);
		window.draw(sprite);

		// Display the content
		window.display();
		//i++;
	}*/
	

	while (window.isOpen()) {
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		std::vector<Object*> objectList = objectListSingleton->GetObjectList();
		for (int i = 0; i < objectList.size(); i++) {
			sf::Sprite sprite(*objectList[i]->GetTexture());
			sprite.setPosition(objectList[i]->GetX(), objectList[i]->GetY());
			window.draw(sprite);
		}
		/*sf::CircleShape shape(50);
		shape.setFillColor(sf::Color::Green);
		shape.setPosition(0, 0);

		window.draw(shape);
		window.draw(sprite);
		*/
		// Display the content
		window.display();
		
		//i++;
	}
}