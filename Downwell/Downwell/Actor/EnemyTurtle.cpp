#include "EnemyTurtle.h"
#include "../Behaviour/BehaviorData.h"
#include "../Behaviour/BehaviorTree.h"
#include "../Behaviour/TurnMoveAction.h"
#include "../Behaviour/Node.h"
#include "../Constant.h"
#include "Bullet.h"
#include "Character.h"
#include "../Resource/TextureData.h"
#include "../Collision/Collision.h"
#include "../Level/LevelsResponsible.h"
/// <summary>
/// �R���X�g���N�^�[
/// </summary>
/// <param name="nEnemyNumber">�G�̕`��ԍ�</param>
/// <param name="AiTree">�r�w�C�r�A�c���[</param>
/// <param name="nHp">�T��HP</param>
/// <param name="vPosition">�T���o��������W</param>
EnemyTurtle::EnemyTurtle(int nEnemyNumber, BehaviorTree AiTree, int nHp, VECTOR vPosition) :
	Activenode_(nullptr),
	AIData_(nullptr),
	bActive_(bInitActive)
{
	bLife_ = bInitEnemyLife;
	AITree_ = AiTree;
	nHp_ = nHp;
	nMaxHp_ = nHp;
	nMoveType_ = nInitEnemyMoveType;
	vMove_ = VGet(fDefaultPos, fDefaultPos, fDefaultPos);
	vPosition_ = vPosition;
	AIData_ = new BehaviorData;
	nTexhandle_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GTurtle);
	nEnemyNumber_ = nEnemyNumber;
	bHitAction_ = bInitEnemyHitAction;
}
/// <summary>
/// �f�X�g���N�^�[
/// </summary>
EnemyTurtle::~EnemyTurtle()
{
	if (AIData_ != nullptr)
	{
		delete AIData_;
	}

	AITree_.Release();
}
/// <summary>
/// �X�V�֐�
/// </summary>
void EnemyTurtle::Update()
{
	QuadTreeCheckCollision();
	TurtleHitCollision();
	TurtleMoveAction();
}
/// <summary>
/// �`��֐�
/// </summary>
void EnemyTurtle::Draw()
{
	if (bLife_)
	{
		DrawBillboard3D(vPosition_, 0.5f, 0.5f, 18.0f, 0.0f, nTexhandle_, false);
	}
}
/// <summary>
/// �N�A�b�h�c���[���ɂ��邩�ǂ������m�F����֐�
/// </summary>
void EnemyTurtle::QuadTreeCheckCollision()
{
	bActive_ = false;
	bool bactive = false;
	Rect rc(vPosition_.x - fTurtleRectPadding, vPosition_.y - fTurtleRectPadding, fTurtleTextureScale, fTurtleTextureScale);
	for (int i = 0; i < nQuadTreeMaxCount; i++)
	{
		bactive = LevelsResponsible::GetInstance().GetQuadTree(i).HitCheck(rc);

		if (bactive)
		{
			bActive_ = true;
		}
	}
}
/// <summary>
/// �v���C���[��u���b�N�Ƃ̏Փ˔���֐�
/// </summary>
void EnemyTurtle::TurtleHitCollision()
{
	if (!bActive_) return;
	if (!bLife_) return;

	bHitAction_ = false;

	for (int i = 0; i < nBulletMaxCount; ++i)
	{
		if (Bullet::GetPosition(i).x - 6.0f >= vPosition_.x - 11.0f && Bullet::GetPosition(i).y - 6.0f < vPosition_.y + 11.0f &&
			Bullet::GetPosition(i).x + 6.0f <= vPosition_.x + 11.0f && Bullet::GetPosition(i).y + 6.0f > vPosition_.y - 11.0f)
		{
			if (nHp_ > nZeroLife)
			{
				nHp_--;
			}
		}
	}

	if (Character::GetPos().x - 8.0f <= vPosition_.x + 9.0f && Character::GetPos().y - 7.0f < vPosition_.y + 8.0f &&
		Character::GetPos().x - 8.0f >= vPosition_.x + 9.0f && Character::GetPos().y + 7.0f > vPosition_.y - 8.0f && bHitAction_ == false)
	{
		Character::SetHitLeftDamage(true);
		bHitAction_ = true;
	}
	if (Character::GetPos().x + 8.0f <= vPosition_.x - 9.0f && Character::GetPos().y - 7.0f < vPosition_.y + 8.0f &&
		Character::GetPos().x + 8.0f >= vPosition_.x - 9.0f && Character::GetPos().y + 7.0f > vPosition_.y - 8.0f && bHitAction_ == false)
	{
		Character::SetHitRightDamage(true);
		bHitAction_ = true;
	}

	if (Character::GetPos().x >= vPosition_.x + -11.0f && Character::GetPos().x <= vPosition_.x + 11.0f &&
		Character::GetPos().y - 8.5f <= vPosition_.y + 11.0f && Character::GetPos().y - 8.5f > vPosition_.y - 5.0f && bHitAction_ == false)
	{
		Character::SetHitEnemy(true);
		if (nHp_ > nZeroLife)
		{
			nHp_--;
		}
	}
}
/// <summary>
/// �T���s�����s���֐�
/// </summary>
void EnemyTurtle::TurtleMoveAction()
{
	if (!bActive_) return;
	if (!bLife_) return;


	if (Activenode_ == nullptr)
	{
		Activenode_ = AITree_.Inference(this, AIData_);
	}
	if (Activenode_ != nullptr)
	{
		Activenode_ = AITree_.Run(*this, Activenode_, AIData_);
	}

	vPosition_.x += vMove_.x;
	vPosition_.y += vMove_.y;
}
