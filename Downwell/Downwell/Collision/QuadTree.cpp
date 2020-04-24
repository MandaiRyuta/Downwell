#include "QuadTree.h"

QuadTree::QuadTree(int maxobj, int maxlevel, int level, Rect bound, QuadTree* parent) :
	maxobject_(maxobj),
	maxlevel_(maxlevel),
	level_(level),
	parent_(parent)
{
	bound_.x = bound.x;
	bound_.y = bound.y;
	bound_.width = bound.width;
	bound_.height = bound.height;
}

void QuadTree::Insert(std::shared_ptr<BoxCollider> object)
{
	//子ノードがあるかどうかを確認
	if (children[0] != nullptr)
	{
		//引数のobjectのノードに子ノードが存在した時、ノードのインデックスを返す
		int indexToPlaceObject = GetChildIndexForObject(object->GetCollidable());

		//インデックス番号が親番号と重複しないか確認し、重複しなければ挿入する。
		if (indexToPlaceObject != thisTree)
		{
			children[indexToPlaceObject]->Insert(object);
			return;
		}
	}

	//子ノードの確認が取れた後なのでノードの挿入
	objects_.emplace_back(object);

	//新しオブジェクトを追加したので、ノードで許可されているオブジェクトの最大数を超えているか確認
	if (objects_.size() > maxobject_&& level_ < maxlevel_ && children[0] == nullptr)
	{
		//オブジェクトの制限を超えている場合は子ノードを初期化する関数
		Split();

		//子ノードを分割したらこのノード内にすべてのオブジェクトを反復処理し、代わりの子ノード内にあるかどうかを計算
		auto objectiterator = objects_.begin();
		while (objectiterator != objects_.end())
		{
			auto obj = *objectiterator;
			int indexToPlaceObject = GetChildIndexForObject(obj->GetCollidable());

			// GetChildIndexForObject関数で受け取った配置場所と親のノード比較して親ノードと被らない場合は子ノードへと被った場合は次のノードを確認
			if (indexToPlaceObject != thisTree)
			{
				children[indexToPlaceObject]->Insert(obj);
				objectiterator = objects_.erase(objectiterator);
			}
			else
			{
				++objectiterator;
			}
		}
	}
}

void QuadTree::Remove(std::shared_ptr<BoxCollider> object)
{
	int index = GetChildIndexForObject(object->GetCollidable());

	if (index == thisTree || children[index] == nullptr)
	{
		for (int i = 0; i < objects_.size(); i++)
		{
			objects_.erase(objects_.begin() + i);
			break;
		}
	}
	else
	{
		return children[index]->Remove(object);
	}
}

void QuadTree::Clear()
{
	objects_.clear();

	for (int i = 0; i < 4; i++)
	{
		if (children[i] != nullptr)
		{
			children[i]->Clear();
			children[i] = nullptr;
		}
	}
}

std::vector<std::shared_ptr<BoxCollider>> QuadTree::Search(const Rect& area)
{
	std::vector<std::shared_ptr<BoxCollider>> possibleoverlaps;
	Search(area, possibleoverlaps);

	std::vector<std::shared_ptr<BoxCollider>> returnList;

	for (auto collider : possibleoverlaps)
	{
		if (area.HitCheck(collider->GetCollidable()))
		{
			returnList.emplace_back(collider);
		}
	}

	return returnList;
}

const Rect& QuadTree::GetBounds() const
{
	return bound_;
}

void QuadTree::Search(const Rect area, std::vector<std::shared_ptr<BoxCollider>>& overlappingobject)
{
	//すべてのオブジェクトを入れる。
	overlappingobject.insert(overlappingobject.end(), objects_.begin(), objects_.end());

	if (children[0] != nullptr)
	{
		int index = GetChildIndexForObject(area);

		if (index == thisTree)
		{
			for (int i = 0; i < 4; i++)
			{
				if (children[i]->GetBounds().HitCheck(area))
				{
					children[i]->Search(area, overlappingobject);
				}
			}
		}
		else
		{
			children[index]->Search(area, overlappingobject);
		}
	}
}

int QuadTree::GetChildIndexForObject(const Rect& objectbounds)
{
	int index = -1;

	double verticalDividingLine = bound_.x + bound_.width * 0.5f;
	double horizontalDividingLine = bound_.y + bound_.height * 0.5f;

	bool north = objectbounds.y <= horizontalDividingLine && (objectbounds.height + objectbounds.y <= horizontalDividingLine);
	bool south = objectbounds.y > horizontalDividingLine;
	bool west = objectbounds.x < verticalDividingLine && (objectbounds.x + objectbounds.width <= verticalDividingLine);
	bool east = objectbounds.x >= verticalDividingLine;

	if (east)
	{
		if (north)
		{
			index = childNE;
		}
		else if (south)
		{
			index = childSE;
		}
	}
	else if (west)
	{
		if (north)
		{
			index = childNW;
		}
		if (south)
		{
			index = childSW;
		}
	}

	return index;
}

void QuadTree::Split()
{
	const int childwidth = static_cast<int>(bound_.width * 0.5);
	const int childheight = static_cast<int>(bound_.height * 0.5);

	children[childNE] = std::make_shared<QuadTree>(maxobject_, maxlevel_, level_ + 1, Rect(bound_.x + childwidth, bound_.y, childwidth, childheight), this);
	children[childNW] = std::make_shared<QuadTree>(maxobject_, maxlevel_, level_ + 1, Rect(bound_.x, bound_.y, childwidth, childheight), this);
	children[childSW] = std::make_shared<QuadTree>(maxobject_, maxlevel_, level_ + 1, Rect(bound_.x, bound_.y + childheight, childwidth, childheight), this);
	children[childSE] = std::make_shared<QuadTree>(maxlevel_, maxlevel_, level_ + 1, Rect(bound_.x + childwidth, bound_.y + childheight, childwidth, childheight), this);

}
