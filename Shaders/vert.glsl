#version 330 core
layout (location = 0) in vec4 aPos;
out float vertexColor;
uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;
void main(){
    vec4 temp =projection * view * transform * vec4(aPos.x,aPos.y,aPos.z,1.0);
    gl_Position = temp;
    vertexColor = aPos.w;
}