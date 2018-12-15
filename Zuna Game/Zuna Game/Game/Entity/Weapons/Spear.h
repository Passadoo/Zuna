#pragma once
#include "../Entity.h"

class Spear : public Entity
{
public:
	Spear();
	~Spear();
	void Draw(sf::RenderWindow &window);
	void Update(float dt);
	void UpdatePosition(sf::Vector2f _pos, Rotation _rot);

	//Get
	bool IsActive();
	int GetDamage()const;

	//Set
	void SetDamage(int _val);
	void StartAttack();


private:
	int mDamage = 5;
	
	float mCurrentActiveTime = 0.0f;
	float mMaxActiveTime = 1.0f;
	bool mIsActive = false;

	sf::Sprite mSprite;
	sf::Texture mTexture;
};

