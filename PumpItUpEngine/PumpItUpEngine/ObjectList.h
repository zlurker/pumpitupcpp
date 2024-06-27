#pragma once
#include <vector>
#include <mutex>
#include "Object.h"

class ObjectList
{
public:
	static void AddObject(Object* object) {
		std::lock_guard<std::mutex> guard(listMutex); // Lock the mutex
		objectList->push_back(object);
	}

private:
	static std::vector<Object*>* objectList;
	static std::mutex listMutex;
};

