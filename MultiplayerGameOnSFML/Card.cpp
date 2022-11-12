#include "Card.h"

std::string path = "Sprites/";
std::string name = "UnoCards.png";

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
	assert(m_texture.loadFromFile(path + name), "Couldn't load image");
	m_sprite.setTexture(m_texture);

	m_sprite.setTextureRect(getRectangle());
	m_sprite.setPosition(100, 100);
	m_sprite.scale(3, 3);
}

sf::IntRect&& Card::getRectangle() {
	int width = 32, height = 48;
	int marginX, marginY;
	marginX = marginY = 2;

	int xPosition, yPosition;
	switch (m_cardType) {
	case WILD: {
		xPosition = 0;
		yPosition = height * 13 + marginY * 13;
		break;
	}
	case WILD_DRAW: {
		xPosition = width + marginX;
		yPosition = height * (DRAW + 1) + marginY * (DRAW + 1);
		break;
	}
	case SHIRT: {
		xPosition = width * 2 + marginX * 2;
		yPosition = height * (DRAW + 1) + marginY * (DRAW + 1);
		break;
	}
	default: {
		xPosition = width * m_colorCard + marginX * m_colorCard;
		yPosition = height * m_cardType + marginY * m_cardType;
	}
	}

	return sf::IntRect(xPosition, yPosition, width, height);
}

Card::Card(CardType cardType, ColorCard colorCard) : m_cardType(cardType), m_colorCard(colorCard) {
	setScore();
	setSprite();
}

Card::Card(CardType cardType) : Card(cardType,NONE)
{
}

const sf::Sprite& Card::getSprite() const {
	return m_sprite;
}

int Card::getScore() const
{
	return m_score;
}

CardType Card::getCardType() const
{
	return m_cardType;
}

ColorCard Card::getColorCard() const
{
	return m_colorCard;
}
