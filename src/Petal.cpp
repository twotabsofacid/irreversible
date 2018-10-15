#include "Petal.hpp"

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
}

void Petal::draw(){
    ofPushStyle();
    float b = color.getBrightness();
    b += 1;
    color.setBrightness(b);
    incrementer += 0.5;
    incrementer = ofClamp(incrementer, 0, 255);
    ofSetColor(color, 255 - incrementer);
    ofDrawEllipse(pos.x, pos.y, size.x, size.y);
    ofPopStyle();
}

float Petal::getIncrementer(){
    return incrementer;
}
