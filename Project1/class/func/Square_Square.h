#pragma once
#include "../Shape/Shape.h"
#include "../func/HitCheckShapes.h"

struct square_square
{
	bool operator()(UniqueShape& shape1, UniqueShape& shape2) {
		return false;
	}
};