#ifndef __CUBE_H
#define __CUBE_H
#include <block.h>
typedef enum{
    R,
    M,
    L,
    U,
    E,
    D,
    F,
    S,
    B
}layers;

class cube
{
public:
    glm::vec3 centerPoint;
    bool isRotating;
    bool reverse;
    layers rotateLayer;
    axis a;
    int index;
    float deg;
    float speed;
    block blocks[3][3][3];
    cube(){};
    cube(Shader *);
    ~cube(){};
    void render();
    void rotate_axis(axis,int);
    void rotate();
    void set_rotate(layers,bool); //bool decides whether reserves
    void rotateFinish();  //change the value
    void action(float);
};



#endif