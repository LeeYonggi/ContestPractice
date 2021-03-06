#include "DXUT.h"
#include "ImageManager.h"


ImageManager::ImageManager()
{
	D3DXCreateSprite(DXUTGetD3D9Device(), &sprite);
	
}


ImageManager::~ImageManager()
{
	for (auto iter : m_Texture)
	{
		SAFE_RELEASE(iter.second->tex)
		SAFE_DELETE(iter.second);
	}
	m_Texture.clear();

	SAFE_RELEASE(sprite);
}

Texture *ImageManager::AddImage(string name, string route)
{
	auto iter = m_Texture.find(name);

	if (iter != m_Texture.end()) return iter->second;

	Texture *texture = new Texture;
	D3DXCreateTextureFromFileExA(DXUTGetD3D9Device(), route.c_str(),
		D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2,
		0, 0, D3DFMT_A8B8G8R8, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0,
		&texture->info, NULL, &texture->tex);

	m_Texture.insert(make_pair(name, texture));
	return texture;
}

vector<Texture*> ImageManager::AddAnimeImage(string route, int low, int size)
{
	vector<Texture*> vTempTex;

	for (int i = low; i <= size; i++)
	{
		char ctr[128];
		sprintf(ctr, route.c_str(), i);

		vTempTex.push_back(AddImage(ctr, ctr));
	}

	return vTempTex;
}

void ImageManager::DrawImage(string name, D3DXVECTOR2 pos, float rotation, float scale, Color color)
{
	auto iter = m_Texture.find(name);
	if (iter == m_Texture.end()) return;

	D3DXMATRIX matWorld, matT, matR, matS;
	D3DXMATRIX matCam;

	D3DXMatrixScaling(&matS, scale, scale, 1);
	D3DXMatrixRotationZ(&matR, D3DXToRadian(rotation));
	D3DXMatrixTranslation(&matT, pos.x, pos.y, 0);
	D3DXMatrixTranslation(&matCam, CAMERAMANAGER->camPos.x, CAMERAMANAGER->camPos.y, 0);

	matWorld = matS * matR * matT * matCam;

	sprite->SetTransform(&matWorld);

	D3DXVECTOR3 center = { (float)(iter->second->info.Width / 2),  (float)(iter->second->info.Height / 2), 0 };

	sprite->Draw(iter->second->tex, nullptr, &center, nullptr, D3DCOLOR_RGBA(color.r, color.g, color.b, color.a));
 }

void ImageManager::DrawUI(string name, D3DXVECTOR2 pos, float rotation, float scale, Color color)
{
	auto iter = m_Texture.find(name);
	if (iter == m_Texture.end()) return;

	D3DXMATRIX matWorld, matT, matR, matS;

	D3DXMatrixScaling(&matS, scale, scale, 1);
	D3DXMatrixRotationZ(&matR, D3DXToRadian(rotation));
	D3DXMatrixTranslation(&matT, pos.x, pos.y, 0);

	matWorld = matS * matR * matT;

	sprite->SetTransform(&matWorld);

	D3DXVECTOR3 center = { (float)(iter->second->info.Width / 2),  (float)(iter->second->info.Height / 2), 0 };

	sprite->Draw(iter->second->tex, nullptr, &center, nullptr, D3DCOLOR_RGBA(color.r, color.g, color.b, color.a));
}

void ImageManager::DrawImage(Texture * tex, D3DXVECTOR2 pos, float rotation, float scale, Color color)
{
	D3DXMATRIX matWorld, matT, matR, matS;
	D3DXMATRIX matCam;

	D3DXMatrixScaling(&matS, scale, scale, 1);
	D3DXMatrixRotationZ(&matR, D3DXToRadian(rotation));
	D3DXMatrixTranslation(&matT, pos.x, pos.y, 0);
	D3DXMatrixTranslation(&matCam, CAMERAMANAGER->camPos.x, CAMERAMANAGER->camPos.y, 0);

	matWorld = matS * matR * matT * matCam;

	sprite->SetTransform(&matWorld);

	D3DXVECTOR3 center = { (float)(tex->info.Width / 2),  (float)(tex->info.Height / 2), 0 };

	sprite->Draw(tex->tex, nullptr, &center, nullptr, D3DCOLOR_RGBA(color.r, color.g, color.b, color.a));
}
