#version 150

//layout(origin_upper_left) in vec4 gl_FragCoord;

out vec4 outputColor;

const float E = 2.7182818284590452353602874713527; // euler's number
const float PHI = (1.0+sqrt(5.0))/2.0;
const float phi = PHI - 1;
const float TWO_PI = 6.28319;

uniform float nowf;
uniform int nowMillis;
uniform vec3 rand;
uniform vec2 window;

vec2 st;


vec3 color() {
  float r = st.x + sin(TWO_PI * (nowf * .5) + (rand.r*.1) );
  float g = st.y + cos(TWO_PI * (nowf * .5) + (rand.g*.1) );
  float b = st.x + st.y * tan(TWO_PI * (nowf * phi) + (rand.b*.1) );
  return vec3(r, g, b);
}



void main() {
  st = gl_FragCoord.xy / window;

  vec4 c = vec4(color(), 1.);

  outputColor = c;
}

