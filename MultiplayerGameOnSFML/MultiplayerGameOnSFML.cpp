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

//Task: make sf::Texture for UNO cards a shared resource [check]
//Create resource manager and see how singleton works

int main() {

	sf::RenderWindow window(sf::VideoMode(800, 600), "UNO");
	//sf::CircleShape shape(100.f);
	CardDeck deck;
	//deck.shuffle();
	int value;

	//shape.setFillColor(sf::Color::Green);

	while (window.isOpen()) {
		sf::Event events;

		while (window.pollEvent(events)) {
			if (events.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(0,0,255));
		window.draw(deck.getTopCard().getSprite());
		value = deck.getTopCard().getScore();
		window.display();
	}
}
