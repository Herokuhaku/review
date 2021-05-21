#pragma once
#include <functional>
#include <utility>
#include <vector>
#include <memory>
#include <map>
#include "../../common/Vector2.h"

#define SCREEN 800
class Shape;
using UniqueShape = std::unique_ptr<Shape>;
using SharedShape = std::shared_ptr<Shape>;
using ShapeVec = std::vector<SharedShape>;
using HitPair = std::pair<Float2, int>;
using HitPairVec = std::vector<HitPair>;
using HitCircle = std::map<int,HitPairVec>;

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
	Shape(Float2&& pos,Float2& vec,int num);
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


	// �`
	virtual ShapeType GetType(void);
	// �q�b�g�{�b�N�X�Ăяo��
	virtual HitPairVec GetHitPairVec(void);
	// �����̐����ԍ��Ăяo��
	virtual int GetMynum(void);

	// �����蔻��
	std::pair<SharedShape&,bool> HitCheck(ShapeVec& shapes);
	// �~�̔��莋�o��
	void HitDraw(void);
	// �����蔻��̍폜
	void ClearHitCheck(void);

	void SetRotaFlag_();
private:
	// �����l�ݒ�
	virtual void Init(void);

protected:
	// ���W
	Float2 pos_;
	Float2 vec_;
	int mynumber_;
	HitPairVec hit_;
	ShapeType stype_;
	int color_;
	std::function<bool(UniqueShape& shape1, UniqueShape& shape2)> hitCheckShapes_;
	bool hitnow_;
	bool otherflag;
	bool screenhit_;
	bool allscreenhit_;

	//
	double rota_;
	bool rotaflag_;
};