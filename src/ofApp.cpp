#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofNoFill();
    corm.load("corm.ttf", 200, true, true, true);
}

//--------------------------------------------------------------
void ofApp::update(){
    circles.clear();
    for (int i = 0; i < 100; i++) {
        Circle c;
        c.x = 50 * ofSignedNoise(0.1 * i, 100, 0.2 * ofGetElapsedTimef());
        c.y = 50 * ofSignedNoise(0.1 * i, 200, 0.2 * ofGetElapsedTimef());
        c.r = 75 + 30 * ofSignedNoise(0.1 * i, 300, 0.2 * ofGetElapsedTimef());
        circles.push_back(c);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    cam.enableOrtho();
    // Green: 6af551
    // Blue: 50e2ff
    ofBackground(0);
    
    vector<ofPath> paths = corm.getStringAsPoints("Hello", false, false);
    for (int i = 0; i < paths.size(); i++) {
        ofPath path = paths[i];
        vector<ofPolyline> polylines = path.getOutline();
        for (int j = 0; j < polylines.size(); j++) {
            
            ofPushMatrix();
            ofTranslate(400, 400);
            ofPolyline p = polylines[j];
            p = p.getResampledBySpacing(5);
            for (int k = 0; k < p.size(); k++) {
                ofDrawCircle(p.getVertices()[k].x, p.getVertices()[k].y, mouseX + mouseX / 2 * sin(2 * ofGetElapsedTimef() + k * 0.1));
            }
            ofPopMatrix();
        }
    }
    cam.end();
//    corm.drawString("Hello", 100, 100);
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
