#include "Stage.h"
#include "../Resource/StageDataBase.h"
#include "../Constant.h"

Stage::Stage()
{
	int nx = 0, ny = 0;
	StageDataBase::GetInstance().InitStage();

	for (int type = 0; type < 5; type++)
	{
		for (int y = 0; y < 50; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				ny = y + (type * 50);
				stage_[ny][x] = (StageDataBase::GetInstance().GetStageType(type, x, y));
			}
		}
	}
}

Stage::~Stage()
{
}

void Stage::Update()
{

}

void Stage::Draw()
{
	for (int y = 0; y < 250; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			if (stage_[y][x] == 0)
			{
				DrawBox(125+ x * 20 + 1,-150 + y * 20 + 1, 125 + x * 20 + 20 - 1, -150 + y * 20 + 20 - 1, GetColor(0, 255, 0), true);
			}
			if (stage_[y][x] == 1)
			{
				DrawBox(125 + x * 20 + 1,-150 + y * 20 + 1, 125 + x * 20 + 20 - 1, -150 + y * 20 + 20 - 1, GetColor(255, 0, 0), true);
			}
			if (stage_[y][x] == 2)
			{
				DrawBox(125 + x * 20 + 1,-150 + y * 20 + 1, 125 + x * 20 + 20 - 1, -150 + y * 20 + 20 - 1, GetColor(0, 0, 255), true);
			}
		}
	}
}
