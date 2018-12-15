#include "Zuna.h"


Zuna::Zuna()
{
	SetIsSolid(true);

	//Sprite
	mDownTexture.loadFromFile("Assets/TestSprite.png");
	mSprite.setTexture(mDownTexture);
	mSpear = std::make_unique<Spear>();
}


Zuna::~Zuna()
{
}

void Zuna::Draw(sf::RenderWindow & window)
{
	mSpear->Draw(window);
	window.draw(mSprite);
}

void Zuna::Update(float dt)
{
	mIsSprinting = false;
	ProcessInput(dt);
	mSpear->Update(dt);

	if(IsMoving())
	{
		if (mIsSprinting)
		{
			SetPosition(sf::Vector2f((GetPosition().x) + (GetSpeed().x * mMovementSpeed * dt * 2), (GetPosition().y + (GetSpeed().y * mMovementSpeed * dt * 2))));
		}
		else
		{
			SetPosition(sf::Vector2f((GetPosition().x) + (GetSpeed().x * mMovementSpeed * dt), (GetPosition().y + (GetSpeed().y * mMovementSpeed * dt))));
		}

		Rotation rot = GetRotation();

		if (rot == eUp)
		{
			if (GetPosition().y <= mPositionToMoveTo)
			{
				SetIsMoving(false);
				SetSpeed(0, 0);
				SetPosition(GetPosition().x, mPositionToMoveTo);
			}
		}
		else if (rot == eLeft)
		{
			if (GetPosition().x <= mPositionToMoveTo)
			{
				SetIsMoving(false);
				SetSpeed(0, 0);
				SetPosition(mPositionToMoveTo, GetPosition().y);
			}
			
		}
		else if (rot == eRight)
		{
			if (GetPosition().x >= mPositionToMoveTo)
			{
				SetIsMoving(false);
				SetSpeed(0, 0);
				SetPosition(mPositionToMoveTo, GetPosition().y);
			}
			
		}
		else if (rot == eDown)
		{
			if (GetPosition().y >= mPositionToMoveTo)
			{
				SetIsMoving(false);
				SetSpeed(0, 0);
				SetPosition(GetPosition().x, mPositionToMoveTo);
			}
		}
	}

	//std::cout << "Grid Cell Position: " << GetGridCellPosition().x << ", " << GetGridCellPosition().y << std::endl;
	mSprite.setPosition(Entity::GetPosition());
}

void Zuna::ProcessInput(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		mIsSprinting = true;
	}

	if (!mSpear->IsActive())
	{
		if (!IsMoving())
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				SetSpeed(0, -1);
				SetIsMoving(true);
				SetRotation(eUp);
				mPositionToMoveTo = GetPosition().y - Defines::GRID_CELL_SIZE;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				SetSpeed(-1, 0);
				SetIsMoving(true);
				SetRotation(eLeft);
				mPositionToMoveTo = GetPosition().x - Defines::GRID_CELL_SIZE;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				SetSpeed(0, 1);
				SetIsMoving(true);
				SetRotation(eDown);
				mPositionToMoveTo = GetPosition().y + Defines::GRID_CELL_SIZE;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				SetSpeed(1, 0);
				SetIsMoving(true);
				SetRotation(eRight);
				mPositionToMoveTo = GetPosition().x + Defines::GRID_CELL_SIZE;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				mSpear->UpdatePosition(GetPosition(), GetRotation());
				mSpear->StartAttack();
			}

			if (mIsSprinting)
			{
				SetPosition(sf::Vector2f((GetPosition().x) + (GetSpeed().x * mMovementSpeed * dt * 2), (GetPosition().y + (GetSpeed().y * mMovementSpeed * dt * 2))));
			}
			else
			{
				SetPosition(sf::Vector2f((GetPosition().x) + (GetSpeed().x * mMovementSpeed * dt), (GetPosition().y + (GetSpeed().y * mMovementSpeed * dt))));
			}
			
		}
	}
}
