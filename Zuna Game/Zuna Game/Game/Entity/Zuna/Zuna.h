#pragma once
#include "../../Game/Entity/Entity.h"
#include "../Weapon/Melee/Spear.h"
#include "../Weapon/Ranged/NinjaStarHolder.h"
#include <memory>

class Zuna : public Entity
{
public:
	Zuna();
	~Zuna();
	void Draw(sf::RenderWindow &window);
	void Update(float dt);
	void ProcessInput();

	std::weak_ptr<MeleeWeapon> GetMeleeWeapon();


private:
	//Health
	int mCurrentHealth;
	int mMaximumHealth;

	//Movement
	int mMovementSpeed = 9000 / Defines::GRID_CELL_SIZE;
	float mPositionToMoveTo;
	Rotation mMovingDirection;
	bool mIsSprinting = false;
	int mCurrentStamina;
	int mMaximumStamina;

	//Damage
	std::shared_ptr<MeleeWeapon> mMeleeWeapon;
	std::shared_ptr<RangedWeapon> mRangedWeapon;
	bool mMousePressedLastFrame = false;

	sf::Texture mTexture;
	sf::Sprite mSprite;
};