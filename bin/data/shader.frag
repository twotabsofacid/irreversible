#version 120

// Varying
varying vec2 vertexCoordVarying;

// Uniform
uniform float u_sizeX;
uniform float u_sizeY;
uniform float u_time;
uniform float u_incrementer;
uniform float u_lifespan;
uniform float u_zIndex;
uniform vec3 u_rgb;

void main() {
    // Should move all these calculations into shader
    vec3 new_rgb = vec3(0.f, 0.f, 0.f);
    float len = distance(vertexCoordVarying.xy, vec2(0.0, 0.0))/distance(vec2(u_sizeX, u_sizeY), vec2(0.0, 0.0));
    float maxVal = max(max(u_rgb.r, u_rgb.g), u_rgb.b);
    float multiplier = (1/maxVal) * (len * 1.6);
    // If we're more than 75% of the way through the lifespan, start fading colors to black
    if (u_incrementer > u_lifespan * 0.75) {
        new_rgb.r = mix(u_rgb.r * multiplier, 0.0, (u_incrementer - u_lifespan * 0.75)/(u_lifespan * 0.25));
        new_rgb.g = mix(u_rgb.g * multiplier, 0.0, (u_incrementer - u_lifespan * 0.75)/(u_lifespan * 0.25));
        new_rgb.b = mix(u_rgb.b * multiplier, 0.0, (u_incrementer - u_lifespan * 0.75)/(u_lifespan * 0.25));
    } else { // otherwise, fade the colors to the highest brightness
        new_rgb.r = mix(u_rgb.r, u_rgb.r * multiplier, u_incrementer/(u_lifespan * 0.75 - 1));
        new_rgb.g = mix(u_rgb.g, u_rgb.g * multiplier, u_incrementer/(u_lifespan * 0.75 - 1));
        new_rgb.b = mix(u_rgb.b, u_rgb.b * multiplier, u_incrementer/(u_lifespan * 0.75 - 1));
    }
    gl_FragColor = vec4(new_rgb, 1.0);
}