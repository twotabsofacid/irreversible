#pragma once
#include "ofMain.h"

class Petal {

    public:
        Petal();
        Petal(glm::vec2 _pos, glm::vec2 _vel, ofColor _color);
        void addForce(glm::vec2 force);
        void update();
        void draw();
        float getIncrementer();

        glm::vec2 pos, vel, acc, size;
        ofColor color;

        float incrementer = 0;
        
};
