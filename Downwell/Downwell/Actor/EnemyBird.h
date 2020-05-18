#pragma once
#include "EnemyParameter.h"
#include "../Behaviour/BehaviorTree.h"

class BehaviorData;	//�r�w�C�r�A�f�[�^�N���X
class Node;	//�m�[�h�N���X

class EnemyBird : public EnemyParameter
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	/// <param name="enemynumber">�G�̕`��ԍ�</param>
	/// <param name="aitree">�r�w�C�r�A�c���[</param>
	/// <param name="nhp">����HP</param>
	/// <param name="nspeed">���̈ړ���</param>
	/// <param name="vposition">�����o��������W</param>
	EnemyBird(int enemynumber, BehaviorTree aitree, int nhp, int nspeed, VECTOR vposition);
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~EnemyBird();
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// �`��֐�
	/// </summary>
	virtual void Draw() override;
private:
	BehaviorData* AIData_;	//�r�w�C�r�A�f�[�^�N���X
	BehaviorTree AITree_;	//�r�w�C�r�A�c���[�N���X
	Node* Activenode_;	//�m�[�h�N���X
	int nTexhandle_;	//�e�N�X�`���[�n���h��
	bool bHitAction_;	//�Փ˃t���O
	bool bActive_;	//�A�N�e�B�u�t���O
};