#include "CircleGroupManager.h"

void CircleGroupManager::addCircleGroup(CircleGroup inputCircleGroup) {
    circleGroups.push_back(inputCircleGroup);
}

void CircleGroupManager::removeLastCircleGroup() {
    if (!circleGroups.empty()) {
        circleGroups.pop_back();
    }
}


void CircleGroupManager::drawCircleGroups(int alpha) {
    for (auto circleGroup: circleGroups) {
        circleGroup.draw(alpha);
    }
}
