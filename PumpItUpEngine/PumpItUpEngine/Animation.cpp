#include "Animation.h"

Animation::Animation() {

}

Animation::Animation(const std::vector<RatioRect>& aS) {
	animationSequence = aS;
}

RatioRect* Animation::GetFrame(int frame) {
	return &animationSequence[frame % animationSequence.size()];
}