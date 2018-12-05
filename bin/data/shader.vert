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
uniform vec3 u_rgb;

// normal variables
float PI = 3.14159265359;

void main() {
	vertexCoordVarying = gl_Vertex.xy;
	
	// get vertex position
    vec4 pos = gl_Vertex;   // vec4 = x,y,z (and w...)

    pos.x += sin( vertexCoordVarying.x/80 + u_time ) * 40.f;

    // TODO
    // Use smoothstep to make the petal curl out & down at the edges
    // to give the illusion of depth

    // Change the pos values if you wanna,
    // then they'll change in the output here
    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * pos;
}