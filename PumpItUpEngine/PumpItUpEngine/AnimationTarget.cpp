#include "AnimationTarget.h"

AnimationTarget::AnimationTarget(Object* tO, const std::string& aN) {
	targetObject = tO;
	animationName = aN;
}

const Object* AnimationTarget::GetTargetObject() {
	return targetObject;
}

const std::string* AnimationTarget::GetAnimationName() {
	return &animationName;
}