#pragma once

#include "ofMain.h"
#include "ofxPostProcessing.h"
#include "ofxBlur.h"
#include "ofxGui.h"
#include "BaseSketch.h"

class EmergentWords : public BaseSketch {
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    void drawText(float xPos, float yPos, int color, vector<ofPolyline> sectionPolylines);
    void getPolylines(vector<ofPath> paths);
    void configureGUI();
    
    vector<vector<ofPolyline>> polylinesList;
    
    ofxPostProcessing post;
    ofxFloatSlider spacing;
    ofxFloatSlider alpha;
    ofxFloatSlider resolution;
    ofxPanel gui;
    
    ofEasyCam cam;
    
    bool mode;
    bool shouldShowDebugUI;
};

