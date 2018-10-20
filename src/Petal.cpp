#include "Petal.hpp"

float xIncrementer = 1.0;
float yIncrementer = 3.0;

// Use an initializer list
Petal::Petal(){
}

// Overload the constructor
Petal::Petal(ofColor _color, float _deg, float _degreeIncrementer){
    size = glm::vec2(xIncrementer, yIncrementer);
    color = _color;
    deg = _deg;
    degreeIncrementer = _degreeIncrementer;
    noiseySize.x = ofNoise(ofGetElapsedTimef());
    noiseySize.y = ofNoise(ofGetElapsedTimef() + 100);
}

void Petal::update(){
    noiseySize.x = ofNoise(ofGetElapsedTimef()) - 0.5;
    noiseySize.y = ofNoise(ofGetElapsedTimef() + 100) - 0.5;
    if (size.x > 300) {
        size.x -= xIncrementer + noiseySize.x;
        size.y -= yIncrementer + noiseySize.y;
    } else {
        size.x += xIncrementer + noiseySize.x;
        size.y += yIncrementer + noiseySize.y;
    }
    deg += degreeIncrementer;
}

void Petal::draw(){
    ofPushStyle();
    ofPushMatrix();
    incrementer += 1;
    incrementer = ofClamp(incrementer, 0, 300);
    ofColor c = color;
    if (incrementer > 50) {
        c.lerp(ofColor(0, 0, 0), (incrementer - 50)/250);
    }
    ofSetColor(c);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotate(deg);
    ofDrawEllipse(0, 0, size.x, size.y);
    // ofBeginShape();
    // vector<glm::vec2> points;
    // points.push_back(glm::vec2(0.0 - size.x, 0.0 - size.y));
    // points.push_back(glm::vec2(0.0 - size.x, 0.0 + size.y));
    // points.push_back(glm::vec2(0.0 + size.x, 0.0 + size.y));
    // points.push_back(glm::vec2(0.0 + size.x, 0.0 - size.y));
    // points.push_back(glm::vec2(0.0 - size.x, 0.0 - size.y));
    // points.push_back(glm::vec2(0.0 - size.x, 0.0 + size.y));
    // points.push_back(glm::vec2(0.0 + size.x, 0.0 + size.y));
    // ofCurveVertices(points);
    // ofEndShape();
    ofPopMatrix();
    ofPopStyle();
}

float Petal::getIncrementer(){
    return incrementer;
}
