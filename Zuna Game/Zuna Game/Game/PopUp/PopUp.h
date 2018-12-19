#pragma once
#include <SFML/Graphics.hpp>
class PopUp
{
public:
	PopUp();
	~PopUp();

	sf::Vector2f GetPosition()const;
	sf::Vector2u GetTextureSize()const;

	void SetPosition(sf::Vector2f _pos);

	virtual void Draw(sf::RenderWindow &window);
	virtual void Update(float dt);

private:
	sf::Sprite mSprite;
	sf::Texture mTexture;

	sf::Vector2f mPosition;

};