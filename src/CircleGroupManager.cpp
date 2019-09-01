#include "CircleGroupManager.h"

void CircleGroupManager::addCircleGroup(CircleGroup inputCircleGroup) {
    circleGroups.push_back(inputCircleGroup);
}

void CircleGroupManager::drawCircleGroups(int alpha) {
    for (auto circleGroup: circleGroups) {
        circleGroup.draw(alpha);
    }
}
