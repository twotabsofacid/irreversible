#pragma once
#include "ofMain.h"

class Petal {

    public:
        Petal();
        Petal(ofColor _color, float _deg, float _degreeIncrementer);
        void addForce(glm::vec2 force);
        void update();
        void draw();
        float getIncrementer();

        glm::vec2 size, noiseySize;
        float deg, degreeIncrementer;
        ofColor color;

        float incrementer = 0;
        
};
