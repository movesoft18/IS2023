#pragma once
#include "GameObject.h"
#include "GameObjectsFactory.h"
class GameObjectBase : public GameObject
{
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	string name;

	virtual void LoadTexture(string fileName);
public:
	virtual ~GameObjectBase();
	string GetName() override;
	void Draw(sf::Vector2f position) override;
	int GetDrawingPriority() override;
};

class Player : public GameObjectBase
{
	Player();
public:
	GameObjectCommand Act(int x, int y, sf::Event event) override;
	bool DeadInConflict(GameObject* conflictedObject) override;
	int GetDrawingPriority() override;
	friend class GameObjectsFactory;
};

class Wall : public GameObjectBase
{
	Wall();
public:
	GameObjectCommand Act(int x, int y, sf::Event event) override;
	bool DeadInConflict(GameObject* conflictedObject) override;
	friend class GameObjectsFactory;
};

class Door : public GameObjectBase
{
	Door();
public:
	GameObjectCommand Act(int x, int y, sf::Event event) override;
	bool DeadInConflict(GameObject* conflictedObject) override;
	friend class GameObjectsFactory;
};

class Coin : public GameObjectBase
{
	Coin();
public:
	GameObjectCommand Act(int x, int y, sf::Event event) override;
	bool DeadInConflict(GameObject* conflictedObject) override;
	friend class GameObjectsFactory;
};

class Bullet : public GameObjectBase
{
	int deltaX;
	int deltaY;
	int maxDistance;
	Bullet();
public:
	GameObjectCommand Act(int x, int y, sf::Event event) override;
	bool DeadInConflict(GameObject* conflictedObject) override;
	void SetFlyingDirection(int dx, int dy);
	friend class GameObjectsFactory;
};

class GameObjectsDecorator : public GameObject
{
protected:
	GameObject* _wrappee;
	sf::Texture texture1, texture2;
	sf::Sprite sprite1, sprite2;
	int stage;
	GameObjectsDecorator(GameObject* inner);
	GameObjectsDecorator(GameObject* inner, string texture1File, string texture2File);
public:

	~GameObjectsDecorator() override;
	GameObjectCommand Act(int x, int y, sf::Event event) override;
	bool DeadInConflict(GameObject* conflictedObject) override;
	string GetName() override;
	void Draw(sf::Vector2f position) override;
	int GetDrawingPriority() override;
	friend class GameObjectsFactory;
};

