#include <utility>
#include "Heart.h"

Heart::Heart(Float2&& pos, int&& size) :Shape(std::move(pos))
{
	pos_ = pos;
	size_ = size;
}

Heart::~Heart()
{
}

void Heart::Update(double delta)
{
}

void Heart::Draw(void)
{
}

void Heart::Draw(float num)
{
}

void Heart::Draw(Float2 offset, float num)
{
}
