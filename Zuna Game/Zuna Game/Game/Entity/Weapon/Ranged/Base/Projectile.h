#pragma once
#include "../../../Entity.h"
#include "../../../../Utilities/MathFunctions.h"

class Projectile : public Entity
{
public:
	Projectile();
	~Projectile();

	virtual void Draw(sf::RenderWindow &window) = 0;
	void Update(float dt);

	Rotation GetMoveDirection()const;
	bool IsActive()const;

	void SetMoveDirection(Rotation _rot);
	void SetActive(bool _result);

protected:
	int mDamage = 5;
	float mMovementSpeed = 14000.f / (float)Defines::GRID_CELL_SIZE;
	Rotation mMovingDirection;
	float mCurrentLifeTime = 0.0f;
	float mMaxLifeTime = 3.0f;
	bool mIsActive = false;
};

