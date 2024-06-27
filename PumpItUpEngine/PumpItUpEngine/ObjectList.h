#pragma once
#include <vector>
#include <mutex>
#include "Object.h"

class ObjectList
{
public:
	static void AddObject(Object* object) {
		objectList.push_back(object);
	}

private:
	static std::vector<Object*> objectList;
	static std::mutex mutex;
};

