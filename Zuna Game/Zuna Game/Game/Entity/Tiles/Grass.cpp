#include "Grass.h"


Grass::Grass()
{
	mTexture.loadFromFile("Assets/TestBG.png");
	mSprite.setTexture(mTexture);
}


Grass::~Grass()
{
}

void Grass::Draw(sf::RenderWindow & window)
{
	window.draw(mSprite);
}

void Grass::Update(float dt)
{
	mSprite.setPosition(Entity::GetPosition());
}
