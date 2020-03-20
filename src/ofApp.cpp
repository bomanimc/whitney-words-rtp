#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    emergentWords.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    emergentWords.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    emergentWords.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    emergentWords.keyPressed(key);
}
