#include "Bush.h"



Bush::Bush()
{
	SetIsSolid(false);

	//Sprite
	mTexture.loadFromFile("Assets/Sprites/bush.png");
	//mTexture.loadFromFile("Assets/TestBG.png");
	mSprite.setTexture(mTexture);
}


Bush::~Bush()
{
}

void Bush::Draw(sf::RenderWindow & window)
{
	window.draw(mSprite);
}

void Bush::Update(float dt)
{
	mSprite.setPosition(Entity::GetPosition());
}
