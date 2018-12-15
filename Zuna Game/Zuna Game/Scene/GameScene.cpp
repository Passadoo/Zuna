#include "GameScene.h"


GameScene::GameScene()
{
	mGrassTiles.resize(Defines::WORLD_WIDTH);

	for (int i = 0; i < Defines::WORLD_WIDTH; i++)
	{
		for (int j = 0; j < Defines::WORLD_HEIGHT; j++)
		{
			mGrassTiles[i].push_back(std::make_unique<Grass>());
			mGrassTiles[i].back()->SetPosition((i * Defines::GRID_CELL_SIZE), (j * Defines::GRID_CELL_SIZE));
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
	for (int i = 0; i < mGrassTiles.size(); i++)
	{
		for (int j = 0; j < mGrassTiles[i].size(); j++)
		{
			mGrassTiles[i][j]->Draw(window);
		}
	}
	
	mZuna->Draw(window);
}

void GameScene::Update(float dt)
{
	for (int i = 0; i < mGrassTiles.size(); i++)
	{
		for (int j = 0; j < mGrassTiles[i].size(); j++)
		{
			mGrassTiles[i][j]->Update(dt);
		}
	}

	mZuna->Update(dt);
}
