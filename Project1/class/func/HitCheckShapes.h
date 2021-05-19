#pragma once
#include "../Shape/Shape.h"
#include "Square_Square.h"

struct hitcheck
{
	bool operator()(UniqueShape& shape1,UniqueShape& shape2) {
		ShapeType stype1,stype2;
		stype1 = shape1->GetType();
		stype2 = shape2->GetType();

		switch (stype1)
		{
		case ShapeType::Square:
			switch (stype2)
			{
				case ShapeType::Square:
					return square_square()(shape1,shape2);
			}
			break;
		case ShapeType::Circle:
			break;
		case ShapeType::Triangle:
			break;
		case ShapeType::Star:
			break;
		case ShapeType::Heart:
			break;
		default:
			break;
		}
		return false;
	}
};