#pragma once
#include "SFML/Graphics.hpp"
#include "GameObjectCommand.h"
#include "GameObject.h"
#include "Point.h"

// описание анимации для объекта.
// в процессе перемещения из одной клетки в другую объект может быть анимирован (плавное, а не дискретное перемещение)
struct Animation
{
    // команда, выполненная объектом в очередном ходе
    GameObjectCommand command;
    // указатель на игровой объект
    GameObject* gameObject;
    // позиция, где должен быть отрисован объект (используется для анимации)
    sf::Vector2f location;
    // Конечная позиция объекта на игровом поле на очередном шаге игры
    Point targetLogicalLocation;
};

