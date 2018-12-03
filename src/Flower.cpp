#include "Flower.hpp"

//--------------------------------------------------------------
Flower::Flower(){

}

//--------------------------------------------------------------
Flower::Flower(int _r, int _g, int _b){
	r = _r;
	g = _g;
	b = _b;
	pos = glm::vec2(ofGetWidth()/2, ofGetHeight()/2);
	savedTime = ofGetFrameNum();
}

//--------------------------------------------------------------
void Flower::update(){
	if (shouldCreateNew && ofGetFrameNum() - savedTime >= 60) {
		savedTime = ofGetFrameNum();
		// make three new petals
		int numPetals = (int)ofRandom(8, 12);
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
		petals[i].draw();
		ofPopMatrix();
	}
}

//--------------------------------------------------------------
void Flower::makeNewPetals(int newPetals) {
	float degreeSlice = 360/newPetals;
	float degreeIncrementer = ofRandom(-1, 1);
	float petalScaler = ofRandom(0.2, 0.5);
	for (int i = 0; i < newPetals; i++) {
        float deg = i * degreeSlice;
        Petal petal = Petal(r, g, b, deg, degreeIncrementer, petalScaler, lifespan);
        petals.push_back(petal);
	}
}

//--------------------------------------------------------------
void Flower::deletePetals() {
	petals.clear();
}

