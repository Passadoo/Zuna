#pragma once
#include "Projectile.h"
#include <memory>

class RangedWeapon
{
public:
	RangedWeapon();
	~RangedWeapon();
	void ShootProjectile(Rotation _direction);
	void SetPosition(sf::Vector2f _position);

	virtual void Draw(sf::RenderWindow &window) = 0;
	virtual void Update(float dt) = 0;

protected:
	std::vector<std::shared_ptr<Projectile>> mProjectiles;
	int mMaxNrOfActiveProjectiles = 3;
	int mCurrentNrOfActiveProjectiles = 0;
	sf::Vector2f mPosition;
};

