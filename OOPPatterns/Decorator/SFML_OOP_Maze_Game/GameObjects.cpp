#include "GameObjects.h"
#include "Game.h"

string GameObjectBase::GetName()
{
    return name;
}

void GameObjectBase::Draw(sf::Vector2f position)
{
    sprite.setPosition(position);
    if (window)
        window->draw(sprite);
}

int GameObjectBase::GetDrawingPriority()
{
    return 1;
}


void GameObjectBase::LoadTexture(string fileName)
{
    texture.loadFromFile(fileName);
    sprite.setTexture(texture);
}


GameObjectBase::~GameObjectBase()
{
    if (GetName() == "Player") Game::players--;
    else if (GetName() == "Wall") Game::walls--;
    else if (GetName() == "Door") Game::doors--;
    else if (GetName() == "Coin") Game::coins--;
    else if (GetName() == "Bullet") Game::bullets--;
}

Player::Player()
{
    name = "Player";
    LoadTexture("assets\\bitmaps\\player.png");
    Game::players++;
}

GameObjectCommand Player::Act(int x, int y, sf::Event event)
{
    auto canMove = [](GameObject* obj) {
        return (obj == nullptr) || (obj->GetName() == "Coin") || (obj->GetName() == "Door");
    };

    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Key::Left:
            if (x > 0 && canMove(Game::maze.levelMap[y][x-1]))
            {
                return GameObjectCommand{ -1,0, this };
            }
            break;
        case sf::Keyboard::Key::Right:
            if (x < Game::maze.GetWidth() - 1 && canMove(Game::maze.levelMap[y][x + 1]))
            {
                return GameObjectCommand{ 1,0, this };
            }
            break;
        case sf::Keyboard::Key::Up:
            if (y > 0 && canMove(Game::maze.levelMap[y-1][x]))
            {
                return GameObjectCommand{ 0,-1, this };
            }
            break;
        case sf::Keyboard::Key::Down:
            if (y < Game::maze.GetHeight() - 1 && canMove(Game::maze.levelMap[y + 1][x]))
            {
                return GameObjectCommand{ 0,1, this };
            }
            break;
        case sf::Keyboard::Key::W:
            if (y > 0)
            {
                Bullet* bullet = static_cast<Bullet*>(GameObjectsFactory::CreateObjectInstance('b'));
                bullet->SetFlyingDirection(0, -1);
                Game::maze.AddAnimation(GameObjectCommand{ 0, -1, bullet }, bullet, x, y);
                return GameObjectCommand{ 0,0, this };
            }
            break;
        }
    }
    return GameObjectCommand {0,0, this};
}

bool Player::DeadInConflict(GameObject* conflictedObject)
{
    return false;
}

int Player::GetDrawingPriority()
{
    return 10;
}

Wall::Wall()
{
    name = "Wall";
    LoadTexture("assets\\bitmaps\\wall.png");
    Game::walls++;
}

GameObjectCommand Wall::Act(int x, int y, sf::Event event)
{
    return GameObjectCommand{ 0,0, this};
}

bool Wall::DeadInConflict(GameObject* conflictedObject)
{
    return false;
}

Door::Door()
{
    name = "Door";
    LoadTexture("assets\\bitmaps\\door.png");
    Game::doors++;
}

GameObjectCommand Door::Act(int x, int y, sf::Event event)
{
    return GameObjectCommand{ 0,0, this};
}

bool Door::DeadInConflict(GameObject* conflictedObject)
{
    Game::isOver = true;
    return (conflictedObject->GetName() == "Player");
}

Coin::Coin()
{
    name = "Coin";
    LoadTexture("assets\\bitmaps\\coin.png");
    Game::coins++;
}

GameObjectCommand Coin::Act(int x, int y, sf::Event event)
{
    return GameObjectCommand{ 0, 0, this};
}

bool Coin::DeadInConflict(GameObject* conflictedObject)
{
    if (conflictedObject->GetName() == "Player")
    {
        Game::score += 100;
    }
    return true;
}


Bullet::Bullet()
{
    name = "Bullet";
    LoadTexture("assets\\bitmaps\\bullet.png");
    maxDistance = 4;
    deltaX = deltaY = 0;
}

GameObjectCommand Bullet::Act(int x, int y, sf::Event event)
{
    //... ваш код
    return GameObjectCommand{ 0, 0, nullptr };
}

bool Bullet::DeadInConflict(GameObject* conflictedObject)
{
    return true;
}

void Bullet::SetFlyingDirection(int dx, int dy)
{
//...
}

GameObjectsDecorator::GameObjectsDecorator(GameObject* inner)
{
    _wrappee = inner;
    stage = rand()%3;
}

GameObjectsDecorator::GameObjectsDecorator(GameObject* inner, string texture1File, string texture2File)
{
    _wrappee = inner;
    stage = rand() % 3;    
    texture1.loadFromFile(texture1File);
    texture2.loadFromFile(texture2File);
    sprite1.setTexture(texture1);
    sprite2.setTexture(texture2);
}

GameObjectsDecorator::~GameObjectsDecorator()
{
    delete _wrappee;
}

GameObjectCommand GameObjectsDecorator::Act(int x, int y, sf::Event event)
{
    auto command = _wrappee->Act(x, y, event);
    return GameObjectCommand{ command.deltaX, command.deltaY, this };
}

bool GameObjectsDecorator::DeadInConflict(GameObject* conflictedObject)
{
    return _wrappee->DeadInConflict(conflictedObject);
}

string GameObjectsDecorator::GetName()
{
    return _wrappee->GetName();
}

void GameObjectsDecorator::Draw(sf::Vector2f position)
{
    switch (stage)
    {
    case 0: _wrappee->Draw(position);
        stage++;
        break;
    case 1: sprite1.setPosition(position);
        if (window)
            window->draw(sprite1);
        stage++;
        break;
    case 2: sprite2.setPosition(position);
        if (window)
            window->draw(sprite2);
        stage = 0;
        break;
    }  
}

int GameObjectsDecorator::GetDrawingPriority()
{
    return _wrappee->GetDrawingPriority();
}

