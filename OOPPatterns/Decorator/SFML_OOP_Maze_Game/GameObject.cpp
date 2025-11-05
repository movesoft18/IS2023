#include "GameObject.h"

sf::RenderWindow* GameObject::window = nullptr;

void GameObject::SetRenderWindow(sf::RenderWindow* window)
{
	GameObject::window = window;
}
