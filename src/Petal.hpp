#pragma once
#include "ofMain.h"
#include "ofxTriangleMesh.h"

class Petal {

    public:
        Petal();
        Petal(glm::vec3 _rgb, float _deg, float _degreeIncrementer, float _petalScaler, int _lifespan);
        void update();
        void draw();
        float getIncrementer();
        void drawLine();

        glm::vec3 rgb;
        glm::vec2 size, noiseySize;
        float deg, degreeIncrementer, petalScaler;
        int lifespan;

        float xIncrementer = 0.7;
        float yIncrementer = 2.1;

        float zIndex = 0.0;

        float noiseIncrementer = 1.0;

        float incrementer = 0;

        ofShader shader;

        ofPolyline line;

        ofxTriangleMesh mesh;
        
};
