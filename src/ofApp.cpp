#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    whitneyWords.setup();
//    ofNoFill();
//    ofEnableAntiAliasing();
    
//    blur.setup(ofGetWidth(), ofGetHeight(), 10, .2, 2);
//    fbo.allocate(4 * ofGetWidth(), 4 * ofGetHeight(), GL_RGBA);
//
//    drawMode = BASIC_DIRECT_DRAW_MODE;
//
////    ofApp::configureText("rise");
//    ofApp::configureGUI();
}

//--------------------------------------------------------------
void ofApp::update(){
    whitneyWords.update();
//    float time = ofGetElapsedTimef();
//
//    blur.setScale(3);
//    blur.setRotation(PI * sin(0.06 * time));
//    ofSetCircleResolution(resolution);
//    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    whitneyWords.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    whitneyWords.keyPressed(key);
}
