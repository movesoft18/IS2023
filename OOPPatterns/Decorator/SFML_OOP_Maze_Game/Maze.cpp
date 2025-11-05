#include "Maze.h"
#include "Game.h"
#include "GameObjectsFactory.h"
#include "GameObject.h"
#include <stdexcept>
#include <map>

void Maze::SetPosition(sf::Vector2f position)
{
    this->position = position;
}

int Maze::GetWidth()
{
    return width;
}

int Maze::GetHeight()
{
    return height;
}

void Maze::CreateMap(vector<string>& map)
{
	ClearMap();
	for (int i = 0; i <map.size(); i++)
	{
		vector<GameObject*> row;
		for (int j = 0; j < map[i].length(); j++)
		{
			row.push_back(GameObjectsFactory::CreateObjectInstance(map[i][j]));
		}
		levelMap.push_back(std::move(row));
	}
    if (map.size() > 0)
        width = map[0].length();
    else
        width = 0;
    this->height = map.size();
}

void Maze::ClearMap()
{
	for (int i = 0; i < levelMap.size(); i++)
		for (int j = 0; j < levelMap[i].size(); j++)
			delete levelMap[i][j];
	levelMap.clear();
    width = 0;
    height = 0;
}

void Maze::BeginAct()
{
    animations.clear();
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
        {
            auto gameObject = levelMap[y][x];
            if (gameObject == nullptr) continue;
            auto command = gameObject->Act(x, y, Game::event);

            if (x + command.deltaX < 0 || x + command.deltaX >= width || y + command.deltaY < 0 ||
                y + command.deltaY >= height)
                throw std::runtime_error("The object " + gameObject->GetName() + " falls out of the game field");


            AddAnimation(command, gameObject, x, y);
            /*Animation animation{
                command,
                gameObject,
                sf::Vector2f(x * cellSize + position.x, y * cellSize + position.y),
                Point(x + command.deltaX, y + command.deltaY),
            };
            animations.push_back(animation); */

        }
    std::sort(
        animations.begin(), 
        animations.end(), 
        [](Animation& i, Animation& j) {
            return (i.gameObject->GetDrawingPriority() < j.gameObject->GetDrawingPriority());
        });

}


void Maze::EndAct()
{
    std::vector<vector<vector<GameObject*>>> objectsPerLocations = GetCandidatesPerLocation();
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            levelMap[y][x] = SelectWinnerCandidatePerLocation(objectsPerLocations, x, y);
        }
    }
}

void Maze::AddAnimation(const GameObjectCommand& command, GameObject* object, int x, int y)
{
    Animation animation{
    command,
    object,
    sf::Vector2f(x * cellSize + position.x, y * cellSize + position.y),
    Point(x + command.deltaX, y + command.deltaY),
    };
    animations.push_back(animation);
}

std::vector<vector<vector<GameObject*>>> Maze::GetCandidatesPerLocation()
{
    std::vector<vector<vector<GameObject*>>> gameObjects(height, vector<vector<GameObject*>>(width));
    for(auto &e : animations)
    {
        auto x = e.targetLogicalLocation.x;
        auto y = e.targetLogicalLocation.y;
        GameObject* nextObject; // объект, в который трансформируется текущий объект в конце хода
        // Трансформация объекта
        if (e.command.transformTo == e.gameObject)
            nextObject = e.gameObject;
        else
        {
            nextObject = e.command.transformTo;
            delete e.gameObject;
            e.gameObject = nullptr;
        }
        gameObjects[y][x].push_back(nextObject);
    }
    return gameObjects;
}

GameObject* Maze::SelectWinnerCandidatePerLocation(std::vector<vector<vector<GameObject*>>>& objects, int x, int y)
{
    vector<GameObject*> deadList;
    auto candidates = objects[y][x];
    auto aliveCandidates = candidates;
    for(auto &candidate : candidates)
        for(auto &rival : candidates)
            if (rival != candidate && (candidate != nullptr && candidate->DeadInConflict(rival)))
            {
                deadList.push_back(candidate);
                auto candidateIterator = std::find(aliveCandidates.begin(), aliveCandidates.end(), candidate);
                aliveCandidates.erase(candidateIterator);
                auto animationsIterator = std::find_if(animations.begin(), animations.end(), [&candidate](const Animation& a) {
                    return a.gameObject == candidate;
                    });
                if (animationsIterator != animations.end())
                {
                    animationsIterator->gameObject = nullptr;
                }
                //delete candidate; // здесь удалять нельзя
            }
    // Удаляем мертвые объекты
    for (auto& d : deadList)
        delete d;
    if (aliveCandidates.size() > 1)
        throw std::runtime_error(
            "Game objects " + aliveCandidates[0]->GetName() + " and " +
             aliveCandidates[1]->GetName() + " claimed the same map cell");
    
    if (aliveCandidates.size() == 0) return nullptr;
    return aliveCandidates[0];
}
