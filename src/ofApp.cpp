#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
    ofSetCircleResolution(100);
	incrementer = 0;
	savedTime = ofGetFrameNum();
	ofBuffer buffer = ofBufferFromFile("output.txt");
	vector<string> linesOfTheFile;
	for (auto line : buffer.getLines()){
	    linesOfTheFile.push_back(line);
	}
	for (int i = 0; i < linesOfTheFile.size(); i++) {
		string hexstring = linesOfTheFile[i];
		int number = (int) strtol( &hexstring[0], NULL, 16);
		// Split them up into r, g, b values
		int r = number >> 16;
		int g = number >> 8 & 0xFF;
		int b = number & 0xFF;
		Flower flower = Flower(r, g, b);
		flowers.push_back(flower);
	}
	cout << flowers.size() << endl;
	currentColor = ofColor(0, 0, 0);
	storedColor = ofColor(flowers[incrementer].r, flowers[incrementer].g, flowers[incrementer].b);
}

//--------------------------------------------------------------
void ofApp::update(){
	float numFrames = ofGetFrameNum() - savedTime;
	// Fade in the sphere at the beginning
	if (numFrames <= 20) {
		currentColor = ofColor(0, 0, 0);
		currentColor.lerp(storedColor, (numFrames)/20);
	}
	// Stop drawing new petals after 960 frames
	if (numFrames >= 960) {
		flowers[incrementer].shouldCreateNew = false;
	} else {
		flowers[incrementer].shouldCreateNew = true;
	}
	// Start fading out the center of the flower at 1100 frames
	if (numFrames >= 1140) {
		currentColor = storedColor;
		currentColor.lerp(ofColor(0, 0, 0), (numFrames - 1140)/(1200 - 1140));
	}
	// Every 1200 frames delete the existing flower and create a new one
	if (numFrames >= 1200) {
		savedTime = ofGetFrameNum();
		flowers[incrementer].deletePetals();
		incrementer = (incrementer + 1) % flowers.size();
		currentColor = ofColor(0, 0, 0);
		storedColor = ofColor(flowers[incrementer].r, flowers[incrementer].g, flowers[incrementer].b);
	} else {
		flowers[incrementer].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();
	ofEnableDepthTest();
	flowers[incrementer].draw();
	ofPushStyle();
	ofSetColor(currentColor);
	ofDrawSphere(0, 0, 0, 36);
	ofPopStyle();
	cam.end();
	ofDisableDepthTest();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == OF_KEY_LEFT) {
		savedTime = ofGetFrameNum();
		flowers[incrementer].deletePetals();
		incrementer = (incrementer - 1) % flowers.size();
		currentColor = ofColor(0, 0, 0);
		storedColor = ofColor(flowers[incrementer].r, flowers[incrementer].g, flowers[incrementer].b);
	} else if (key == OF_KEY_RIGHT) {
		savedTime = ofGetFrameNum();
		flowers[incrementer].deletePetals();
		incrementer = (incrementer + 1) % flowers.size();
		currentColor = ofColor(0, 0, 0);
		storedColor = ofColor(flowers[incrementer].r, flowers[incrementer].g, flowers[incrementer].b);
	}
}
