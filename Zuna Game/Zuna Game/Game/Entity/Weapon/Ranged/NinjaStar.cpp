#include "NinjaStar.h"



NinjaStar::NinjaStar()
{
	mTexture1.loadFromFile("Assets/sprites/NinjaStar1.png");
	mTexture2.loadFromFile("Assets/sprites/NinjaStar2.png");
	mTexture3.loadFromFile("Assets/sprites/NinjaStar3.png");
	mTexture3.loadFromFile("Assets/sprites/NinjaStar4.png");

	mSprite.setTexture(mTexture1);
}


NinjaStar::~NinjaStar()
{
}

void NinjaStar::Draw(sf::RenderWindow & window)
{
	window.draw(mSprite);
}

void NinjaStar::Update(float dt)
{
	//Movement
	if (mMovingDirection == eUp)
	{
		SetPosition(sf::Vector2f((GetPosition().x) + (GetDirection().x * mMovementSpeed * dt), (GetPosition().y + (GetDirection().y * mMovementSpeed * dt))));
	}


	//Sprite changing
	mTextureChangeTime += dt;

	if (mTextureChangeTime >= 0.3f)
	{
		if (mCurrentTextureNr == 1)
		{
			mCurrentTextureNr = 2;
			mSprite.setTexture(mTexture2);
		}
		else if (mCurrentTextureNr == 2)
		{
			mCurrentTextureNr = 3;
			mSprite.setTexture(mTexture3);
		}
		else if (mCurrentTextureNr == 3)
		{
			mCurrentTextureNr = 4;
			mSprite.setTexture(mTexture4);
		}
		else if (mCurrentTextureNr == 4)
		{
			mCurrentTextureNr = 1;
			mSprite.setTexture(mTexture1);
		}
		mTextureChangeTime = 0.0f;
	}
}
