#include "ofApp.h"
#include "CircleGroup.h"

#define BASIC_DIRECT_DRAW_MODE 1
#define FBO_DRAW_MODE 2
#define BLUR_MODE 3

//--------------------------------------------------------------
void ofApp::setup(){
    ofNoFill();
    ofEnableAntiAliasing();
    
    blur.setup(ofGetWidth(), ofGetHeight(), 10, .2, 2);
    fbo.allocate(4 * ofGetWidth(), 4 * ofGetHeight(), GL_RGBA);
    
    drawMode = BASIC_DIRECT_DRAW_MODE;
    
    ofApp::configureGUI();
}

void ofApp::configureGUI() {
    gui.setup();
    gui.add(spacing.setup("spacing", 1.25, 1, 10));
    gui.add(alpha.setup("alpha", 30, 0, 255));
    gui.add(resolution.setup("resolution", 70, 3, 100));
}

//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef();
    
    blur.setScale(3);
    blur.setRotation(PI * sin(0.06 * time));
    ofSetCircleResolution(resolution);
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    if (drawMode == BASIC_DIRECT_DRAW_MODE) {
        circleGroupManager.drawCircleGroups(alpha);
    }
    else if (drawMode == FBO_DRAW_MODE) {
        ofApp::drawCircleGroupsWithFBO();
    }
    else if (drawMode == BLUR_MODE) {
        ofApp::drawCircleGroupsWithBlur();
    }
    
    if (shouldShowDebugUI) {
        drawDebugUI();
    }
}

void ofApp::drawDebugUI() {
    gui.draw();
}

void ofApp::drawCircleGroupsWithBlur() {
    ofApp::resetBlendingSettings();
    
    blur.begin();
        circleGroupManager.drawCircleGroups(alpha);
    blur.end();
    
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofSetColor(255,255,255);
    blur.draw();
    ofDisableBlendMode();
    
    circleGroupManager.drawCircleGroups(alpha);
}

void ofApp::drawCircleGroupsWithFBO() {
    ofApp::resetBlendingSettings();
    
    fbo.begin();
        ofClear(0, 0, 0, 0);
        circleGroupManager.drawCircleGroups(alpha);
        ofClearAlpha();
    fbo.end();
    
    fbo.draw(0,0);
}

void ofApp::resetBlendingSettings() {
    ofDisableBlendMode();
    ofSetColor(255, 255, 255);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        shouldShowDebugUI = !shouldShowDebugUI;
    }
    else if (key == '1') {
        drawMode = BASIC_DIRECT_DRAW_MODE;
    }
    else if (key == '2') {
        drawMode = FBO_DRAW_MODE;
    }
    else if (key == '3') {
        drawMode = BLUR_MODE;
    }
    else if (key == 'r') {
        mode = !mode;
    }
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
    CircleGroup c(ofVec2f(x, y), 30, 0xff5252, ofGetElapsedTimef());
    circleGroupManager.addCircleGroup(c);
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
