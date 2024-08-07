#pragma once
#include <vector>
#include "RatioRect.h"

class Animation
{
public:
	Animation(const std::vector<RatioRect>&);
	RatioRect* GetFrame(int);
private:
	std::vector<RatioRect> animationSequence;
};

