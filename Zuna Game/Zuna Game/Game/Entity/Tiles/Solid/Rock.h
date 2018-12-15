#pragma once
#include "../../Game/Entity/Entity.h"

class Rock : public Entity
{
public:
	Rock();
	~Rock();
	void Draw(sf::RenderWindow &window);
	void Update(float dt);

private:
	sf::Texture mTexture;
	sf::Sprite mSprite;

};

