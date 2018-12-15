#pragma once
#include "../../Game/Entity/Entity.h"

class Grass : public Entity
{
public:
	Grass();
	~Grass();
	void Draw(sf::RenderWindow &window);
	void Update(float dt);

private:
	sf::Sprite mSprite;
	sf::Texture mTexture;

};

