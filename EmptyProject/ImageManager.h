#pragma once
#include "Singleton.h"


struct Texture
{
	D3DXIMAGE_INFO info;
	LPDIRECT3DTEXTURE9 tex;
};

struct Color
{
	int r, g, b, a;
};
class ImageManager :
	public Singleton<ImageManager>
{
private:
	map<string, Texture*> m_Texture;
public:
	LPD3DXSPRITE sprite;
	
public:
	ImageManager();
	virtual ~ImageManager();
public:
	Texture *AddImage(string name, string route);
	vector<Texture*> AddAnimeImage(string route, int low, int size);
	void DrawImage(string name, D3DXVECTOR2 pos, float rotation = 0.0f, float scale = 1.0f, Color color = {255, 255, 255, 255});
	void DrawUI(string name, D3DXVECTOR2 pos, float rotation = 0.0f, float scale = 1.0f, Color color = { 255, 255, 255, 255 });
	void DrawImage(Texture *tex, D3DXVECTOR2 pos, float rotation = 0.0f, float scale = 1.0f, Color color = { 255, 255, 255, 255 });
};

#define IMAGEMANAGER ImageManager::GetInstance()