#include "Flower.hpp"

//--------------------------------------------------------------
Flower::Flower(){

}

//--------------------------------------------------------------
Flower::Flower(ofColor _color){
	pos = glm::vec2(ofGetWidth()/2, ofGetHeight()/2);
	color = _color;
	savedTime = ofGetElapsedTimeMillis();
	// Create ten petals to start
	makeNewPetals(3);
}

//--------------------------------------------------------------
void Flower::update(){
	if (ofGetElapsedTimeMillis() - savedTime >= 1000) {
		savedTime = ofGetElapsedTimeMillis();
		// make three new petals
		makeNewPetals(3);
	}
	for (int i = 0; i < petals.size(); i++) {
		petals[i].update();
	}
	for (int j = 0; j < petals.size(); j++) {
		if (petals[j].getIncrementer() >= 255) {
			petals.erase(petals.begin() + j);
		}
	}
}

//--------------------------------------------------------------
void Flower::draw(){
	for (int i = 0; i < petals.size(); i++) {
		petals[i].draw();
	}
}

void Flower::makeNewPetals(int newPetals) {
	for (int i = 0; i < newPetals; i++) {
		glm::vec2 pos, vel;
		pos.x = ofGetWidth()/2;
		pos.y = ofGetHeight()/2;
        float ranValForCircle = ofRandom(0, 6.28);
        float ranValForSpread = ofRandom(0.1, 0.2);
        vel.x = sin(ranValForCircle) * ranValForSpread;
        vel.y = cos(ranValForCircle) * ranValForSpread;
        Petal petal = Petal(pos, vel, color);
        petals.push_back(petal);
	}
}
