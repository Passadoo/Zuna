#include "Rock.h"



Rock::Rock()
{
	SetIsSolid(true);

	//Sprite
	mTexture.loadFromFile("Assets/Sprites/rock.png");
	mSprite.setTexture(mTexture);
	mSprite.setPosition(Entity::GetPosition());
}


Rock::~Rock()
{
}

void Rock::Draw(sf::RenderWindow &window)
{
	window.draw(mSprite);
}


void Rock::Update(float dt)
{
	mSprite.setPosition(Entity::GetPosition());
}