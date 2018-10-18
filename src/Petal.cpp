#include "Petal.hpp"

float deg = 0.0;

// Use an initializer list
Petal::Petal()
: pos(0, 0),
  vel(0, 0)
{
    // pos = glm::vec2(0, 0);
    // vel = glm::vec2(0, 0);
}

// Overload the constructor
Petal::Petal(glm::vec2 _pos, glm::vec2 _vel, ofColor _color){
    pos = _pos;
    vel = _vel;
    size = glm::vec2(10, 10);
    color = _color;
}

void Petal::update(){
    vel += acc;
    pos += vel;
    size.x++;
    size.y++;
    deg += 0.1;
}

void Petal::draw(){
    ofPushStyle();
    ofPushMatrix();
    ofEnableSmoothing();
    ofEnableAntiAliasing();
    // float b = color.getBrightness();
    // b += 1;
    // color.setBrightness(b);
    incrementer += 0.5;
    incrementer = ofClamp(incrementer, 0, 255);
    ofColor c = color;
    c.lerp(ofColor(255, 255, 255, 255 - incrementer), incrementer/255);
    ofSetColor(c);
    //ofDrawEllipse(pos.x, pos.y, size.x, size.y);
    ofTranslate(pos);
    ofRotate(deg);
    ofBeginShape();
    vector<glm::vec2> points;
    points.push_back(glm::vec2(0.0 - size.x, 0.0 - size.y));
    points.push_back(glm::vec2(0.0 - size.x, 0.0 + size.y));
    points.push_back(glm::vec2(0.0 + size.x, 0.0 + size.y));
    points.push_back(glm::vec2(0.0 + size.x, 0.0 - size.y));
    points.push_back(glm::vec2(0.0 - size.x, 0.0 - size.y));
    points.push_back(glm::vec2(0.0 - size.x, 0.0 + size.y));
    points.push_back(glm::vec2(0.0 + size.x, 0.0 + size.y));
    ofCurveVertices(points);
    ofEndShape();
    ofPopMatrix();
    ofPopStyle();
}

float Petal::getIncrementer(){
    return incrementer;
}
