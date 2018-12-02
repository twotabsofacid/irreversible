#version 120

uniform float u_r;
uniform float u_g;
uniform float u_b;

void main() {
	gl_FragColor = vec4(u_r,u_g,u_b,1.0);
}