#include "GameObjectsFactory.h"
#include "GameObjects.h"
#include <stdexcept>

GameObject* GameObjectsFactory::CreateObjectInstance(char objectType)
{
    switch (objectType)
    {
    case 'P':
        return new Player();
    case 'W':
        return new Wall();
    case 'C':
        return new Coin();
    case 'D':
        return new Door();
    case 'b':
        return new Bullet();
    case 'c':
        return new GameObjectsDecorator(new Coin(),"assets\\bitmaps\\coin1.png","assets\\bitmaps\\coin2.png");
    case 'e':
        return new GameObjectsDecorator(new Door(), "assets\\bitmaps\\door1.png", "assets\\bitmaps\\door2.png");
    case ' ':
        return nullptr;
    default:
        throw std::invalid_argument("An attempt was made to create an invalid object type");
    }
}
