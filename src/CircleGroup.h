#pragma once

#include "ofMain.h"
#define NUM_CIRCLES_IN_GROUP 500

class CircleGroup {
    ofVec2f startingPos;
    int thickness;
    int color;
    
    public:
        CircleGroup(ofVec2f inputPosition, int inputThickness, int inputColor);
        void draw(float radius, int alpha, int numCirclesInGroup = NUM_CIRCLES_IN_GROUP);
};
