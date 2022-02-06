#ifndef __PLANE_H
#define __PLANE_H
#include <glfw3native.h>
#include "./glad/glad.h"
#include <myShader.h>
#include "../include/glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
typedef enum{
	blue=0,
	green,
	red,
	orange,
	white,
	yellow,
	grey

}colors;
typedef enum{
	x=0,
	y,
	z
}axis;
typedef enum{
	front=0,
	back,
	up,
	down,
	left,
	right
}directions;
colors direction2color(directions);


class plane
{
public:
	glm::mat4 transform;
	glm::vec3 p1;
    glm::vec3 p2;
    glm::vec3 p3;
	glm::vec3 p4;
	colors color;
    GLuint VAO;
    GLuint VBO;
	GLuint EBO;
	Shader *shader;
	plane(){};
	plane(glm::vec3,directions,Shader*);
	~plane(){};
	void rotate(axis,float);
	void rotate(axis,float,glm::vec3);
	void rotateFinish(axis,float,glm::vec3);
	void use_program();
	void render();
};


#endif
