#pragma once
#include "SFML/Graphics.hpp"
#include <string>

// класс, отображающий фон на игровом окне
class Background
{
	sf::Texture texture; // текстура фона
	sf::Sprite sprite; // спрайт фона
public:
	Background(std::string fileName); // констуктор, создает фон из файла изображения
	virtual void Draw(sf::RenderWindow& window); // отрисовывает фон в буфере кадра
	sf::FloatRect GetSize(); // возвращает размер фона
};

