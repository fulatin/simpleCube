#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
float *add(float f1[3],float f2[3]){
    float *dest = (float *)calloc(3,sizeof(float));
    dest[0] = f1[0]+f2[0];
    dest[1] = f1[1]+f2[1];
    dest[2] = f1[2]+f2[2];
    return dest;
}


/**
 * @brief 
 * note:
 *  this is f1-f2
 * @param f1 a vector
 * @param f2 a vector
 * @return ** float* 
 */

float *substract(float f1[3],float f2[3]){
    float *dest = (float *)calloc(3,sizeof(float));
    dest[0] = f1[0]-f2[0];
    dest[1] = f1[1]-f2[1];
    dest[2] = f1[2]-f2[2];
    return dest;
}