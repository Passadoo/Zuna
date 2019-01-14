#include "Zuna.h"


Zuna::Zuna()
{
	SetIsSolid(true);

	//Sprite
	//mDownTexture.loadFromFile("Assets/TestSprite.png");
	mTexture.loadFromFile("Assets/TestArrow.png");
	mSprite.setTexture(mTexture);
	mMeleeWeapon = std::make_shared<Spear>();
	mRangedWeapon = std::make_shared<NinjaStarHolder>();
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
		mRangedWeapon->Draw(window);

	}
}

#include <iostream>
void Zuna::Update(float dt)
{
	auto spear = std::dynamic_pointer_cast<Spear>(mMeleeWeapon);
	auto ninjastars = std::dynamic_pointer_cast<NinjaStarHolder>(mRangedWeapon);
	mIsSprinting = false;
	ProcessInput();
	spear->Update(dt);
	ninjastars->Update(dt);

	if(mAllowedToMove)
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
			if (GetPosition().y <= mPositionToMoveTo.y)
			{
				SetIsMoving(false);
				SetDirection(0, 0);
				SetPosition(mPositionToMoveTo);
				mWantsToMove = false;
				mAllowedToMove = false;
			}
		}
		else if (rot == eLeft)
		{
			if (GetPosition().x <= mPositionToMoveTo.x)
			{
				SetIsMoving(false);
				SetDirection(0, 0);
				SetPosition(mPositionToMoveTo);
				mWantsToMove = false;
				mAllowedToMove = false;
			}
			
		}
		else if (rot == eRight)
		{
			if (GetPosition().x >= mPositionToMoveTo.x)
			{
				SetIsMoving(false);
				SetDirection(0, 0);
				SetPosition(mPositionToMoveTo);
				mWantsToMove = false;
				mAllowedToMove = false;
			}
		}
		else if (rot == eDown)
		{
			if (GetPosition().y >= mPositionToMoveTo.y)
			{
				SetIsMoving(false);
				SetDirection(0, 0);
				SetPosition(mPositionToMoveTo);
				mWantsToMove = false;
				mAllowedToMove = false;
			}
		}
	}

	//std::cout << "Grid Cell Position: " << GetGridCellPosition().x << ", " << GetGridCellPosition().y << std::endl;
	mSprite.setPosition(Entity::GetPosition());
}

void Zuna::ProcessInput()
{
	auto spear = std::dynamic_pointer_cast<Spear>(mMeleeWeapon);
	auto ninjastars = std::dynamic_pointer_cast<NinjaStarHolder>(mRangedWeapon);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		mIsSprinting = true;
	}

	if (!spear->IsActive())
	{
		if (!IsMoving())
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				SetDirection(0, -1);
				mMovingDirection = eUp;
				mPositionToMoveTo = sf::Vector2f(GetPosition().x, GetPosition().y - Defines::GRID_CELL_SIZE);
				SetIsMoving(true);
				mWantsToMove = true;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				SetDirection(-1, 0);
				mMovingDirection = eLeft;
				mPositionToMoveTo = sf::Vector2f(GetPosition().x - Defines::GRID_CELL_SIZE, GetPosition().y);
				SetIsMoving(true);
				mWantsToMove = true;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				SetDirection(0, 1);
				mMovingDirection = eDown;
				mPositionToMoveTo = sf::Vector2f(GetPosition().x, GetPosition().y + Defines::GRID_CELL_SIZE);
				SetIsMoving(true);
				mWantsToMove = true;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				SetDirection(1, 0);
				mMovingDirection = eRight;
				mPositionToMoveTo = sf::Vector2f(GetPosition().x + Defines::GRID_CELL_SIZE, GetPosition().y);
				SetIsMoving(true);
				mWantsToMove = true;
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !mMousePressedLastFrame)
			{
				spear->SetPositionAndRotation(GetPosition(), GetRotation());
				spear->StartAttack();
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && !mMousePressedLastFrame)
			{
				ninjastars->SetPosition(GetPosition());
				ninjastars->ShootProjectile(GetRotation());
			}
			mMousePressedLastFrame = (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Mouse::isButtonPressed(sf::Mouse::Right));
		}
	}

}

void Zuna::SetAllowedToMove(bool _result)
{
	mAllowedToMove = _result;
}

std::weak_ptr<MeleeWeapon> Zuna::GetMeleeWeapon()
{
	return mMeleeWeapon;
}

std::weak_ptr<RangedWeapon> Zuna::GetRangedWeapon()
{
	return mRangedWeapon;
}

bool Zuna::WantsToMove() const
{
	return mWantsToMove;
}

sf::Vector2f Zuna::GetPositionToMoveTo() const
{
	return mPositionToMoveTo;
}
