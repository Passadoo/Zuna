#include "Projectile.h"



Projectile::Projectile()
{
}


Projectile::~Projectile()
{
}

Rotation Projectile::GetMoveDirection() const
{
	return mMovingDirection;
}

void Projectile::SetMoveDirection(Rotation _rot)
{
	mMovingDirection = _rot;
}
