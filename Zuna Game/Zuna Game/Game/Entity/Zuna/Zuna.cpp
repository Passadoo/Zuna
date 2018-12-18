#include "Zuna.h"


Zuna::Zuna()
{
	SetIsSolid(true);

	//Sprite
	//mDownTexture.loadFromFile("Assets/TestSprite.png");
	mTexture.loadFromFile("Assets/TestArrow.png");
	mSprite.setTexture(mTexture);
	mMeleeWeapon = std::make_shared<Spear>();
}


Zuna::~Zuna()
{
}

void Zuna::Draw(sf::RenderWindow & window)
{
	if (IsVisible())
	{
		Rotation rot = GetRotation();
		sf::Transform transform;

		if (rot == eUp)
		{
			transform.rotate(0, GetPosition().x + (Defines::GRID_CELL_SIZE / 2), GetPosition().y + (Defines::GRID_CELL_SIZE / 2));
		}
		else if (rot == eLeft)
		{
			transform.rotate(270, GetPosition().x + (Defines::GRID_CELL_SIZE / 2), GetPosition().y + (Defines::GRID_CELL_SIZE / 2));
		}
		else if (rot == eRight)
		{
			transform.rotate(90, GetPosition().x + (Defines::GRID_CELL_SIZE / 2), GetPosition().y + (Defines::GRID_CELL_SIZE / 2));
		}
		else if (rot == eDown)
		{
			transform.rotate(180, GetPosition().x + (Defines::GRID_CELL_SIZE / 2), GetPosition().y + (Defines::GRID_CELL_SIZE / 2));
		}
		window.draw(mSprite, transform);
		mMeleeWeapon->Draw(window);

	}
}

void Zuna::Update(float dt)
{
	auto spear = std::dynamic_pointer_cast<Spear>(mMeleeWeapon);
	mIsSprinting = false;
	ProcessInput();
	spear->Update(dt);

	if(IsMoving())
	{
		if (mIsSprinting)
		{
			SetPosition(sf::Vector2f((GetPosition().x) + (GetDirection().x * mMovementSpeed * dt * 2), (GetPosition().y + (GetDirection().y * mMovementSpeed * dt * 2))));
		}
		else
		{
			SetPosition(sf::Vector2f((GetPosition().x) + (GetDirection().x * mMovementSpeed * dt), (GetPosition().y + (GetDirection().y * mMovementSpeed * dt))));
		}

		Rotation rot = mMovingDirection;

		if (rot == eUp)
		{
			if (GetPosition().y <= mPositionToMoveTo)
			{
				SetIsMoving(false);
				SetDirection(0, 0);
				SetPosition(GetPosition().x, mPositionToMoveTo);
			}
		}
		else if (rot == eLeft)
		{
			if (GetPosition().x <= mPositionToMoveTo)
			{
				SetIsMoving(false);
				SetDirection(0, 0);
				SetPosition(mPositionToMoveTo, GetPosition().y);
			}
			
		}
		else if (rot == eRight)
		{
			if (GetPosition().x >= mPositionToMoveTo)
			{
				SetIsMoving(false);
				SetDirection(0, 0);
				SetPosition(mPositionToMoveTo, GetPosition().y);
			}
			
		}
		else if (rot == eDown)
		{
			if (GetPosition().y >= mPositionToMoveTo)
			{
				SetIsMoving(false);
				SetDirection(0, 0);
				SetPosition(GetPosition().x, mPositionToMoveTo);
			}
		}
	}

	//std::cout << "Grid Cell Position: " << GetGridCellPosition().x << ", " << GetGridCellPosition().y << std::endl;
	mSprite.setPosition(Entity::GetPosition());
}

void Zuna::ProcessInput()
{
	auto spear = std::dynamic_pointer_cast<Spear>(mMeleeWeapon);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		mIsSprinting = true;
	}

	if (!std::dynamic_pointer_cast<Spear>(spear)->IsActive())
	{
		if (!IsMoving())
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				SetDirection(0, -1);
				SetIsMoving(true);
				mMovingDirection = eUp;
				mPositionToMoveTo = GetPosition().y - Defines::GRID_CELL_SIZE;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				SetDirection(-1, 0);
				SetIsMoving(true);
				mMovingDirection = eLeft;
				mPositionToMoveTo = GetPosition().x - Defines::GRID_CELL_SIZE;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				SetDirection(0, 1);
				SetIsMoving(true);
				mMovingDirection = eDown;
				mPositionToMoveTo = GetPosition().y + Defines::GRID_CELL_SIZE;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				SetDirection(1, 0);
				SetIsMoving(true);
				mMovingDirection = eRight;
				mPositionToMoveTo = GetPosition().x + Defines::GRID_CELL_SIZE;
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
					spear->SetPositionAndRotation(GetPosition(), GetRotation());
					spear->StartAttack();
			}
		}
	}
}

std::weak_ptr<MeleeWeapon> Zuna::GetMeleeWeapon()
{
	return mMeleeWeapon;
}
