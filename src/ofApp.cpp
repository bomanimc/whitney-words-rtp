#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofNoFill();
    //ofSetFrameRate(15);
    
    font.load("corm.ttf", 200, true, true, true);
    vector<ofPath> nineteen = font.getStringAsPoints("spr", false, false);
    vector<ofPath> sixteen = font.getStringAsPoints("out", false, false);
    textSections.push_back(nineteen);
    textSections.push_back(sixteen);
    
    // Center the text by using bounding box and x-height.
    boundingRect = font.getStringBoundingBox("sprout", 0, 0);
    textXPos = 0;
    textYPos = 0;
    
    blur.setup(ofGetWidth(), ofGetHeight(), 10, .2, 2);
    
    gui.setup();
    gui.add(spacing.setup("spacing", 75, 1, 100));
    gui.add(alpha.setup("alpha", 25, 0, 255));
    gui.add(resolution.setup("resolution", 12, 3, 50));
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
    
    cam.begin();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    for (int sectionNum = textSections.size() - 1; sectionNum >= 0; sectionNum--) {
        vector<ofPath> paths = textSections[sectionNum];
        int sectionXPos = textXPos + ((boundingRect.width / textSections.size()) * sectionNum);

        ofApp::drawText(paths, sectionXPos, textYPos + 100, colors[sectionNum]);
    }
    cam.end();
    
//    gui.draw();
}

void ofApp::drawText(vector<ofPath> paths, float xPos, float yPos, int color) {
    ofSetColor(ofColor::fromHex(color, alpha));
    float decayFactor = 0.2;
    float timeScaleForDecay = 0.2;
    
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
            float spacingTerm = (0.2 * spacing) + (0.8 * spacing * pow(1 - decayFactor, timeScaleForDecay * time));
            p = p.getResampledBySpacing(spacingTerm);
            ofSetSphereResolution(resolution);
            
            for (int k = 0; k < p.size(); k++) {
                ofSeedRandom(k);
                float amplitude = ofRandom(-150, 150);
                float speed = ofMap(ofRandomf(), 0, 1, -decayFactor, decayFactor);
                float decayTerm = amplitude * pow(1 - decayFactor, timeScaleForDecay * time);
                
                ofDrawSphere(
                     (decayTerm * cos(speed * time)) + p.getVertices()[k].x - (boundingRect.width / 2),
                     (decayTerm * sin(speed * time)) + -1 * p.getVertices()[k].y - (boundingRect.height / 2),
                     0,
                     50 * pow(1 - decayFactor, timeScaleForDecay * time)
                );
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
