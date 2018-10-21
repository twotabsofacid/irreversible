#include "ofApp.h"

ofSerial mySerial;
int baud = 57600;
int myByte = 0;

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
    ofSetCircleResolution(100);
	incrementer = 0;
	ofBuffer buffer = ofBufferFromFile("mao-swimming-colors.txt");
	vector<string> linesOfTheFile;
	petalScaler = 1.0;
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
		color.setBrightness(200);
		Flower flower = Flower(color);
		flowers.push_back(flower);
	}
	cout << flowers.size() << endl;
	mySerial.listDevices();  
	vector <ofSerialDeviceInfo> deviceList = mySerial.getDeviceList();  
	mySerial.setup(0, baud); //open the first device
}

//--------------------------------------------------------------
void ofApp::update(){
	// Update the scaler value
	int myByte = mySerial.readByte();
	if ( myByte == OF_SERIAL_NO_DATA ) {
		cout << "no data was read" << endl;
	} else if ( myByte == OF_SERIAL_ERROR ) {
		cout << "an error occured" << endl;
	} else {
		petalScaler = ((float)myByte / 100) + 1;
	}
	flowers[incrementer].update(petalScaler);
}

//--------------------------------------------------------------
void ofApp::draw(){
	flowers[incrementer].draw();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	incrementer = (incrementer + 1) % flowers.size();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == ' ') {
		incrementer = (incrementer + 1) % flowers.size();
	}
}
