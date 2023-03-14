#version 330 core
out vec4 FragColor;

in vec2 outTexco;

uniform sampler2D textureID;

void main(){
  FragColor = texture(textureID, outTexco);
}

