#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofNoFill();
    ofEnableAntiAliasing();
    
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
//    float time = ofGetElapsedTimef();
//
//    blur.setScale(3);
//    blur.setRotation(PI * sin(0.06 * time));
//    ofSetCircleResolution(resolution);
//    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    whitneyWords.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    whitneyWords.keyPressed();
//    if (key == ' ') {
//        shouldShowDebugUI = !shouldShowDebugUI;
//    }
//    else if (key == '1') {
//        drawMode = BASIC_DIRECT_DRAW_MODE;
//    }
//    else if (key == '2') {
//        drawMode = FBO_DRAW_MODE;
//    }
//    else if (key == '3') {
//        drawMode = BLUR_MODE;
//    }
//    else if (key == 'r') {
//        mode = !mode;
//    }
}
