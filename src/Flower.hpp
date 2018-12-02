#pragma once
#include "ofMain.h"
#include "Petal.hpp"

class Flower {
	public:
		Flower();
		Flower(int _r, int _g, int _b);
		void update();
		void draw();
		void makeNewPetals(int newPetals);
		void deletePetals();

		glm::vec2 pos;
		int r, g, b;

		bool shouldCreateNew = true;

		float savedTime;

		const int lifespan = 300;

		vector<Petal> petals;
};
