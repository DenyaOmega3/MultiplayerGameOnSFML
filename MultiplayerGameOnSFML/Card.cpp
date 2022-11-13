#include "Card.h"

std::string path = "Sprites/";
std::string name = "UnoCards.png";

//Probably not its responsibility
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
	m_sprite.setTexture(ResourceManager::getInstance(path, name)->getTexture());
	m_sprite.setTextureRect(getRectangle());

	sf::Sprite& checkAddress = m_sprite;

	setPosition(sf::Vector2f(0.0f, 0.0f));
}

//Probably not its responsibility
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

Card::Card(CardType cardType, ColorCard colorCard) 
	: m_cardType(cardType), m_colorCard(colorCard), m_facingDown(false) {
	setScore();
	setSprite();
	scale(3, 3);
}

Card::Card(CardType cardType) 
	: Card(cardType,NONE)
{
}

Card::Card() : Card(SHIRT) {
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

void Card::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	target.draw(m_sprite, states);
}

void Card::setPosition(const sf::Vector2f& position) {
	m_sprite.setPosition(position);
}

sf::Vector2f Card::getPosition() const
{
	return m_sprite.getPosition();
}

void Card::scale(float factorX, float factorY)
{
	m_sprite.scale(factorX, factorY);
}

void Card::switchFace()
{
	CardType tmpVariable = m_cardType;
	sf::Vector2f resetCoords = m_sprite.getPosition();
	if (!m_facingDown) {
		m_cardType = SHIRT;
		setSprite();
		m_cardType = tmpVariable;
	}
	else
		setSprite();

	setPosition(resetCoords);
	m_facingDown = !m_facingDown;
}
