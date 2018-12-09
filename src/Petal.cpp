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
    // load the shaders
    shader.load("shader.vert","shader.frag");
}

void Petal::update(){
    noiseySize.x = (ofSignedNoise(ofGetElapsedTimef())) * noiseIncrementer;
    noiseySize.y = (ofSignedNoise(ofGetElapsedTimef() + 100)) * noiseIncrementer;
    zIndex -= 1;
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
    ofRotate(deg);
    // Draw the line
    drawLine();
    // Begin the shader, assign variables
    shader.begin();
    shader.setUniform1f("u_sizeX", size.x * 2.0);
    shader.setUniform1f("u_sizey", size.y);
    shader.setUniform1f("u_time", ofGetElapsedTimef());
    shader.setUniform1f("u_incrementer", incrementer);
    shader.setUniform1f("u_lifespan", lifespan);
    shader.setUniform1f("u_zIndex", zIndex);
    shader.setUniform3f("u_rgb", glm::vec3(r/255.0, g/255.0, b/255.0));
    // Create the mesh based on the ofPolyline object, draw it
    mesh.triangulate(line, 28, -1);
    mesh.draw();
    // End the shader
    shader.end();
    ofPopStyle();
}

float Petal::getIncrementer(){
    return incrementer;
}

void Petal::drawLine(){
    line.clear();
    // Bottom
    line.addVertex(0, 0);
    line.curveTo(0, 0);
    // Left side
    line.curveTo(-size.x, size.y * petalScaler);
    // Top
    line.curveTo(0, size.y);
    // Right size
    line.curveTo(size.x, size.y * petalScaler);
    // Bottom again
    line.curveTo(0, 0);
    line.close();
}
