#pragma once
#include "../../../Entity.h"

class Projectile : public Entity
{
public:
	Projectile();
	~Projectile();

	virtual void Draw(sf::RenderWindow &window) = 0;
	virtual void Update(float dt) = 0;

	Rotation GetMoveDirection()const;

	void SetMoveDirection(Rotation _rot);


protected:
	int mDamage = 5;
	float mMovementSpeed = 14000.f / (float)Defines::GRID_CELL_SIZE;
	Rotation mMovingDirection;
	float mLifeSpan = 3.0f;

};

