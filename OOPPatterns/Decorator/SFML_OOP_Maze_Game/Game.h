#pragma once
#include "Maze.h"
#include <string>
#include "SFML/Graphics.hpp"
#include <vector>
#include "Background.h"
#include "Dashboard.h"
using std::string;

// класс игры
static class Game
{
	// анимация происходит за определенные интервалы таймера, это счетчик этих шагов
	static int timerTickCounter;
	// фоновое изображение игры
	static Background background;
public:
	static vector<string> levelMap; // карта уровня
	static sf::RenderWindow window; // окно рендеринга
	static Dashboard dashboard; // панель индикаторов игры
	// -------------- вспомогательные поля для отладки, количество созданных объектов каждого типа
	static int walls;
	static int players;
	static int doors;
	static int coins;
	static int bullets;
	// ----------------------------
	static Maze maze; // лабиритн
	static int score; // счет
	static int timeLeft; // остаток времени на уровень
	static bool isOver; // признак конца игры
	static sf::Event event; // класс событий SFML, используется для обработки нажатий клавиш
	static void CreateGameWindow(); // создает окно игры
	static void StartGame(); // запускает игру
	static void PaintScene(); // отрисовывает в окне сцену игры
	static void TimerTick(); // инициирует процесс анимации в процессе перехода из клетки в клетку объектов
};

