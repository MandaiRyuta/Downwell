#include "Factory.h"
#include "EnemyParameter.h"
#include "EnemySeaUrchin.h"
#include "EnemyBird.h"
#include "EnemyTurtle.h"
#include "../Behaviour/TurnMoveAction.h"
#include "../Behaviour/BehaviorTree.h"
#include "../Behaviour/LoiteringMoveAction.h"
#include "../Behaviour/TrackingMoveAction.h"
#include "../Behaviour/LifeJudgment.h"
/// <summary>
/// GśŹÖ
/// </summary>
/// <param name="nEnemyNumber">GĚ`ćÔ</param>
/// <param name="nType">GĚíŢ</param>
/// <param name="nHp">GĚHP</param>
/// <param name="vPosition">GĚoťŔW</param>
/// <returns></returns>
EnemyParameter* CreateFactory::CreateInstance(int nEnemyNumber, int nType, int nHp, VECTOR vPosition)
{
	BehaviorTree behavior;

	switch (nType)
	{
	case 0:
		behavior.AddNode("", "Root", 0, TREE_RULE::PRIORITY, nullptr);
		behavior.AddNode("Root", "Move", 1, TREE_RULE::SEQUENTIALLOOP, TurnMoveAction::GetInstance());
		return new EnemyTurtle(nEnemyNumber, behavior, nHp, vPosition);
		break;
	case 1:
		behavior.AddNode("", "Root", 0, TREE_RULE::PRIORITY, nullptr);
		behavior.AddNode("Root", "Rotate", 1, TREE_RULE::SEQUENTIALLOOP, LoiterningMoveAction::GetInstance());
		return new EnemySeaUrchin(nEnemyNumber, behavior, nHp, vPosition);
		break;
	case 2:
		behavior.AddNode("", "Root", 0, TREE_RULE::PRIORITY, nullptr);
		behavior.AddNode("Root", "Move", 1, TREE_RULE::SEQUENTIALLOOP, TrackingMoveAction::GetInstance());
		return new EnemyBird(nEnemyNumber, behavior, nHp, vPosition);
		break;
	default:
		return nullptr;
		break;
	}
}
