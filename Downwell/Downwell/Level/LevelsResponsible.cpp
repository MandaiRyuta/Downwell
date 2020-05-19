#include "LevelsResponsible.h"
#include "GameLevel.h"
#include "../Resource/TextureData.h"
#include "../Input/Input.h"
#include "../Actor/Character.h"

/// <summary>
/// �������֐�
/// </summary>
void LevelsResponsible::Init()
{
	bLevelState_ = false;
	nNowLevel_ = nTitleLevel;
	bChangeLevel_ = false;
	TextureDataBase::TextureData::GetInstance().Init();
	nNowStage_ = nFirstStage;
	Level_ = new GameLevel(nTitleLevel);
}
/// <summary>
/// �X�V�֐�
/// </summary>
void LevelsResponsible::Update()
{
	if (nNowLevel_ == 2 && bChangeLevel_ == false)
	{
		if (Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x001)
		{
			nNowLevel_ = 0;
			bChangeLevel_ = true;
		}
	}
	     
	if (bChangeLevel_)
	{
		switch (nNowLevel_)
		{
		case 0:
			ChangeLevel(0);
			bChangeLevel_ = false;
			break;
		case 1:
			ChangeLevel(1);
			bChangeLevel_ = false;
			break;
		case 2:
			ChangeLevel(2);
			bChangeLevel_ = false;
			break;
		default:
			break;
		}
	}

	if (Level_ == nullptr) return;

	if (nNowLevel_ == 1)
	{
		Quadtree_[0].x = 0.0f;
		Quadtree_[0].y = Character::GetPos().y + 0.0f;
		Quadtree_[0].width = Character::GetPos().x + static_cast<float>(ScreenWidth) * 0.5f;
		Quadtree_[0].height = ScreenHeight * 0.5f;

		Quadtree_[1].x = (static_cast<float>(ScreenWidth) * 0.5f) + Character::GetPos().x;
		Quadtree_[1].y = (static_cast<float>(-ScreenHeight) * 0.5f) + Character::GetPos().y;
		Quadtree_[1].width = static_cast<float>(ScreenWidth) * 0.5f;
		Quadtree_[1].height = static_cast<float>(ScreenHeight) * 0.5f;

		Quadtree_[2].x = 0.0f;
		Quadtree_[2].y = (static_cast<float>(-ScreenHeight) * 0.5f) + Character::GetPos().y;
		Quadtree_[2].width = Character::GetPos().x + static_cast<float>(ScreenWidth) * 0.5f;
		Quadtree_[2].height = static_cast<float>(ScreenHeight) * 0.5f;
		
		Quadtree_[3].x = (static_cast<float>(ScreenWidth) * 0.5f) + Character::GetPos().x;
		Quadtree_[3].y = 0.0f + Character::GetPos().y;
		Quadtree_[3].width = static_cast<float>(ScreenWidth) * 0.5f;
		Quadtree_[3].height = static_cast<float>(ScreenHeight) * 0.5f;
	}

	Level_->Update();
}
/// <summary>
/// �`��֐�
/// </summary>
void LevelsResponsible::Draw()
{
	if (Level_ == nullptr) return;
	Level_->Draw();
}
/// <summary>
/// ����֐�
/// </summary>
void LevelsResponsible::Release()
{
	delete Level_;
}
/// <summary>
/// �I���֐�
/// </summary>
void LevelsResponsible::Exit()
{
	nNowLevel_ = nMaxLevel;
}
/// <summary>
/// ���x���؂�ւ��֐�
/// </summary>
/// <param name="type">�؂�ւ��������x��</param>
void LevelsResponsible::ChangeLevel(int type)
{
	if (Level_ != nullptr)
	{
		delete Level_;
	}

	auto chengelevel = [](int type)
	{
		switch (type)
		{
		case 0:
			return new GameLevel(type);
			break;
		case 1:
			return new GameLevel(type);
			break;
		case 2:
			return new GameLevel(type);
			break;
		default:
			return new GameLevel(0);
			break;
		}
	};

	Level_ = chengelevel(type);
}
/// <summary>
/// ���x���擾�֐�
/// </summary>
/// <returns>���݂̃��x��</returns>
const int& LevelsResponsible::GetNowLevel()
{
	return nNowLevel_;
}
/// <summary>
/// ���x���؂�ւ��t���O�ݒ�֐�
/// </summary>
/// <param name="bchangescene">	true : �؂�ւ���	false : �؂�ւ��Ȃ�</param>
void LevelsResponsible::SetChangeLevel(bool bchangescene)
{
	bChangeLevel_ = bchangescene;
}
/// <summary>
/// ���x���؂�ւ��t���O�擾�֐�
/// </summary>
/// <returns>���x���؂�ւ��t���O</returns>
const bool& LevelsResponsible::GetChengeLevelExist()
{
	return bChangeLevel_;
}
/// <summary>
/// ���x���ݒ�֐�
/// </summary>
/// <param name="nlevel">�w�肵�������x��</param>
void LevelsResponsible::SetNowLevel(int nlevel)
{
	nNowLevel_ = nlevel;
}
/// <summary>
/// ���݂̃��x����؂�ւ��Ă邩�m�F����֐�
/// </summary>
/// <returns>true : �؂�ւ���		false : �؂�ւ��Ȃ�</returns>
const bool& LevelsResponsible::GetLevelState()
{
	return bLevelState_;
}
/// <summary>
/// ���݂̃��x����؂�ւ��邩�w�肷��֐�
/// </summary>
/// <param name="bstate">true : �؂�ւ���		false : �؂�ւ��Ȃ�</param>
void LevelsResponsible::SetLevelState(bool bstate)
{
	bLevelState_ = bstate;
}
/// <summary>
/// ���̃��x�����ĂԊ֐�
/// </summary>
void LevelsResponsible::NextStage()
{
	if (bNextStage_ == false)
	{
		nNowStage_ += 1;
		bNextStage_ = true;
	}
}
/// <summary>
/// ���݂̋���������������֐�
/// </summary>
void LevelsResponsible::ResetNowStage()
{
	nNowStage_ = nFirstStage;
}
/// <summary>
/// ���݃v���C���[����������擾����֐�
/// </summary>
/// <returns>���݃v���C���[���ʒu������</returns>
const int& LevelsResponsible::GetNowStage()
{
	return nNowStage_;
}
/// <summary>
/// ���̋��ɐ؂�ւ���֐�
/// </summary>
/// <param name="bnextstage">true : �؂�ւ���	false : �؂�ւ��Ȃ�</param>
void LevelsResponsible::SetNextStage(bool bnextstage)
{
	bNextStage_ = bnextstage;
}
/// <summary>
/// ���̃��x���ɐ؂�ւ������m�F����֐�
/// </summary>
/// <returns>true : �؂�ւ��Ă���	false : �؂�ւ��ĂȂ�</returns>
const bool& LevelsResponsible::GetNextStageExist()
{
	return bNextStage_;
}

Rect& LevelsResponsible::GetQuadTree(int area)
{
	return Quadtree_[area];
}