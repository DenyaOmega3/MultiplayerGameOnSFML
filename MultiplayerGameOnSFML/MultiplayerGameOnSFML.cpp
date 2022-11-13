#include <SFML/Graphics.hpp>
#include "CardDeck.h"

/*
UNO game

Card deck: 112 cards
18 cards 1 to 9 + 1 card 0 - each color
2 Skip cards - each color
2 Reverse cards - each color
2 Draw 2-cards - each color
4 Wild cards
4 Wild draw 4-cards
*/

/*
Rule: each player has 7 cards
*/

//Task: modify ResourceManager for thread-safety
//Task2: overload window.draw for other objects

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "UNO");
	CardDeck deck;
	deck.shuffle();

	while (window.isOpen()) {
		sf::Event events;

		while (window.pollEvent(events)) {
			if (events.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(0,0,255));
		window.draw(deck.getTopCard().getSprite());
		window.display();
	}
}
