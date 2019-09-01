#pragma once

#include "ofMain.h"
#define NUM_CIRCLES_IN_GROUP 500

class CircleGroup {
    ofVec2f startingPos;
    int thickness;
    int color;
    float startingTime;
    
    public:
        CircleGroup(ofVec2f inputPosition, int inputThickness, int inputColor, float inputStartTime);
        void draw(int alpha, int numCirclesInGroup = NUM_CIRCLES_IN_GROUP);
};
