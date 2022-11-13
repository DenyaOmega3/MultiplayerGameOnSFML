#pragma once
#include "Card.h"
#include <list>
#include <algorithm>
#include <random>
#include <chrono>
#include <thread>

class CardDeck
{
	std::list<Card> m_deck;

public:
	CardDeck();
	void shuffle();
	Card& getTopCard();

	static int iterator;
};

