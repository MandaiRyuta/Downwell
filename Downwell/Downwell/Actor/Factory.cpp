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
/// ìGê∂ê¨ä÷êî
/// </summary>
/// <param name="nEnemyNumber">ìGÇÃï`âÊî‘çÜ</param>
/// <param name="nType">ìGÇÃéÌóﬁ</param>
/// <param name="nHp">ìGÇÃHP</param>
/// <param name="vPosition">ìGÇÃèoåªç¿ïW</param>
/// <returns></returns>
EnemyParameter* CreateFactory::CreateInstance(int nEnemyNumber, int nType, int nHp, VECTOR vPosition)
{
	BehaviorTree behavior;

	switch (nType)
	{
	case 0:
		behavior.AddNode("", "Root", 0, TREE_RULE::PRIORITY, nullptr);
		behavior.AddNode("Root", "Move", 1, TREE_RULE::SEQUENTIALLOOP, new TurnMoveAction);
		return new EnemyTurtle(nEnemyNumber, behavior, nHp, vPosition);
		break;
	case 1:
		behavior.AddNode("", "Root", 0, TREE_RULE::PRIORITY, nullptr);
		behavior.AddNode("Root", "Rotate", 1, TREE_RULE::SEQUENTIALLOOP,new LoiterningMoveAction);
		return new EnemySeaUrchin(nEnemyNumber, behavior, nHp, vPosition);
		break;
	case 2:
		behavior.AddNode("", "Root", 0, TREE_RULE::PRIORITY, nullptr);
		behavior.AddNode("Root", "Move", 1, TREE_RULE::SEQUENTIALLOOP,new TrackingMoveAction);
		return new EnemyBird(nEnemyNumber, behavior, nHp, vPosition);
		break;
	default:
		return nullptr;
		break;
	}
}
