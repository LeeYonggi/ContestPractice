#include "DXUT.h"
#include "Object.h"




Object::~Object()
{
}

void Object::Draw()
{
	IMAGEMANAGER->DrawImage(texture, pos, rotation, scale, color);
}
