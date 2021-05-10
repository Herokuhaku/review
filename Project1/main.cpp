#include <DxLib.h>
#include <memory>
#include "class/Shape.h"
#include "class/Square.h"

bool SysInit()
{
	SetGraphMode(800, 800, 32);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1){
		return false;
	}
	return true;
}

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	if (!SysInit()){
		return 0;
	}
	// Square��Draw��`�悷��
	// square��make_unique�ō��
	std::unique_ptr<Shape> shape(std::make_unique<Square>(Float2(400, 400), Float2(50, 50)));
	// new �ō��
	std::unique_ptr<Shape> shape_(new Square(Float2(400,400),Float2(50,50)));
	// ���ɂ������珊�L����Ⴄ
	std::unique_ptr<Shape> shape__(std::move(shape_));
	// ���L���n������ɋ�ɂȂ��Ă�̂ō���Ƃ�
	shape_.reset(new Square(Float2(100, 100), Float2(50, 50)));

	std::unique_ptr<Shape> test;
	test = std::make_unique<Square>(Float2(400,400),Float2(50,50));
	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClearDrawScreen();
		shape__->Draw(Float2(25, 25), 2);
		shape__->Draw();
		DrawLine(0-1,400-1,800-1,400-1,0xff0000);
		DrawLine(400-1,0-1, 400-1, 800-1, 0xff0000);
		
		ScreenFlip();
	}

	return 1;
}