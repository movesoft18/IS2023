#pragma once
#include <vector>
#include "Animation.h"

using std::vector;

class Maze
{
	int width; // ширина лабиринта
	int height; // высота лабиринта
	sf::Vector2f position{ 0, 0 }; // позиция отрисовки лабиринта в окне
public:
	int cellSize = 24; // размер ячейки игрового поля в пикселах
	vector<Animation> animations; // массив объектов для разбора их действий на очередном шаге игры
	vector<vector<GameObject*>> levelMap; // Двумерный массив указателей на игровые объекты. Собственно это и есть рабочее игровое поле с конкретными объектами

	void SetPosition(sf::Vector2f position); // устанавливает позицию для отображения лабиринта в окне
	int GetWidth(); // получить ширину лабиринта
	int GetHeight(); // получить высоту лабиринта
	void CreateMap(vector<string>& levelMap); // создает карту уровня
	void ClearMap(); // очищает карту уровня
	void BeginAct(); // запуск очередного хода игры, на данном этапе все игровые элементы могут совеершать определенные их алгоритмом действия
	void EndAct(); // завершение хода игры, подведение итогов хода, определение кто жив, кто умер, кто превратился и т.п.
	void AddAnimation(const GameObjectCommand& command, GameObject* object, int x, int y); // добавление объекта в игру в процессе игрового хода

private:
	// возвращает список всех претендентов на завлвдение игровой клеткой
	// например 2 объекта оказались на очередном шаге в одной клетке
	// они оба являются кандидатами на завладение этой клеткой
	std::vector<vector<vector<GameObject*>>> GetCandidatesPerLocation(); 
	// определяет, кто из кандидатов на завлвдение клеткой отанется жив при попытке завладеть клеткой, или они все умрут
	GameObject* SelectWinnerCandidatePerLocation(std::vector<vector<vector<GameObject*>>>& objects, int x, int y);
};

