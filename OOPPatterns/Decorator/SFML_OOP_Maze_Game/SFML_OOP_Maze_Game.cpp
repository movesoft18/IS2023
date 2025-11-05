#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "GameObjectsFactory.h"
#include "Game.h"
using namespace sf;


int main()
{
	Game::maze.CreateMap(Game::levelMap);
	Game::StartGame();
}