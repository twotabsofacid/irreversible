#pragma once
#include "ofMain.h"

class Petal {

    public:
        Petal();
        Petal(ofColor _color, float _deg, float _degreeIncrementer, int _lifespan);
        void addForce(glm::vec2 force);
        void update();
        void draw();
        float getIncrementer();

        glm::vec2 size, noiseySize;
        float deg, degreeIncrementer;
        int lifespan;
        ofColor color;

        float xIncrementer = 1.0;
        float yIncrementer = 3.0;

        float incrementer = 0;
        
};
