#include <stdio.h>
#include <stdlib.h>
#include <glad/glad.h>
#include "../include/glfw3.h"
#include "../include/myShader.h"
#include "../include/plane.h"
#define HEIGHT 400
#define WIDTH 800
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void process_input(GLFWwindow *window){

    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, 1);
}
int main(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "cube", NULL, NULL);
    if(!window){
        printf("load window faild\n");
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        printf("glad load faild\n");
        return -1;
    }
    Shader shader = Shader("./Shaders/vert.glsl","./Shaders/frag.glsl");
    glm::vec3 o = {-1.0f,-1.0f,0.0f};
    plane *p = create_plane(o,back,shader.ID);
    glViewport(0, 0, WIDTH, HEIGHT);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    while (!glfwWindowShouldClose(window))
    {
        
        process_input(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        render_plane(p);
        rotate_plane(p,z,(float)glfwGetTime()*100);


        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}

