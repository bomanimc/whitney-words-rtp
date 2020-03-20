#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    whitneyWords.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    whitneyWords.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    whitneyWords.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    whitneyWords.keyPressed(key);
}
