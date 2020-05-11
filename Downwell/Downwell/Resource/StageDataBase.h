#pragma once

class StageDataBase
{
private:
	StageDataBase() : Stage_() {}
	~StageDataBase() {}
public:
	static StageDataBase& GetInstance()
	{
		static StageDataBase Inst;
		return Inst;
	}

	void InitStage();
	int GetStageType(int type, int x, int y);
	int Stage_[12][50][20];
};