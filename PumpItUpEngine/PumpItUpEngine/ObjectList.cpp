#include "ObjectList.h"

ObjectList::ObjectList() {
	objectList = new std::vector<Object*>();
}

std::vector<Object*> ObjectList::GetObjectList() {
	return *objectList;
}

void ObjectList::AddObject(Object* object) {
	std::lock_guard<std::mutex> guard(listMutex); // Lock the mutex
	objectList->push_back(object);
}

void ObjectList::ClearAllObjects() {
	std::lock_guard<std::mutex> guard(listMutex); // Lock the mutex
	objectList->clear();
}