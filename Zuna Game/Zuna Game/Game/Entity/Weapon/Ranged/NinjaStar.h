#pragma once
#include "Base/Projectile.h"

class NinjaStar : public Projectile
{
public:
	NinjaStar();
	~NinjaStar();
	virtual void Draw(sf::RenderWindow &window);
	virtual void Update(float dt);

private:
	sf::Sprite mSprite;
	sf::Texture mTexture1;
	sf::Texture mTexture2;
	sf::Texture mTexture3;

	float mTextureChangeTime = 0.0f;
	int mCurrentTextureNr = 1;
};

