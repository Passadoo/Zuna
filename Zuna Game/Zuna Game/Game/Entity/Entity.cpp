#include "Entity.h"


Entity::Entity()
{
}


Entity::~Entity()
{
}

sf::Vector2f Entity::GetPosition()
{
	return mPosition;
}

sf::Vector2f Entity::GetGridCellPosition() const
{
	return sf::Vector2f((mPosition.x / Defines::GRID_CELL_SIZE), (mPosition.y / Defines::GRID_CELL_SIZE));
}

sf::Vector2f Entity::GetSpeed()
{
	return mSpeed;
}

Rotation Entity::GetRotation()
{
	return mRotation;
}

bool Entity::IsMoving() const
{
	return mIsMoving;
}

void Entity::SetPosition(sf::Vector2f _position)
{
	mPosition = _position;
}

void Entity::SetPosition(float _x, float _y)
{
	sf::Vector2f vec = sf::Vector2f(_x, _y);
	SetPosition(vec);
}

void Entity::SetSpeed(sf::Vector2f _speed)
{
	mSpeed = _speed;
}

void Entity::SetSpeed(float _x, float _y)
{
	sf::Vector2f speed = sf::Vector2f(_x, _y);
	SetSpeed(speed);
}

void Entity::SetRotation(Rotation _dir)
{
	mRotation = _dir;
}

void Entity::SetIsMoving(bool _result)
{
	mIsMoving = _result;
}
