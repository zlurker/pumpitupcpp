#pragma once
#include <string>
#include "Object.h"
class AnimationTarget
{
public:
	AnimationTarget(Object*,const std::string&);
	const Object* GetTargetObject();
	const std::string* GetAnimationName();
private:
	Object* targetObject;
	std::string animationName;
};

