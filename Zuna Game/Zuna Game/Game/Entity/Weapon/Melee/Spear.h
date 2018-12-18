#pragma once
#include "Base/MeleeWeapon.h"

class Spear : public MeleeWeapon
{
public:
	Spear();
	~Spear();
	void Draw(sf::RenderWindow &window);
	void Update(float dt);

	//Get
	sf::Vector2f GetSpearPosition();

	//Set
	void StartAttack();


private:
	
	float mCurrentActiveTime = 0.0f;
	float mMaxActiveTime = 0.3f;
	bool mPositionSet = false;
	int mDamage = 8;
};

