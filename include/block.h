#ifndef __BLOCK_H
#define __BLOCK_H
#include<plane.h>
class block
{
public:
    plane planes[6];
    block(glm::vec3,Shader *s);
    ~block(){};
    void rotate(axis,float,glm::vec3);
    void render();
};


#endif  