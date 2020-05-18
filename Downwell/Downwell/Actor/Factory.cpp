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
EnemyParameter* CreateFactory::CreateInstance(int enemynumber, int ntype, int nhp, int nspeed, VECTOR vposition)
{
	BehaviorTree behavior;

	switch (ntype)
	{
	case 0:
		behavior.AddNode("", "Root", 0, TREE_RULE::PRIORITY, nullptr, nullptr);
		behavior.AddNode("Root", "Move", 1, TREE_RULE::SEQUENTIALLOOP, LifeJudgment::GetInstance(), TurnMoveAction::GetInstance());
		return new EnemyTurtle(enemynumber, behavior, nhp, nspeed, vposition);
		break;
	case 1:
		behavior.AddNode("", "Root", 0, TREE_RULE::PRIORITY, nullptr, nullptr);
		behavior.AddNode("Root", "Rotate", 1, TREE_RULE::SEQUENTIALLOOP, LifeJudgment::GetInstance(), LoiterningMoveAction::GetInstance());
		return new EnemySeaUrchin(enemynumber, behavior, nhp, nspeed, vposition);
		break;
	case 2:
		behavior.AddNode("", "Root", 0, TREE_RULE::PRIORITY, nullptr, nullptr);
		behavior.AddNode("Root", "Move", 1, TREE_RULE::SEQUENTIALLOOP, LifeJudgment::GetInstance(), TrackingMoveAction::GetInstance());
		return new EnemyBird(enemynumber, behavior, nhp, nspeed, vposition);
		break;
	default:
		return nullptr;
		break;
	}
}
