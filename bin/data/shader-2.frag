#ifdef GL_ES
precision mediump float;
#endif

#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable

uniform sampler2DRect texture0;
uniform float u_time;

void main() {
	vec2 pos = gl_TexCoord[0].st;
	float amp = sin( pos.y * 0.03 );
	pos.x += sin( u_time * 2.0 ) * amp * 50.0; //Shifting x-coordinate
	gl_FragColor = vec4(1.0, 0.0, 1.0, 1.0);
	//Getting pixel color from texture tex0 in position pos
	vec4 color = texture2DRect( texture0, pos );
	//Output of shader
	gl_FragColor = color;
}