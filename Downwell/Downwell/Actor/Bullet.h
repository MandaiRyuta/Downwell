#pragma once
#include "../Constant.h"

class Bullet
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	Bullet();
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~Bullet();
public:
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	void Update();
	/// <summary>
	/// �`��֐�
	/// </summary>
	void Draw();
	/// <summary>
	/// �e�쐬�֐�
	/// </summary>
	/// <param name="vpos">�e�̏o�����W</param>
	void Create(const VECTOR& vpos);
	/// <summary>
	/// �e�̉摜�傫���擾�֐�
	/// </summary>
	/// <returns>�e�摜�̕�</returns>
	const float& Scale();
	/// <summary>
	/// �e�̍��W�擾�֐�
	/// </summary>
	/// <param name="nbulletnumber">�e�̔ԍ�</param>
	/// <returns>�e�̍��W</returns>
	const static VECTOR& GetPosition(int nbulletnumber);
	/// <summary>
	/// �e�̍��W�������֐�
	/// </summary>
	/// <param name="nbulletnumber">�e�̔ԍ�</param>
	static void ResetSetPosition(int nbulletnumber);
	/// <summary>
	/// �e�̕\���t���O�擾�֐�
	/// </summary>
	/// <param name="num">�e�̔ԍ�</param>
	/// <returns>�e�̕\���������͔�\���t���O</returns>
	static const bool& GetBulletExist(int num);
private:
	int nBulletType_;	//�e�̎��
	int nBulletTexture_;	//�e�̉摜�n���h��
	static VECTOR vPosition_[10];	//�e�̍��W
	float fScale_;	//�摜�̑傫��
	static bool bBullet_[10];	//�e�̕\���t���O
	static float fBulletspeed_[10];	//�e�̈ړ���
	unsigned int nBulletNumber;	//�e�̔ԍ�
};