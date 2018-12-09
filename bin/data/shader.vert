#version 120

// Varying
varying vec2 vertexCoordVarying;
varying float len;

// Uniform
uniform float u_sizeX;
uniform float u_sizeY;
uniform float u_time;
uniform float u_incrementer;
uniform float u_lifespan;
uniform float u_zIndex;
uniform vec3 u_rgb;

// normal variables
float PI = 3.14159265359;

void main() {
	vertexCoordVarying = gl_Vertex.xy;
	
	// get vertex position
    vec4 pos = gl_Vertex;   // vec4 = x,y,z (and w...)

    // Calculate the distance of the vertex from 0,0
    float len = distance(pos.xy, vec2(0.0, 0.0))/distance(vec2(u_sizeX, u_sizeY), vec2(0.0, 0.0));
    float lenX = pos.x/u_sizeX;
    float lenY = pos.y/u_sizeY;

    // Change the z position of vertex depending on where it is in relation to 0.0
    // so that the petals don't overlap each other
    pos.z = (1.f * lenX) + u_zIndex;
    // Change the z position based on how far away the petal is, curl it up at the end
    // pos.z += 10.f * smoothstep(0.9, 1.f, lenY);

    pos.x += sin(pos.x/80.f + u_time) * 30.f;

    // Change the pos values if you wanna,
    // then they'll change in the output here
    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * pos;
}