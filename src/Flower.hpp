#pragma once
#include "ofMain.h"
#include "Petal.hpp"

class Flower {
	public:
		Flower();
		Flower(ofColor _color);
		void update();
		void draw();
		void makeNewPetals(int newPetals);

		glm::vec2 pos;
		ofColor color;

		float savedTime;

		vector<Petal> petals;
};
