#pragma once
#include "../Constant.h"
#include "../Collision/Collision.h"
class Level;	//���x���N���X

class LevelsResponsible :
	public Initialize,
	public Clear
{
private:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	LevelsResponsible() : nNowLevel_(0), Level_(nullptr), bChangeLevel_(false), bLevelState_(false), bNextStage_(false), nNowStage_(1) {}
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~LevelsResponsible() {}
public:
	/// <summary>
	/// �C���X�^���X�擾�֐�
	/// </summary>
	/// <returns>�ÓI��LevelsResponsible�C���X�^���X</returns>
	static LevelsResponsible& GetInstance()
	{
		static LevelsResponsible Inst;
		return Inst;
	}
	/// <summary>
	/// �������֐�
	/// </summary>
	virtual void Init() override;
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	void Update();
	/// <summary>
	/// �`��֐�
	/// </summary>
	void Draw();
	/// <summary>
	/// ����֐�
	/// </summary>
	virtual void Release() override;
	/// <summary>
	/// �I���֐�
	/// </summary>
	void Exit();
	/// <summary>
	/// ���x���؂�ւ��֐�
	/// </summary>
	/// <param name="nType">�؂�ւ��������x��</param>
	void ChangeLevel(int nType);
	/// <summary>
	/// ���x���擾�֐�
	/// </summary>
	/// <returns>���݂̃��x��</returns>
	const int& GetNowLevel();
	/// <summary>
	/// ���x���؂�ւ��t���O�ݒ�֐�
	/// </summary>
	/// <param name="bchangescene">	true : �؂�ւ���	false : �؂�ւ��Ȃ�</param>
	void SetChangeLevel(bool bChangeLevel);
	/// <summary>
	/// ���x���؂�ւ��t���O�擾�֐�
	/// </summary>
	/// <returns>���x���؂�ւ��t���O</returns>
	const bool& GetChengeLevelExist();
	/// <summary>
	/// ���x���ݒ�֐�
	/// </summary>
	/// <param name="nLevel">�w�肵�������x��</param>
	void SetNowLevel(int nLevel);
	/// <summary>
	/// ���݂̃��x����؂�ւ��Ă邩�m�F����֐�
	/// </summary>
	/// <returns>true : �؂�ւ���		false : �؂�ւ��Ȃ�</returns>
	const bool& GetLevelState();
	/// <summary>
	/// ���݂̃��x����؂�ւ��邩�w�肷��֐�
	/// </summary>
	/// <param name="bState">true : �؂�ւ���		false : �؂�ւ��Ȃ�</param>
	void SetLevelState(bool bState);
	/// <summary>
	/// ���̃��x�����ĂԊ֐�
	/// </summary>
	void NextStage();
	/// <summary>
	/// ���݂̋���������������֐�
	/// </summary>
	void ResetNowStage();
	/// <summary>
	/// ���݃v���C���[����������擾����֐�
	/// </summary>
	/// <returns>���݃v���C���[���ʒu������</returns>
	const int& GetNowStage();
	/// <summary>
	/// ���̋��ɐ؂�ւ���֐�
	/// </summary>
	/// <param name="bNextStage">true : �؂�ւ���	false : �؂�ւ��Ȃ�</param>
	void SetNextStage(bool bNextStage);
	/// <summary>
	/// ���̃��x���ɐ؂�ւ������m�F����֐�
	/// </summary>
	/// <returns>true : �؂�ւ��Ă���	false : �؂�ւ��ĂȂ�</returns>
	const bool& GetNextStageExist();
	/// <summary>
	/// �G���A���擾�֐�
	/// </summary>
	/// <param name="nArea">�G���A�ԍ�</param>
	/// <returns></returns>
	Rect& GetQuadTree(int nArea);
private:
	int nNowStage_;	//���݂̃X�e�[�W
	bool bNextStage_;	//���̐؂�ւ���t���O
	bool bLevelState_;	//���x����؂�ւ��Ă��邩�m�F����t���O
	bool bChangeLevel_;	//���x����؂�ւ���t���O
	int nNowLevel_;	//���݂̃��x��
	Level* Level_;	//���x���N���X
	Rect Quadtree_[4];	//�N�A�b�h�c���[
};