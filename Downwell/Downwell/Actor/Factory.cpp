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
/// <param name="enemynumber">GĚ`ćÔ</param>
/// <param name="ntype">GĚíŢ</param>
/// <param name="nhp">GĚHP</param>
/// <param name="nspeed">GĚÚŽĘ</param>
/// <param name="vposition">GĚoťŔW</param>
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
