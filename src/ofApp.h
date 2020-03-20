#pragma once

#include "ofMain.h"
#include "ofxPostProcessing.h"
#include "ofxBlur.h"
#include "ofxGui.h"
#include "whitneyWords.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
    
    void drawDebugUI();
    void drawWordWithBlur();
    void drawWordWithFBO();
    void drawWord();
    void drawSection(vector<ofPath> paths, float xPos, float yPos, int color);
    void resetBlendingSettings();
    void configureGUI();
//    void configureText(string word);
    
    ofFbo fbo;
    
    ofTrueTypeFont font;
    ofRectangle boundingRect;
    vector<int> colors{0xff5252, 0x706fd3};
    vector<vector<ofPath>> textSections;
    float textXPos;
    float textYPos;
    
    ofxPostProcessing post;
    ofxBlur blur;
    
    ofxFloatSlider spacing;
    ofxFloatSlider alpha;
    ofxFloatSlider resolution;
    ofxPanel gui;
    
    bool mode;
    int drawMode;
    bool shouldShowDebugUI;
    
    WhitneyWords whitneyWords;
};
