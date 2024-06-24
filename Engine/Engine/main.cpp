#include <SFML/Graphics.hpp>

int main()
{
    // Create a window with a title and size
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pump It Up");

    // Main game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear();

        // Draw your game content here
        // Example: Draw a simple circle
        sf::CircleShape shape(50);
        shape.setFillColor(sf::Color::Green);
        window.draw(shape);

        // Display the content
        window.display();
    }

    return 0;
}