#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofNoFill();

    font.load("corm.ttf", 200, true, true, true);
    vector<ofPath> nineteen = font.getStringAsPoints("spr", false, false);
    vector<ofPath> sixteen = font.getStringAsPoints("out", false, false);
    textSections.push_back(nineteen);
    textSections.push_back(sixteen);
    
    // Center the text by using bounding box and x-height.
    boundingRect = font.getStringBoundingBox("sprout", 0, 0);
    textXPos = 0;
    textYPos = 0;
    
    gui.setup();
    gui.add(spacing.setup("spacing", 75, 1, 100));
    gui.add(alpha.setup("alpha", 25, 0, 255));
    gui.add(resolution.setup("resolution", 12, 3, 50));
    
    animationCounter = 0;
    for (int sectionNum = 0; sectionNum < textSections.size(); sectionNum++) {
        vector<ofPath> paths = textSections[sectionNum];
        int sectionXPos = textXPos + ((boundingRect.width / textSections.size()) * sectionNum);
        
        ofApp::getPolylines(paths);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    cam.begin();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    for (int sectionNum = textSections.size() - 1; sectionNum >= 0; sectionNum--) {
        int sectionXPos = textXPos + ((boundingRect.width / textSections.size()) * sectionNum);
        
        ofApp::drawText(sectionXPos, textYPos + 100, colors[sectionNum], polylinesList[sectionNum]);
    }

    cam.end();
    
//    gui.draw();
}

void ofApp::getPolylines(vector<ofPath> paths) {
    vector<ofPolyline> sectionPolylines;
    for (int i = 0; i < paths.size(); i++) {
        ofPath path = paths[i];
        vector<ofPolyline> polylines = path.getOutline();
        for (int j = 0; j < polylines.size(); j++) {
            ofPolyline p = polylines[j];
            sectionPolylines.push_back(p);
        }
    }
    polylinesList.push_back(sectionPolylines);
}

void ofApp::drawText(float xPos, float yPos, int color, vector<ofPolyline> sectionPolylines) {
    ofSetColor(ofColor::fromHex(color, alpha));
    float decayFactor = 0.2;
    float timeScaleForDecay = 0.2;
    float elapsedSeconds = ofGetElapsedTimef();
    float time = 0;
    if (elapsedSeconds >= 10) {
        time = elapsedSeconds - 10;
    }
    
    for (int j = 0; j < sectionPolylines.size(); j++) {
        ofPolyline p = sectionPolylines[j];
        
        ofPushMatrix();
        ofTranslate(xPos, yPos);
        float spacingTerm = (0.2 * spacing) + (0.8 * spacing * pow(1 - decayFactor, timeScaleForDecay * time));
        float resolutionTerm = (0.7 * resolution) + (0.3 * resolution * pow(1 - 0.1, timeScaleForDecay * time));
        p = p.getResampledBySpacing(spacingTerm);
        ofSetSphereResolution(resolutionTerm);
        
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
