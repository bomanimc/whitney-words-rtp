#include "WhitneyWords.h"

#define BASIC_DIRECT_DRAW_MODE 1
#define FBO_DRAW_MODE 2
#define BLUR_MODE 3

void WhitneyWords::setup() {
    ofNoFill();
    ofEnableAntiAliasing();

    blur.setup(ofGetWidth(), ofGetHeight(), 10, .2, 2);
    fbo.allocate(4 * ofGetWidth(), 4 * ofGetHeight(), GL_RGBA);

    drawMode = BASIC_DIRECT_DRAW_MODE;

    WhitneyWords::configureText("rise");
    WhitneyWords::configureGUI();
}

void WhitneyWords::update(){
    float time = ofGetElapsedTimef();

    blur.setScale(3);
    blur.setRotation(PI * sin(0.06 * time));
    ofSetCircleResolution(resolution);
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

void WhitneyWords::draw() {
    ofBackground(0);
    
    if (drawMode == BASIC_DIRECT_DRAW_MODE) {
        WhitneyWords::drawWord();
    }
    else if (drawMode == FBO_DRAW_MODE) {
        WhitneyWords::drawWordWithFBO();
    }
    else if (drawMode == BLUR_MODE) {
        WhitneyWords::drawWordWithBlur();
    }


    if (shouldShowDebugUI) {
        drawDebugUI();
    }
}

void WhitneyWords::keyPressed(int key){
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

void WhitneyWords::configureGUI() {
    gui.setup();
    gui.add(spacing.setup("spacing", 1.25, 1, 10));
    gui.add(alpha.setup("alpha", 30, 0, 255));
    gui.add(resolution.setup("resolution", 70, 3, 100));
}

void WhitneyWords::drawDebugUI() {
    gui.draw();
}

void WhitneyWords::drawWordWithBlur() {
    WhitneyWords::resetBlendingSettings();

    blur.begin();
    WhitneyWords::drawWordWithFBO();
    blur.end();

    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofSetColor(255,255,255);
    blur.draw();
    ofDisableBlendMode();

    WhitneyWords::drawWord();
}

void WhitneyWords::drawWordWithFBO() {
    WhitneyWords::resetBlendingSettings();

    fbo.begin();
    ofClear(0, 0, 0, 0);
    WhitneyWords::drawWord();
    ofClearAlpha();
    fbo.end();

    fbo.draw(0,0);
}

void WhitneyWords::drawWord() {
    WhitneyWords::resetBlendingSettings();

    ofEnableBlendMode(OF_BLENDMODE_ADD);
    for (int sectionNum = textSections.size() - 1; sectionNum >= 0; sectionNum--) {
        vector<ofPath> paths = textSections[sectionNum];
        int sectionXPos = textXPos + ((boundingRect.width / textSections.size()) * sectionNum);

        WhitneyWords::drawSection(paths, sectionXPos, textYPos, colors[sectionNum]);
    }
    ofClearAlpha();
}

void WhitneyWords::drawSection(vector<ofPath> paths, float xPos, float yPos, int color) {
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

void WhitneyWords::resetBlendingSettings() {
    ofDisableBlendMode();
    ofSetColor(255, 255, 255);
}
