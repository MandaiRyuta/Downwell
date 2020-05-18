#include "BehaviorData.h"
#include "Node.h"
/// <summary>
/// デストラクター
/// </summary>
BehaviorData::~BehaviorData()
{
	UpdateSequenceStep_.clear();
	UsedNode_.clear();

	while (SequenceStack_.size() > 0)
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
	while (SequenceStack_.size() > 0)
	{
		SequenceStack_.pop();
	}
}
/// <summary>
/// シーケンスノードを追加する関数
/// </summary>
/// <param name="node">追加するノード</param>
void BehaviorData::PushSequenceNode(Node* node)
{
	SequenceStack_.push(node);
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
/// <param name="name">ノード名</param>
/// <returns>true : 使用　false : 未使用</returns>
bool BehaviorData::NodeUsedExist(std::string name)
{
	if (UsedNode_.count(name) == 0)
	{
		return false;
	}

	return UsedNode_[name];
}
/// <summary>
/// 指定したノードを使用するときの命令関数
/// </summary>
/// <param name="name">使用するノード名</param>
void BehaviorData::EntryUsedNode(std::string name)
{
	UsedNode_[name] = true;
}
/// <summary>
/// シーケンス番号取得関数
/// </summary>
/// <param name="name">シーケンス名</param>
/// <returns></returns>
int BehaviorData::GetSequenceStep(std::string name)
{
	if (UpdateSequenceStep_.count(name) == 0)
	{
		UpdateSequenceStep_[name] = 0;
	}
	return UpdateSequenceStep_[name];
}
/// <summary>
/// シーケンス登録関数
/// </summary>
/// <param name="name">シーケンス名</param>
/// <param name="step">シーケンス番号</param>
void BehaviorData::SetSequenceStep(std::string name, int step)
{
	UpdateSequenceStep_[name] = step;
}
/// <summary>
/// 使用しているノードのリセット関数
/// </summary>
/// <param name="reset_hierachy">リセットノード</param>
void BehaviorData::ResetUsedNode(std::vector<Node*>* reset_hierachy)
{
	for (auto itr = reset_hierachy->begin(); itr != reset_hierachy->end(); itr++)
	{
		UsedNode_[(*itr)->GetName()] = false;
	}
}





