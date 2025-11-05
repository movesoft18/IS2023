#include "Background.h"

Background::Background(std::string fileName)
{
	bool result = texture.loadFromFile(fileName);
	sprite.setTexture(texture);
	sprite.setColor(sf::Color(255, 255, 255, 100));
}

void Background::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

sf::FloatRect Background::GetSize()
{
	auto size = sprite.getLocalBounds();
	return size;
}

