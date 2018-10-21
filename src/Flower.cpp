#include "Flower.hpp"

//--------------------------------------------------------------
Flower::Flower(){
}

//--------------------------------------------------------------
Flower::Flower(ofColor _color){
	pos = glm::vec2(ofGetWidth()/2, ofGetHeight()/2);
	color = _color;
	savedTime = ofGetElapsedTimeMillis();
	petalScaler = 1;
	// Create ten petals to start
	// makeNewPetals(3);
}

//--------------------------------------------------------------
void Flower::update(float _scaler){
	petalScaler = _scaler;
	if (ofGetElapsedTimeMillis() - savedTime >= 1000) {
		savedTime = ofGetElapsedTimeMillis();
		// make three new petals
		int numPetals = (int)ofRandom(3, 8);
		makeNewPetals(numPetals);
	}
	for (int i = 0; i < petals.size(); i++) {
		petals[i].update();
	}
	for (int j = 0; j < petals.size(); j++) {
		if (petals[j].getIncrementer() >= lifespan) {
			petals.erase(petals.begin() + j);
		}
	}
}

//--------------------------------------------------------------
void Flower::draw(){
	for (int i = 0; i < petals.size(); i++) {
		ofPushMatrix();
		ofTranslate(pos.x, pos.y);
		petals[i].draw();
		ofPopMatrix();
	}
}

void Flower::makeNewPetals(int newPetals) {
	float degreeSlice = 180/newPetals;
	float degreeIncrementer = ofRandom(-1, 1);
	for (int i = 0; i < newPetals; i++) {
        float deg = i * degreeSlice;
        Petal petal = Petal(color, deg, degreeIncrementer, lifespan, petalScaler);
        petals.push_back(petal);
	}
}
