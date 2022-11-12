#include "Card.h"

void Card::setScore() {
	switch (m_cardType) {
	case DRAW: case SKIP: case REVERSE: case WILD:
		m_score = 20; break;
	case WILD_DRAW:
		m_score = 50; break;
	default:
		m_score = m_cardType;
	}
}

void Card::setSprite() {
	//Change tileset order and cards
	assert(m_texture.loadFromFile("UnoCardsTilesetUpdated.png"), "Couldn't load image");
	m_sprite.setTexture(m_texture);

	int width = 32, height = 48;
	int marginX, marginY;
	marginX = marginY = 2;

	int xPosition = width * m_colorCard + m_colorCard * marginX;
	int yPosition = height * m_cardType + m_cardType * marginY;

	m_sprite.setTextureRect(sf::IntRect(xPosition, yPosition, width, height));
	m_sprite.setPosition(100, 100);
	m_sprite.scale(3, 3);
}

Card::Card(CardType cardType, ColorCard colorCard) : m_cardType(cardType), m_colorCard(colorCard) {
	setScore();
	setSprite();
}

Card::Card(CardType cardType) : Card(cardType,NONE)
{
}
