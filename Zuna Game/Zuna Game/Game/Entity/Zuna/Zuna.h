#pragma once
#include "../../Game/Entity/Entity.h"
#include "../Weapons/Spear.h"
#include <memory>

class Zuna : public Entity
{
public:
	Zuna();
	~Zuna();
	void Draw(sf::RenderWindow &window);
	void Update(float dt);
	void ProcessInput(float dt);


private:
	//Health
	int mCurrentHealth;
	int mMaximumHealth;

	//Movement
	int mMovementSpeed = 400 / Defines::GRID_CELL_SIZE;
	int mCurrentStamina;
	int mMaximumStamina;

	//Damage
	std::unique_ptr<Spear> mSpear;
	int mMeleeDamage;
	int mRangedDamage;
	int mCriticalHitChance; 

	sf::Texture mLeftTexture;
	sf::Texture mRightTexture;
	sf::Texture mDownTexture;
	sf::Texture mUpTexture;
	sf::Sprite mSprite;


};