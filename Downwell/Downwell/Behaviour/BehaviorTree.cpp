#include "BehaviorTree.h"
#include "ActionBase.h"
#include "Node.h"
#include "../Actor/EnemyParameter.h"
#include "BehaviorData.h"
/// <summary>
/// 解放関数
/// </summary>
void BehaviorTree::Release()
{
	if (Add_Node_ != nullptr)
	{
		delete Add_Node_;
	}
	if (Root_ != nullptr)
	{
		delete Root_;
	}
}
/// <summary>
/// 実行ノードを推論する関数
/// </summary>
/// <param name="enemy">推論するノード</param>
/// <param name="data">推論するビヘイビアデータ</param>
/// <returns>推論し終えた親ノード</returns>
Node* BehaviorTree::Inference(EnemyParameter* enemy, BehaviorData* data)
{
	data->Init();
	return Root_->Inference(enemy, data);
}
/// <summary>
/// シーケンスノードを推論する関数
/// </summary>
/// <param name="sequence_node">シーケンスノード</param>
/// <param name="enemy">推論する敵情報</param>
/// <param name="data">推論するビヘイビアデータ</param>
/// <returns>推論し終えたノード</returns>
Node* BehaviorTree::SequenceBack(Node* sequence_node, EnemyParameter* enemy, BehaviorData* data)
{
	return sequence_node->Inference(enemy, data);;
}
/// <summary>
/// ノード追加関数
/// </summary>
/// <param name="search_name">ノード名</param>
/// <param name="entry_name">ノード名</param>
/// <param name="priority">優先度</param>
/// <param name="select_rule">ルール</param>
/// <param name="judgment">判定クラス</param>
/// <param name="action">行動クラス</param>
void BehaviorTree::AddNode(std::string search_name, std::string entry_name, int priority, TREE_RULE select_rule, ActionBase* action)
{
	if (search_name == "")
	{
		Root_ = new Node(entry_name, NULL, NULL, priority, select_rule, action, 1);
	}
	else
	{
		Node* search = Root_->SearchNode(search_name);

		if (search != nullptr)
		{
			Node* sibling = search->GetLastChild();
			Add_Node_ = new Node(entry_name, search, sibling, priority, select_rule, action, search->GetHierarchyNumber() + 1);

			search->AddChild(Add_Node_);
		}
	}
}
/// <summary>
/// 更新関数
/// </summary>
/// <param name="enemy">敵情報</param>
/// <param name="actionnode">行動ノード</param>
/// <param name="data">ビヘイビアデータ</param>
/// <returns>ルールで判別し終えた行動ノード</returns>
Node* BehaviorTree::Run(EnemyParameter* enemy, Node* actionnode, BehaviorData* data)
{
	ActionBase::STATE state = actionnode->Run(enemy);

	if (state == ActionBase::STATE::COMPLETE)
	{
		Node* sequence_node = data->PopSequenceNode();

		if (sequence_node == nullptr)
		{
			return nullptr;
		}
		else
		{
			return SequenceBack(sequence_node, enemy, data);
		}
	}
	else if (state == ActionBase::STATE::FAILED)
	{
		return nullptr;
	}

	return actionnode;
}
