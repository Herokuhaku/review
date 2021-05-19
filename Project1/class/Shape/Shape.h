#pragma once
#include <functional>
#include <utility>
#include <vector>
#include <memory>
#include "../../common/Vector2.h"

#define SCREEN 800
class Shape;
using UniqueShape = std::unique_ptr<Shape>;
using SharedShape = std::shared_ptr<Shape>;
using ShapeVec = std::vector<UniqueShape>;

enum class ShapeType {
	NON,
	Square,
	Circle,
	Triangle,
	Star,
	Heart,
	MAX
};

class Shape
{
public:
	Shape(Float2&& pos,int& num);
	~Shape();

	// Update
	virtual void Update(float delta,ShapeVec& shapes) = 0;
	
	// Draw�n
	// Draw���Ă�
	virtual void Draw(void) = 0;
	// n�{��Draw
	virtual void Draw(float num) = 0;
	// offset�𒆐S�Ɋg�債�ĕ`�悷��
	// 1 : offset , 2 : �g�嗦
	virtual void Draw(Float2 offset, float num = 1);

	// �����蔻��
	virtual bool HitCheck(ShapeVec& shapes);

	virtual ShapeType GetType(void);
private:
	// �����l�ݒ�
	virtual void Init(void);

protected:
	// ���W
	Float2 pos_;
	int mynumber_;
	ShapeType stype_;
	std::function<bool(UniqueShape& shape1, UniqueShape& shape2)> hitCheckShapes_;
};