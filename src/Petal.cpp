#include "Petal.hpp"

// Use an initializer list
Petal::Petal(){
}

// Overload the constructor
Petal::Petal(int _r, int _g, int _b, float _deg, float _degreeIncrementer, float _petalScaler, int _lifespan){
    r = _r;
    g = _g;
    b = _b;
    size = glm::vec2(xIncrementer, yIncrementer);
    deg = _deg;
    degreeIncrementer = _degreeIncrementer;
    petalScaler = _petalScaler;
    lifespan = _lifespan;
    noiseySize.x = ofNoise(ofGetElapsedTimef());
    noiseySize.y = ofNoise(ofGetElapsedTimef() + 100);
    // Unable to get shader.vert working...
    shader.load("","shader.frag");
}

void Petal::update(){
    noiseySize.x = (ofSignedNoise(ofGetElapsedTimef())) * noiseIncrementer;
    noiseySize.y = (ofSignedNoise(ofGetElapsedTimef() + 100)) * noiseIncrementer;
    incrementer += 1;
    incrementer = ofClamp(incrementer, 0, lifespan);
    if (incrementer > lifespan * 0.75) {
        size.x -= xIncrementer/8 + noiseySize.x;
        size.y -= yIncrementer/8 + noiseySize.y;
    } else {
        size.x += xIncrementer + noiseySize.x;
        size.y += yIncrementer + noiseySize.y;
    }
    deg += degreeIncrementer;
}

void Petal::draw(){
    ofPushStyle();
    int newR;
    int newG;
    int newB;
    int maxVal = MAX(MAX(r, g), b);
    float multiplier = 255/maxVal;
    if (incrementer > lifespan * 0.75) {
        newR = ofLerp(int(r*multiplier), 0, (incrementer - lifespan * 0.75)/(lifespan * 0.25));
        newG = ofLerp(int(g*multiplier), 0, (incrementer - lifespan * 0.75)/(lifespan * 0.25));
        newB = ofLerp(int(b*multiplier), 0, (incrementer - lifespan * 0.75)/(lifespan * 0.25));
    } else {
        newR = ofLerp(r, int(r * multiplier), incrementer/(lifespan * 0.75 - 1));
        newG = ofLerp(g, int(g * multiplier), incrementer/(lifespan * 0.75 - 1));
        newB = ofLerp(b, int(b * multiplier), incrementer/(lifespan * 0.75 - 1));
    }
    ofRotate(deg);
    // Draw the shape here
    ofPath path;
    path.moveTo(0, 0);
    path.curveTo(0, 0);
    path.curveTo(-size.x, size.y * petalScaler);
    path.curveTo(0, size.y);
    path.curveTo(size.x, size.y * petalScaler);
    path.curveTo(0, 0);
    path.close();
    shader.begin();
    shader.setUniform1f("u_r", newR/255.0);
    shader.setUniform1f("u_g", newG/255.0);
    shader.setUniform1f("u_b", newB/255.0);
    path.setCircleResolution(100);
    path.draw();
    shader.end();
    ofPopStyle();
}

float Petal::getIncrementer(){
    return incrementer;
}
