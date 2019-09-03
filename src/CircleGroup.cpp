#include "CircleGroup.h"

CircleGroup::CircleGroup(ofVec2f inputPosition, int inputThickness, int inputColor, float inputStartTime) {
    startingPos = inputPosition;
    color = inputColor;
    thickness = inputThickness;
    startingTime = inputStartTime;
}

void CircleGroup::draw(int alpha, int numCirclesInGroup) {
    float staticRadius = 70;
    float angle = TWO_PI / (float) numCirclesInGroup;
    float timeSinceAdded = ofGetElapsedTimef() - startingTime;
    float radius = 200 * sin(0.1 * timeSinceAdded);
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetColor(ofColor::fromHex(color, alpha));
    ofPushMatrix();
    ofTranslate(startingPos.x, startingPos.y);
    
    // Draw the inner ring
    for (int i = 0; i < numCirclesInGroup; i++) {
        ofDrawCircle(staticRadius * sin(angle * i), staticRadius * cos(angle * i), radius);
    }
    
    // Draw the outer ring
    float outerRingRadius = staticRadius + thickness;
    for (int i = 0; i < numCirclesInGroup; i++) {
        ofDrawCircle(outerRingRadius * sin(angle * i), outerRingRadius * cos(angle * i), radius + thickness);
    }
    
    ofPopMatrix();
    ofDisableBlendMode();
}
