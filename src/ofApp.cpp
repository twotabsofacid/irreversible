#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
    ofSetCircleResolution(100);
	incrementer = 0;
	ofBuffer buffer = ofBufferFromFile("mao-swimming-colors.txt");
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
		color.setBrightness(222);
		Flower flower = Flower(color);
		flowers.push_back(flower);
	}
	cout << flowers.size() << endl;
}

//--------------------------------------------------------------
void ofApp::update(){
	flowers[incrementer].update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	flowers[incrementer].draw();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	incrementer = (incrementer + 1) % flowers.size();
}
