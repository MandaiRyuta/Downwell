#pragma once
#include "../Constant.h"

class Level;

class LevelsResponsible :
	public Initialize,
	public Clear
{
private:
	LevelsResponsible() : nNowLevel_(0), Level_(nullptr), bChangeScene_(false), bLevelState_(false) {}
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
	void Exit();
public:
	void ChangeLevel(int type);
	const int& GetNowLevel();
	void SetChangeScene(bool bchangescene);
	const bool& GetChengeSceneExist();
	void SetNowLevel(int nlevel);
	const bool& GetLevelState();
	void SetLevelState(bool bstate);
private:
	bool bLevelState_;
	bool bChangeScene_;
	int nNowLevel_;
	Level* Level_;
};