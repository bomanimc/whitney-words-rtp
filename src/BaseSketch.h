#pragma once
#include "ofApp.h"

class BaseSketch {
public:
    ofTrueTypeFont font;
    ofRectangle boundingRect;
    vector<int> colors{0xff5252, 0x706fd3};
    vector<vector<ofPath>> textSections;
    float textXPos;
    float textYPos;
    
    void configureText(string word) {
        font.load("corm.ttf", 200, true, true, true);
        int wordMidpoint = word.length() / 2;
        string wordFirstHalf = word.substr(0, wordMidpoint);
        string wordSecondHalf = word.substr(wordMidpoint, word.length());
        vector<ofPath> firstHalf = font.getStringAsPoints(wordFirstHalf, false, false);
        vector<ofPath> secondHalf = font.getStringAsPoints(wordSecondHalf, false, false);
        textSections.push_back(firstHalf);
        textSections.push_back(secondHalf);
        
        // Center the text by using bounding box and x-height.
        boundingRect = font.getStringBoundingBox(word, 0, 0);
        textXPos = (ofGetWidth() / 2) - (boundingRect.width / 2);
        textYPos = (ofGetHeight() / 2) + (font.stringHeight("x") / 2);
    }
    
    void keyPressed() {
        // Do nothing in base class instance.
    }
    
    virtual void setup() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
};
