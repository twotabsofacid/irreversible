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
        ofColor newColor;

        float xIncrementer = 0.3;
        float yIncrementer = 0.9;

        float incrementer = 0;
        
};
