#pragma once

struct Rect
{
	float x;	//x���W
	float y;	//y���W
	float height;	//����
	float width;	//��

public:
	/// <summary>
	/// �f�t�H���g�R���X�g���N�^�[
	/// </summary>
	Rect()
	{
		x = y = height = width = 0.0f;
	}
	/// <summary>
	/// �R�s�[�R���X�g���N�^�[
	/// </summary>
	/// <param name="fx">x���W</param>
	/// <param name="fy">y���W</param>
	/// <param name="fwidth">��</param>
	/// <param name="fheight">����</param>
	Rect(float fx, float fy, float fwidth, float fheight)
	{
		x = fx;
		y = fy;
		width = fwidth;
		height = fheight;
	}
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~Rect() {}
	/// <summary>
	/// �Փˌ��m�֐�
	/// </summary>
	/// <param name="targetrect">�����Ă�����W</param>
	/// <returns>�Փˌ���	true : �Փ˂��Ă���		false : �Փ˂��Ă��Ȃ�</returns>
	bool HitCheck(const Rect& targetrect) const
	{
		if (x + width > targetrect.x&& x < targetrect.x + targetrect.width)
		{
			if (y + height > targetrect.y&& y < targetrect.y + targetrect.height)
			{
				return true;
			}
		}

		return false;
	}
};

class BoxCollider
{
public:
	/// <summary>
	/// �f�t�H���g�R���X�g���N�^�[
	/// </summary>
	BoxCollider() {}
	/// <summary>
	/// �R�s�[�R���X�g���N�^�[
	/// </summary>
	/// <param name="x">x���W</param>
	/// <param name="y">y���W</param>
	/// <param name="width">��</param>
	/// <param name="height">����</param>
	BoxCollider(float x, float y, float width, float height)
	{
		rect_.x = x;
		rect_.y = y;
		rect_.width = width;
		rect_.height = height;
	}
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~BoxCollider() {}

	/// <summary>
	/// Rect���擾�֐�
	/// </summary>
	/// <returns>Rect���</returns>
	const Rect& GetCollidable()
	{
		return rect_;
	}

	Rect rect_;
};