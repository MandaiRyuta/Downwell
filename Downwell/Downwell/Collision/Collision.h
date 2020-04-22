#pragma once
#include <DxLib.h>
#include <math.h>
struct Rect
{
	float X, Y, Width, Height;

	Rect()
	{
		X = Y = Width = Height = 0;
	}
};

struct  Vector3
{
public:
	float x, y, z;

	Vector3(){}
	
	Vector3(float vecx, float vecy, float vecz)
		: x(vecx),
		y(vecy),
		z(vecz)
	{}

	Vector3 operator + (const Vector3 in) const 
	{
		Vector3 vec;
		vec.x = x + in.x;
		vec.y = y + in.y;
		vec.z = z + in.z;
		return vec;
	}

	Vector3 operator - (const Vector3 in) const 
	{
		Vector3 vec;
		vec.x = x - in.x;
		vec.y = y - in.y;
		vec.z = z - in.z;
		return vec;
	}
	
	Vector3 operator * (float in) const
	{
		Vector3 vec;
		vec.x = x * in;
		vec.y = y * in;
		vec.z = z * in;
	}
	
	Vector3 operator / (float in) const
	{
		Vector3 vec;

		if (in == 0.0f) 
		{
			return *this;
		}

		vec.x = x / in;
		vec.y = y / in;
		vec.z = z / in;

		return vec;
	}

	Vector3& operator += (const Vector3 dvec) {
		x += dvec.x;
		y += dvec.y;
		z += dvec.z;
		return *this;
	};

	Vector3& operator -= (const Vector3 dvec) {
		x -= dvec.x;
		y -= dvec.y;
		z -= dvec.z;
		return *this;
	};

	Vector3& operator *= (float fDat) {
		x *= fDat;
		y *= fDat;
		z *= fDat;
		return *this;
	};

	Vector3& operator /= (float fDat) {

		if (fDat == 0.0f) {
			return *this;
		}

		x /= fDat;
		y /= fDat;
		z /= fDat;
		return *this;
	};
};


bool ShapeCollision(Rect& moverect, Rect& targetrect)
{
	if (moverect.X <= targetrect.X + targetrect.Width &&
		moverect.X + (moverect.Width - (moverect.Width / 2)) >= targetrect.X &&
		moverect.Y <= targetrect.Y + targetrect.Height &&
		moverect.Y + (moverect.Height - (moverect.Height / 2)) >= targetrect.Y)
	{
		return true;
	}
	return false;
}

float Vec3Length(Vector3* pV)
{
	double x, y, z;
	double len;

	if (!pV) return 0.0f;

	x = (double)(pV->x);
	y = (double)(pV->y);
	z = (double)(pV->z);
	len = sqrt(x * x + y * y + z * z);

	return (float)(len);
}

int Vec3Normalize(Vector3* pOut, Vector3* pV)
{
	double len;
	double x, y, z;

	x = (double)(pV->x);
	y = (double)(pV->y);
	z = (double)(pV->z);
	len = sqrt(x * x + y * y + z * z);

	if (len < (1e-6)) return 0;

	len = 1.0 / len;
	x *= len;
	y *= len;
	z *= len;

	pOut->x = (float)x;
	pOut->y = (float)y;
	pOut->z = (float)z;

	return 1;
}

float Vec3Dot(Vector3* pV1, Vector3* pV2)
{
	return ((pV1->x) * (pV2->x) + (pV1->y) * (pV2->y) + (pV1->z) * (pV2->z));
}

void Vec3Cross(Vector3* pOut, Vector3* pV1, Vector3* pV2)
{
	Vector3 vec;
	double x1, y1, z1, x2, y2, z2;

	x1 = (double)(pV1->x);
	y1 = (double)(pV1->y);
	z1 = (double)(pV1->z);
	x2 = (double)(pV2->x);
	y2 = (double)(pV2->y);
	z2 = (double)(pV2->z);

	vec.x = (float)(y1 * z2 - z1 * y2);
	vec.y = (float)(z1 * x2 - x1 * z2);
	vec.z = (float)(x1 * y2 - y1 * x2);
	*pOut = vec;
}