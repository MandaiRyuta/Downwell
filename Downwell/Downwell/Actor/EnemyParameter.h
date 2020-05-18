#pragma once
#include "../Constant.h"
#include "../DownwellConstant.h"
class EnemyParameter
{
public:
	/// <summary>
	/// ƒRƒ“ƒXƒgƒ‰ƒNƒ^[
	/// </summary>
	EnemyParameter();
	/// <summary>
	/// ƒfƒXƒgƒ‰ƒNƒ^[
	/// </summary>
	virtual ~EnemyParameter() {};
	/// <summary>
	/// XVŠÖ”
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// •`‰æŠÖ”
	/// </summary>
	virtual void Draw() = 0;
	/// <summary>
	/// “G‚ÌHPæ“¾ŠÖ”
	/// </summary>
	/// <returns>“G‚ÌHP</returns>
	const int& GetHp()
	{
		return nHp_;
	}
	/// <summary>
	/// “G‚ÌÅ‘åHPæ“¾ŠÖ”
	/// </summary>
	/// <returns>“G‚ÌÅ‘åHP</returns>
	const int& GetMaxHp()
	{
		return nMaxHp_;
	}
	/// <summary>
	/// “G‚ÌˆÚ“®—Êæ“¾ŠÖ”
	/// </summary>
	/// <returns>“G‚ÌˆÚ“®—Ê</returns>
	const int& GetSpeed()
	{
		return nSpeed_;
	}
	/// <summary>
	/// “G‚ÌÅ‘åˆÚ“®—Êæ“¾ŠÖ”
	/// </summary>
	/// <returns>Å‘åˆÚ“®—Ê</returns>
	const int& GetMaxSpeed()
	{
		return nMaxSpeed_;
	}
	/// <summary>
	/// “G‚ÌÀ•Wæ“¾ŠÖ”
	/// </summary>
	/// <returns>“G‚ÌŒ»İ‚ÌÀ•W</returns>
	const VECTOR& GetPosition()
	{
		return vPosition_;
	}
	/// <summary>
	/// “G‚ÌÀ•W‚ğİ’è‚·‚éŠÖ”
	/// </summary>
	/// <param name="position">w’èÀ•W</param>
	void SetPosition(VECTOR position)
	{
		vPosition_.x = position.x;
		vPosition_.y = position.y;
		vPosition_.z = position.z;
	}
	/// <summary>
	/// “G‚ÌˆÚ“®ŠÖ”
	/// </summary>
	/// <param name="move">ˆÚ“®—Ê</param>
	void MovePosition(VECTOR move)
	{
		vMove_.x = move.x;
		vMove_.y = move.y;
		vMove_.z = move.z;
	}
	/// <summary>
	/// “G‚ÌYÀ•WˆÚ“®ŠÖ”
	/// </summary>
	/// <param name="fmovey">YÀ•W‚ÌˆÚ“®—Ê</param>
	void AddMovePositionY(float fmovey)
	{
		vMove_.y += fmovey;
	}
	/// <summary>
	/// “G‚ÌXÀ•WˆÚ“®ŠÖ”
	/// </summary>
	/// <param name="fmovex">XÀ•W‚ÌˆÚ“®—Ê</param>
	void AddMovePositionX(float fmovex)
	{
		vMove_.x += fmovex;
	}
	/// <summary>
	/// “G‚ÌˆÚ“®í—Şw’èŠÖ”
	/// </summary>
	/// <param name="ntype">ˆÚ“®í—Ş</param>
	void SetMoveType(int ntype)
	{
		nMoveType_ = ntype;
	}
	/// <summary>
	/// “G‚ÌˆÚ“®î•ñæ“¾ŠÖ”
	/// </summary>
	/// <returns>w’è‚µ‚½ˆÚ“®í—Ş</returns>
	const int& GetMoveType()
	{
		return nMoveType_;
	}
	/// <summary>
	/// “G‚ÌÕ“ËŠÖ”
	/// </summary>
	/// <param name="bbottomtouch">true : ’…’n	false : ’…’n‚µ‚Ä‚¢‚È‚¢</param>
	void SetBottomTouch(bool bbottomtouch)
	{
		bBottomtouch_ = bbottomtouch;
	}
	/// <summary>
	/// “G‚Ì•`‰æ”Ô†İ’èŠÖ”
	/// </summary>
	/// <param name="nnumber">•`‰æ”Ô†</param>
	void SetEnemyNumber(int nnumber)
	{
		nEnemyNumber_ = nnumber;
	}
	/// <summary>
	/// “G‚Ì•`‰æ”Ô†æ“¾ŠÖ”
	/// </summary>
	/// <returns>w’è‚µ‚½•`‰æ”Ô†</returns>
	const int& GetEnemyNumber()
	{
		return nEnemyNumber_;
	}
	/// <summary>
	/// “G‚Ì¶‘¶æ“¾ŠÖ”
	/// </summary>
	/// <returns>true : ¶‘¶‚µ‚Ä‚¢‚é@false : €‚ñ‚Å‚¢‚é</returns>
	const bool& GetbLifeExist()
	{
		return bLife_;
	}
	/// <summary>
	/// “G‚Ì¶‘¶w’èŠÖ”
	/// </summary>
	/// <param name="blife">true : ¶‘¶‚µ‚Ä‚¢‚é@false : €‚ñ‚Å‚¢‚é</param>
	void SetbLife(bool blife)
	{
		bLife_ = blife;
	}
protected:
	bool bLife_;	//¶‘¶ƒtƒ‰ƒO
	int nEnemyNumber_;	//“G‚Ì•`‰æ”Ô†
	int nMoveType_;	//“G‚ÌˆÚ“®í—Ş
	int nHp_;	//“G‚ÌHP
	int nMaxHp_;	//“G‚ÌÅ‘åHP
	int nSpeed_;	//“G‚ÌˆÚ“®—Ê
	int nMaxSpeed_;	//“G‚ÌÅ‘åˆÚ“®—Ê
	bool bBottomtouch_;	//“G‚Ì’n–ÊÕ“Ëƒtƒ‰ƒO
	VECTOR vPosition_;	//“G‚ÌÀ•W
	VECTOR vMove_;	//“G‚ÌˆÚ“®—Ê
};