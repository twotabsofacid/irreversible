#pragma once

#include "ofMain.h"
#include "Flower.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyReleased(int key);

		vector<Flower> flowers;

		float savedTime;

		int incrementer;
		
};
