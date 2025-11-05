#pragma once
#include "SFML/Graphics.hpp"
#include <string>
using std::string;

//класс - игровой индикатор
class DashboardItem
{
	sf::Texture texture; // текстура, определяющая внешний вид индикатора
	sf::Sprite sprite; // спрайт, созданный из текстуры
	sf::Font font; // шрифт для отображения текста индикатора
	sf::Text text;	// объект для отображения текста индикатора
	int* value;
public:
	// конструктор создания индикатора, observedValue - указатель на переменную, которую отслеживает индикатор и своевременно обновляет
	DashboardItem(const string& textureFile, const string& fontFile, int* observedValue);
	// отрисовывает индиктора на панели
	virtual void Draw(sf::RenderWindow& window, sf::Vector2f position);
	// возвращает размер спрайта индикатора
	sf::FloatRect GetSpriteSize();
};

