#pragma once
#include <SFML/Graphics.hpp>

enum Rotation
{
	eUp = 0,
	eDown,
	eLeft,
	eRight
};

class Defines
{
public:


	//Grid
	static int GRID_CELL_SIZE;
	static int WORLD_WIDTH;
	static int WORLD_HEIGHT;
};