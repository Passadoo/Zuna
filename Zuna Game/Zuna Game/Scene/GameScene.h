#pragma once
#include <memory>
#include "../Game/Utilities/MathFunctions.h"
#include "../Game/Entity/Zuna/Zuna.h"
#include "../Game/Entity/Tiles/Background/Grass.h"
#include "../Game/Entity/Tiles/Background/Bush.h"
#include "../Game/Entity/Tiles/Solid/Rock.h"
class GameScene
{
public:
	GameScene();
	~GameScene();
	void Draw(sf::RenderWindow &window);
	void Update(float dt);

private:
	std::vector<sf::Vector2f> mTakenPositions;
	std::vector<std::vector<std::unique_ptr<Grass>>> mDefaultTiles;
	std::vector <std::unique_ptr<Rock>> mRocks;
	std::vector<std::unique_ptr<Bush>> mBushes;
	std::unique_ptr<Zuna> mZuna;

	const int NUMBER_OF_ROCKS = 5;
	const int NUMBER_OF_BUSHES = 5;
};

