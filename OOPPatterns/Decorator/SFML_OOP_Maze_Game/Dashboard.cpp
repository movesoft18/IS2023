#include "Dashboard.h"

Dashboard::Dashboard()
{
}

Dashboard::~Dashboard()
{
	for (auto& i : items)
	{
		if (i != nullptr) delete i;
	}
}

void Dashboard::Draw(sf::RenderWindow& window, sf::Vector2f position)
{
	if (items.size() == 0) return;
	int divRatio = items.size() + 1;
	auto size = window.getSize();
	float step = size.x / divRatio;
	for (int x = 0; x < items.size(); x++)
	{
		items[x]->Draw(window, sf::Vector2f(position.x + (x + 1) * step - items[x]->GetSpriteSize().width, position.y + 5));
	}
}

void Dashboard::AddItem(DashboardItem* item)
{
	if (item != nullptr) items.push_back(item);
}
