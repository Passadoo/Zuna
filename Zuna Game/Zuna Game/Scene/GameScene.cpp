#include "GameScene.h"

#include <iostream>
GameScene::GameScene()
{
	mDefaultTiles.resize(Defines::WORLD_WIDTH);

	for (int i = 0; i < Defines::WORLD_WIDTH; i++)
	{
		for (int j = 0; j < Defines::WORLD_HEIGHT; j++)
		{
			mDefaultTiles[i].push_back(std::make_unique<Grass>());
			mDefaultTiles[i].back()->SetPosition((i * Defines::GRID_CELL_SIZE), (j * Defines::GRID_CELL_SIZE));
		}
	}

	for (int i = 0; i < NUMBER_OF_ROCKS; i++)
	{
		mRocks.push_back(std::make_unique<Rock>());
		sf::Vector2f pos;
		bool positionFound = false;
		while (!positionFound)
		{
			pos = sf::Vector2f((float)Defines::GRID_CELL_SIZE * MathFunctions::RandomIntRange(0, Defines::WORLD_WIDTH - 1), (float)(Defines::GRID_CELL_SIZE * MathFunctions::RandomIntRange(0, Defines::WORLD_HEIGHT - 1)));
			
			if (mTakenPositions.size() == 0)
			{
				positionFound = true;
				mRocks.back()->SetPosition(pos);
				mTakenPositions.push_back(pos);
			}
			else
			{
				for (int i = 0; i < mTakenPositions.size() && !positionFound; i++)
				{
					if (pos != mTakenPositions[i])
					{
						positionFound = true;
						mRocks.back()->SetPosition(pos);
						mTakenPositions.push_back(pos);
					}
				}
			}
		}
	}

	for (int i = 0; i < NUMBER_OF_BUSHES; i++)
	{
		mBushes.push_back(std::make_unique<Bush>());
		sf::Vector2f pos;
		bool positionFound = false;
		while (!positionFound)
		{
			pos = sf::Vector2f((float)Defines::GRID_CELL_SIZE * MathFunctions::RandomIntRange(0, Defines::WORLD_WIDTH -1), (float)(Defines::GRID_CELL_SIZE * MathFunctions::RandomIntRange(0, Defines::WORLD_HEIGHT - 1)));

			if (mTakenPositions.size() == 0)
			{
				positionFound = true;
				mRocks.back()->SetPosition(pos);
				mTakenPositions.push_back(pos);
			}
			else
			{
				for (int i = 0; i < mTakenPositions.size() && !positionFound; i++)
				{
					if (pos != mTakenPositions[i])
					{
						positionFound = true;
						mBushes.back()->SetPosition(pos);
						mTakenPositions.push_back(pos);
					}
				}
			}
		}
	}

	mZuna = std::make_unique<Zuna>();
	mZuna->SetPosition((Defines::GRID_CELL_SIZE * (Defines::WORLD_WIDTH / 2)), (Defines::GRID_CELL_SIZE * (Defines::WORLD_HEIGHT / 2)));

}


GameScene::~GameScene()
{
}

void GameScene::Draw(sf::RenderWindow & window)
{
	for (int i = 0; i < mDefaultTiles.size(); i++)
	{
		for (int j = 0; j < mDefaultTiles[i].size(); j++)
		{
			mDefaultTiles[i][j]->Draw(window);
		}
	}

	for (int i = 0; i < mRocks.size(); i++)
	{
		mRocks[i]->Draw(window);
	}
	for (int i = 0; i < mBushes.size(); i++)
	{
		mBushes[i]->Draw(window);
	}
	
	mZuna->Draw(window);
}

void GameScene::Update(float dt)
{
	for (int i = 0; i < mDefaultTiles.size(); i++)
	{
		for (int j = 0; j < mDefaultTiles[i].size(); j++)
		{
			mDefaultTiles[i][j]->Update(dt);
		}
	}

	for (int i = 0; i < mRocks.size(); i++)
	{
		mRocks[i]->Update(dt);
	}
	for (int i = 0; i < mBushes.size(); i++)
	{
		mBushes[i]->Update(dt);
	}

	mZuna->Update(dt);
}
