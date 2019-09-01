#include "CircleGroup.h"

CircleGroup::CircleGroup(ofVec2f inputPosition, int inputThickness, int inputColor) {
    startingPos = inputPosition;
    color = inputColor;
    thickness = inputThickness;
}

void CircleGroup::draw(float radius, int alpha, int numCirclesInGroup) {
    float staticRadius = 70;
    float angle = TWO_PI / (float) numCirclesInGroup;
    
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
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
