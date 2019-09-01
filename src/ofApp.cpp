#include "ofApp.h"
#include "CircleGroup.h"

#define BASIC_DIRECT_DRAW_MODE 1
#define FBO_DRAW_MODE 2
#define BLUR_MODE 3

//--------------------------------------------------------------
void ofApp::setup(){
    ofNoFill();
    ofEnableAntiAliasing();
    
    font.load("corm.ttf", 200, true, true, true);
    vector<ofPath> nineteen = font.getStringAsPoints("ri", false, false);
    vector<ofPath> sixteen = font.getStringAsPoints("se", false, false);
    textSections.push_back(nineteen);
    textSections.push_back(sixteen);
    
    // Center the text by using bounding box and x-height.
    boundingRect = font.getStringBoundingBox("rise", 0, 0);
    textXPos = (ofGetWidth() / 2) - (boundingRect.width / 2);
    textYPos = (ofGetHeight() / 2) + (font.stringHeight("x") / 2);
    
    blur.setup(ofGetWidth(), ofGetHeight(), 10, .2, 2);
    
    
    fbo.allocate(4 * ofGetWidth(), 4 * ofGetHeight(), GL_RGBA);
    
    drawMode = BASIC_DIRECT_DRAW_MODE;
    
    CircleGroup c(ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2), 30, 0x706fd3);
    circleGroups.push_back(c);
    
    ofApp::configureGUI();
}

void ofApp::configureGUI() {
    gui.setup();
    gui.add(spacing.setup("spacing", 1.25, 1, 10));
    gui.add(alpha.setup("alpha", 30, 0, 255));
    gui.add(resolution.setup("resolution", 70, 3, 100));
}

//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef();
    
    blur.setScale(3);
    blur.setRotation(PI * sin(0.06 * time));
    ofSetCircleResolution(resolution);
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    float time = ofGetElapsedTimef();
    for (auto circleGroup : circleGroups) {
        circleGroup.draw(200 * sin(0.1 * time), alpha);
    }
    
    if (shouldShowDebugUI) {
        drawDebugUI();
    }
}

void ofApp::drawDebugUI() {
    gui.draw();
}

void ofApp::drawWordWithBlur() {
    ofApp::resetBlendingSettings();
    
    blur.begin();
        ofApp::drawWordWithFBO();
    blur.end();
    
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofSetColor(255,255,255);
    blur.draw();
    ofDisableBlendMode();
    
    ofApp::drawWord();
}

void ofApp::drawWordWithFBO() {
    ofApp::resetBlendingSettings();
    
    fbo.begin();
        ofClear(0, 0, 0, 0);
        ofApp::drawWord();
        ofClearAlpha();
    fbo.end();
    
    fbo.draw(0,0);
}

void ofApp::drawWord() {
    ofApp::resetBlendingSettings();
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    for (int sectionNum = textSections.size() - 1; sectionNum >= 0; sectionNum--) {
        vector<ofPath> paths = textSections[sectionNum];
        int sectionXPos = textXPos + ((boundingRect.width / textSections.size()) * sectionNum);
        
        ofApp::drawSection(paths, sectionXPos, textYPos, colors[sectionNum]);
    }
    ofClearAlpha();
}

void ofApp::drawSection(vector<ofPath> paths, float xPos, float yPos, int color) {
    ofSetColor(ofColor::fromHex(color, alpha));
    

    float time = ofGetElapsedTimef();
    for (int i = 0; i < paths.size(); i++) {
        ofPath path = paths[i];
        vector<ofPolyline> polylines = path.getOutline();
        for (int j = 0; j < polylines.size(); j++) {
            ofPushMatrix();
            ofTranslate(xPos, yPos);
            ofPolyline p = polylines[j];
            if (mode) {
                p = p.getResampledBySpacing(spacing);
            } else {
                p = p.getResampledByCount(500);
            }
            
            
            for (int k = 0; k < p.size(); k++) {
                ofDrawCircle(p.getVertices()[k].x, p.getVertices()[k].y, 200 * sin(0.06 * time));
            }
            ofPopMatrix();
        }
    }
}

void ofApp::resetBlendingSettings() {
    ofDisableBlendMode();
    ofSetColor(255, 255, 255);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        shouldShowDebugUI = !shouldShowDebugUI;
    }
    else if (key == '1') {
        drawMode = BASIC_DIRECT_DRAW_MODE;
    }
    else if (key == '2') {
        drawMode = FBO_DRAW_MODE;
    }
    else if (key == '3') {
        drawMode = BLUR_MODE;
    }
    else if (key == 'r') {
        mode = !mode;
    }
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
