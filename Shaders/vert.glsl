#version 330 core
layout (location = 0) in vec4 aPos;
out vec4 vertexColor;
void main(){
    gl_Position = vec4(aPos.x,aPos.y,aPos.z,1.0);
    vertexColor = vec4(aPos.z,0.0,0.0,1.0);
}