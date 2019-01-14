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
				mBushes.back()->SetPosition(pos);
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

	mPopUp = std::make_unique<PopUp>();
	mPopUp->SetPosition(sf::Vector2f(0, (Defines::GRID_CELL_SIZE * Defines::WORLD_HEIGHT) - 200.0f));
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
	mPopUp->Draw(window);
}

void GameScene::Update(float dt)
{
	std::cout << "Zuna: " << mZuna->GetGridCellPosition().x << ", " << mZuna->GetGridCellPosition().y << std::endl;
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

	if (!mPopUp->IsCharacterMovementLocked())
	{
		bool result = true;
		if (mZuna->WantsToMove())
		{
			for (int i = 0; i < mRocks.size(); i++)
			{
				//std::cout << "Zuna: " << mZuna->GetGridCellPosition().x << ", " << mZuna->GetGridCellPosition().y << "| Rock: " << mRocks[i]->GetGridCellPosition().x << ", " << mRocks[i]->GetGridCellPosition().y << std::endl;
				if (mZuna->GetPositionToMoveTo() == mRocks[i]->GetPosition())
				{
					result = false;
				}
			}

			if (result)
			{
				mZuna->SetAllowedToMove(true);
			}
			else
			{
				mZuna->SetIsMoving(false);
			}
		}
		mZuna->Update(dt);
	}
		
	mPopUp->Update(dt);
}

void GameScene::ProcessInput(sf::RenderWindow &window)
{
	if (!mPopUp->IsCharacterMovementLocked())
	{
		sf::Vector2i windowPos = sf::Mouse::getPosition(window);

		float xDifference = (float)windowPos.x - (mZuna->GetPosition().x + (Defines::GRID_CELL_SIZE / 2));
		float yDifference = (float)windowPos.y - (mZuna->GetPosition().y + (Defines::GRID_CELL_SIZE / 2));

		if (abs(xDifference) > abs(yDifference))
		{
			if (xDifference > 0.0f)
			{
				mZuna->SetRotation(eRight);
			}
			else
			{
				mZuna->SetRotation(eLeft);
			}
		}
		else
		{
			if (yDifference > 0.0f)
			{
				mZuna->SetRotation(eDown);
			}
			else
			{
				mZuna->SetRotation(eUp);
			}
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && !mWasFPressedLastFrame)
	{
		if (mPopUp->IsTextOpen())
		{
			mPopUp->CycleText();
		}
		else
		{
			mPopUp->OpenText("Assets/Text/Dialogue1.txt", true);
		}

	}
	mWasFPressedLastFrame = sf::Keyboard::isKeyPressed(sf::Keyboard::F);


}
