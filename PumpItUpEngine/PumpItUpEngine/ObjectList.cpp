#include "ObjectList.h"

ObjectList::ObjectList() {
	objectList = new std::vector<Object*>();
}

void ObjectList::AddObject(Object* object) {
	std::lock_guard<std::mutex> guard(listMutex); // Lock the mutex
	objectList->push_back(object);
}