#ifndef __PLANE_H
#define __PLANE_H
#include <glfw3native.h>
#include "./glad/glad.h"
#include "../include/utils.h"
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
	right,
	none
}directions;

typedef struct
{
    float v1[3];
    float v2[3];
    float origin[3];
	colors color;
    GLuint VAO;
    GLuint VBO;
	GLuint EBO;
	GLuint program;
}plane;


colors direction2color(directions);
void init_vector(plane *,directions);
plane *create_plane(float [3],directions,GLint);
void rotate_plane(plane *,axis,float);
void use_program(plane *);
void render_plane(plane *);
#endif
