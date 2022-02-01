#version 330 core
layout (location = 0) in vec4 aPos;
out vec4 vertexColor;
uniform mat4 transform;
void main(){
    gl_Position = transform*vec4(aPos.x,aPos.y,aPos.z,5.0);
    vertexColor = vec4(aPos.w,0.0,0.0,1.0);
}