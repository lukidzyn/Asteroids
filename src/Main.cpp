#include "Player.hpp"

int main()
{
	util::Platform platform;
	sf::RenderWindow window;

	const int ScreenWidth = 1024;
	const int ScreenHeight = 768;

	window.create(sf::VideoMode(ScreenWidth, ScreenHeight), "Asteroids");
	platform.setIcon(window.getSystemHandle());

	// sf::CircleShape triangle(80, 5);
	// sf::Texture tx;

	// tx.loadFromFile("content/player.png");
	// sh.setTexture(&tx);

	Player pl;
	pl.triangle.setPosition(sf::Vector2f(ScreenWidth / 2, ScreenHeight / 2));
	pl.triangle.setFillColor(sf::Color::White);

	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		// pl.shape.setPosition(sf::Vector2f(100, 100));
		// pl.shape.setFillColor(sf::Color::White);

		window.draw(pl.triangle);
		window.display();
	}

	return 0;
}