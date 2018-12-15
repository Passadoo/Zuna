#pragma once
#include <tuple>

class MathFunctions
{
public:
	static int RandomIntRange(int _lower, int _upper)
	{
		return _lower + rand() % (_upper - _lower + 1);
	}



};