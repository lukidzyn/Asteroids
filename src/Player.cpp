#include "Player.hpp"

Player::Player()
{
	CreateShape();
	// LoadTexture(shape, texture);
}

Player::~Player()
{
}

void Player::CreateShape()
{
	triangle.setRadius(32);
	triangle.setPointCount(3);
}

void Player::LoadTexture(sf::ConvexShape sh, sf::Texture tx)
{
	tx.loadFromFile("content/player.png");
	sh.setTexture(&tx);
}