#pragma once

class InGameScene :
	public Scene
{
public:
	InGameScene();
	~InGameScene();
	
private:


public:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;

};

