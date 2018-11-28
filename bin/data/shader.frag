#version 120

varying vec2 texCoordVarying;

uniform float u_incrementer;

void main() {
	if (u_incrementer > 225.0) {
		gl_FragColor = vec4(texCoordVarying.x, texCoordVarying.y,1.0,1.0);
	} else {
		gl_FragColor = vec4(1.0,texCoordVarying.x,texCoordVarying.y,1.0);
	}
}