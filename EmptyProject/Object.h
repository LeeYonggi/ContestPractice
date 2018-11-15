#pragma once
class Object
{
protected:
	Vector2 pos;
	float rotation;
	float scale;
	bool destroy;
	bool active;
	Color color;
	Texture *texture;

public:
	Object()
		: pos({ 0, 0 }), rotation(0), scale(1.0f), destroy(false), active(true), color({255, 255, 255, 255})
	{

	}
	virtual ~Object();

public:
	virtual void Init()		= 0;
	virtual void Update()	= 0;
	virtual void Render()	= 0;
	virtual void Release()	= 0;

public:
	void SetPos(Vector2 vec2) { pos = vec2; }
	Vector2 GetPosition() { return pos; }

	bool GetDestroy() { return destroy; }
	void SetDestroy(bool _destroy) { destroy = _destroy; }

	bool GetActive() { return active; }
	void SetActive(bool _active) { active = _active; }
	void Draw();
};

