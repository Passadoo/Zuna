#pragma once
#include <SFML\Graphics.hpp>
#include "../Utilities/Defines.h"

class Entity
{
public:
	Entity();
	~Entity();
	virtual void Draw(sf::RenderWindow &window) = 0;
	virtual void Update(float dt) = 0;

	//Get
	sf::Vector2f GetPosition();
	sf::Vector2f GetGridCellPosition()const;
	sf::Vector2f GetSpeed();
	Rotation GetRotation();
	bool IsMoving()const;
	bool IsSolid()const;

	//Set
	void SetPosition(sf::Vector2f _position);
	void SetPosition(float _x, float _y);
	void SetSpeed(sf::Vector2f _speed);
	void SetSpeed(float _x, float _y);
	void SetRotation(Rotation _dir);
	void SetIsMoving(bool _result);
	void SetIsSolid(bool _result);

private:
	bool mIsMoving = false;
	bool mIsSolid = false;
	sf::Vector2f mPosition;
	sf::Vector2f mSpeed;
	Rotation mRotation = eDown;

};

