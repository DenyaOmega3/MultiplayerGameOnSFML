## 11.11.22
"Project" was created

## 12.11.22
class Card created

## 13.11.22
class Card changed:
- removed member sf::Texture m_texture
- Card::setSprite() now loads for every object from one sf::Texture using ResourceManager, i.e. we pass into sf::setTexture an address of sf::Texture
- class Card derives class sf::Drawable
- every Card can be switched to faced down position
- can set position and scale card

class CardDeck changed:
- replaced std::list with std::vector
- added method CardDeck::shuffle()
