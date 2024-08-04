#include "ObjectList.h"

ObjectList::ObjectList() {
}

const std::vector<Object>& ObjectList::GetObjectList() {
	return objectList;
}

int ObjectList::AddObject(Object object) {
	std::lock_guard<std::mutex> guard(listMutex); // Lock the mutex
	float objectId = objectList.size();
	objectList.push_back(object);
	return objectId;
}

void ObjectList::ClearAllObjects() {
	std::lock_guard<std::mutex> guard(listMutex); // Lock the mutex
	objectList.clear();
}