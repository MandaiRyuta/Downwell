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
/// <param name="enemynumber">ìGÇÃï`âÊî‘çÜ</param>
/// <param name="ntype">ìGÇÃéÌóﬁ</param>
/// <param name="nhp">ìGÇÃHP</param>
/// <param name="nspeed">ìGÇÃà⁄ìÆó </param>
/// <param name="vposition">ìGÇÃèoåªç¿ïW</param>
/// <returns></returns>
EnemyParameter* CreateFactory::CreateInstance(int enemynumber, int ntype, int nhp, VECTOR vposition)
{
	BehaviorTree behavior;

	switch (ntype)
	{
	case 0:
		behavior.AddNode("", "Root", 0, TREE_RULE::PRIORITY, nullptr);
		behavior.AddNode("Root", "Move", 1, TREE_RULE::SEQUENTIALLOOP, TurnMoveAction::GetInstance());
		return new EnemyTurtle(enemynumber, behavior, nhp, vposition);
		break;
	case 1:
		behavior.AddNode("", "Root", 0, TREE_RULE::PRIORITY, nullptr);
		behavior.AddNode("Root", "Rotate", 1, TREE_RULE::SEQUENTIALLOOP, LoiterningMoveAction::GetInstance());
		return new EnemySeaUrchin(enemynumber, behavior, nhp, vposition);
		break;
	case 2:
		behavior.AddNode("", "Root", 0, TREE_RULE::PRIORITY, nullptr);
		behavior.AddNode("Root", "Move", 1, TREE_RULE::SEQUENTIALLOOP, TrackingMoveAction::GetInstance());
		return new EnemyBird(enemynumber, behavior, nhp, vposition);
		break;
	default:
		return nullptr;
		break;
	}
}
