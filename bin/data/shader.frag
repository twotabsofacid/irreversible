#version 120

uniform float u_incrementer;
uniform float u_lifespan;
uniform float u_r;
uniform float u_g;
uniform float u_b;

varying vec2 texCoordVarying;

void main() {
	// Should move all these calculations into shader
    float newR;
    float newG;
    float newB;
    float maxVal = max(max(u_r, u_g), u_b);
    float multiplier = 1/maxVal;
    if (u_incrementer > u_lifespan * 0.75) {
        newR = mix(u_r * multiplier, 0.0, (u_incrementer - u_lifespan * 0.75)/(u_lifespan * 0.25));
        newG = mix(u_g * multiplier, 0.0, (u_incrementer - u_lifespan * 0.75)/(u_lifespan * 0.25));
        newB = mix(u_b * multiplier, 0.0, (u_incrementer - u_lifespan * 0.75)/(u_lifespan * 0.25));
    } else {
        newR = mix(u_r, u_r * multiplier, u_incrementer/(u_lifespan * 0.75 - 1));
        newG = mix(u_g, u_g * multiplier, u_incrementer/(u_lifespan * 0.75 - 1));
        newB = mix(u_b, u_b * multiplier, u_incrementer/(u_lifespan * 0.75 - 1));
    }
	gl_FragColor = vec4(newR, newG, newB, 1.0);
}