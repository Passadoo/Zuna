#pragma once
#include "NinjaStar.h"
#include "Base/RangedWeapon.h"

class NinjaStarHolder : public RangedWeapon
{
public:
	NinjaStarHolder();
	~NinjaStarHolder();
	virtual void Draw(sf::RenderWindow &window);
	virtual void Update(float dt);

private:


};

