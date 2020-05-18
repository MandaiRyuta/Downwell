#pragma once

struct Rect
{
	float x;	//x座標
	float y;	//y座標
	float height;	//高さ
	float width;	//幅

public:
	/// <summary>
	/// デフォルトコンストラクター
	/// </summary>
	Rect()
	{
		x = y = height = width = 0.0f;
	}
	/// <summary>
	/// コピーコンストラクター
	/// </summary>
	/// <param name="fx">x座標</param>
	/// <param name="fy">y座標</param>
	/// <param name="fwidth">幅</param>
	/// <param name="fheight">高さ</param>
	Rect(float fx, float fy, float fwidth, float fheight)
	{
		x = fx;
		y = fy;
		width = fwidth;
		height = fheight;
	}
	/// <summary>
	/// デストラクター
	/// </summary>
	~Rect() {}
	/// <summary>
	/// 衝突検知関数
	/// </summary>
	/// <param name="targetrect">動いている座標</param>
	/// <returns>衝突結果	true : 衝突している		false : 衝突していない</returns>
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
	/// デフォルトコンストラクター
	/// </summary>
	BoxCollider() {}
	/// <summary>
	/// コピーコンストラクター
	/// </summary>
	/// <param name="x">x座標</param>
	/// <param name="y">y座標</param>
	/// <param name="width">幅</param>
	/// <param name="height">高さ</param>
	BoxCollider(float x, float y, float width, float height)
	{
		rect_.x = x;
		rect_.y = y;
		rect_.width = width;
		rect_.height = height;
	}
	/// <summary>
	/// デストラクター
	/// </summary>
	~BoxCollider() {}

	/// <summary>
	/// Rect情報取得関数
	/// </summary>
	/// <returns>Rect情報</returns>
	const Rect& GetCollidable()
	{
		return rect_;
	}

	Rect rect_;
};