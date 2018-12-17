#pragma once
#include "../Entity.h"

class Weapon : public Entity
{
public:
	Weapon();
	~Weapon();
	virtual void Draw(sf::RenderWindow &window) = 0;
	virtual void Update(float dt) = 0;

	void SetPositionAndRotation(sf::Vector2f _position, Rotation _rotation);

	//Get
	bool IsActive();
	int GetDamage()const;

	//Set
	void SetDamage(int _val);
	virtual void StartAttack() = 0;

private:


protected:
	bool mIsActive = false;
	int mDamage;
	sf::Sprite mSprite;
	sf::Texture mTexture;
};

