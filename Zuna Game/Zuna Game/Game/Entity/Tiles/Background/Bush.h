#pragma once
#include "../../Game/Entity/Entity.h"

class Bush : public Entity
{
public:
	Bush();
	~Bush();
	void Draw(sf::RenderWindow &window);
	void Update(float dt);

private:
	sf::Sprite mSprite;
	sf::Texture mTexture;

};

