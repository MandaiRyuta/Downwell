#pragma once
#include "Level.h"
#include "../Constant.h"
#include "../Actor/Actor.h"
#include "../Widget/Widget.h"

class GameLevel : public Level
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	/// <param name="type">�V�[���ԍ�</param>
	GameLevel(int type);
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~GameLevel();
public:
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// �`��֐�
	/// </summary>
	virtual void Draw() override;

private:
	int nNowLevel_;	//���݂̃V�[���ԍ�
	std::list<Actor*> Obj_[3];	//Actor���
	std::list<Widget*> Widgetobj_[3];	//Widget���
};