#ifndef MODELVERTEX_H
#define MODELVERTEX_H

struct MODEL_VERTEX{
    MODEL_VERTEX(float x,float y,float z){
        this->x =x;
        this->y = y;
        this->z = z;
    }

    float x;
    float y;
    float z;
};

#endif // MODELVERTEX_H
