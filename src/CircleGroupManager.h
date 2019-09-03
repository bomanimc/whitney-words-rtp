#pragma once

#include "ofMain.h"
#include "CircleGroup.h"

class CircleGroupManager {
    vector<CircleGroup> circleGroups;
    
public:
    void addCircleGroup(CircleGroup inputCircleGroup);
    void removeLastCircleGroup();
    void drawCircleGroups(int alpha);
};
