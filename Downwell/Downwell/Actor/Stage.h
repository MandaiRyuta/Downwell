#pragma once
#include "Actor.h"
#include <array>
#include <algorithm>
#include "../Constant.h"
#include "../Collision/Collision.h"

constexpr int StageWidth = 20;	//�X�e�[�W�̕�
constexpr int StageHeigh = 350;	//�X�e�[�W�̍���
constexpr int OneBlockHeight = 50;	//1���̍���
constexpr int OneBlockWidth = 20;	//1���̕�
constexpr int BlockWidth = 18;	//�u���b�N�̍���
constexpr int BlockHeight = 18;	//�u���b�N�̕�
constexpr int BlockSize = 18;	//�u���b�N�̃T�C�Y

class Stage
{
private:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	Stage();
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~Stage();
public:
	/// <summary>
	/// �C���X�^���X�擾�֐�
	/// </summary>
	/// <returns>�ÓI��Stage�̃C���X�^���X</returns>
	static Stage& GetInstance()
	{
		static Stage Instance;
		return Instance;
	}
	/// <summary>
	/// �������֐�
	/// </summary>
	/// <param name="nscenenumber">�V�[���ԍ�</param>
	void Init(int nscenenumber);
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	void Update();
	/// <summary>
	/// �`��֐�
	/// </summary>
	void Draw();

	/// <summary>
	/// �X�e�[�W�̍��W�֐�
	/// </summary>
	/// <param name="x">�v���C���[�������͓G��X���W</param>
	/// <param name="y">�v���C���[�������͓G��Y���W</param>
	/// <returns></returns>
	const VECTOR& GetStagePos(int x, int y);
	/// <summary>
	/// �X�e�[�W�̃u���b�N��ނ𒲂ׂ�֐�
	/// </summary>
	/// <param name="x">�v���C���[�������͓G��X���W</param>
	/// <param name="y">�v���C���[�������͓G��Y���W</param>
	/// <returns></returns>
	const int& GetStageType(int x, int y);
	/// <summary>
	/// �u���b�N�̎�ނ�ύX����֐�
	/// </summary>
	/// <param name="type">�ύX�����ނ̔ԍ�</param>
	/// <param name="x">�u���b�N�̉���</param>
	/// <param name="y">�u���b�N�̏c��</param>
	void SetStageType(int type, int x, int y);
private:
	static std::array<std::array<int, StageWidth>, StageHeigh> Stage_;	//�X�e�[�W��̃u���b�N��ނ��Ǘ�
	static std::array<std::array<VECTOR, StageWidth>, StageHeigh> Blockpos_; //�X�e�[�W��̃u���b�N��z�u������W���Ǘ�

	int nSceneNumber_;	//�V�[���ԍ�
	int nBlockTexture_;	//�w�i�e�N�X�`���[�n���h��
	int nNonBlockTexture_;	//�u���b�N�e�N�X�`���[�n���h��
	int nInSideBlockTexture_;	//�O���ɔz�u���Ă���u���b�N�e�N�X�`���[�n���h��
	int nSideBlockTexture_;	//�ǃu���b�N�̃e�N�X�`���[�n���h��
	int nBlockSideBlockTexture_;	//�O���ɔz�u���Ă���u���b�N�̓����ɗp�̃e�N�X�`���[�n���h��
};