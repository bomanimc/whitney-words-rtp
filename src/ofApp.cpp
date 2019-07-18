#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    shader.load("shader");
    
    ofNoFill();
    
    font.load("corm.ttf", 200, true, true, true);
    vector<ofPath> nineteen = font.getStringAsPoints("bom", false, false);
    vector<ofPath> sixteen = font.getStringAsPoints("ani", false, false);
    textSections.push_back(nineteen);
    textSections.push_back(sixteen);
    
    // Center the text by using bounding box and x-height.
    boundingRect = font.getStringBoundingBox("bomani", 0, 0);
    textXPos = (ofGetWidth() / 2) - (boundingRect.width / 2);
    textYPos = (ofGetHeight() / 2) + (font.stringHeight("x") / 2);
    
    blur.setup(ofGetWidth(), ofGetHeight(), 10, .2, 2);
    
    gui.setup();
    gui.add(spacing.setup("spacing", 5, 1, 50));
    gui.add(alpha.setup("alpha", 25, 0, 255));
    gui.add(resolution.setup("resolution", 20, 3, 75));
    
    ofApp::createPositionsArray();
}

//--------------------------------------------------------------
void ofApp::update(){
    blur.setScale(1);
    blur.setRotation(PI);
    ofSetCircleResolution(resolution);
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);

    // Remove non-white tint
    ofSetColor(255,255,255);
    
   // blur.draw();
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    if (showDebug) {
        ofApp::drawDebugPoints();
    }
    
    ofRectangle baseShape = ofRectangle(circlePositions[0].x, circlePositions[0].y, 5, 5);
    baseShape.get
    ofVboMesh vboMesh = baseShape.getMesh();
    
    shader.begin();
    shader.setUniform1f("time", ofGetElapsedTimef());
    shader.setUniform1fv("xPositions", &circlePositions[0].x, circlePositions.size());
    shader.setUniform1fv("yPositions", &circlePositions[0].y, circlePositions.size());
    ofCircle(circlePositions[0].x, circlePositions[0].y, 5);
    shader.end();
    
    gui.draw();
}

void ofApp::drawDebugPoints() {
    for (int i = 0; i < circlePositions.size(); i++) {
        ofVec2f pos = circlePositions[i];
        ofDrawCircle(pos.x, pos.y, 1);
    }
}

void ofApp::createPositionsArray() {
    for (int sectionNum = textSections.size() - 1; sectionNum >= 0; sectionNum--) {
        vector<ofPath> paths = textSections[sectionNum];
        int sectionXPos = textXPos + ((boundingRect.width / textSections.size()) * sectionNum);
        
        ofApp::determineTextPositions(paths, sectionXPos, textYPos, colors[sectionNum]);
    }
}

void ofApp::determineTextPositions(vector<ofPath> paths, float xPos, float yPos, int color) {
    ofSetColor(ofColor::fromHex(color, alpha));
    
    float time = ofGetElapsedTimef();
    for (int i = 0; i < paths.size(); i++) {
        ofPath path = paths[i];
        vector<ofPolyline> polylines = path.getOutline();
        for (int j = 0; j < polylines.size(); j++) {
            ofPushMatrix();
            ofTranslate(xPos, yPos);
            ofPolyline p = polylines[j];
            p = p.getResampledByCount(350);
            
            for (int k = 0; k < p.size(); k++) {
                ofVec2f pos;
                pos.set(xPos + p.getVertices()[k].x, yPos + p.getVertices()[k].y);
                circlePositions.push_back(pos);
            }
            ofPopMatrix();
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    showDebug = !showDebug;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
