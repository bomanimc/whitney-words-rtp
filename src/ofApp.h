#pragma once

#include "ofMain.h"
#include "ofxPostProcessing.h"
#include "ofxBlur.h"
#include "ofxDatGui.h"
#include "WhitneyWords.h"
#include "EmergentWords.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
        void configureGUI();
        void setupSketches();
    
        WhitneyWords whitneyWords;
        EmergentWords emergentWords;
    
        string currentSketch;
};
