#include <plane.h>
class myplane:public plane{
public:
    myplane(glm::vec3 origan,directions d,Shader* shader){
        shader = shader;
    }
	void rotate_plane(plane *,axis,float);
	void rotate_plane(plane *,axis,float,glm::vec3);
	void use_program(plane *);
	void render_plane(plane *);
};

