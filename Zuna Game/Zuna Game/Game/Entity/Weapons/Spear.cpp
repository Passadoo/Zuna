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
		window.draw(mSprite);
	}
}

void Spear::Update(float dt)
{
	if (mIsActive)
	{
		mCurrentActiveTime += dt;

		if (mCurrentActiveTime >= mMaxActiveTime)
		{
			mIsActive = false;
		}
		else
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

void Spear::SetDamage(int _val)
{
	mDamage = _val;
}

void Spear::StartAttack()
{
	mIsActive = true;
	mCurrentActiveTime = 0.0f;
}
