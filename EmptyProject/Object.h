#pragma once
class Object
{
protected:
	Vector2 pos;
	float rotation;
	float scale;
	bool destroy;
	Color color;

public:
	Object();
	virtual ~Object();

public:
	virtual void Init()		= 0;
	virtual void Update()	= 0;
	virtual void Render()	= 0;
	virtual void Release()	= 0;

public:
	bool GetDestroy() { return destroy; }
	void SetDestroy(bool _destroy) { destroy = _destroy; }

};

