#include "Factory.h"
#include "EnemyParameter.h"
#include "EnemyBigSeaUrchin.h"
#include "EnemyBird.h"
#include "EnemyMask.h"
#include "EnemySeaUrchin.h"
#include "EnemySkeleton.h"
#include "EnemySlime.h"
#include "EnemySnake.h"
#include "EnemySoul.h"
#include "EnemySquid.h"
#include "EnemyTurtle.h"
#include "../Behaviour/BehaviorTree.h"

EnemyParameter* CreateFactory::CreateInstance(int ntype, int nhp, int nspeed)
{
	BehaviorTree behavior;

	switch (ntype)
	{
	case 0:
		behavior.AddNode("", "Root", 0, TREE_RULE::PRIORITY, nullptr, nullptr);
		behavior.AddNode("Root", "Move", 0, TREE_RULE::SEQUENTIALLOOP, nullptr, nullptr);
		return new EnemySnake(&behavior, nhp, nspeed);
		break;
	case 1:
		behavior.AddNode("", "Root", 0, TREE_RULE::PRIORITY, nullptr, nullptr);
		behavior.AddNode("Root", "Move", 0, TREE_RULE::SEQUENTIALLOOP, nullptr, nullptr);
		return new EnemyTurtle(&behavior, nhp, nspeed);
		break;
	case 2:
		behavior.AddNode("", "Root", 0, TREE_RULE::PRIORITY, nullptr, nullptr);
		behavior.AddNode("Root", "Move", 0, TREE_RULE::SEQUENTIALLOOP, nullptr, nullptr);
		return new EnemySquid(&behavior, nhp, nspeed);
	case 3:
		behavior.AddNode("", "Root", 0, TREE_RULE::PRIORITY, nullptr, nullptr);
		behavior.AddNode("Root", "Move", 0, TREE_RULE::SEQUENTIALLOOP, nullptr, nullptr);
		return new EnemySlime(&behavior, nhp, nspeed);
		break;
	case 4:
		behavior.AddNode("", "Root", 0, TREE_RULE::PRIORITY, nullptr, nullptr);
		behavior.AddNode("Root", "Move", 0, TREE_RULE::SEQUENTIALLOOP, nullptr, nullptr);
		return new EnemySkeleton(&behavior, nhp, nspeed);
		break;
	case 5:
		behavior.AddNode("", "Root", 0, TREE_RULE::PRIORITY, nullptr, nullptr);
		behavior.AddNode("Root", "Move", 0, TREE_RULE::SEQUENTIALLOOP, nullptr, nullptr);
		return new EnemySeaUrchin(&behavior, nhp, nspeed);
		break;
	case 6:
		behavior.AddNode("", "Root", 0, TREE_RULE::PRIORITY, nullptr, nullptr);
		behavior.AddNode("Root", "Move", 0, TREE_RULE::SEQUENTIALLOOP, nullptr, nullptr);
		return new EnemyMask(&behavior, nhp, nspeed);
		break;
	case 7:
		behavior.AddNode("", "Root", 0, TREE_RULE::PRIORITY, nullptr, nullptr);
		behavior.AddNode("Root", "Move", 0, TREE_RULE::SEQUENTIALLOOP, nullptr, nullptr);
		return new EnemyBird(&behavior, nhp, nspeed);
		break;
	case 8:
		behavior.AddNode("", "Root", 0, TREE_RULE::PRIORITY, nullptr, nullptr);
		behavior.AddNode("Root", "Move", 0, TREE_RULE::SEQUENTIALLOOP, nullptr, nullptr);
		return new EnemyBigSeaUrchin(&behavior, nhp, nspeed);
		break;
	default:
		return nullptr;
		break;
	}
}
