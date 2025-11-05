#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include "DashboardItem.h"
using std::vector;

// класс, реализующий панельдля игровых индикаторов
// аозволяет добавлять индикатор в панель, отрисовывать панель с индикаторами
class Dashboard
{
	vector<DashboardItem*> items; // список индикаторов
public:
	Dashboard();
	virtual ~Dashboard();
	virtual void Draw(sf::RenderWindow& window, sf::Vector2f position); // отрисовка панели
	void AddItem(DashboardItem* item); // добавляет индикатор на панель
};

