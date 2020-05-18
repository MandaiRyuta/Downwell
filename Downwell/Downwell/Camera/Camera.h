#pragma once
#include <DxLib.h>



class Camera {
private:
	/// <summary>
	/// コンストラクター
	/// </summary>
	Camera()
	{
		fShakePower_ = 0.0f;
		bShake_ = false;
		vPosition_ = VGet(0.0f, 0.0f, 0.0f);
	}
	/// <summary>
	/// デストラクター
	/// </summary>
	~Camera() {}
public:
	/// <summary>
	/// カメラインスタンス関数
	/// </summary>
	/// <returns>静的なCameraのインスタンス</returns>
	static Camera& GetInstance()
	{
		static Camera Inst;
		return Inst;
	}
	/// <summary>
	/// 初期化関数
	/// </summary>
	/// <param name="pos">初期座標</param>
	void Init(VECTOR pos);
	/// <summary>
	/// 更新関数
	/// </summary>
	void Update();
	/// <summary>
	/// デバッグ用関数
	/// </summary>
	void DebugCamera();
	/// <summary>
	/// カメラ行列取得関数
	/// </summary>
	/// <returns>カメラ行列</returns>
	MATRIX GetMatrix();
	/// <summary>
	/// カメラ座標を設定する関数
	/// </summary>
	/// <param name="pos">設定するカメラ座標</param>
	void SetPosition(VECTOR pos);
	/// <summary>
	/// カメラを振動させる関数
	/// </summary>
	/// <param name="bshake">カメラの振動フラグ	true : 振動させる	false : 振動させない</param>
	void SetShake(bool bshake);
private:
	VECTOR vPosition_;	//座標
	bool bShake_;	//振動フラグ
	float fShakePower_;	//振動量
};


