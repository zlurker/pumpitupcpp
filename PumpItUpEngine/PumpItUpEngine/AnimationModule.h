#pragma once
#include <vector>
#include <unordered_map>
#include "Animation.h"
#include "AnimationTarget.h"

class AnimationModule
{
public:
	AnimationModule();
	void AddTarget(const AnimationTarget&);
	void AddAnimation(const std::string&, const Animation&);
	void Run();

private:
	std::vector<AnimationTarget> targets;
	std::unordered_map<std::string, Animation> animations;
};