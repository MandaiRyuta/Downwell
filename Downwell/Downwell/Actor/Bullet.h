#pragma once
#include "../Constant.h"

class Bullet
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	Bullet();
	/// <summary>
	/// デストラクター
	/// </summary>
	~Bullet();
public:
	/// <summary>
	/// 更新関数
	/// </summary>
	void Update();
	/// <summary>
	/// 描画関数
	/// </summary>
	void Draw();
	/// <summary>
	/// 弾作成関数
	/// </summary>
	/// <param name="vpos">弾の出現座標</param>
	void Create(const VECTOR& vpos);
	/// <summary>
	/// 弾の画像大きさ取得関数
	/// </summary>
	/// <returns>弾画像の幅</returns>
	const float& Scale();
	/// <summary>
	/// 弾の座標取得関数
	/// </summary>
	/// <param name="nbulletnumber">弾の番号</param>
	/// <returns>弾の座標</returns>
	const static VECTOR& GetPosition(int nbulletnumber);
	/// <summary>
	/// 弾の座標初期化関数
	/// </summary>
	/// <param name="nbulletnumber">弾の番号</param>
	static void ResetSetPosition(int nbulletnumber);
	/// <summary>
	/// 弾の表示フラグ取得関数
	/// </summary>
	/// <param name="num">弾の番号</param>
	/// <returns>弾の表示もしくは非表示フラグ</returns>
	static const bool& GetBulletExist(int num);
private:
	int nBulletType_;	//弾の種類
	int nBulletTexture_;	//弾の画像ハンドル
	static VECTOR vPosition_[10];	//弾の座標
	float fScale_;	//画像の大きさ
	static bool bBullet_[10];	//弾の表示フラグ
	static float fBulletspeed_[10];	//弾の移動量
	unsigned int nBulletNumber;	//弾の番号
};