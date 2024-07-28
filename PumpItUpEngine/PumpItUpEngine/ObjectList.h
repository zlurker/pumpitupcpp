#pragma once
#include <vector>
#include <mutex>
#include "Object.h"

class ObjectList
{
public:
	ObjectList();
	std::vector<Object*> GetObjectList();
	void AddObject(Object*);
	void ClearAllObjects();

private:
	std::vector<Object*>* objectList;
	std::mutex listMutex;
};

