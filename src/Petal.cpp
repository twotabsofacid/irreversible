#include "Petal.hpp"

// Use an initializer list
Petal::Petal(){
}

// Overload the constructor
Petal::Petal(ofColor _color, float _deg, float _degreeIncrementer, int _lifespan){
    size = glm::vec2(xIncrementer, yIncrementer);
    color = _color;
    newColor = _color;
    deg = _deg;
    degreeIncrementer = _degreeIncrementer;
    lifespan = _lifespan;
    noiseySize.x = ofNoise(ofGetElapsedTimef());
    noiseySize.y = ofNoise(ofGetElapsedTimef() + 100);
}

void Petal::update(){
    noiseySize.x = (ofNoise(ofGetElapsedTimef()) - 0.5) * 2;
    noiseySize.y = (ofNoise(ofGetElapsedTimef() + 100) - 0.5) * 2;
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
    ofColor c = color;
    c.setBrightness(240);
    if (incrementer > lifespan * 0.75) {
        newColor = c;
        newColor.lerp(ofColor(0, 0, 0), (incrementer - lifespan * 0.75)/(lifespan * 0.25));
    } else {
        newColor = color;
        newColor.lerp(c, incrementer/(lifespan * 0.75 - 1));
    }
    ofSetColor(newColor);
    ofRotate(deg);
    // Draw the shape here
    // ofDrawEllipse(0, 0, size.x, size.y);
    ofPath path;
    path.arc(0, size.y/2, size.x, size.y, 0, 360);
    path.setFillColor(newColor);
    path.setCircleResolution(100);
    path.draw();
    ofPopStyle();
}

float Petal::getIncrementer(){
    return incrementer;
}
