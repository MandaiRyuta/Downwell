#pragma once

class StageDataBase
{
private:
	StageDataBase() {}
	~StageDataBase() {}
public:
	static StageDataBase& GetInstance()
	{
		static StageDataBase Inst;
		return Inst;
	}

	void InitStage();
	int GetStageType(int type, int x, int y);
	int Stage_[10][50][20];
};