#version 120

varying vec2 vertexCoordVarying;
varying float len;
uniform float u_time;

void main() {
	vertexCoordVarying = gl_Vertex.xy;
	
	// get vertex position
    vec4 pos = gl_Vertex;   // vec4 = x,y,z (and w...)
    
    
    // manipulate depth based on sin wave
    //  wave travels along x
    
    // float x = pos.x * 15.f;  // arbitrary scale
    
    // pos.z += sin( x + u_time ) * 1.f;
    
    // set vertex screen position
    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * pos;
}