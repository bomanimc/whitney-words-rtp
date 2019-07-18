#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofNoFill();
    //ofSetFrameRate(15);
    
    font.load("corm.ttf", 200, true, true, true);
    vector<ofPath> nineteen = font.getStringAsPoints("bom", false, false);
    vector<ofPath> sixteen = font.getStringAsPoints("ani", false, false);
    textSections.push_back(nineteen);
    textSections.push_back(sixteen);
    
    // Center the text by using bounding box and x-height.
    boundingRect = font.getStringBoundingBox("bomani", 0, 0);
    textXPos = 0;
    textYPos = 0;
    
    blur.setup(ofGetWidth(), ofGetHeight(), 10, .2, 2);
    
    gui.setup();
    gui.add(spacing.setup("spacing", 50, 1, 100));
    gui.add(alpha.setup("alpha", 25, 0, 255));
    gui.add(resolution.setup("resolution", 20, 3, 50));
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
    cam.begin();
//    blur.begin();
//    ofClear(0,0,0,255);
//    for (int sectionNum = textSections.size() - 1; sectionNum >= 0; sectionNum--) {
//
//        vector<ofPath> paths = textSections[sectionNum];
//        int sectionXPos = textXPos + ((boundingRect.width / textSections.size()) * sectionNum);
//
//        ofApp::drawText(paths, sectionXPos, textYPos, colors[sectionNum]);
//    }
//    ofClearAlpha();
//    blur.end();
    
    // Remove non-white tint
    ofSetColor(255,255,255);
    
   // blur.draw();
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);

    for (int sectionNum = textSections.size() - 1; sectionNum >= 0; sectionNum--) {
        vector<ofPath> paths = textSections[sectionNum];
        int sectionXPos = textXPos + ((boundingRect.width / textSections.size()) * sectionNum);

        ofApp::drawText(paths, sectionXPos, textYPos, colors[sectionNum]);
    }
    cam.end();
    
    gui.draw();
}

void ofApp::drawText(vector<ofPath> paths, float xPos, float yPos, int color) {
    ofSetColor(ofColor::fromHex(color, alpha));
    
    
    float time = ofGetElapsedTimef();
    for (int i = 0; i < paths.size(); i++) {
        ofPath path = paths[i];
        vector<ofPolyline> polylines = path.getOutline();
        for (int j = 0; j < polylines.size(); j++) {
            ofPushMatrix();
            ofTranslate(xPos, yPos);
            ofPolyline p = polylines[j];
//            if (mode) {
//                p = p.getResampledBySpacing(spacing);
//            } else {
//                p = p.getResampledByCount(100);
//            }
//            p = p.getResampledByCount(10);
            p = p.getResampledBySpacing(spacing);
//            cout << ofGetSphereResolution() << endl;
            ofSetSphereResolution(resolution);
            
            for (int k = 0; k < p.size(); k++) {
                ofDrawSphere(p.getVertices()[k].x - (boundingRect.width / 2), -1 * p.getVertices()[k].y - (boundingRect.height / 2), 0, 100 * sin(0.02 * time));
            }
            ofPopMatrix();
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    mode = !mode;
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
