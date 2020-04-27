#pragma once
#include "../Constant.h"

class Level;

class LevelsResponsible :
	public Initialize,
	public Clear
{
private:
	LevelsResponsible() {}
	~LevelsResponsible() {}
public:
	static LevelsResponsible& GetInstance()
	{
		static LevelsResponsible Inst;
		return Inst;
	}
public:
	virtual void Init() override;
	void Update();
	void Draw();
	virtual void Release() override;
public:
	void ChangeLevel(int type);
	int& GetNowLevel();
private:
	int NowLevel_;
	Level* Level_;
};