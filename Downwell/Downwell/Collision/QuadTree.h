#pragma once
#include "../Constant.h"

struct Rect
{
	float x;
	float y;
	float height;
	float width;

public:
	Rect()
	{
		x = y = height = width = 0.0f;
	}
	Rect(float fx, float fy, float fwidth, float fheight)
	{
		x = fx;
		y = fy;
		width = fwidth;
		height = fheight;
	}
	~Rect(){}

	bool HitCheck(const Rect& targetrect) const
	{
		if (x + width > targetrect.x && x < targetrect.x + targetrect.width)
		{
			if (y + height > targetrect.y && y < targetrect.y + targetrect.height)
			{
				return true;
			}
		}

		return false;
	}
};

class BoxCollider
{
public:
	BoxCollider() {}
	BoxCollider(float x, float y, float width, float height)
	{
		rect_.x = x;
		rect_.y = y;
		rect_.width = width;
		rect_.height = height;
	}
	~BoxCollider() {}

	const Rect& GetCollidable()
	{
		return rect_;
	}

	Rect rect_;
};

class QuadTree
{
public:
	QuadTree() 
	{
		maxobject_ = 0;
		parent_ = nullptr;
		maxlevel_ = 0;
		level_ = 0;
	}
	QuadTree(int maxobj, int maxlevel, int level, Rect bounds, QuadTree* parent);
	
	void Insert(std::shared_ptr<BoxCollider> object);
	//指定のレイヤーに配属されているコリジョンを削除するとき
	void Remove(std::shared_ptr<BoxCollider> object);
	//消去
	void Clear();

	std::vector<std::shared_ptr<BoxCollider>>
		Search(const Rect& area);

	const Rect& GetBounds() const;

private:
	void Search(const Rect area, std::vector<std::shared_ptr<BoxCollider>>& overlappingobject);
	int GetChildIndexForObject(const Rect& objectbounds);
	void Split();

	static const int thisTree = -1;
	static const int childNE = 0;
	static const int childNW = 1;
	static const int childSW = 2;
	static const int childSE = 3;

	int maxobject_;
	int maxlevel_;

	QuadTree* parent_;
	std::shared_ptr<QuadTree> children[4];
	std::vector<std::shared_ptr<BoxCollider>> objects_;
	int level_;
	Rect bound_;
};
