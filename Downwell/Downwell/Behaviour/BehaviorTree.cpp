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
/// <param name="Enemy">推論するノード</param>
/// <param name="Data">推論するビヘイビアデータ</param>
/// <returns>推論し終えた親ノード</returns>
Node* BehaviorTree::Inference(EnemyParameter* Enemy, BehaviorData* Data)
{
	Data->Init();
	return Root_->Inference(Enemy, Data);
}
/// <summary>
/// シーケンスノードを推論する関数
/// </summary>
/// <param name="SequenceNode">シーケンスノード</param>
/// <param name="Enemy">推論する敵情報</param>
/// <param name="Data">推論するビヘイビアデータ</param>
/// <returns>推論し終えたノード</returns>
Node* BehaviorTree::SequenceBack(Node* SequenceNode, EnemyParameter* Enemy, BehaviorData* Data)
{
	return SequenceNode->Inference(Enemy, Data);;
}
/// <summary>
/// ノード追加関数
/// </summary>
/// <param name="SearchName">ノード名</param>
/// <param name="EntryName">ノード名</param>
/// <param name="nPriority">優先度</param>
/// <param name="nSelectRule">ルール</param>
/// <param name="judgment">判定クラス</param>
/// <param name="Action">行動クラス</param>
void BehaviorTree::AddNode(std::string SearchName, std::string EntryName, int nPriority, TREE_RULE nSelectRule, ActionBase* Action)
{
	if (SearchName == "")
	{
		Root_ = new Node(EntryName, NULL, NULL, nPriority, nSelectRule, Action, 1);
	}
	else
	{
		Node* search = Root_->SearchNode(SearchName);

		if (search != nullptr)
		{
			Node* sibling = search->GetLastChild();
			Add_Node_ = new Node(EntryName, search, sibling, nPriority, nSelectRule, Action, search->GetHierarchyNumber() + 1);

			search->AddChild(Add_Node_);
		}
	}
}
/// <summary>
/// 更新関数
/// </summary>
/// <param name="Enemy">敵情報</param>
/// <param name="ActionNode">行動ノード</param>
/// <param name="Data">ビヘイビアデータ</param>
/// <returns>ルールで判別し終えた行動ノード</returns>
Node* BehaviorTree::Run(EnemyParameter& Enemy, Node* ActionNode, BehaviorData* Data)
{
	ActionBase::STATE state = ActionNode->Run(Enemy);

	if (state == ActionBase::STATE::COMPLETE)
	{
		Node* SequenceNode = Data->PopSequenceNode();

		if (SequenceNode == nullptr)
		{
			return nullptr;
		}
		else
		{
			return SequenceBack(SequenceNode, &Enemy, Data);
		}
	}
	else if (state == ActionBase::STATE::FAILED)
	{
		return nullptr;
	}

	return ActionNode;
}
