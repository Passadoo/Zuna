#pragma once
#include "../../Game/Entity/Entity.h"
#include "../Weapon/Spear.h"
#include <memory>

class Zuna : public Entity
{
public:
	Zuna();
	~Zuna();
	void Draw(sf::RenderWindow &window);
	void Update(float dt);
	void ProcessInput();

	std::weak_ptr<Weapon> GetWeapon();


private:
	//Health
	int mCurrentHealth;
	int mMaximumHealth;

	//Movement
	int mMovementSpeed = 9000 / Defines::GRID_CELL_SIZE;
	float mPositionToMoveTo;
	bool mIsSprinting = false;
	int mCurrentStamina;
	int mMaximumStamina;

	//Damage
	std::shared_ptr<Weapon> mWeapon;
	int mMeleeDamage;
	int mRangedDamage;
	int mCriticalHitChance; 

	sf::Texture mLeftTexture;
	sf::Texture mRightTexture;
	sf::Texture mDownTexture;
	sf::Texture mUpTexture;
	sf::Sprite mSprite;


};