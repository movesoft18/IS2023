#include "DashboardItem.h"

DashboardItem::DashboardItem(const string& textureFile, const string& fontFile, int* observedValue)
{
	texture.loadFromFile(textureFile);
	font.loadFromFile(fontFile);
	sprite.setTexture(texture);
	text.setFont(font);
	value = observedValue;
}

void DashboardItem::Draw(sf::RenderWindow& window, sf::Vector2f position)
{
	sprite.setPosition(position);
	window.draw(sprite);
	auto size = sprite.getLocalBounds();
	text.setString(std::to_string(*value));
	text.setPosition(sf::Vector2f(position.x + size.width + 5, position.y + 5));
	window.draw(text);
}

sf::FloatRect DashboardItem::GetSpriteSize()
{
	return sprite.getLocalBounds();
}
