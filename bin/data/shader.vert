// vertex shader

#version 150

uniform mat4 modelViewProjectionMatrix;
uniform float time;
uniform float xPositions[3000];
uniform float yPositions[3000];
in vec4 position;

void main(){
    gl_Position = modelViewProjectionMatrix * position;
}
