#include "BehaviorData.h"
#include "Node.h"
#include "../DownwellConstant.h"
/// <summary>
/// デストラクター
/// </summary>
BehaviorData::~BehaviorData()
{
	UpdateSequenceStep_.clear();
	UsedNode_.clear();

	while (SequenceStack_.size() > nZeroSize)
	{
		SequenceStack_.pop();
	}
}
/// <summary>
/// 初期化関数
/// </summary>
void BehaviorData::Init()
{
	UpdateSequenceStep_.clear();
	while (SequenceStack_.size() > nZeroSize)
	{
		SequenceStack_.pop();
	}
}
/// <summary>
/// シーケンスノードを追加する関数
/// </summary>
/// <param name="Node">追加するノード</param>
void BehaviorData::PushSequenceNode(Node* Node)
{
	SequenceStack_.push(Node);
}
/// <summary>
/// シーケンスノードからノードを取り除く関数
/// </summary>
/// <returns>取り除いたシーケンスノード</returns>
Node* BehaviorData::PopSequenceNode()
{
	if (SequenceStack_.empty() != 0)
	{
		return nullptr;
	}

	Node* node = SequenceStack_.top();

	if (node != nullptr)
	{
		SequenceStack_.pop();
	}

	return node;
}
/// <summary>
/// ノードが使われているか確認する関数
/// </summary>
/// <param name="Name">ノード名</param>
/// <returns>true : 使用　false : 未使用</returns>
bool BehaviorData::NodeUsedExist(std::string Name)
{
	if (UsedNode_.count(Name) == 0)
	{
		return false;
	}

	return UsedNode_[Name];
}
/// <summary>
/// 指定したノードを使用するときの命令関数
/// </summary>
/// <param name="Name">使用するノード名</param>
void BehaviorData::EntryUsedNode(std::string Name)
{
	UsedNode_[Name] = true;
}
/// <summary>
/// シーケンス番号取得関数
/// </summary>
/// <param name="Name">シーケンス名</param>
/// <returns></returns>
int BehaviorData::GetSequenceStep(std::string Name)
{
	if (UpdateSequenceStep_.count(Name) == 0)
	{
		UpdateSequenceStep_[Name] = 0;
	}
	return UpdateSequenceStep_[Name];
}
/// <summary>
/// シーケンス登録関数
/// </summary>
/// <param name="Name">シーケンス名</param>
/// <param name="nStep">シーケンス番号</param>
void BehaviorData::SetSequenceStep(std::string Name, int nStep)
{
	UpdateSequenceStep_[Name] = nStep;
}
/// <summary>
/// 使用しているノードのリセット関数
/// </summary>
/// <param name="ResetHierachy">リセットノード</param>
void BehaviorData::ResetUsedNode(std::vector<Node*>* ResetHierachy)
{
	for (auto itr = ResetHierachy->begin(); itr != ResetHierachy->end(); itr++)
	{
		UsedNode_[(*itr)->GetName()] = false;
	}
}





