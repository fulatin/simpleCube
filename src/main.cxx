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
    float o[3] = {0.0f,0.0f,0.0f};
    plane *p = create_plane(o,back,shader.ID);
    plane *p1 = create_plane(o,left,shader.ID);
    glViewport(0, 0, WIDTH, HEIGHT);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    while (!glfwWindowShouldClose(window))
    {
        
        process_input(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        render_plane(p);
        render_plane(p1);
        // unsigned int VBO;
        // glGenBuffers(1,&VBO);
        // glBindBuffer(GL_ARRAY_BUFFER,VBO);
        // glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
        // const char *vertexShaderSource = "#version 330 core\n"
        //             "layout (location = 0) in vec3 aPos;\n"
        //             "void main()\n"
        //             "{\n"
        //             "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        //             "}\0";
        // unsigned int vertexShader;
        // vertexShader = glCreateShader(GL_VERTEX_SHADER);
        // glShaderSource(vertexShader,1,&vertexShader,NULL);
        // glCompileShader(vertexShader);
        // const char* fragmentShaderSource = "#version 330 core"
        //         "out vec4 FragColor;\n"
        //         "void main()\n"
        //         "{\n"
        //         "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        //         "} \0";
        // unsigned int fragmentShader;
        // fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        // glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        // glCompileShader(fragmentShader);
        // unsigned int shaderProgram;
        // shaderProgram = glCreateProgram();
        // glAttachShader(shaderProgram, vertexShader);
        // glAttachShader(shaderProgram, fragmentShader);
        // glLinkProgram(shaderProgram);
        // glDeleteShader(vertexShader);
        // glDeleteShader(fragmentShader);
        // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        // glEnableVertexAttribArray(0);


        

        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}

