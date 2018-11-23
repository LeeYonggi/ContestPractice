#include "DXUT.h"
#include "Object.h"




Object::~Object()
{
}

bool Object::CircleCollision(Vector2 pos1, Vector2 pos2, float radius1, float radius2)
{
	float tempX = pos2.x - pos1.x;
	float tempY = pos2.y - pos1.y;

	float radius = tempX * tempX + tempY * tempY;

	if (sqrt(radius) < radius1 + radius2) return true;
	return false;
}

Vector2 Object::TrackingPos(Object * obj)
{
	Vector2 temp = obj->GetPosition() - pos;

	D3DXVec2Normalize(&temp, &temp);

	return temp;
}

float Object::GetTargetAngle(Object * obj)
{
	return D3DXToDegree(atan2f(obj->GetPosition().y - pos.y, obj->GetPosition().x - pos.x));
}

void Object::Draw()
{
	IMAGEMANAGER->DrawImage(texture, pos, rotation, scale, color);
}
