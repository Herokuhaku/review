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
using VecInt = std::vector<int>;
enum class ShapeType {
	NON,
	Square,
	Circle,
	Triangle,
	Star,
	Heart,
	MAX
};

struct Parameters {
	Parameters() {
		p = Float2(0, 0);
		v = Float2(0, 0);
		s = Float2(0, 0);
	};
	Parameters(Float2 p,Float2 v,Float2 s) {
		Parameters::p = p;
		Parameters::v = v;
		Parameters::s = s;
	};
	// pos
	Float2 p;
	// vec
	Float2 v;
	// size
	Float2 s;
};

using ParamVec = std::vector<Parameters>;
class Shape
{
public:
	Shape();
	Shape(Parameters parm,int num);
	~Shape();

	// Update
	virtual void Update(float delta,ShapeVec& shapes,VecInt& vecint,ParamVec& param) = 0;
	
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
	std::pair<SharedShape&,bool> HitCheck(ShapeVec shapes);
	// �~�̔��莋�o��
	void HitDraw(void);
	// �����蔻��̍폜
	void ClearHitCheck(void);
	// ��]�t���O�𔽓]������
	void ChangeRotaFlag();
	// Drwa�̊g�嗦��ς���t���O
	void ChangeDrawSizeFlag();

	// Change�̒��g���Ă�
	std::pair<double, bool> GetChange(std::string str);

	// Draw�̃T�C�Y��ς���
	void ChangeDrawSize(double plus);
	// Draw�̐F��ς���
	void ChangeColor(void);

	// �X�s�[�h���グ��
	void ChangeVec(float speed,Float2 max = { 300,300 },Float2 min = { 20,20 });

private:
	// �����l�ݒ�
	virtual void Init(void);

protected:
	// ���W
	Float2 pos_;
	Float2 size_;
	Float2 vec_;
	int mynumber_;
	HitPairVec hit_;
	ShapeType stype_;
	int color_;
	std::function<bool(UniqueShape& shape1, UniqueShape& shape2)> hitCheckShapes_;
	
	// �����蔻��
	bool hitnow_;
	bool otherflag;
	bool screenhit_;
	bool allscreenhit_;

	// �g��
	std::map<std::string, std::pair<double, bool>> change_;
	std::pair<double, bool> smooth_;
	int smoothsize_;
	int maxmag_;
	double plusmag_;
};