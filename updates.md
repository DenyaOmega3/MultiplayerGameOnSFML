##13.11.22
class Card changed:
- removed member sf::Texture
- Card::setSprite() now loads for every object from one sf::Texture using ResourceManager, i.e. we pass into sf::setTexture an address of sf::Texture
