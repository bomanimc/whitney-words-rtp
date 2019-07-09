#pragma once

#include "ofMain.h"
#include "ofxPostProcessing.h"
#include "ofxBlur.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void drawDebugPoints();
    void createPositionsArray();
    void determineTextPositions(vector<ofPath> paths, float xPos, float yPos, int color);
    
    ofTrueTypeFont font;
    ofRectangle boundingRect;
    vector<int> colors{0xff5252, 0x706fd3};
    vector<vector<ofPath>> textSections;
    float textXPos;
    float textYPos;
    
    ofShader shader;
    vector<ofVec2f> circlePositions;
    ofxPostProcessing post;
    ofxBlur blur;
    
    ofxFloatSlider spacing;
    ofxFloatSlider alpha;
    ofxFloatSlider resolution;
    ofxPanel gui;
    
    bool showDebug;
};
