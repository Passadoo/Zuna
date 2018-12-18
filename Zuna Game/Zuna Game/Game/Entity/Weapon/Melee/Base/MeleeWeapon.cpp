#include "MeleeWeapon.h"



MeleeWeapon::MeleeWeapon()
{
}


MeleeWeapon::~MeleeWeapon()
{
}

void MeleeWeapon::SetPositionAndRotation(sf::Vector2f _position, Rotation _rotation)
{
	SetPosition(_position);
	SetRotation(_rotation);
}

bool MeleeWeapon::IsActive()
{
	return mIsActive;
}

int MeleeWeapon::GetDamage()const
{
	return mDamage;
}


void MeleeWeapon::SetDamage(int _val)
{
	mDamage = _val;
}