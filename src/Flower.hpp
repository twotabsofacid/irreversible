#pragma once
#include "ofMain.h"
#include "Petal.hpp"

class Flower {
	public:
		Flower();
		Flower(glm::vec3 _rgb);
		void update();
		void draw();
		void makeNewPetals(int newPetals);
		void deletePetals();

		glm::vec2 pos;
		glm::vec3 rgb;

		bool shouldCreateNew = true;

		float savedTime;

		const int lifespan = 300;

		vector<Petal> petals;
};
