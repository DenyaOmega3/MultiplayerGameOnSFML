#pragma once
#include <SFML/Graphics.hpp>
#include <cassert>
#include <string>

/*
Uno Card description:
- spritesheet size: 134 x 698
- card size: 32 x 48
- margin between cards: 2 px left, 2 px down
*/

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
	sf::Sprite m_sprite;
	CardType m_cardType;
	ColorCard m_colorCard;
	int m_score;

	void setScore();
	void setSprite();
	sf::IntRect&& getRectangle();

public:	
	Card(CardType cardType, ColorCard colorCard);
	Card(CardType cardType);

	const sf::Sprite& getSprite() const;

	int getScore() const;
	CardType getCardType() const;
	ColorCard getColorCard() const;
};

