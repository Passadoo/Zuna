#include "RangedWeapon.h"



RangedWeapon::RangedWeapon()
{
}


RangedWeapon::~RangedWeapon()
{
}

void RangedWeapon::ShootProjectile(Rotation _direction)
{
	bool done = false;
	for (int i = 0; i < mMaxNrOfActiveProjectiles & !done; i++)
	{
		if (!mProjectiles[i]->IsActive())
		{
			mProjectiles[i]->SetPosition(mPosition);
			mProjectiles[i]->SetMoveDirection(_direction);
			mProjectiles[i]->SetActive(true);
			done = true;
		}
	}
}

void RangedWeapon::SetPosition(sf::Vector2f _position)
{
	mPosition = _position;
}
