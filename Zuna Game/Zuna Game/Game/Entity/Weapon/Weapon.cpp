#include "Weapon.h"



Weapon::Weapon()
{
}


Weapon::~Weapon()
{
}

void Weapon::SetPositionAndRotation(sf::Vector2f _position, Rotation _rotation)
{
	SetPosition(_position);
	SetRotation(_rotation);
}

bool Weapon::IsActive()
{
	return mIsActive;
}

int Weapon::GetDamage()const
{
	return mDamage;
}


void Weapon::SetDamage(int _val)
{
	mDamage = _val;
}