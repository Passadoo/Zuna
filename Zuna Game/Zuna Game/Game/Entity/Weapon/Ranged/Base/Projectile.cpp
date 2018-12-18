#include "Projectile.h"



Projectile::Projectile()
{
}


Projectile::~Projectile()
{
}

void Projectile::Update(float dt)
{
	if (mIsActive)
	{
		mCurrentLifeTime += dt;

		if (mCurrentLifeTime >= mMaxLifeTime)
		{
			mIsActive = false;
			mCurrentLifeTime = 0.0f;
		}

		//Movement
		SetPosition(sf::Vector2f((GetPosition().x) + (MathFunctions::GetRotationAsVector2f(mMovingDirection).x * mMovementSpeed * dt), (GetPosition().y + (MathFunctions::GetRotationAsVector2f(mMovingDirection).y * mMovementSpeed * dt))));
	}
}

Rotation Projectile::GetMoveDirection() const
{
	return mMovingDirection;
}

bool Projectile::IsActive() const
{
	return mIsActive;
}

void Projectile::SetMoveDirection(Rotation _rot)
{
	mMovingDirection = _rot;
}

void Projectile::SetActive(bool _result)
{
	mIsActive = _result;
}
