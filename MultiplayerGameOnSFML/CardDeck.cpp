#include "CardDeck.h"

int CardDeck::iterator = 0;

CardDeck::CardDeck()
{
	m_deck.resize(0);
	//See how to simplify this

	for (int i = 0; i < 4; i++) {
		m_deck.emplace_back(ZERO, static_cast<ColorCard>(i));
		m_deck.emplace_back(WILD);
		m_deck.emplace_back(WILD_DRAW);
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= 12; j++) {
			m_deck.emplace_back(static_cast<CardType>(j), static_cast<ColorCard>(i));
			m_deck.emplace_back(static_cast<CardType>(j), static_cast<ColorCard>(i));
		}
	}
}

void CardDeck::shuffle()
{
	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
	int var = m_deck.size();
	std::shuffle(m_deck.begin(), m_deck.end(), std::default_random_engine(seed));
}

Card& CardDeck::getTopCard()
{
	return *m_deck.begin();
}
