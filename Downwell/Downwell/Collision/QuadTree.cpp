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
	//�q�m�[�h�����邩�ǂ������m�F
	if (children[0] != nullptr)
	{
		//������object�̃m�[�h�Ɏq�m�[�h�����݂������A�m�[�h�̃C���f�b�N�X��Ԃ�
		int indexToPlaceObject = GetChildIndexForObject(object->GetCollidable());

		//�C���f�b�N�X�ԍ����e�ԍ��Əd�����Ȃ����m�F���A�d�����Ȃ���Α}������B
		if (indexToPlaceObject != thisTree)
		{
			children[indexToPlaceObject]->Insert(object);
			return;
		}
	}

	//�q�m�[�h�̊m�F����ꂽ��Ȃ̂Ńm�[�h�̑}��
	objects_.emplace_back(object);

	//�V���I�u�W�F�N�g��ǉ������̂ŁA�m�[�h�ŋ�����Ă���I�u�W�F�N�g�̍ő吔�𒴂��Ă��邩�m�F
	if (objects_.size() > maxobject_&& level_ < maxlevel_ && children[0] == nullptr)
	{
		//�I�u�W�F�N�g�̐����𒴂��Ă���ꍇ�͎q�m�[�h������������֐�
		Split();

		//�q�m�[�h�𕪊������炱�̃m�[�h���ɂ��ׂẴI�u�W�F�N�g�𔽕��������A����̎q�m�[�h���ɂ��邩�ǂ������v�Z
		auto objectiterator = objects_.begin();
		while (objectiterator != objects_.end())
		{
			auto obj = *objectiterator;
			int indexToPlaceObject = GetChildIndexForObject(obj->GetCollidable());

			// GetChildIndexForObject�֐��Ŏ󂯎�����z�u�ꏊ�Ɛe�̃m�[�h��r���Đe�m�[�h�Ɣ��Ȃ��ꍇ�͎q�m�[�h�ւƔ�����ꍇ�͎��̃m�[�h���m�F
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
	//���ׂẴI�u�W�F�N�g������B
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
