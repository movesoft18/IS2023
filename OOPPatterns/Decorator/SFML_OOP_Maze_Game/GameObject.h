#pragma once
#include "SFML/graphics.hpp"
#include <string>
using std::string;
// ќпережающее описание структуры
struct GameObjectCommand;


// Ѕазовый абстрактный класс, описывающий функционал любых игровых объектов
class GameObject
{
public:
	static sf::RenderWindow* window;
	static void SetRenderWindow(sf::RenderWindow* w);
	// метод отрисовки объекта
	virtual void Draw(sf::Vector2f position) = 0;
	// метод, определ€ющиц поведение объекта на очередном ходе игры
	// х, у - координаты объекта в игровом поле, event - событи€ клавиатуры, которые объект может обработать
	virtual GameObjectCommand Act(int x, int y, sf::Event event) = 0;
	// возвращает им€ объекта
	virtual string GetName() = 0;
	// определ€ет, умрет ли объект при столкновении с другим объектом, если они окажутс€ в одной клетке
	virtual bool DeadInConflict(GameObject* conflictedObject) = 0;
	// приоритет отрисовки, вли€ет на перекрытие объектов на экране
	virtual int GetDrawingPriority() = 0;
	virtual ~GameObject() {};
};

