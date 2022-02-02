#version 330 core
out vec4 FragColor;
in float vertexColor;
// typedef enum{
// 	blue=0,
// 	green,
// 	red,
// 	orange,
// 	white,
// 	yellow,
// 	grey

// }colors;
void main(){
    vec4 color;
    if(vertexColor<1){
        color = vec4(0.0,0.0,0.5,1.0);
    }
    else if(vertexColor<2){
        color = vec4(0.0,0.5,0.0,1.0); 
    }
    else if(vertexColor<3){
        color = vec4(0.5,0.0,0.0,1.0);
    }
    else if(vertexColor<4){
        color = vec4(0.5,0.5,0.1,1.0);//orange
    }
    else if(vertexColor<5){
        color = vec4(0.5,0.5,0.5,1.0);
    }
    else if(vertexColor<6){
        color = vec4(0.5,0.1,0.5,1.0);//yellow
    }
    else if(vertexColor<7){
        color = vec4(0.1,0.1,0.1,1.0);
    }

    

    FragColor = color;
}