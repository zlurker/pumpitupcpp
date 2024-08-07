#include "AnimationModule.h"

AnimationModule::AnimationModule() {

}

void AnimationModule::AddTarget(const AnimationTarget& target) {
	targets.push_back(target);
}

void AnimationModule::AddAnimation(const std::string& name, const Animation& animation) {
	animations[name] = animation;
}

void AnimationModule::Run() {
	while (true) {
		for (int i = 0; i < targets.size(); i++) {
			targets[i].GetTargetObject();
		}
	}
}
