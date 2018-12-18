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

sf::Vector2f Entity::GetDirection()
{
	return mDirection;
}

Rotation Entity::GetRotation()
{
	return mRotation;
}

bool Entity::IsMoving() const
{
	return mIsMoving;
}

bool Entity::IsSolid() const
{
	return mIsSolid;
}

bool Entity::IsVisible() const
{
	return mIsVisible;
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

void Entity::SetDirection(sf::Vector2f _speed)
{
	mDirection = _speed;
}

void Entity::SetDirection(float _x, float _y)
{
	sf::Vector2f direction = sf::Vector2f(_x, _y);
	SetDirection(direction);
}

void Entity::SetRotation(Rotation _dir)
{
	mRotation = _dir;
}

void Entity::SetIsMoving(bool _result)
{
	mIsMoving = _result;
}

void Entity::SetIsSolid(bool _result)
{
	mIsSolid = _result;
}

void Entity::SetIsVisible(bool _result)
{
	mIsVisible = _result;
}
