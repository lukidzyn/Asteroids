#include "Platform/Platform.hpp"

class Player
{
public:
	Player();
	~Player();

	sf::CircleShape triangle;
	sf::Texture texture;

	void CreateShape();
	void LoadTexture(sf::ConvexShape sh, sf::Texture tx);
};