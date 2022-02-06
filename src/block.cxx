#include <block.h>
/**
 *          | y:+  
 *          |   z:-
 *          | /    we put block here;
 * x:- -----/------  x:+
 *         /|
 *        / | y:-
 *      z:+   
 * 
 * 
 */
block::block(glm::vec3 o,Shader *s)
{
    planes[0] = plane(o,left,s);
    planes[1] = plane(o,down,s);
    planes[2] = plane(o,front,s);

    o = o+glm::vec3(1.0,1.0,1.0);
    planes[3] = plane(o,right,s);
    planes[4] = plane(o,up,s);
    planes[5] = plane(o,back,s);

};
void block::render(){
    int i;
    for(i=0;i<6;i++){
        planes[i].render();           
    }
        
};

void block::rotate(axis a,float deg,glm::vec3 o){
    int i;
    for(i=0;i<6;i++){
        planes[i].rotate(a,deg,o);
    }

}

void block::rotateFinish(axis a,float deg,glm::vec3 o){
    int i;
    for(i=0;i<6;i++){
        planes[i].rotateFinish(a,deg,o);
    }
}

