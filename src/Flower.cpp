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
	// makeNewPetals(3);
}

//--------------------------------------------------------------
void Flower::update(){
	if (ofGetElapsedTimeMillis() - savedTime >= 500) {
		savedTime = ofGetElapsedTimeMillis();
		// make three new petals
		makeNewPetals((int)ofRandom(3, 6));
	}
	for (int i = 0; i < petals.size(); i++) {
		petals[i].update();
	}
	for (int j = 0; j < petals.size(); j++) {
		if (petals[j].getIncrementer() >= 300) {
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
	float degreeSlice = 360/newPetals;
	float degreeIncrementer = ofRandom(-3, 3);
	for (int i = 0; i < newPetals; i++) {
        float deg = i * degreeSlice;
        Petal petal = Petal(color, deg, degreeIncrementer);
        petals.push_back(petal);
	}
}
