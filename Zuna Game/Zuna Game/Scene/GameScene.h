#pragma once
#include <memory>
#include "../../Game/Entity/Zuna/Zuna.h"
#include "../../Game/Entity/Tiles/Grass.h"
class GameScene
{
public:
	GameScene();
	~GameScene();
	void Draw(sf::RenderWindow &window);
	void Update(float dt);

private:
	std::vector<std::vector<std::unique_ptr<Grass>>> mGrassTiles;
	std::unique_ptr<Zuna> mZuna;

};

