#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofNoFill();
    corm.load("corm.ttf", 200, true, true, true);
    paths = corm.getStringAsPoints("1961", false, false);
    
    // Center the text by using bounding box and x-height.
    ofRectangle boundingRect = corm.getStringBoundingBox("1961", 0, 0);
    textXPos = (ofGetWidth() / 2) - (boundingRect.width / 2);
    textYPos = (ofGetHeight() / 2) + (corm.stringHeight("x") / 2);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    for (int i = 0; i < paths.size(); i++) {
        ofPath path = paths[i];
        vector<ofPolyline> polylines = path.getOutline();
        for (int j = 0; j < polylines.size(); j++) {
            ofPushMatrix();
            ofTranslate(textXPos, textYPos);
            ofPolyline p = polylines[j];
            p = p.getResampledBySpacing(5);
            for (int k = 0; k < p.size(); k++) {
                ofDrawCircle(p.getVertices()[k].x, p.getVertices()[k].y, mouseX + mouseX / 2 * sin(2 * ofGetElapsedTimef() + k * 0.1));
            }
            ofPopMatrix();
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
