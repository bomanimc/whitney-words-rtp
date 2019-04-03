#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofNoFill();
    ofSetCircleResolution(50);
    ofSetFrameRate(20);
    
    font.load("corm.ttf", 200, true, true, true);
    vector<ofPath> nineteen = font.getStringAsPoints("19", false, false);
    vector<ofPath> sixteen = font.getStringAsPoints("61", false, false);
    textSections.push_back(nineteen);
    textSections.push_back(sixteen);
    
    // Center the text by using bounding box and x-height.
    boundingRect = font.getStringBoundingBox("1961", 0, 0);
    textXPos = (ofGetWidth() / 2) - (boundingRect.width / 2);
    textYPos = (ofGetHeight() / 2) + (font.stringHeight("x") / 2);
    
//    post.init(ofGetWidth(), ofGetHeight());
//    post.createPass<BloomPass>();
//    post.createPass<ZoomBlurPass>();
    blur.setup(ofGetWidth(), ofGetHeight(), 10, .2, 2);
}

//--------------------------------------------------------------
void ofApp::update(){
    blur.setScale(1);
    blur.setRotation(PI);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    blur.begin();
    for (int sectionNum = textSections.size() - 1; sectionNum >= 0; sectionNum--) {
        vector<ofPath> paths = textSections[sectionNum];
        int sectionXPos = textXPos + ((boundingRect.width / textSections.size()) * sectionNum);
        
        ofApp::drawText(paths, sectionXPos, textYPos, colors[sectionNum]);
    }
    blur.end();
    blur.draw();
    
    for (int sectionNum = textSections.size() - 1; sectionNum >= 0; sectionNum--) {
        vector<ofPath> paths = textSections[sectionNum];
        int sectionXPos = textXPos + ((boundingRect.width / textSections.size()) * sectionNum);
        
        ofApp::drawText(paths, sectionXPos, textYPos, colors[sectionNum]);
    }
}

void ofApp::drawText(vector<ofPath> paths, float xPos, float yPos, int color) {
    ofSetColor(ofColor::fromHex(color, 25));
    
    for (int i = 0; i < paths.size(); i++) {
        ofPath path = paths[i];
        vector<ofPolyline> polylines = path.getOutline();
        for (int j = 0; j < polylines.size(); j++) {
            ofPushMatrix();
            ofTranslate(xPos, yPos);
            ofPolyline p = polylines[j];
            p = p.getResampledByCount(500);
            for (int k = 0; k < p.size(); k++) {
                ofDrawCircle(p.getVertices()[k].x, p.getVertices()[k].y, 200 * sin(0.1 * ofGetElapsedTimef()));
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
