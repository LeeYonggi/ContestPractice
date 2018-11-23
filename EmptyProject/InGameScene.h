#pragma once



enum STAGE_STATE
{
	STAGE1,
	STAGE2,
	STAGE3
};
class InGameScene :
	public Scene
{
public:
	InGameScene();
	~InGameScene();
	
private:
	STAGE_STATE stageKind;

public:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;

};

