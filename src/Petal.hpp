#pragma once
#include "ofMain.h"

class Petal {

    public:
        Petal();
        Petal(ofColor _color, float _deg, float _degreeIncrementer, float _petalScaler, int _lifespan);
        void addForce(glm::vec2 force);
        void update();
        void draw();
        float getIncrementer();

        glm::vec2 size, noiseySize;
        float deg, degreeIncrementer, petalScaler;
        int lifespan;
        ofColor color;
        ofColor newColor;

        float xIncrementer = 0.6;
        float yIncrementer = 1.8;

        float noiseIncrementer = 1.0;

        float incrementer = 0;
        
};
