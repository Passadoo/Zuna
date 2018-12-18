#pragma once
#include <tuple>
#include "SFML/Graphics.hpp"
#include "Defines.h"

class MathFunctions
{
public:
	static int RandomIntRange(int _lower, int _upper)
	{
		return _lower + rand() % (_upper - _lower + 1);
	}

	static sf::Vector2f GetRotationAsVector2f(Rotation _rot)
	{
		sf::Vector2f result;

		if (_rot == eUp)
		{
			result = sf::Vector2f(0.0f, -1.0f);
		}
		else if (_rot == eDown)
		{
			result = sf::Vector2f(0.0f, 1.0f);
		}
		else if (_rot == eLeft)
		{
			result = sf::Vector2f(-1.0f, 0.0f);
		}
		else
		{
			result = sf::Vector2f(1.0f, 0.0f);
		}

		return result;
	}

	static Rotation GetVector2fAsRotation(sf::Vector2f _vec)
	{
		Rotation result;

		if (_vec.x == 0.0f && _vec.y == 1.0f)
		{
			result = eDown;
		}
		else if (_vec.x == 0.0f && _vec.y == -1.0f)
		{
			result == eUp;
		}
		else if (_vec.x == 1.0f && _vec.y == 0.0f)
		{
			result == eRight;
		}
		else if (_vec.x == -1.0f && _vec.y == 0.0f)
		{
			result == eLeft;
		}

		return result;
	}

};