#include "DXUT.h"
#include "ObjectManager.h"


ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{

}

void ObjectManager::Init()
{
	for (int i = 0; i < OBJECT_SIZE; i++)
		m_Object.insert(make_pair(OBJECT_STATE(i), new vector<Object*>));
}

void ObjectManager::Update()
{
	for (auto iter : m_Object)
	{
		for (auto _iter = iter.second->begin(); _iter != iter.second->end(); )
		{
			if ((*_iter)->GetDestroy())
			{
				_iter = iter.second->erase(_iter);
			}
			else
				++_iter;
		}
	}
}

void ObjectManager::Render()
{
	for (auto iter : m_Object)
	{
		for (auto _iter : *iter.second)
		{
			_iter->Render();
		}
	}
}

void ObjectManager::Release()
{
	for (auto iter : m_Object)
	{
		for (auto _iter : *iter.second)
		{
			SAFE_RELEASE(_iter);
			SAFE_DELETE(_iter);
		}
		iter.second->clear();
		SAFE_DELETE(iter.second);
	}
	m_Object.clear();
}

Object* ObjectManager::AddObject(OBJECT_STATE state, Object * obj)
{
	auto iter = m_Object.find(state);
	if (iter == m_Object.end()) return nullptr;

	iter->second->push_back(obj);

	return obj;
}

vector<Object*>* ObjectManager::GetObjects(OBJECT_STATE state)
{
	return nullptr;
}
