#include "Stage.h"
#include "../Resource/StageDataBase.h"
#include "Character.h"
#include "EnemySeaUrchin.h"
#include "../Resource/TextureData.h"
#include "Bullet.h"
#include "../Collision/MapHitCheck.h"
#include <random>

std::array<std::array<int, StageWidth>, StageHeigh> Stage::Stage_ = {};	//�X�e�[�W��̃u���b�N��ނ��Ǘ�
std::array<std::array<VECTOR, StageWidth>, StageHeigh> Stage::Blockpos_ = {};	//�X�e�[�W��̃u���b�N��z�u������W���Ǘ�
/// <summary>
/// �R���X�g���N�^�[
/// </summary>
Stage::Stage():
	nSceneNumber_(nInitStageLevelNumber),
	nBlockSideBlockTexture_(nInitBlockSideBlockTexture),
	nNonBlockTexture_(nInitNonBlockTexture),
	nSideBlockTexture_(nInitSideBlockTexture),
	nBlockTexture_(nInitBlockTexture),
	nInSideBlockTexture_(nInitInSideBlockTexture)
{}
/// <summary>
/// �f�X�g���N�^�[
/// </summary>
Stage::~Stage(){}
/// <summary>
/// �������֐�
/// </summary>
/// <param name="nscenenumber">�V�[���ԍ�</param>
void Stage::Init(int nscenenumber)
{
	nSceneNumber_ = nscenenumber;

	int nx = 0, ny = 0, stagetype = 0;
	StageDataBase::GetInstance().InitStage();
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> randset(1, 10);
	float blockwidth = static_cast<float>(BlockWidth);
	float blockheight = static_cast<float>(BlockHeight);

	for (int type = 0; type < nAreaMax; type++)
	{
		stagetype = randset(mt);
		for (int y = 0; y < OneBlockHeight; y++)
		{
			for (int x = 0; x < OneBlockWidth; x++)
			{
				ny = y + (type * OneBlockHeight);

				if (type == nBackGroundType)
				{
					Stage_[ny][x] = (StageDataBase::GetInstance().GetStageType(0, x, y));
					Blockpos_[ny][x] = VGet(171.0f + static_cast<float>(x)* (float)blockwidth, (static_cast<float>(-ny)* blockheight) + (blockheight * -0.5f), 0.0f);
				}
				else if (type == nGoalType)
				{
					Stage_[ny][x] = (StageDataBase::GetInstance().GetStageType(11, x, y));
					Blockpos_[ny][x] = VGet(171.0f + static_cast<float>(x)* (float)blockwidth, (static_cast<float>(-ny)* blockheight) + (blockheight * -0.5f), 0.0f);
				}
				else
				{
					Stage_[ny][x] = (StageDataBase::GetInstance().GetStageType(stagetype, x, y));
					Blockpos_[ny][x] = VGet(171.0f + static_cast<float>(x)* (float)blockwidth, (static_cast<float>(-ny)* blockheight) + (blockheight * -0.5f), 0.0f);
				}
			}
		}
	}

	if (nSceneNumber_ == nTitleLevel)
	{
		nBlockTexture_ = TextureDataBase::TextureData::GetInstance().GetTitleTextureData(TextureDataBase::TitleTextureNumber::TBackgroundBlock);
		nInSideBlockTexture_ = TextureDataBase::TextureData::GetInstance().GetTitleTextureData(TextureDataBase::TitleTextureNumber::TOutBlock);
	}
	else if (nSceneNumber_ == nGameLevel)
	{
		nBlockTexture_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GBackgroundBlock);
		nInSideBlockTexture_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GOutBlock);
		nNonBlockTexture_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GBlock);
		nSideBlockTexture_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GSideBlock);
		nBlockSideBlockTexture_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GBlockInSideBlock);
	}
	else if (nSceneNumber_ == nResultLevel)
	{
		nBlockTexture_ = TextureDataBase::TextureData::GetInstance().GetResultTextureData(TextureDataBase::ResultTextureNumber::RBackgroundBlock);
		nInSideBlockTexture_ = TextureDataBase::TextureData::GetInstance().GetResultTextureData(TextureDataBase::ResultTextureNumber::ROutBlock);
	}
}
/// <summary>
/// �X�V�֐�
/// </summary>
void Stage::Update()
{
	/// <summary>
	/// �e�}�b�v�`�b�v�̍��W�ƃJ�����̋�`�𔻒肵�āA�t���O���w�肷��@true || false 
	/// true �̏ꍇ�@�`��A�@false �̏ꍇ�@�`�悳���Ȃ��B
	/// </summary>
	if (nSceneNumber_ == nGameLevel)
	{
		for (int i = 0; i < nBulletMaxCount; i++)
		{
			if (MapHitChecker::GetChipParam(VGet(Bullet::GetPosition(i).x - 3.0f, Bullet::GetPosition(i).y - 6.0f, 0.0f)) == 3 ||
				MapHitChecker::GetChipParam(VGet(Bullet::GetPosition(i).x + 3.0f, Bullet::GetPosition(i).y - 6.0f, 0.0f)) == 3 )
			{
				int x = static_cast<int>(Bullet::GetPosition(i).x / BlockSize - (BlockSize * 0.5f));
				int y = static_cast<int>(Bullet::GetPosition(i).y / -BlockSize);

				Stage_[y][x] = 0;
				int up = y - 1;
				int right = x + 1;
				int left = x - 1;

				if (Stage_[y][right] == nBackGroundType)
				{
					Stage_[up][right] = nLeftChangeType;
				}
				else if (Stage_[y][left] == nBackGroundType)
				{
					Stage_[up][left] = nRightChangeType;
				}
				else if (Stage_[y][right] == nBackGroundType && Stage_[y][left] == nMoveBlockType)
				{
					Stage_[up][right] = nLeftChangeType;
				}
				else if (Stage_[y][left] == nBackGroundType && Stage_[y][right] == nMoveBlockType)
				{
					Stage_[up][left] = nRightChangeType;
				}

				Bullet::ResetSetPosition(i);
			}
		}
	}
}
/// <summary>
/// �`��֐�
/// </summary>
void Stage::Draw()
{
	int MapDrawPointX, MapDrawPointY;
	MapDrawPointX = MapDrawPointY = 0;
	MapDrawPointX = static_cast<int>(-Character::GetPos().x + ((640 / 20 + 2) / 2 - 1));
	MapDrawPointY = static_cast<int>(-Character::GetPos().y + ((640 / 20 + 2) / 2 - 1));
	
	int numcount = 0;
	for (int y = 0; y < StageHeigh; y++)
	{
		for (int x = 0; x < StageWidth; x++)
		{
			//��ʊO�̃X�e�[�W�I�u�W�F�N�g�̓J�����O
			if (y + MapDrawPointY < 0 || y + MapDrawPointY >= y + MapDrawPointY + 50)	continue;
			
			if (nSceneNumber_ == nTitleLevel)
			{
				if (Stage_[y][x] == nMoveBlockType)
				{
					DrawBillboard3D(Blockpos_[y][x], 0.5f, 0.5f, BlockSize, 0, nInSideBlockTexture_, false);
				}
				else
				{
					DrawBillboard3D(Blockpos_[y][x], 0.5f, 0.5f, BlockSize, 0, nBlockTexture_, false);
				}
			}
			if (nSceneNumber_ == nGameLevel)
			{
				if (Stage_[y][x] == nMoveBlockType)
				{
					DrawBillboard3D(Blockpos_[y][x], 0.5f, 0.5f, BlockSize, 0, nInSideBlockTexture_, false);
				}
				else if (Stage_[y][x] == nFloatingBlockType)
				{
					DrawBillboard3D(Blockpos_[y][x], 0.5f, 0.5f, BlockSize, 0, nNonBlockTexture_, false);
				}
				else if (Stage_[y][x] == nBlokenBlockType)
				{
					DrawBillboard3D(Blockpos_[y][x], 0.5f, 0.5f, BlockSize, 0, nNonBlockTexture_, false);
				}
				else if (Stage_[y][x] == nSideBlockType)
				{
					DrawBillboard3D(Blockpos_[y][x], 0.5f, 0.5f, BlockSize, 0, nSideBlockTexture_, false);
				}
				else if (Stage_[y][x] == nInSideBlockType)
				{
					DrawBillboard3D(Blockpos_[y][x], 0.5f, 0.5f, BlockSize, 0, nSideBlockTexture_, false);
				}
				else
				{
					DrawBillboard3D(Blockpos_[y][x], 0.5f, 0.5f, BlockSize, 0, nBlockTexture_, false);
				}
			}
			if (nSceneNumber_ == nResultLevel)
			{
				if (Stage_[y][x] == nMoveBlockType)
				{
					DrawBillboard3D(Blockpos_[y][x], 0.5f, 0.5f, BlockSize, 0, nInSideBlockTexture_, false);
				}
				else
				{
					DrawBillboard3D(Blockpos_[y][x], 0.5f, 0.5f, BlockSize, 0, nBlockTexture_, false);
				}
			}
			numcount++;
		}
	}
}
/// <summary>
/// �X�e�[�W�̍��W�֐�
/// </summary>
/// <param name="x">�v���C���[�������͓G��X���W</param>
/// <param name="y">�v���C���[�������͓G��Y���W</param>
/// <returns></returns>
const VECTOR& Stage::GetStagePos(int x, int y)
{
	return Blockpos_[y][x];
}
/// <summary>
/// �X�e�[�W�̃u���b�N��ނ𒲂ׂ�֐�
/// </summary>
/// <param name="x">�v���C���[�������͓G��X���W</param>
/// <param name="y">�v���C���[�������͓G��Y���W</param>
/// <returns></returns>
const int& Stage::GetStageType(int x, int y)
{
	return Stage_[y][x];
}
/// <summary>
/// �u���b�N�̎�ނ�ύX����֐�
/// </summary>
/// <param name="type">�ύX�����ނ̔ԍ�</param>
/// <param name="x">�u���b�N�̉���</param>
/// <param name="y">�u���b�N�̏c��</param>
void Stage::SetStageType(int type, int x, int y)
{
	Stage_[y][x] = type;
}
