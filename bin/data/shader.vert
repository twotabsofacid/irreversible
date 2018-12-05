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

    // Calculate the distance of the vertex from 0,0
    float len = distance(gl_Vertex.xy, vec2(0.0, 0.0))/distance(vec2(u_sizeX, u_sizeY), vec2(0.0, 0.0));

    // TODO
    // Use smoothstep to make the petal curl out & down at the edges
    // to give the illusion of depth
    // This is kind of working but also extremely fucked
    if (distance(vec2(u_sizeX, u_sizeY), vec2(0.0, 0.0)) > 200) {
        pos.z -= smoothstep(0.9, 1.0, len);
    }

    pos.x += sin(gl_Vertex.x/80.f + u_time) * 30.f;

    // Change the pos values if you wanna,
    // then they'll change in the output here
    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * pos;
}