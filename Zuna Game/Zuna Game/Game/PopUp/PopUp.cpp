#include "PopUp.h"



PopUp::PopUp()
{
	mTexture.loadFromFile("Assets/sprites/PopUpTest.png");
	mSprite.setTexture(mTexture);
}

PopUp::~PopUp()
{
}

sf::Vector2f PopUp::GetPosition() const
{
	return mPosition;
}

sf::Vector2u PopUp::GetTextureSize() const
{
	return mTexture.getSize();
}

void PopUp::SetPosition(sf::Vector2f _pos)
{
	mPosition = _pos;
}

void PopUp::Draw(sf::RenderWindow & window)
{
	window.draw(mSprite);
}

void PopUp::Update(float dt)
{
	mSprite.setPosition(mPosition);
}
