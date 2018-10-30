#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
    ofSetCircleResolution(100);
	incrementer = 0;
	savedTime = ofGetElapsedTimeMillis();
	ofBuffer buffer = ofBufferFromFile("output.txt");
	vector<string> linesOfTheFile;
	for (auto line : buffer.getLines()){
	    linesOfTheFile.push_back(line);
	}
	for (int i = 0; i < linesOfTheFile.size(); i++) {
		string hexstring = linesOfTheFile[i];
		int number = (int) strtol( &hexstring[0], NULL, 16);
		// Split them up into r, g, b values
		unsigned char r = number >> 16;
		unsigned char g = number >> 8 & 0xFF;
		unsigned char b = number & 0xFF;
		ofColor color = ofColor(r, g, b);
		Flower flower = Flower(color);
		flowers.push_back(flower);
	}
	cout << flowers.size() << endl;
}

//--------------------------------------------------------------
void ofApp::update(){
	if (ofGetElapsedTimeMillis() - savedTime >= 16000) {
		flowers[incrementer].shouldCreateNew = false;
	} else {
		flowers[incrementer].shouldCreateNew = true;
	}
	// Every twenty seconds get rid of the flower and draw a new one
	if (ofGetElapsedTimeMillis() - savedTime >= 20000) {
		savedTime = ofGetElapsedTimeMillis();
		flowers[incrementer].deletePetals();
		incrementer = (incrementer + 1) % flowers.size();
	} else {
		flowers[incrementer].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	flowers[incrementer].draw();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	savedTime = ofGetElapsedTimeMillis();
	if (key == OF_KEY_LEFT) {
		flowers[incrementer].deletePetals();
		incrementer = (incrementer - 1) % flowers.size();
	} else if (key == OF_KEY_RIGHT) {
		flowers[incrementer].deletePetals();
		incrementer = (incrementer + 1) % flowers.size();
	}
}
