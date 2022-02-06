#include <cube.h>

cube::cube(Shader *s){
    isRotating = false;
    speed = 30;
    deg = 0;
    centerPoint = glm::vec3(-1.5,-1.5,-1.5);
    int i,j,k;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            for(k=0;k<3;k++){
                blocks[i][j][k] = block(glm::vec3(i,j,k),s);
            }
        }
    }
}

void cube::render(){
    int i,j,k;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            for(k=0;k<3;k++){
                blocks[i][j][k].render();
            }
        }
    }
}

void cube::set_rotate(layers l,bool r){
    if(!isRotating){
        isRotating = true;
        deg = 0.0f;
        reverse = r;
        if(l==R||l==M||l==L)
        {
            a = x;
            switch (l)
            {
                case R:
                    index = 2;
                    break;
                case M:
                    index = 1;
                    break;
                case L:
                    printf("enter");
                    index = 0;
                    break;
                default:
                    break;
            }
        }
        if(l== U||l==E||l==D)
        {
            printf("enter");
            a = y;
            switch (l)
            {
                case U:
                    index = 2;
                    break;
                case M:
                    index = 1;
                    break;
                case D:
                    index = 0;
                    break;
                default:
                    break;
            }
        }
        if(l==F||l==S||l==B)
        {
            printf("enter");
            a = z;
            switch (l)
            {
                case B:
                    index = 2;
                    break;
                case S:
                    index = 1;
                    break;
                case F:
                    index = 0;
                    break;
                default:
                    break;
            }
        }
    }
}
void cube::action(float deltaTime){
    if(isRotating){
        rotate(deltaTime*speed);
        if(reverse)
        {
            deg -=deltaTime*speed;
        }
        else
        {
            deg +=deltaTime*speed;
        }
    }
    render();
    if(deg<-90){
        deg = -90;
        rotateFinish();
        isRotating = false;
    }
    if(deg>90){
        deg = 90;
        rotateFinish();
        isRotating = false;
    }
}

void cube::rotate(float degree){
    int i,j;
    if(a == x){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                blocks[index][i][j].rotate(a,degree,centerPoint);
            }
        }
    }
    if(a == y){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                blocks[i][index][j].rotate(a,degree,centerPoint);
            }
        }
    }
    if(a == z){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                blocks[j][i][index].rotate(a,degree,centerPoint);
            }
        }
    }
}
void exchange(block *b1,block *b2){
    block temp;
    temp = *b1;
    *b1 = *b2;
    *b2 = temp;
}


//there must be a smarter way
void cube::rotateFinish(){
    int i,j;
    if(a == x){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                blocks[index][i][j].rotateFinish(a,deg,centerPoint);
            }
        }
        if(!reverse){
            printf("yes\n");

            //exchange the corners
            exchange(&blocks[index][0][0],&blocks[index][2][0]);
            exchange(&blocks[index][0][0],&blocks[index][2][2]);
            exchange(&blocks[index][0][0],&blocks[index][0][2]);

            //exchange the edges
            exchange(&blocks[index][0][1],&blocks[index][1][0]);
            exchange(&blocks[index][0][1],&blocks[index][2][1]);
            exchange(&blocks[index][0][1],&blocks[index][1][2]);


        }
        else{
            printf("yes\n");

            //exchange the corners
            exchange(&blocks[index][0][0],&blocks[index][0][2]);
            exchange(&blocks[index][0][0],&blocks[index][2][2]);
            exchange(&blocks[index][0][0],&blocks[index][2][0]);

            //exchange the edges
            exchange(&blocks[index][0][1],&blocks[index][1][2]);  
            exchange(&blocks[index][0][1],&blocks[index][2][1]);
            exchange(&blocks[index][0][1],&blocks[index][1][0]);
        }
    }
    if(a == y){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                blocks[i][index][j].rotateFinish(a,deg,centerPoint);
            }
        }
        if(!reverse){
            printf("yes\n");

            //exchange the corners
            exchange(&blocks[0][index][0],&blocks[2][index][0]);
            exchange(&blocks[0][index][0],&blocks[2][index][2]);
            exchange(&blocks[0][index][0],&blocks[0][index][2]);
            //exchange the edges
            exchange(&blocks[0][index][1],&blocks[1][index][0]);
            exchange(&blocks[0][index][1],&blocks[2][index][1]);
            exchange(&blocks[0][index][1],&blocks[1][index][2]);
        }
        else{
            printf("yes\n");

            //exchange the corners
            exchange(&blocks[0][index][0],&blocks[0][index][2]);   
            exchange(&blocks[0][index][0],&blocks[2][index][2]);
            exchange(&blocks[0][index][0],&blocks[2][index][0]);
            //exchange the edges
            exchange(&blocks[0][index][1],&blocks[1][index][2]);
            exchange(&blocks[0][index][1],&blocks[2][index][1]);
            exchange(&blocks[0][index][1],&blocks[1][index][0]);

        }
    }

    /* 
    it seems that there is something wrong!!!
     */
    if(a == z){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                blocks[j][i][index].rotateFinish(a,deg,centerPoint);
            }
        }
        if(!reverse){
            //exchange the corners
            exchange(&blocks[0][0][index],&blocks[2][0][index]);
            exchange(&blocks[0][0][index],&blocks[2][2][index]);
            exchange(&blocks[0][0][index],&blocks[0][2][index]);
            //exchange the edges
            printf("yes\n");
            exchange(&blocks[0][1][index],&blocks[1][0][index]);
            exchange(&blocks[0][1][index],&blocks[2][1][index]);
            exchange(&blocks[0][1][index],&blocks[1][2][index]);
        }
        else{
            printf("yes\n");

            //exchange the corners
            exchange(&blocks[0][0][index],&blocks[0][2][index]);   
            exchange(&blocks[0][0][index],&blocks[2][2][index]);
            exchange(&blocks[0][0][index],&blocks[2][0][index]);
            //exchange the edges
            exchange(&blocks[0][1][index],&blocks[1][2][index]);
            exchange(&blocks[0][1][index],&blocks[2][1][index]);
            exchange(&blocks[0][1][index],&blocks[1][0][index]);

        }
    }
}