#include "Flower.hpp"

//--------------------------------------------------------------
Flower::Flower(){

}

//--------------------------------------------------------------
Flower::Flower(ofColor _color){
	pos = glm::vec2(ofGetWidth()/2, ofGetHeight()/2);
	color = _color;
	savedTime = ofGetFrameNum();
	shader.load("","shaderFrag.c");
    fbo.allocate(ofGetWidth(), ofGetHeight());
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
		fbo.begin();
		ofPushMatrix();
		ofTranslate(pos.x, pos.y);
		petals[i].draw();
		ofPopMatrix();
		fbo.end();
	    shader.begin();
	    shader.setUniform1f("u_time", ofGetElapsedTimef());
	    shader.end();
	    fbo.draw(0, 0);
	}
}

//--------------------------------------------------------------
void Flower::makeNewPetals(int newPetals) {
	float degreeSlice = 360/newPetals;
	float degreeIncrementer = ofRandom(-1, 1);
	float petalScaler = ofRandom(0.2, 0.5);
	for (int i = 0; i < newPetals; i++) {
        float deg = i * degreeSlice;
        Petal petal = Petal(color, deg, degreeIncrementer, petalScaler, lifespan);
        petals.push_back(petal);
	}
}

//--------------------------------------------------------------
void Flower::deletePetals() {
	petals.clear();
}

