#include "Character.h"
#include "../Input/Input.h"
#include "../Camera/Camera.h"
#include "Stage.h"
#include "EnemyParameter.h"
#include "../Resource/TextureData.h"
#include "../Collision/MapHitCheck.h"
#include "../Level/LevelsResponsible.h"
#include <random>

VECTOR Character::vPosition_ = VGet(0.0f, 0.0f, 0.0f);	//�v���C���[���W
bool Character::bHitEnemy_ = false;	//�v���C���[�̑������G�̐^�㒅�n�����ۂ̃t���O
bool Character::bDamage_ = false;	//�_���[�W�t���O
bool Character::bLeftDamage_ = false;	//�v���C���[�̍����ʂ��G�ɏՓ˂����ۂ̃t���O
bool Character::bRightDamage_ = false;	//�v���C���[�̉E���ʂ��G�ɏՓ˂����ۂ̃t���O
int Character::nLife_ = 0;	//�v���C���[HP
/// <summary>
/// �R���X�g���N�^�[
/// </summary>
/// <param name="nscenenumber">�V�[���ԍ�</param>
Character::Character(int nscenenumber) : nNowScene_(nscenenumber)
{
	if (nNowScene_ == 0)
	{
		vPosition_ = VGet(ScreenWidth / 2 - 150.0f, -300.0f, 0.0f);
		vOldPosition_ = VGet(ScreenWidth / 2 - 150.0f, -300.0f, 0.0f);
		nTexhandle_ = TextureDataBase::TextureData::GetInstance().GetTitleTextureData(TextureDataBase::TitleTextureNumber::TPlayer);
	}
	if (nNowScene_ == 1)
	{
		vPosition_ = VGet(ScreenWidth / 2 + 18.0f, -700.0f, 0.0f);
		vOldPosition_ = VGet(ScreenWidth / 2 + 18.0f, -700.0f, 0.0f);
		nTexhandle_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GPlayer);
	}
	if (nNowScene_ == 2)
	{
		vPosition_ = VGet(ScreenWidth / 2 + 18.0f, -900.0f, 0.0f);
		vOldPosition_ = VGet(ScreenWidth / 2 + 18.0f, -900.0f, 0.0f);
		nTexhandle_ = TextureDataBase::TextureData::GetInstance().GetResultTextureData(TextureDataBase::ResultTextureNumber::RPlayer);
	}

	nLife_ = 5;
	fSize_ = 16;
	bPlayershake_ = false;
	fPlayershake_ = 2.5f;


	vSpeed_.x = 0.0f;
	vSpeed_.y = 0.0f;
	vSpeed_.z = 0.0f;

	bHitEnemy_ = false;
	bLeftDamage_ = false;
	bRightDamage_ = false;
	fGravity_ = 0.0f;
	nCharacterActionState_ = 0;
	nHitCooltime_ = 0;
	bInvincible_ = false;
}
/// <summary>
/// �f�X�g���N�^�[
/// </summary>
Character::~Character()
{
}
/// <summary>
/// �X�V�֐�
/// </summary>
void Character::Update()
{
	if (nNowScene_ == 0)
	{
		if (MapHitCheck::GetChipParam(VGet(vPosition_.x + 8, vPosition_.y + 8, 0.0f)) == 99 && LevelsResponsible::GetInstance().GetNextStageExist() == false ||
			MapHitCheck::GetChipParam(VGet(vPosition_.x - 8, vPosition_.y - 8, 0.0f)) == 99 && LevelsResponsible::GetInstance().GetNextStageExist() == false)
		{
			LevelsResponsible::GetInstance().SetNowLevel(1);
			LevelsResponsible::GetInstance().SetChangeLevel(true);
		}

		if (MapHitCheck::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 0 && LevelsResponsible::GetInstance().GetNextStageExist() == true ||
			MapHitCheck::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 0 && LevelsResponsible::GetInstance().GetNextStageExist() == true)
		{
			LevelsResponsible::GetInstance().SetNextStage(false);
		}
		else if (MapHitCheck::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 99 && LevelsResponsible::GetInstance().GetNextStageExist() == false ||
			MapHitCheck::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 99 && LevelsResponsible::GetInstance().GetNextStageExist() == false)
		{
			LevelsResponsible::GetInstance().NextStage();
		}
	}
	if (nNowScene_ == 1)
	{
		if (MapHitCheck::GetChipParam(VGet(vPosition_.x + 8, vPosition_.y + 8, 0.0f)) == 18 || MapHitCheck::GetChipParam(VGet(vPosition_.x - 8, vPosition_.y - 8, 0.0f)) == 18)
		{
			LevelsResponsible::GetInstance().SetLevelState(false);
			LevelsResponsible::GetInstance().SetNowLevel(2);
			LevelsResponsible::GetInstance().SetChangeLevel(true);
		}
		if (nLife_ == 0)
		{
			LevelsResponsible::GetInstance().SetLevelState(true);
			LevelsResponsible::GetInstance().SetNowLevel(2);
			LevelsResponsible::GetInstance().SetChangeLevel(true);
		}
		if (MapHitCheck::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 0 && LevelsResponsible::GetInstance().GetNextStageExist() == true ||
			MapHitCheck::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 0 && LevelsResponsible::GetInstance().GetNextStageExist() == true)
		{
			LevelsResponsible::GetInstance().SetNextStage(false);
		}
		else if (MapHitCheck::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 99 && LevelsResponsible::GetInstance().GetNextStageExist() == false ||
			MapHitCheck::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 99 && LevelsResponsible::GetInstance().GetNextStageExist() == false)
		{
			LevelsResponsible::GetInstance().NextStage();
		}
	}

	if (nNowScene_ == 0 || nNowScene_ == 1)
	{
		if (bInvincible_)
		{
			if (bDamage_)
			{
				bDamage_ = false;
			}
			if (bLeftDamage_)
			{
				bLeftDamage_ = false;
			}
			if (bRightDamage_)
			{
				bRightDamage_ = false;
			}

			if (nHitCooltime_ > 120)
			{
				bInvincible_ = false;
				nHitCooltime_ = 0;
			}

			nHitCooltime_++;
		}
		if (fGravity_ > -10.0f)
		{
			fGravity_ += fGravity;
		}

		vSpeed_.y = fGravity_;

		if (bPlayershake_)
		{
			vSpeed_.y = vSpeed_.y + (fPlayershake_ * -1.0f);
		}

		if(bHitEnemy_)
		{
			vSpeed_.y += 20.0f;
			bHitEnemy_ = false;
		}
		if (bDamage_)
		{
			nLife_ -= 1;
			vPosition_.y += 5.0f;
			bLeftDamage_ = false;
			bInvincible_ = true;
		}
		if (bLeftDamage_)
		{
			nLife_ -= 1;
			vPosition_.y += 5.0f;
			vPosition_.x += 5.0f;
			bLeftDamage_ = false;
			bInvincible_ = true;
		}
		if (bRightDamage_)
		{
			nLife_ -= 1;
			vPosition_.y += 5.0f;
			vPosition_.x -= 5.0f;
			bRightDamage_ = false;
			bInvincible_ = true;
		}

		MoveState_.SideMove(vPosition_,vSpeed_.x,vSpeed_.y, fGravity_, fSize_);
		AttackState_.Attack(vPosition_, JumpState_.GetJumpExist(), JumpState_.GetBulletJumpExist(), nCharacterActionState_, fGravity_, bPlayershake_);
		JumpState_.JumpState(vPosition_, vSpeed_, fGravity_, nCharacterActionState_);

		vPosition_.y += vSpeed_.y;
	}
}
/// <summary>
/// �`��֐�
/// </summary>
void Character::Draw()
{
	DrawBillboard3D(VGet(vPosition_.x, vPosition_.y, 0.0f), 0.5f, 0.5f, fSize_, 0, nTexhandle_,false);
	
	AttackState_.Draw(); 
}
/// <summary>
/// ���W�擾�֐�
/// </summary>
/// <returns>�v���C���[���W</returns>
const VECTOR& Character::GetPos()
{
    return vPosition_;
}
/// <summary>
/// �G�̐^��ɑ��������n�����Ƃ��̏Փˊ֐�
/// </summary>
/// <param name="bhit"> true : �Փ�   false : ��Փ�</param>
void Character::SetHitEnemy(bool bhit)
{
	bHitEnemy_ = bhit;
}
/// <summary>
/// �G�ƏՓˎ��̃_���[�W�֐�
/// </summary>
/// <param name="bdamage"> true : �_���[�W���󂯂�  false : �_���[�W���󂯂Ȃ�</param>
void Character::SetHitDamage(bool bdamage)
{
	bDamage_ = bdamage;
}
/// <summary>
/// �v���C���[�̑��ʂƓG�̏Փ˔���
/// </summary>
/// <param name="bdamage">true : �Փ�  false : ��Փ�</param>
void Character::SetHitLeftDamage(bool bdamage)
{
	bLeftDamage_ = bdamage;
}
/// <summary>
/// �v���C���[�̑��ʂƓG�̏Փ˔���
/// </summary>
/// <param name="bdamage">true : �Փˁ@false : ��Փ�</param>
void Character::SetHitRightDamage(bool bdamage)
{
	bRightDamage_ = bdamage;
}
/// <summary>
/// �v���C���[�̎c��HP�擾�֐�
/// </summary>
/// <returns>�c��HP</returns>
const int& Character::GetCharacterLife()
{
	return nLife_;
}


