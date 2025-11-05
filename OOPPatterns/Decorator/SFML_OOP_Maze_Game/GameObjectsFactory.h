#pragma once
#include "GameObject.h"

// класс-фабрика, позволяет создавать игровый объекты
class GameObjectsFactory
{
public:
	static GameObject* CreateObjectInstance(char objectType); // создает игровой объект по его символьному обозначению на карте
};