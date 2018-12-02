#version 120

varying vec2 texCoordVarying;   // shared texture coords

void main() {
	texCoordVarying = gl_MultiTexCoord0.xy;
}