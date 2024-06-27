#pragma once
#include <vector>
#include <mutex>
#include "Object.h"

class ObjectList
{
public:
	ObjectList();
	void AddObject(Object*);

private:
	std::vector<Object*>* objectList;
	std::mutex listMutex;
};

