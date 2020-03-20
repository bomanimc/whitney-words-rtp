#pragma once

#include "ofMain.h"
#include "ofxPostProcessing.h"
#include "ofxBlur.h"
#include "ofxGui.h"
#include "WhitneyWords.h"
#include "EmergentWords.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
    
        WhitneyWords whitneyWords;
        EmergentWords emergentWords;
};
