#pragma once
#include <memory>
#include "../Game/Utilities/MathFunctions.h"
#include "../Game/Entity/Zuna/Zuna.h"
#include "../Game/Entity/Tiles/Background/Grass.h"
#include "../Game/Entity/Tiles/Background/Bush.h"
#include "../Game/Entity/Tiles/Solid/Rock.h"
#include "../Game/PopUp/PopUp.h"

class GameScene
{
public:
	GameScene();
	~GameScene();
	void Draw(sf::RenderWindow &window);
	void Update(float dt);

	void ProcessInput(sf::RenderWindow &window);

private:
	std::vector<sf::Vector2f> mTakenPositions;
	std::vector<std::vector<std::unique_ptr<Grass>>> mDefaultTiles;
	std::vector <std::unique_ptr<Rock>> mRocks;
	std::vector<std::unique_ptr<Bush>> mBushes;
	std::unique_ptr<Zuna> mZuna;
	std::unique_ptr<PopUp> mPopUp;

	bool mWasFPressedLastFrame = false;

	const int NUMBER_OF_ROCKS = 5;
	const int NUMBER_OF_BUSHES = 5;
};

