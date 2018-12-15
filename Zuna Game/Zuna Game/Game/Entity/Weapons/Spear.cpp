#include "Spear.h"



Spear::Spear()
{
	mTexture.loadFromFile("Assets/SpearTest.png");
	mSprite.setTexture(mTexture);
}


Spear::~Spear()
{
}

void Spear::Draw(sf::RenderWindow & window)
{
	if (mIsActive)
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
	}
}

#include <iostream>

void Spear::Update(float dt)
{
	if (mIsActive)
	{
		mCurrentActiveTime += dt;

		if (mCurrentActiveTime >= mMaxActiveTime)
		{
			mIsActive = false;
		}

		if (!mPositionSet)
		{
			Rotation rot = GetRotation();

			if (rot == eUp)
			{
				SetPosition(GetPosition() + sf::Vector2f(0, -Defines::GRID_CELL_SIZE));
			}
			else if (rot == eLeft)
			{
				SetPosition(GetPosition() + sf::Vector2f(-Defines::GRID_CELL_SIZE, 0));
			}
			else if (rot == eRight)
			{
				SetPosition(GetPosition() + sf::Vector2f(Defines::GRID_CELL_SIZE, 0));
			}
			else if (rot == eDown)
			{
				SetPosition(GetPosition() + sf::Vector2f(0, Defines::GRID_CELL_SIZE));
			}
			mSprite.setPosition(GetPosition());
			mPositionSet = true;
		}
	}
}

void Spear::UpdatePosition(sf::Vector2f _pos, Rotation _rot)
{
	SetPosition(_pos);
	SetRotation(_rot);
}


bool Spear::IsActive()
{
	return mIsActive;
}

int Spear::GetDamage()const
{
	return mDamage;
}

sf::Vector2f Spear::GetSpearPosition()
{
	return GetPosition();
}

void Spear::SetDamage(int _val)
{
	mDamage = _val;
}

void Spear::StartAttack()
{
	mIsActive = true;
	mCurrentActiveTime = 0.0f;
	mPositionSet = false;
}
