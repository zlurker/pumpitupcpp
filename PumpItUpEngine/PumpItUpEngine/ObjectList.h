#pragma once
#include <vector>
#include <mutex>
#include "Object.h"

class ObjectList
{
public:
	ObjectList();
	const std::vector<Object>& GetObjectList();
	int AddObject(Object);
	void ClearAllObjects();

private:
	std::vector<Object> objectList;
	std::mutex listMutex;
};

