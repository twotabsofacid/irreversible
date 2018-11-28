#version 120

varying vec2 texCoordVarying;

uniform float u_incrementer;

void main() {
	texCoordVarying = gl_MultiTexCoord0.xy;
	
	gl_Position = ftransform();
}