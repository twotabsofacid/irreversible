#include "Petal.hpp"

// Use an initializer list
Petal::Petal(){
}

// Overload the constructor
Petal::Petal(ofColor _color, float _deg, float _degreeIncrementer){
    size = glm::vec2(1, 2.5);
    color = _color;
    deg = _deg;
    degreeIncrementer = _degreeIncrementer;
    noiseySize.x = ofNoise(ofGetElapsedTimef());
    noiseySize.y = ofNoise(ofGetElapsedTimef() + 100);
}

void Petal::update(){
    noiseySize.x = ofNoise(ofGetElapsedTimef());
    noiseySize.y = ofNoise(ofGetElapsedTimef() + 100);
    size.x += 1 + noiseySize.x;
    size.y += 2.5 + noiseySize.y;
    deg += degreeIncrementer;
}

void Petal::draw(){
    ofPushStyle();
    ofPushMatrix();
    incrementer += 1;
    incrementer = ofClamp(incrementer, 0, 255);
    ofColor c = color;
    c.lerp(ofColor(255, 255, 255), incrementer/255);
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
