#include "Zuna.h"


Zuna::Zuna()
{
	mDownTexture.loadFromFile("Assets/TestSprite.png");
	mSprite.setTexture(mDownTexture);
	mSpear = std::make_unique<Spear>();
}


Zuna::~Zuna()
{
}

void Zuna::Draw(sf::RenderWindow & window)
{
	window.draw(mSprite);
}

#include <iostream>

void Zuna::Update(float dt)
{
	mSpear->UpdatePosition(GetPosition(), GetRotation());
	ProcessInput(dt);

	if(IsMoving())
	{
		SetPosition(sf::Vector2f((GetPosition().x) + (GetSpeed().x * mMovementSpeed * dt), (GetPosition().y + (GetSpeed().y * mMovementSpeed * dt))));

		if (fmod(GetPosition().x, Defines::GRID_CELL_SIZE) == 0 && fmod(GetPosition().y, Defines::GRID_CELL_SIZE) == 0)
		{
			SetIsMoving(false);
			SetSpeed(0, 0);
		}
	}

	//std::cout << "Grid Cell Position: " << GetGridCellPosition().x << ", " << GetGridCellPosition().y << std::endl;
	mSprite.setPosition(Entity::GetPosition());
}

void Zuna::ProcessInput(float dt)
{
	if (!IsMoving())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			SetSpeed(0, -1);
			SetIsMoving(true);
			SetRotation(eUp);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			SetSpeed(-1, 0);
			SetIsMoving(true);
			SetRotation(eLeft);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			SetSpeed(0, 1);
			SetIsMoving(true);
			SetRotation(eDown);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			SetSpeed(1, 0);
			SetIsMoving(true);
			SetRotation(eRight);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			mSpear->StartAttack();
		}

		SetPosition(sf::Vector2f((GetPosition().x) + (GetSpeed().x * mMovementSpeed * dt), (GetPosition().y + (GetSpeed().y * mMovementSpeed * dt))));
	}
}
