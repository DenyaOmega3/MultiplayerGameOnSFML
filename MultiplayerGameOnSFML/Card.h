#pragma once
#include <SFML/Graphics.hpp>
#include <cassert>

//Uno Card
//Image spritesheet size: 270 x 498
//Card size: 32 x 48
//Margin size: 2px

enum CardType {
	ZERO = 0, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, 
	SKIP, REVERSE, DRAW, WILD, WILD_DRAW, SHIRT = -1
};

enum ColorCard {
	RED = 0, YELLOW, GREEN, BLUE, NONE = -1
};

class Card
{
	sf::Texture m_texture;
	CardType m_cardType;
	ColorCard m_colorCard;
	int m_score;

	void setScore();
	void setSprite();

public:
	sf::Sprite m_sprite;
	//Make impossible to create card WILD, WILD_DRAW, SHIRT with colors
	Card(CardType cardType, ColorCard colorCard);
	Card(CardType cardType);
};

