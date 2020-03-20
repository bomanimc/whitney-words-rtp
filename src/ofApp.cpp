#include "ofApp.h"

#define WHITNEY_WORDS "Whitney Words"
#define EMERGENT_WORDS "Emergent Words"

//--------------------------------------------------------------
void ofApp::setup(){
    ofApp::configureGUI();
    ofApp::setupSketches();
}

void ofApp::setupSketches() {
    if (currentSketch == EMERGENT_WORDS) {
        emergentWords.setup();
    }
    else {
        whitneyWords.setup();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    if (currentSketch == EMERGENT_WORDS) {
        emergentWords.update();
    }
    else {
        whitneyWords.update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (currentSketch == EMERGENT_WORDS) {
        emergentWords.draw();
    }
    else {
        whitneyWords.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (currentSketch == EMERGENT_WORDS) {
        emergentWords.keyPressed(key);
    }
    else {
        whitneyWords.keyPressed(key);
    }
}

void ofApp::configureGUI() {
    ofxDatGui* gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
    vector<string> options = {WHITNEY_WORDS, EMERGENT_WORDS};
    gui->addDropdown("Experiment Type", options);
    gui->onDropdownEvent([&](ofxDatGuiDropdownEvent e)
    {
        currentSketch = e.target->getLabel();
        ofApp::setupSketches();
    });
}
