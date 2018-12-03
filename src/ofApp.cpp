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
}

//--------------------------------------------------------------
void ofApp::update(){
	if (ofGetFrameNum() - savedTime >= 960) {
		flowers[incrementer].shouldCreateNew = false;
	} else {
		flowers[incrementer].shouldCreateNew = true;
	}
	// Every twenty seconds get rid of the flower and draw a new one
	if (ofGetFrameNum() - savedTime >= 1200) {
		savedTime = ofGetFrameNum();
		flowers[incrementer].deletePetals();
		incrementer = (incrementer + 1) % flowers.size();
	} else {
		flowers[incrementer].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();
	flowers[incrementer].draw();
	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == OF_KEY_LEFT) {
		savedTime = ofGetFrameNum();
		flowers[incrementer].deletePetals();
		incrementer = (incrementer - 1) % flowers.size();
	} else if (key == OF_KEY_RIGHT) {
		savedTime = ofGetFrameNum();
		flowers[incrementer].deletePetals();
		incrementer = (incrementer + 1) % flowers.size();
	}
}
