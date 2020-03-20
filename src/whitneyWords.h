#pragma once

#include "ofMain.h"
#include "ofxPostProcessing.h"
#include "ofxBlur.h"
#include "ofxGui.h"
#include "BaseSketch.h"

class WhitneyWords : public BaseSketch {
    
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
    
    ofFbo fbo;
    
    ofxPostProcessing post;
    ofxBlur blur;
    
    ofxFloatSlider spacing;
    ofxFloatSlider alpha;
    ofxFloatSlider resolution;
    ofxPanel gui;
    
    bool mode;
    int drawMode;
    bool shouldShowDebugUI;
};

