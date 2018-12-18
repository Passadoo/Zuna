#include "NinjaStarHolder.h"



NinjaStarHolder::NinjaStarHolder()
{
	mMaxNrOfActiveProjectiles = 3;
	for (int i = 0; i < mMaxNrOfActiveProjectiles; i++)
	{
		mProjectiles.push_back(std::make_unique<NinjaStar>());
	}
}


NinjaStarHolder::~NinjaStarHolder()
{
}

void NinjaStarHolder::Draw(sf::RenderWindow & window)
{
	for (int i = 0; i < mProjectiles.size(); i++)
	{
		std::dynamic_pointer_cast<NinjaStar>(mProjectiles[i])->Draw(window);
	}
}

void NinjaStarHolder::Update(float dt)
{
	for (int i = 0; i < mProjectiles.size(); i++)
	{
		std::dynamic_pointer_cast<NinjaStar>(mProjectiles[i])->Update(dt);
	}
}
