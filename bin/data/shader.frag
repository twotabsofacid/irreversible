#ifdef GL_ES
precision mediump float;
#endif

uniform float u_incrementer;

void main() {
	if (u_incrementer > 225.0) {
		gl_FragColor = vec4(1.0,0.0,1.0,1.0);
	} else {
		gl_FragColor = vec4(1.0,0.0,0.5,1.0);
	}
}